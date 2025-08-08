#include<iostream>
#include<string>
using namespace std;
class Student{
    private:
        int id;
        string name;
        int age;
        char gender;
        string major;
    public:
        Student(){
            id = 0; name = "Unknown"; age = 0; gender = 'N'; major = "IKD";
        }
        Student(int i, string n, int a, char g, string m){
            id = i; name = n; age = a; gender = g; major = m;
        }
        void Input(){
            cout << "Enter Your ID :"; cin>>id;
            cout << "Enter Your Name :"; cin.ignore(); getline(cin,name);
            cout << "Enter Your Age :"; cin>>age;
            cout << "Enter Your Gender (M/F):"; cin>>gender;
            cout << "Enter Your Major :"; cin.ignore(); getline(cin,major);
        }
        void Details(){
            cout << id <<"\t"<< name <<"\t"<< age <<"\t"<< gender <<"\t"<< major <<endl;
        }    
        int getid(){return id;}
        void setid(int i){id = i;}
};
void Register(Student a[], int n){
    for(int i = 0; i<n; i++){
        cout << "Registering Student " << i+1 << endl;
        a[i].Input();
    }
}
void ShowDetails(Student a[], int n){
    for(int i = 0; i<n; i++){
        a[i].Details();
        cout << "---------------------------------------" << endl;
    }
}
void* Search(Student a[], int n, int idd){
    Student *ptr = NULL;
    for(int i = 0; i<n; i++){
        if(a[i].getid() == idd){
            ptr = &a[i];
        }
    }
    return ptr;
}
void Sort(Student a[], int n){
    Student temp;
    for(int i = 0; i<n-1; i++){
        for(int j= i+1; j<n; j++){
            if(a[i].getid() > a[j].getid()){
                temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
    }
}
int main(){
    Student st[20], *ptr;
    int n;
    cout << "Enter the number of students to register: ";
    cin>> n;
    Register(st,n);
    cout << "Details of students to register: ";
    cout << endl;
    cout << "ID\tName\tAge\tGender\tMajor" << endl;
    ShowDetails(st,n);
    int idd, up;
    cout << "Enter ID to search: ";
    cin >> idd;
    ptr = (Student*)Search(st, n, idd);
    if(ptr == NULL){
        cout << "Student With ID "<<idd<<" Not Found!!!!"<<endl;
    }else{
        cout << "Please Enter New Student info Details :" << endl;
        ptr->Input();
    }
    cout << "=====Details of Student After Update=====" << endl;
    cout << "ID\tName\tAge\tGender\tMajor" << endl;
    ShowDetails(st, n);
    cout << "Sorting Students by ID in Descending Order" << endl;   
    Sort(st, n);
    cout <<"=====Detils of student after Sortting =====" << endl;
    cout << "ID\tName\tAge\tGender\tMajor" << endl;
    ShowDetails(st, n);
    return 0;
}    
