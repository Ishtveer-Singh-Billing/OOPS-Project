\
#include <iostream>
using namespace std;

#include <cmath>
#include <fstream>
#include <string.h>
#include<string>
#include <conio.h>
#include <iomanip>


class student
{
private:
    char name[30];
    char roll_no[10];
    char attd[200];
    int pres;
    int total;
    int day=0;
    int count;

    
    char class_code[15];
    char roll_code[10];
    char year[5];
    char batch_name[10];
    int strength;
    int class_count;
    
public:

    friend int new_class();

    int get_classdata();
   
    int show_classdata();

    int get_data();

    int show_data();

    int get_attd();

    int show_attd();

    int delete_class();
    
    int add_student(int n, int r, int total);

    int get_count()
    {
        return count;
    }

    string get_classcode()
    {
        return class_code;
    }

    int edit_attnd(int n);
   
}a[1000];


class attendance : private student
{
    private:
    char date[2];
    char month[2];
    char year[4];
    char full_date[200];
    
    public:

    int get_date()
    {
        int day;
    cout<<"Enter the date:";
    cin.getline(date,2);
    cout<<"/";
    cin.getline(month,2);
    cout<<"/";
    cin.getline(year,4);
   
        strcpy(full_date,date);
          strcat(full_date,month);
            strcat(full_date,year);

    return 0;
    }
    
    
};

int mark_attd();
int view_class();
int get_student();
int edit_attd();
int print_attd();
int delay_save();
int delay();
int main_menu();
int start_menu();
int del_class();




int view_class()
{
        system("cls");
    cout<<"\t\t\t\tVIEW A CLASS\t\t\t\n";
    cout<<"***\t\t Press 1  to proceed  ||  0 to go back   \t\t***\n";
    char dec;
    dec=getch();
if(dec=='1')
{
        label:
        cout<<"Enter the class code\t";
        char str[15];
        cin>>str;
        int c,r;
        for(int i=0;i<1000;i++)
        {
        const char* code = a[i].get_classcode().c_str();
        c=strcmp(code,str);
        if(c==0)
        {
            r=i;
            break;
        }
        }
        cout<<"\n\nLoading the class...\n";
        delay();
        cout<<"\n\nThe class is as follows:\n\n";
        a[r].show_classdata();
        cout<<"\n \n Do you want to view student 's data list?\n";
        cout<<"*****\ty=yes  ||   n=no\t******"<<endl<<endl;
        char ch;
        cin>>ch;
           if(ch=='n' || ch=='N')
           {
            loop:
            cout<<"Do you want to view another class?\n";
            cout<<"*****\ty=yes  ||   n=no\t******"<<endl<<endl;
            char choice;
            cin>>choice;
            if(choice=='y'  || choice=='Y')
            {
                goto label;
            }
            else if(choice=='n'  || choice=='N')
            {
                cout<<"\n\n\n\n\nExiting Now...";
                delay();
                main_menu();
            }
           }
            else if(ch=='y' || ch=='Y')
            {
                int num;
                num=a[r].get_count();
                for(int j=r;j<num;j++)
                {
                        a[j].show_data();
                        cout<<"\n\n";
                }
                
                goto loop;
            } 
}
else if(dec=='0')
{
    cout<<"\n\n\nExiting...";
    delay();
    main_menu();
}
    return 0;
}




 

