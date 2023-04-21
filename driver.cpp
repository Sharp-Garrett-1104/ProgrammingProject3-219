// Garrett Sharp
// 02/22/23
//
// Reusing infrastructure from PP1
// 
//


// Included Libraries
#include <iostream>
#include <fstream>
#include <string>
#include <bits/stdc++.h>

// Using lessSecurity std;
using namespace std;

// Function Prototypes
void readFile(string, int);

void addHex(unsigned long long int, unsigned long long int);

void convert(string line, string &operation, string &operand1, string &operand2, string &operand3);

void defaultMessage();



bool nCheck(int);

bool zCheck(int);


// Main
int main()
{

        // Successfully ran with file
        int menuChoice, hex1, hex2;
            do
            {
                // Futureproofing with a menu
                cout << "1: Run Program" << endl;
                cout << "0: Exit the Program" << endl;
                cout << "Input: ";
                cin >> menuChoice;
                switch(menuChoice)
                
                {
                    case 1:
                        // Runs the Function that reads the file, gives the file and the menu choice (future proofing™)
                        readFile("calcNum.txt",1);
                        break;                 
                    default:
                        // Tux jumpscare default message
                        defaultMessage(); 
                        break;
                    case 0:
                        // Exits the Program
                        menuChoice = 0;
                        break;
                    }
            }
            while (menuChoice != 0);
            // If they choose 0 the loop ends
           

return 0;
}

void defaultMessage()
{
// Jumpscare Tux 
cout << R"(Wrong Choice, Tux is very disapointed
                                .:xxxxxxxx:.
                             .xxxxxxxxxxxxxxxx.
                            :xxxxxxxxxxxxxxxxxxx:.
                           .xxxxxxxxxxxxxxxxxxxxxxx:
                          :xxxxxxxxxxxxxxxxxxxxxxxxx:
                          xxxxxxxxxxxxxxxxxxxxxxxxxxX:
                          xxx:::xxxxxxxx::::xxxxxxxxx:
                         .xx:   ::xxxxx:     :xxxxxxxx
                         :xx  x.  xxxx:  xx.  xxxxxxxx
                         :xx xxx  xxxx: xxxx  :xxxxxxx
                         'xx 'xx  xxxx:. xx'  xxxxxxxx
                          xx ::::::xx:::::.   xxxxxxxx
                          xx:::::.::::.:::::::xxxxxxxx
                          :x'::::'::::':::::':xxxxxxxxx.
                          :xx.::::::::::::'   xxxxxxxxxx
                          :xx: '::::::::'     :xxxxxxxxxx.
                         .xx     '::::'        'xxxxxxxxxx.
                       .xxxx                     'xxxxxxxxx.
                     .xxxx                         'xxxxxxxxx.
                   .xxxxx:                          xxxxxxxxxx.
                  .xxxxx:'                          xxxxxxxxxxx.
                 .xxxxxx:::.           .       ..:::_xxxxxxxxxxx:.
                .xxxxxxx''      ':::''            ''::xxxxxxxxxxxx.
                xxxxxx            :                  '::xxxxxxxxxxxx
               :xxxx:'            :                    'xxxxxxxxxxxx:
              .xxxxx              :                     ::xxxxxxxxxxxx
              xxxx:'                                    ::xxxxxxxxxxxx
              xxxx               .                      ::xxxxxxxxxxxx.
          .:xxxxxx               :                      ::xxxxxxxxxxxx::
          xxxxxxxx               :                      ::xxxxxxxxxxxxx:
          xxxxxxxx               :                      ::xxxxxxxxxxxxx:
          ':xxxxxx               '                      ::xxxxxxxxxxxx:'
            .:. xx:.                                   .:xxxxxxxxxxxxx'
          ::::::.'xx:.            :                  .:: xxxxxxxxxxx':
  .:::::::::::::::.'xxxx.                            ::::'xxxxxxxx':::.
  ::::::::::::::::::.'xxxxx                          :::::.'.xx.'::::::.
  ::::::::::::::::::::.'xxxx:.                       :::::::.'':::::::::
  ':::::::::::::::::::::.'xx:'                     .'::::::::::::::::::::..
    :::::::::::::::::::::.'xx                    .:: :::::::::::::::::::::::
  .:::::::::::::::::::::::. xx               .::xxxx :::::::::::::::::::::::
  :::::::::::::::::::::::::.'xxx..        .::xxxxxxx ::::::::::::::::::::'
  '::::::::::::::::::::::::: xxxxxxxxxxxxxxxxxxxxxxx :::::::::::::::::'
    '::::::::::::::::::::::: xxxxxxxxxxxxxxxxxxxxxxx :::::::::::::::'
        ':::::::::::::::::::_xxxxxx::'''::xxxxxxxxxx '::::::::::::'
             '':.::::::::::'                        `._'::::::''
------------------------------------------------
)" << endl;


}

// Reads the file
void readFile(string filename, int addSub)
{
    // Declares the two numbers that the hex will be translated to
    unsigned int num1, num2, num3;

    signed int sNum1;

    string hex1, hex2, hex3;
    // Opening file
    ifstream file;
    file.open(filename);

    if(file.is_open())
    {
        string r0, r1, r2, r3, r4, r5, r6, r7, r8;
        while(!file.eof())
        {
            //cout << "gets to read the file" << endl;
            string line, operation = "          ", operand1 = "             ", operand2 = "             ", operand3 = "             ";
            getline(file, line);
            convert(line, operation, operand1, operand2, operand3);
            cout << operation << " " << operand1 << " " << operand2 << " " << operand3 << endl;

            if(operation == "MOV" || operation == "mov")
            {
                switch(operand1[1])
                {
                    case 0:
                        r0 = operand2;
                    break;
                    case 1:
                        r1 = operand2;
                    break;
                    case 2:
                        r2 = operand2;
                    break;
                    case 3:
                        r3 = operand2;
                    break;
                    case 4:
                        r4 = operand2;
                    break;
                    case 5:
                        r5 = operand2;
                    break;
                    case 6:
                        r6 = operand2;
                    break;
                    case 7:
                        r7 = operand2;
                    break;
                }
                cout << "MOV done :)" << endl; 
            }
            else if(operation == "ADD" || operation == "ADDS" || operation == "add" || operation == "adds")
            {
                int num1, num2, num3;
                num1 = stoll(operand1, 0, 16);
                num2 = stoll(operand2, 0, 16);
                num3 = stoll(operand3, 0, 16);
                cout << num1 << num2 << num3 << endl;
            }
            
        }
    }
    file.close();
    cout << endl;
    
}

void convert(string line, string &operation, string &operand1, string &operand2, string &operand3)
{
//cout << line << endl;
int i = 0;
do
{
    operation[i] = line[i];
    i++;
} while (line[i] != ' ');
i++;
int j = 0;
do
{
    operand1[j] = line[i];
    i++;
    j++;
} while (line[i] != ' ');
i++;
int k = 0;
do
{
    operand2[k] = line[i];
    i++;
    k++;
} while (line[i] != ' ');
i++;
int l = 0;
//if(line[i] != ' ')
do
{
    operand3[l] = line[i];
    i++;
    l++;
}while(line[i] != '\0');



}



bool nCheck(int num)
{
    int numCompare;
    string compareNum = "3fffffff";
    numCompare = stoll(compareNum, 0, 16);
    if(num > numCompare)
    {
        return 1;
    }else{
        return 0;
    }
}

bool zCheck(int num)
{

    if(num == 0)
    {
        return 1;
    }else{
        return 0;
    }

}