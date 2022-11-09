#include <bits/stdc++.h>
using namespace std;

class emp {
  public:
    int empId;
    int manId;
    string name;
    int age;

};


unordered_map<int, emp> table;
set<emp> setTable;
priority_queue<int> pqTable;


// assuming tables created.
// we only maintaining it.
// so only searchers allowed. NO insertion, deletion & creation

/*

Give assum:

time    | retrieve | input          | DS
const   | empName   | manId         | hashing
const   | manName   | empId         | hashing
linear  | all age>X | filter(x)     | linear search for age

====================================

<O(n)   | empDetails| empId         | binary serach as Ids are sorted
const   | min(age)  | filter - getmin | ?? 

search(manid)   // returns emp[]                                //
search(empid)   // returns his managerName linked to his manId
filter(x)       // return emp[], emp[].age > x
search(empid)   // return empDetails, fastest 
getYoungest()   // return empDetails[] of minAge

hashing with empid (key, value)

*/


void searchEmployeeName(int pManId) {
    //vector<emp> found;
    
     // emp array of 
    emp obj = table[pManId]; // get manager detail\

    //get empId of employee.manId == pManId;

    while(1) {
        cout <<  for_each(table, table[i].manid == pManId); // linear
    }



}

void searchManagerName(int pEmpId) {

    emp obj = table[pEmpId];
    emp ans = table[obj.manId];
    cout << "ManagerName: " << ans.name << "\n";
}

void filterForAgeGreaterThan(int pAge) {

}

void getEmployeeDetails(int pEmpId) {
    emp ojb = table[pEmpId];

    cout << "Employee Details:  \n"
        << "EmployeeId: " << ojb.empId << endl
        << "ManagerId: " << ojb.manId << endl
        << "Employee Name: " << ojb.name << endl
        << "Employee Age: " << ojb.age << endl;
}

void getYoungestEmployee() {

}

int main()
{

    searchEmployeeName(1034);
    searchManagerName(1045);
    filterForAgeGreaterThan(26);
    getEmployeeDetails(1034);
    getYoungestEmployee();
    return 0;
}