int new_class()
{
    system("cls");
    cout<<"\t\t\t\tADDING A NEW CLASS\t\t\n";
    cout<<"***\t\t Press 1  to proceed  ||  0 to go back   \t\t***\n";
    char dec;
    dec=getch();
if(dec=='1')
{
    int k=0,n;
    int std;
    for(int i=0;i<1000;i++)
    {
        std=a[i].get_count();
        if(std==0)
        {   
            k=i;
            break;
        }
    }
    n=a[k].get_classdata();
    for( int i=1;i<n;i++)
    {
        strcpy(a[k+i].class_code,a[k].class_code);
        strcpy( a[k+i].roll_code,a[k].roll_code);
        strcpy(a[k+i].year,a[k].year);
        strcpy(a[k+i].batch_name,a[k].batch_name);
        a[k+i].strength=a[k].strength;
        a[k+i].class_count=a[k].class_count;
       
    }
    cout<<endl<<endl<<"Enter the details of students:"<<endl<<endl;
   for(int i=0;i<n;i++)
   {
    a[i].get_data();
   }
    cout<<"Do you want to change anything?"<<endl<<endl;
    label:
    cout<<"*****\t y- to edit   ||    n to view/save class \t*****"<<endl<<endl;
    char ch;
    cin>>ch;
    if(ch=='n' || ch=='N')
    {
        cout<<"Do you want to view the class before saving?"<<endl<<endl;
        cout<<"*****\ty=yes  ||   n=no\t******"<<endl<<endl;
        
        char choice;
        cin>>choice;
        if(choice=='y'  || choice=='Y')
        {
            cout<<endl<<endl;
            a[k].show_classdata();
           cout<<endl<<endl;
            for(int j=0;j<n;j++)
            {
                a[k+j].show_data();
                cout<<endl<<endl;
            }
        }
        else if(choice=='n'  || choice=='N')
        {
            cout<<endl<<endl;
        }
    }
    else if(ch=='y' || ch=='Y')
    {
        cout<<"Enter the roll no. to edit:";
        int roll;
        cin>>roll;
        roll=roll-1;
        cout<<endl<<"The details of student were:"<<endl<<endl;
        a[k+roll].show_data();
        cout<<endl<<"Please enter the new details:"<<endl<<endl;
        a[k+roll].get_data();
        cout<<endl<<endl<<"Do you  want to change anything else?";
        goto label;

    }
    cout<<"Are you sure you want to save the batch?"<<endl;
    cout<<"*****\ty=yes  ||   n=no\t******"<<endl<<endl;
    char yn;
    cin>>yn;
    if(yn=='y' || yn=='Y')
    {
        cout<<endl<<endl<<endl<<endl<<endl;
        delay_save();
        main_menu();
    }
    else if(yn=='n' || yn=='N')
    {
        cout<<"*****\tPress 0 to exit   ||   1 to stay\t***** ";
        char ass;
        cin>>ass;
        if(ass=='0')
        {
        main_menu;
        }
        else
        {
        cout<<"Do you want to change anything?"<<endl<<endl;
        goto label;
        }
    }
}
else if(dec=='0')
{
    cout<<"\n\n\nExiting...";
    delay();
    main_menu();
}
    return 0; 
}





int main()
{
start_menu(); 
return 0;      
}




int student :: get_classdata()
 {
    char branch[10];
    cout<<"Enter the branch(in short form):\t";
    cin>>branch;
    strcpy(batch_name,branch);
    cout<<endl<<endl<<"Enter their college academic year:\t";
    cin>>year;
    strcat(branch,year);
    strcpy(class_code,branch);
    cout<<endl<<endl<<"The class code of the class is thus:\t";
    puts(class_code);
    cout<<endl<<endl<<"*****\tRemember this class code in order to access class directly in future.\t******"<<endl;
    cout<<"*****\tIts just (branch name + year)\t******"<<endl<<endl;
    cout<<endl<<endl<<"Enter the batch 's roll code(optional):\t";
    cin.ignore(10,'\n');
    cin.getline(roll_code,10);
    cout<<endl<<endl<<"Enter the strength of class:";
    cin>>strength;
    count= count + strength;
    class_count++;
    return strength;
}




int student ::show_classdata()
{
        cout<<"Batch:\t";
        puts(batch_name);
        cout<<endl<<"Year:\t";
        puts(year);
        cout<<endl<<"Class code:\t";
        puts(class_code);
        cout<<"\n The strength of the class is "<<strength<<".";
        return 0;
}




