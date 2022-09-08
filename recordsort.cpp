//Assignment4.cpp
/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <iomanip>
#include <string> 
#include <fstream>
#include <cctype>
#include <cmath>
#define size 50 

//array size
using namespace std; 
//Functions Below Main 
//Declare Struct

struct employeeData 
//listnode 
{ 
//declare functions
employeeData(); // constructor
void dept_code_converter();
bool dept_code_valid();
bool name_checker();
bool email_checker();
bool checkS_Date();
bool checkE_Date();
bool sal_checker();
bool validChecker();
void salary_predictor();
float dur_calc();
void emp_active();
void dept_title_conv();
int dur;
void month_conv(); 

//Declare Variables 
string first_name;
string last_name;
//char first_name[15];
//char last_name[15];
unsigned start_month;
unsigned start_day;
unsigned start_year;
unsigned end_month;
unsigned end_mon;
unsigned end_day;
unsigned end_year;
float annual_salary;
float annual_salary_pre;
string dept_code; 
string email_address;
bool isValid;
string dept_title;
string date_title; 

};//end struct

//Declare Functions 
//void dept_code_converter();
//bool start_isLeap();
//bool end_isLeap();
//bool date_checker(); 

employeeData employees_temp[size];  
employeeData employees[size];
ofstream outfile;  

void change(); 
void year_converter(); 
void bubbleSort();
void display_emp();
void error_disp();
void display_title();
void check(); 

int final_month;
int final_day;
int final_year;
int end_Month;
int end_Day;
int end_Year;
float duration; 
float dur;
float curr_month;
float curr_day;
float curr_year;
int z=0;
int curr_rec_tot;
int i;
int index; 
int valid_count;
int val_count;
int j;
int error_count;
int complete_rec_tot;

void display_final();  
employeeData yos; //years of service 
int main()
{
       
  //declare variables
  
  ifstream file; 
  file.open("employee.3.09.21.txt"); 
  outfile.open("error.dat"); 
    
  string line;
  int counter=0;
  valid_count=0; 

   display_title(); 
 
 //Reading each record from file
 while(file >> employees_temp[z].last_name )
 {
     
     file    >>  employees_temp[z].first_name 
             >>  employees_temp[z].start_month 
             >>  employees_temp[z].start_day 
             >>  employees_temp[z].start_year 
             >>  employees_temp[z].end_month 
             >>  employees_temp[z].end_day 
             >>  employees_temp[z].end_year  
             >>  employees_temp[z].annual_salary 
             >>  employees_temp[z].dept_code 
             >>  employees_temp[z].email_address;
           //Validation of each record from file 
            employees_temp[z].isValid = employees_temp[z].validChecker();
            employees_temp[z].dept_code_converter();
            employees_temp[z].name_checker(); 
            employees_temp[z].sal_checker();    
            employees_temp[z].email_checker();                  
            employees_temp[z].checkS_Date();
            employees_temp[z].checkE_Date(); 
            
          if(employees_temp[z].isValid == true)
          {       
          employees[valid_count]=employees_temp[z];//Load
          bubbleSort();
          employees[valid_count].salary_predictor();
          valid_count++;
          }   
     error_disp();
     
     curr_rec_tot++; //account for total amount of records
     
 }

display_emp();
complete_rec_tot = curr_rec_tot; 
outfile << endl << "Total number of error record: "<< error_count;
cout<< "\n\nTotal records read: " << complete_rec_tot << endl; 
cout << "Total number of error record: "<< error_count << endl;
cout << "Total Records Processed: "<< valid_count;

 //display_emp();
  cout << endl;

//close files
   file.close();     
   outfile.close();
    
    return 0;
}

void check()
{
    
    for(int jj=0;jj<valid_count;jj++)
    {
        cout << "CHECK CALLED:";
    
cout         <<  employees[jj].last_name <<" "
             <<  employees[jj].first_name <<" "
             <<  employees[jj].start_month <<" "
             <<  employees[jj].start_day<<" " 
             <<  employees[jj].start_year <<" "
             <<  employees[jj].end_month<<" " 
             <<  employees[jj].end_day<<" " 
             <<  employees[jj].end_year <<" " <<endl; 
             /*<<  employees[jj].annual_salary <<" "
             <<  employees[jj].dept_code <<" "
             <<  employees[jj].email_address << endl;*/
}
    
    
}



//https://www.vbforums.com/showthread.php?638840-Manually-calculating-date-difference
float  employeeData::dur_calc()
{
  int end_mon=end_month; 
  int end_yea=end_year; 
  int end_da=end_day; 
  float result;
    
    if(end_month < start_month) 
   {
    end_yea=end_year-1;
    end_mon=end_mon+12;
    }
   
  if(start_day > end_day)
  {
     end_da=end_day+31;
     end_mon=end_mon-1;
     
  }
  
   final_day = end_da-start_day;
   final_month=end_mon - start_month; 
   final_year=end_yea-start_year; 
   result = (final_year * 365) + (final_month*31) + final_day;
   result = result/365; 
   result = round(result);
   //cout <<left << setw(10)<< result << endl;
   return result;
    

}

