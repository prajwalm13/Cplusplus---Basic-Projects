#include<iostream>
#include<vector>
using namespace std;

class Student{
public:
    int id;
    string name;
    int age;

    void input(){
     cout << "Enter Student ID: ";

    while(!(cin >> id)){
    cout << "Invalid input! Enter numeric ID: ";
    cin.clear();                 // clear error state
    cin.ignore(1000, '\n');     // flush buffer
    }
    cin.ignore();

        cout<<"Enter the Student name: ";
        getline(cin,name);

        cout<<"Enter the Student age: ";
        cin>>age;
    }


    void display(){
        cout<<"Student ID :- "<<id<<endl;
        cout<<"Name       :- "<<name<<endl;
        cout<<"Age        :- "<<age<<endl;
    }
};

int main(){

    vector<Student> students;
    int search, choice;

    do{
        cout << "\n1. Add Student\n";
        cout << "2. View Students\n";
        cout << "3. Search Student\n";
        cout<<  "4. Delete student\n";
        cout << "5. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        // 🔹 Add Student
        if(choice==1){
            Student s;
            s.input();

            bool exists = false;

            for(auto &st : students){
                if(st.id == s.id){
                    exists = true;
                    break;
                }
            }

            if(exists){
                cout<<"❌ This ID already exists\n";
            } 
            else {
                students.push_back(s);
                cout<<"✅ Student added successfully!\n";
            }
        }

        // 🔹 View Students
        else if(choice==2){
            if(students.empty()){
                cout<<"⚠ No data available\n";
            } 
            else{
                for(int i=0;i<students.size();i++){
                    cout<<"------------------"<<endl;
                    students[i].display();
                    cout<<"------------------"<<endl;

                }
            }
        }

        // 🔹 Search Student
        else if(choice==3){
            if(students.empty()){
                cout<<"⚠ No data available\n";
                continue;
            }

            bool found = false;

            cout<<"Enter student ID or Age to search: ";
            cin>>search;

            for(auto &st : students){
                if(st.id==search || st.age==search){
                    cout<<"✅ Student found!\n";
                    cout<<"__________________"<<endl;
                    st.display();
                    cout<<"__________________"<<endl;
                    found = true;
                    break;
                }
            }

            if(!found){
                cout<<"❌ Student not found!\n";
            }
        }
        // delete the student
        else if(choice==4){
            Student s;
           int deleteID;
           bool found = false;

           cout<<"Enter the deleting ID"<<endl;
           cin>>deleteID;

           for(int i=0;i<students.size();i++){
            if(students[i].id==deleteID){
              students.erase(students.begin() + i);
                cout<<"-----------------------------------------------------------------------------\n";
                cout<<"ID:"<<students[i].id<<" "<<"Name:"<<students[i].name<<" "<<"Age:"<<students[i].age<<endl;
                cout<<"Deleted successfully "<<endl;

                cout<<"-----------------------------------------------------------------------------\n";
                found = true;
                break;
           }
        }
        if(!found){
            cout<<"Student with these ID is not exits:"<<endl;
        }

    }

        else{
            cout<<"*** You exited! Thank you for visiting ***\n";

        }

    }while(choice != 5);

    return 0;
}