int student :: get_data()
 {
        cout << "Roll No.:\t";
        cin>>roll_no;
        cout <<endl<< "Name:\t";
        cin.ignore(30,'\n');
        cin.getline(name,30);
        cout<<endl;
       return 0;
}



int student :: show_data()
{
    cout<<"Roll No.:";
    puts(roll_code);puts(roll_no);
    cout<<"Name:"<<name<<endl;  
    return 0;

}






int student :: get_attd()
{
 cout<<"Roll No:\t"<<roll_no<<endl;
 cout<<"Name:\t"<<name<<endl;
cout<<"Enter attendance:\t";
char att;
cin>>att;
if(att=='a' || att=='A')
{
    attd[day]=att;
    total++;
    day++;
}
else if(att=='p' || att=='P')
{
    attd[day]=att;
    pres++;
    total++;
    day++;
}
return 0;
}




int student :: show_attd()
{
cout<<" Total Attendance:\t"<<pres<<"/"<<total<<endl;
int r;
for(int i=0;i<200;i++)
{
    if(attd[i]=='\n' || attd[i]=='0')
    {
        break;
        r=i;
    }
    else
    cout<<attd[i]<<"\t";
    
}
cout<<"This is the attendance of "<<r<<"days marked.";
return 0;
}


int start_menu()
{
 system("cls");
     cout << "\n\n\n\n\n\t\t\t\t\t********************************************\n" << endl;

    cout << "\t\t\t\t\t\t\tWELCOME TO" << endl
         << endl;
    cout << "\t\t\t\t\t\t\tATTENDANCE MARKER" << endl
         << endl;
    cout << "\t\t\t\t\t********************************************\n" << endl<< endl;
    cout<<"\n\t\t\t\t\t\t\t\t\t\t\tMADE BY:\n";
    cout<<"\t\t\t\t\t\t\t\t\t\t\tISHTVEER SINGH BILLING\n";
    cout<<"\t\t\t\t\t\t\t\t\t\t\tCO21325\n";
    cout<<"\t\t\t\t\t\t\t\t\t\t\tKHUSHAL\n";
    cout<<"\t\t\t\t\t\t\t\t\t\t\tCO21335\n";
    cout << "Press 1 to  start" << endl;
    cout << "Press 0 to exit" << endl;
    int x = 0;
    cin >> x;
    if (x == 1)
    {
        main_menu();
    }
    if (x == 0)
    {
        cout << "Exiting..." << endl;
        delay();
        system("pause");
        return 0;
    }

   



    return 0;
}



int main_menu()
{
    system("cls");
    int x = 0;
    cout << "\n\n\n\t\t\t\t1-> Mark Attendance \n" << endl;
    cout << "\t\t\t\t2-> View a class\n" << endl;
    cout << "\t\t\t\t3-> Add a new class\n" << endl;
    cout << "\t\t\t\t4-> Edit/Remove a student \n" << endl;
    cout << "\t\t\t\t5-> Delete a class\n" << endl;
    cout << "\t\t\t\t6-> Edit previous attendance\n" << endl;
    cout << "\t\t\t\t7-> Print a class attendance\n" << endl
         << endl
         << endl;
    cout << "\t\t\t\t0-> Return to previous screen \n" << endl;
    cin >> x;
    switch (x)
    {
    case 1:
        mark_attd();
        break;
    case 2:
        view_class();
        break;
    case 3:
        new_class();
        break;

    case 4:
        get_student();
        break;

    case 5:
        del_class();
        break;

    case 6:
        edit_attd();
        break;

    case 7:
        print_attd();
        break;

    case 0:
        start_menu();
        break;
    break;
    }
return 0;
}