void employeeData::salary_predictor()
{
    
    
   //cout <<endl;
     
      dur = dur_calc();
  
    if (dur>0 && dur<=5)
    {
    annual_salary_pre = (4.5/100) * annual_salary;
    //cout << "0-5" <<endl;
    }
    if (dur>=6 && dur<=10)
    {
    annual_salary_pre = (12.5/100) * annual_salary;
    //cout << "6-10" <<endl;
    }
    if (dur>=11 && dur<=15 )
    {
    annual_salary_pre = (30.85/100) * annual_salary; 
    //cout<<annual_salary_pre << "=" <<" (30.85/100)" << "*" << annual_salary; 
    //cout << "11-15" <<endl;
    }
    if (dur>=16 && dur<20)
    {
    annual_salary_pre = (45.9/100) * annual_salary; 
    //cout << "16-20" <<endl;
    }
    if (dur>=20)
    {
    annual_salary_pre = (65.90/100) * annual_salary;
    //cout << "Greater than 20" <<endl;
    }
     
}
    
    
void display_emp()   
 {
    
    for(index;index<valid_count;index++)
    {
    employees[index].dept_title_conv();
    employees[index].month_conv();
    
    cout     <<fixed << setprecision(2)
             <<left<<setw(20) 
             << employees[index].last_name
             << setw(15)<< employees[index].first_name[0] 
              <<setw(5)<<  employees[index].date_title << " " 
                               
                               <<  employees[index].start_day << ","  
                               <<  employees[index].start_year  << setw(5)
                               << right 
                    << setw(20)<<  employees[index].dur 
                    << setw(25)<<  employees[index].annual_salary 
                    << setw(20) << employees[index].annual_salary_pre 
                    << setw(35) << employees[index].dept_title <<endl;
    }
              

        
}
 


void display_title()
 {
    cout << "JOSHUA RIGO\n " << endl; 
    cout << "ALGORITHMS & DATASTRUCTURES"<<endl; 
    cout << endl; 
    //TITLE
    cout <<setw(50) << "EMPLOYEE REPORT " << " 4.19.2021" << endl; 
   cout <<"\t\t\t********************************************" << endl << endl;
    
    //RESULTS
    cout <<left << setw(5)
         <<"|Last Name"      <<setw(5)<< " "
        << "|First Initial"  <<setw(5)<< " "
        << "|Date of Hire"   <<setw(5)<< " "
         <<"|Years of Service"<<setw(5)<<" " 
        << "|Annual Salary"  <<setw(5)<<" "
        << "|Predicted Month. Retirement"
        << right << setw(20)
        << "|Dep. Title" << endl;
    cout << endl;
    
    
}  
 
   
int inval_id()
{
    
if(employees_temp[z].email_checker()==false)
    return 1;
if(employees_temp[z].checkS_Date()==false)
     return 2;
if (employees_temp[z].checkE_Date()==false)
     return 3;      
}
  
// A function to implement bubble sort 
void bubbleSort() 
{ 
    employeeData temp;
    for (i = 0; i < valid_count-1; i++) // Last i elements are already in place 
     for (j = 0; j < valid_count-i-1; j++)
     {  
        if (employees[j].last_name > employees[j+1].last_name)
        {
           // change();
           temp=employees[j];      
           employees[j]=employees[j+1];
           employees[j+1]=temp;
        }
 }
}

void error_disp()
{
 int id_value=inval_id();
 if(id_value==1){outfile << "record " << curr_rec_tot+1 << setw(25)<<  "<invalid email: "  <<endl;}
 if(id_value==2){outfile << "record " << curr_rec_tot+1 << setw(25) << "<invalid start year: " <<endl; }
 if(id_value==3){outfile << "record " << curr_rec_tot+1 << setw(25) << "<invalid end year: " <<endl;}
 
         if(employees_temp[z].isValid==false)
         {//what to do if invalid
    
    /*
    outfile  << " "<<  employees_temp[z].last_name 
             << " "<<  employees_temp[z].first_name 
             << " "<<  employees_temp[z].start_month 
             << " "<<  employees_temp[z].start_day 
             << " "<<  employees_temp[z].start_year 
             << " "<<  employees_temp[z].end_month 
             << " "<<  employees_temp[z].end_day 
             << " "<<  employees_temp[z].end_year  
             << " "<<  employees_temp[z].annual_salary 
             << " "<<  employees_temp[z].dept_code 
             << " "<<  employees_temp[z].email_address << endl;*/ 
             
             error_count++;
                    
                }
    
    
}
  

void employeeData::dept_code_converter()
{
    int i=0; 
    char c; 
    while (dept_code[i])
    {
      c=dept_code[i];
        //dept_code=dept_code[i]; 
     if (islower(c)) c=toupper(c);
         dept_code[i]=c;
         //putchar(c);
         i++;
        

    }  
        
   }

bool employeeData::dept_code_valid()
{
    
dept_code_converter();    
if(dept_code=="AC") return true;
if(dept_code=="MD") return true;
if(dept_code=="EG") return true;
if(dept_code=="TE") return true;  
if(dept_code=="PP") return true;
if(dept_code=="ST") return true;  
if(dept_code=="LW") return true;
if(dept_code=="RD") return true;
if(dept_code=="TT") return true;
if(dept_code=="QC") return true;
if(dept_code=="SC") return true; 
if(dept_code=="OR") return true;
return false;  
    
}


bool employeeData::name_checker()
{
    int i=0;
    char ln_ch; 
    char fn_ch; 
    while(last_name[i] && first_name[i])
    {
     ln_ch = last_name[i]; 
     fn_ch= first_name[i]; 
    if(!isalpha(fn_ch)||!isalpha(ln_ch)){return false;}
        return true; 
    i++;
    }
   //removeElement(); 
    
}

bool employeeData::email_checker()
{    
    string email_val = "@myemail.com";
    //string email_address;
    size_t pos = email_address.find("@");
    string email_split = email_address.substr(pos);
    if (email_val!=email_split) 
    {
        return false; 
    }
    else
    {
       return true;
    }
    }//end funct
 

  bool employeeData::checkS_Date()
{
  
  if (! (1582<= start_year))
     return false;
  if (! (1<= start_month && start_month<=12) )
     return false;
  if (! (1<= start_day && start_day<=31) )
     return false;
  if ( (start_day==31) && (start_month==2 || start_month==4 || start_month==6 || start_month==9 || start_month==11) )
     return false;
  if ( (start_day==30) && (start_month==2) )
     return false;
  if ( (start_month==2) && (start_day==29) && (start_year%4!=0) )
     return false;
  if ( (start_month==2) && (start_day==29) && (start_year%400==0) )
     return true;
  if ( (start_month==2) && (start_day==29) && (start_year%100==0) )
     return false;
  if ( (start_month==2) && (start_day==29) && (start_year%4==0)  )
     return true;
  
      
      return true; 
}

bool employeeData::checkE_Date()
{
    
   if ( (end_month==00) && (end_day==00) && (end_year==0000)  )
  {end_month=04;  end_day=19;  end_year=2021; return true;} 
  
  if (! (1582<= end_year))
     return false;
  if (! (1<= end_month && end_month<=12) )
     return false;
  if (! (1<= end_day && end_day<=31) ) 
     return false;
  if ( (end_day==31) && (end_month==2 || end_month==4 || end_month==6 || end_month==9 || end_month==11) )  
     return false;
  if ( (end_day==30) && (end_month==2) ) 
     return false;
  if ( (end_month==2) && (end_day==29) && (end_year%4!=0) )
     return false;
  if ( (end_month==2) && (end_day==29) && (end_year%100==0) )
     return false;   
  if ( (end_month==2) && (end_day==29) && (end_year%400==0) )      
     return true;
  if ( (end_month==2) && (end_day==29) && (end_year%4==0)  )
     return true;

      return true; 
}


bool employeeData::sal_checker()
{
    
    if(annual_salary<0 && annual_salary>1000000000) 
        return false; 
    return true;
    
}
    
//this will run for every employee data created!
employeeData::employeeData()
{
    isValid = false;
    
}

/*void employeeData::emp_active()
{
  if(end_month==00 && end_day==00 && end_year==0000)
  { 
     employees_temp[z].isValid==true;
    //end_day=17;
    //end_year=2021;
    
    }*/


bool employeeData::validChecker()
{
      return (name_checker() && sal_checker() && email_checker() &&checkS_Date() && checkE_Date() && dept_code_valid());
    
}

void employeeData::dept_title_conv()
{
if(dept_code=="AC") dept_title = "accounting ";
if(dept_code=="MD") dept_title ="medical";  
if(dept_code=="EG") dept_title = "engineering";    
if(dept_code=="TE") dept_title ="technical";   
if(dept_code=="PP") dept_title = "physical plant";   
if(dept_code=="ST") dept_title =  "staff";  
if(dept_code=="LW") dept_title = "legal ";
if(dept_code=="RD") dept_title  ="research";
if(dept_code=="TT") dept_title ="testing";
if(dept_code=="QC") dept_title  ="quality control"; 
if(dept_code=="SC") dept_title  ="service Center"; 
if(dept_code=="OR") dept_title ="Occupational Research";
}
 

 void employeeData::month_conv()
{
    if(end_month ==1){date_title = " Jan."; }
    if(end_month ==2){date_title ="Feb.";}
    if(end_month ==3){date_title = "Mar.";}
    if(end_month ==4){date_title ="Apr.";}
    if(end_month ==5){date_title = "May.";}
    if(end_month ==6){date_title ="Jun.";}
    if(end_month ==7){date_title = "Jul.";} 
    if(end_month ==8){date_title ="Aug.";}
    if(end_month ==9){date_title = "Sep.";}
    if(end_month ==10){date_title ="Oct.";}
    if(end_month ==11){date_title = "Nov.";}
    if(end_month ==12){date_title = "Dec.";}
     
} 