int mark_attd()
{   
    system("cls");
    cout<<"\t\t\t\tMARK ATTENDANCE\t\t\n";
    cout<<"***\t\t Press 1  to proceed  ||  0 to go back   \t\t***\n";
    char dec;
    dec=getch();
if(dec=='1')
{
    label:
    cout << "Enter the class code:" << endl;
    char str[15];
    cin.ignore(15,'\n');
    cin>>str;
    int cmp,n;
    for(int i=0;i<1000;i++)
    {
        const char* code = a[i].get_classcode().c_str();
        cmp=strcmp(str,code);
        if(cmp==0)
        {
            n=i;
            break;
        }
    }
    cout<<"\n\n\nThe class is loading...";
    delay();
    cout<<"\n\n The class is as follows:\n\n";
    a[n].show_classdata();
    cout<<"\n\n*****\tEnter the attendance:\t*****\n\n";
    cout<<"*****\t a=absent   ||    p=present\t******\n";

    int num;
    num=a[n].get_count();

    for(int j=n;j<num;j++)
    {
        a[j].get_attd();
        cout<<endl<<endl;
    }

    cout<<"***\tAll students have been marked.\t***\n";
    cout<<"Do you want to mark another attendance?\n";
    cout<<"****\t y=yes   ||   n=no \t***\n";
    char ch;
    cin>>ch;
    if(ch=='y' || ch=='Y')
    {
        cout<<endl<<endl;
        goto label;
    }
    else if(ch=='n' || ch=='N')
    {
        cout<<"\n\n\n";
        delay_save();
        main_menu();
    }
}
else if(dec=='0')
{
    cout<<"\n\n\nExiting...";
    delay();
    main_menu();
}

    return 0;
}




int get_student()
{
    system("cls");
    cout<<"\t\t\t\tEDIT/REMOVE A STUDENT\t\t\n";
    cout<<"***\t\t Press 1  to proceed  ||  0 to go back   \t\t***\n";
    char dec;
    dec=getch();
if(dec=='1')
{
    cout<<"Do you want to edit a student 's record?\n";
    cout<<"***\t y=yes   ||   n=no \t***\n";
    char ch;
    cin>>ch;
    
    if(ch=='y' || ch=='Y')
    {
    cout << "\n\nEnter the class code:\t";
    char str[15];
    cin.ignore(15,'\n');
    cin.getline(str,15);
    cout<<"Enter the roll no.:\t";
    char arr[10];
    cin.ignore(10,'\n');
    cin.getline(arr,10);
    int cmp,n;
    for(int i=0;i<1000;i++)
    {
        const char* code = a[i].get_classcode().c_str();
        cmp=strcmp(str,code);
        if(cmp==0)
        {
            n=i;
            break;
        }
    }
    int count;
    count=a[n].get_count();
    int r;
    for(int j=n;j<count;j++)
    {
        const char* cod = a[j].get_classcode().c_str();
        cmp=strcmp(str,cod);
        if(cmp==0)
        {
            r=j;
            break;
        }
    }
    cout<<"\n The details of the student are:\n\n";
    a[r].show_data();
    cout<<"\n\n";
    cout<<"Enter the new details of the student:\n\n";
    a[r].get_data();
    cout<<"***\n\nThe data has been updated.***";
    }
    else if (ch=='n' || ch=='N')
    {
        cout<<"Do you want to remove a student 's record?\n";
        cout<<"***\t y=yes   ||   n=no \t***\n";
        char ch;
        cin>>ch;
        
        if(ch=='y' || ch=='Y')
        {
        cout << "Enter the class code:\t";
        char str[15];
        cin.ignore(15,'\n');
        cin.getline(str,15);
        cout<<"Enter the roll no.:\t";
        char arr[10];
        cin.ignore(10,'\n');
        cin.getline(arr,10);
        int cmp,n;
        for(int i=0;i<1000;i++)
        {
            const char* code = a[i].get_classcode().c_str();
            cmp=strcmp(str,code);
            if(cmp==0)
            {
                n=i;
                break;
            }
        }
        int count;
        count=a[n].get_count();
         int r;
        for(int j=n;j<count;j++)
        {
            const char* cod = a[j].get_classcode().c_str();
            cmp=strcmp(str,cod);
            if(cmp==0)
            {
                r=j;
                break;
            }
        }
        cout<<"\n The details of the student are:\n\n";
        a[r].show_data();
        cout<<"\n\n";

        cout<<"***The data has been removed successfully.***";
        }
        else if (ch=='n' || ch=='N')
        {
            delay_save();
            main_menu();
        }
    }
}
else if(dec=='0')
{
    cout<<"\n\n\nExiting...";
    delay();
    main_menu();
}

    return 0;
}


int student :: add_student(int n, int r, int total)
{
    cout<<"Do you want to add a new student?\n";
        cout<<"***\t y=yes   ||   n=no \t***\n";
        char ch;
        cin>>ch;
        
        if(ch=='y' || ch=='Y')
        {
        cout << "Enter the class code:\t";
        char str[15];
        cin.ignore(15,'\n');
        cin.getline(str,15);
        cout<<"Enter the roll no.:\t";
        char arr[10];
        cin.ignore(10,'\n');
        cin.getline(arr,10);
        int cmp,n;
        for(int i=0;i<1000;i++)
        {
            const char* code = a[i].get_classcode().c_str();
            cmp=strcmp(str,code);
            if(cmp==0)
            {
                n=i;
                break;
            }
        }
        int total;
        total=a[n].get_count();
        for(int j=n;j<total;j++)
        {
            int r;
            const char* cod = a[j].get_classcode().c_str();
            cmp=strcmp(str,cod);
            if(cmp==0)
            {
                r=j;
                break;
            }
        }
        for(int i=n;i<total;i++)
        {
            count++;    
        }
        for(int i=r+1;i<1000;i++)
        {
            count++;
        }
        cout<<"\n TPlease enter the details of new student:\n\n";
        a[r].get_data();
        cout<<"\n\n";
      
        cout<<"***The data has been removed successfully.***";
        }
return 0;
}

int student :: delete_class()
{
            
            pres=0;
            total=0;
            day=0;
            count=0;
            strength=0;
            class_count=0;
            return 0;        
}
int del_class()
{
    system("cls");
    cout<<"\t\t\t\tDELETE A CLASS\t\t\n";
    cout<<"***\t\t Press 1  to proceed  ||  0 to go back   \t\t***\n";
    char dec;
    dec=getch();
if(dec=='1')
{
    cout<<"Enter the class code:";
    char str[15];
    cin.ignore(15,'\n');
    cin.getline(str,15);
    int cmp,n;
        for(int i=0;i<1000;i++)
        {
            const char* code = a[i].get_classcode().c_str();
            cmp=strcmp(str,code);
            if(cmp==0)
            {
                n=i;
                break;
            }
        }
    cout<<"***\t The class has been loaded. \t***\n\n";
    a[n].show_classdata();
    int last;
    last=a[n].get_count();
    cout<<"\n\nAre you sure u want to delete the class?\n";
    cout<<"***\t y=yes    ||   n=no \t***";
    char ch;
    cin>>ch;
    if(ch=='y' || ch=='Y')
    {
        for(int i=n;i<last;i++)
        {
            a[i].delete_class();
        }
        cout<<"***\t The class has been  deleted successfully.\t****";
        delay_save();
        main_menu();
    }
    else if(ch=='n' || ch=='N')
    {
        cout<<"***\t No class deleted. \t***";
        delay_save();
        main_menu();
    }
}
else if(dec=='0')
{
    cout<<"\n\n\nExiting...";
    delay();
    main_menu();
}
    return 0;
}


int edit_attd()
{
    system("cls");
    cout<<"\t\t\t\tEDIT ATTENDANCE\t\t\n";
    cout<<"***\t\t Press 1  to proceed  ||  0 to go back   \t\t***\n";
    char dec;
    dec=getch();
if(dec=='1')
{
    label:
    cout<<"Enter the class code:\t";
    char str[15];
    cin.ignore(15,'\n');
    cin.getline(str,15);
    int cmp,n;
        for(int i=0;i<1000;i++)
        {
            const char* code = a[i].get_classcode().c_str();
            cmp=strcmp(str,code);
            if(cmp==0)
            {
                n=i;
                break;
            }
        }
    cout<<"Enter the roll no.:\t";
    int num;
    cin>>num;
    num=num-1;
    num=num+n;
    cout<<"\n The details of the student are:\n\n";
    a[num].show_data();
    cout<<"\nEnter the day:\t";
    int day;
    cin>>day;
    a[num].edit_attnd(day);
    cout<<"\n\n Do you want to change any other attendance?";
    cout<<"***\t y=yes   ||   n=no \t***\n";
    char ch;
    cin>>ch;
    
    if(ch=='y' || ch=='Y')
    goto label;
    else if(ch=='n' || ch=='N')
    {
        delay_save();
        main_menu();
    }
}
else if(dec=='0')
{
    cout<<"\n\n\nExiting...";
    delay();
    main_menu();
}
    return 0;
}

int student :: edit_attnd(int n)
{
    char p;
    p = attd[n];
    if(p=='a')
    {   
        cout<<"The attendance on the day was: absent";
        attd[n]='p';
        cout<<"\n***\tThe attendance on that day has been changed to present.\t***";

    }
    else if(p=='p')
    {
        cout<<"The attendance on the day was: present";
        attd[n]='a';
        cout<<"\n***\tThe attendance on that day has been changed to absent.\t***";
    }
    return 0;
}

int print_attd()
{
    system("cls");
    cout<<"\t\t\t\tPRINT THE ATTENDANCE\t\t\n";
    cout<<"***\t\t Press 1  to proceed  ||  0 to go back   \t\t***\n";
    char dec;
    dec=getch();
if(dec=='1')
{
    label:
    cout<<"Enter the class code:\t";
    char str[15];
    cin>>str;
    int cmp,n;
        for(int i=0;i<1000;i++)
        {
            const char* code = a[i].get_classcode().c_str();
            cmp=strcmp(str,code);
            if(cmp==0)
            {
                n=i;
                break;
            }
        }
    cout<<"\nDo you want to print attendance of full class or a student?";
    cout<<"\n***\t Enter 0=student   ||   1=all class \t***\n";
    int ch;
    cin>>ch;
    if(ch==0)
    {
        cout<<"\nEnter the roll no.:\t";
        int num;
        cin>>num;
        num=num-1;
        num=num+n;
        cout<<"\n The details of the student are:\n\n";
        a[num].show_data();
        cout<<"\n***\tThe attendance of the student is as follows:\t***\n\n";
        a[num].show_attd();
    }
    else if (ch==1)
    {
        cout<<"\nThe attendance of the whole class is as follows:\n\n";
        int total;
        total=a[n].get_count();
        for(int i=n;i<total;i++)
        {
            a[i].show_data();
            cout<<"\n";
            a[i].show_attd();
        }
    }
    delay_save();
    main_menu();
    return 0;

}    
else if(dec=='0')
{
    cout<<"\n\n\nExiting...";
    delay();
    main_menu();
}

    return 0;
}


int delay_save()
{
    cout << "\n Saving Records ...";
    for (int i = 0; i < 3; i++)
    {
        for (int ii = 0; ii < 20000; ii++)
        {
            for (int iii = 0; iii < 20000; iii++)
            {
            }
        }
    }
cout<<endl<<endl;
    cout << "\n Exiting Now ...";
    for (int i = 0; i < 3; i++)
    {
        for (int ii = 0; ii < 20000; ii++)
        {
            for (int iii = 0; iii < 20000; iii++)
            {
            }
        }
    }
    return 0;
}


int delay()
{
      
    for (int i = 0; i < 3; i++)
    {
        for (int ii = 0; ii < 20000; ii++)
        {
            for (int iii = 0; iii < 20000; iii++)
            {
            }
        }
    }
    return 0;
}
