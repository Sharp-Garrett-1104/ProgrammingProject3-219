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

string intToHex(int long long str);

bool nCheck(int);

bool zCheck(int);

void setOperand(string r0, string r1, string r2, string r3, string r4, string r5, string r6, string r7, string &operand);

void setResult(string &r0, string &r1, string &r2, string &r3, string &r4, string &r5, string &r6, string &r7, string operand, string set);

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
ifstream file;
file.open(filename);

if(file.is_open())
{
    string r0 = "0\0       ", r1= "0\0        ", r2= "0\0       ", r3= "0\0       ", r4= "0\0       ", 
    r5= "0\0       ", r6= "0\0       ", r7= "0\0       ";
    bool N = 0, Z = 0, C = 0, V = 0;

    while(!file.eof())
    {
        //cout << "gets to read the file" << endl;
        string line, operation = "    ", operand1 = "         ", operand2 = "         ", operand3 = "         ";
        getline(file, line);
        cout << line << endl;
        convert(line, operation, operand1, operand2, operand3);
        //cout << operation << " " << operand1 << " " << operand2 << " " << operand3 << endl;

        if(operation == "MOV " || operation == "mov ")
        {
            setResult(r0, r1, r2, r3, r4, r5, r6, r7, operand1, operand2);
        }
        else if(operation == "ADD" || operation == "ADDS" || operation == "add" || operation == "adds")
        {

        setOperand(r0, r1, r2, r3, r4, r5, r6, r7, operand2);
        setOperand(r0, r1, r2, r3, r4, r5, r6, r7, operand3);                

        int long num1 = stoll(operand2,0,16);
        int long num2 = stoll(operand3,0,16);
        int long tempInt = num1 + num2;
        string temp = intToHex(tempInt);

        setResult(r0, r1, r2, r3, r4, r5, r6, r7, operand1, temp);          

            if(operation == "ADDS" || operation == "adds")
            {
                if(tempInt > 2147483647)
                {
                    N = !N;
                } 

            }
                if(tempInt == 0)
                {
                    Z = !Z;
                }

                if(tempInt < num1)
                {
                    C = !C;
                }
                int vCheck = tempInt;
                if(tempInt > num1 || tempInt < num2)
                {
                    V = !V;
                }

        }
        else if(operation == "SUB" || operation == "sub" || operation == "SUBS" || operation == "subs")
        {
        setOperand(r0, r1, r2, r3, r4, r5, r6, r7, operand2);
        setOperand(r0, r1, r2, r3, r4, r5, r6, r7, operand3);                
    
            int long long num1 = stoll(operand2,0,16);
            int long long num2 = stoll(operand3,0,16);
            int long long tempInt = num1 - num2;
            string temp = intToHex(tempInt);

        setResult(r0, r1, r2, r3, r4, r5, r6, r7, operand1, temp);                 

            if(operation == "SUBS" || operation == "subs")
            {
                if(tempInt < 2147483647)
                {
                    N = !N;
                } 

            }
                if(tempInt == 0)
                {
                    Z = !Z;
                }

                if(tempInt < num1)
                {
                    C = !C;
                }
                int vCheck = tempInt;
                if(tempInt > num1 || tempInt < num2)
                {
                    V = !V;
                }

        }
        else if(operation == "AND" || operation == "and" || operation == "ANDS" || operation == "ands")
        {
        setOperand(r0, r1, r2, r3, r4, r5, r6, r7, operand2);
        setOperand(r0, r1, r2, r3, r4, r5, r6, r7, operand3);                
    
            int long num1 = stoll(operand2,0,16);
            int long num2 = stoll(operand3,0,16);
            int long tempInt = num1 & num2;
            string temp = intToHex(tempInt);

        setResult(r0, r1, r2, r3, r4, r5, r6, r7, operand1, temp);  

        if(operation == "ANDS" || operation == "ands")
        {
            if(tempInt > 2147483647)
            {
                N = !N;
            } 
        }

            if(tempInt == 0)
            {
                Z = !Z;
            }

            if(tempInt > num1)
            {
                C = !C;
            }
            int vCheck = tempInt;
            if(tempInt > num1 || tempInt > num2)
            {
                V = !V;
            }

        }
        else if(operation == "ORR" || operation == "orr " || operation == "ORRS" || operation == "orrs")
        {
        setOperand(r0, r1, r2, r3, r4, r5, r6, r7, operand2);
        setOperand(r0, r1, r2, r3, r4, r5, r6, r7, operand3);                
    
            int long long num1 = stoll(operand2,0,16);
            int long long num2 = stoll(operand3,0,16);
            int long long tempInt = num1 | num2;
            string temp = intToHex(tempInt);

        setResult(r0, r1, r2, r3, r4, r5, r6, r7, operand1, temp);       
        if(operation == "ORRS" || operation == "orrs")
        {
            if(tempInt > 2147483647)
            {
                N = !N;
            } 
        }

            if(tempInt == 0)
            {
                Z = !Z;
            }

            if(tempInt < num1)
            {
                C = !C;
            }
            int vCheck = tempInt;
            if(tempInt < num1 || tempInt < num2)
            {
                V = !V;
            }

        }
        else if(operation == "XOR " || operation == "xor " || operation == "XORS" || operation == "xors")
        {
        setOperand(r0, r1, r2, r3, r4, r5, r6, r7, operand2);
        setOperand(r0, r1, r2, r3, r4, r5, r6, r7, operand3);                
    
            int long long num1 = stoll(operand2,0,16);
            int long long num2 = stoll(operand3,0,16);
            int long long tempInt = num1 ^ num2;
            string temp = intToHex(tempInt);

        setResult(r0, r1, r2, r3, r4, r5, r6, r7, operand1, temp);  
        if(operation == "XORS" || operation == "xors")
        {
            if(tempInt > 2147483647)
            {
                N = !N;
            } 
        }

            if(tempInt == 0)
            {
                Z = !Z;
            }

            if(tempInt < num1)
            {
                C = !C;
            }
            int vCheck = tempInt;
            if(tempInt < num1 || tempInt < num2)
            {
                V = !V;
            }



        }    
        else if(operation == "LSR " || operation == "lsr " || operation == "LSRS" || operation == "lsrs")
        {
        setOperand(r0, r1, r2, r3, r4, r5, r6, r7, operand2);             
            int shift = operand3[1]-48;
            int long long num1 = stoll(operand2,0,16);
            int long long tempInt = num1 >> shift;
            string temp = intToHex(tempInt);

        setResult(r0, r1, r2, r3, r4, r5, r6, r7, operand1, temp);                 

        if(operation == "LSRS" || operation == "lsrs")
        {
            if(tempInt > 2147483647)
            {
                N = !N;
            } 
        }

            if(tempInt == 0)
            {
                Z = !Z;
            }

            if(tempInt > num1)
            {
                C = !C;
            }
            int vCheck = tempInt;
            if(tempInt > num1)
            {
                V = !V;
            }


        }
        else if(operation == "LSL " || operation == "lsl " || operation == "LSLS" || operation == "lsls")
        {
        setOperand(r0, r1, r2, r3, r4, r5, r6, r7, operand2); 
            int shift = operand3[1]-48;
            int long long num1 = stoll(operand2,0,16);
            int long long tempInt = num1 << shift;
            string temp = intToHex(tempInt);

        setResult(r0, r1, r2, r3, r4, r5, r6, r7, operand1, temp);  
        if(operation == "LSLS" || operation == "lsls")
        {
            if(tempInt > 2147483647)
            {
                N = !N;
            } 
        }

            if(tempInt == 0)
            {
                Z = !Z;
            }

            if(tempInt > num1)
            {
                C = !C;
            }
            int vCheck = tempInt;
            if(tempInt < num1)
            {
                V = !V;
            }

        }

    cout << "r0:0x" <<  r0 << " r1:0x" << r1 << " r2:0x" << r2 << " r3:0x" << r3 << endl << "r4:0x" << r4 << " r5:0x" << r5 << " r6:0x" << r6 << " r7:0x" << r7 << endl; 
    cout << "N = " << N << " Z = " << Z << " C = " << C << " V = " << V << endl;    
    }
}
file.close();
cout << endl;

}

void convert(string line, string &operation, string &operand1, string &operand2, string &operand3)
{
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
    if(line[i] != ',')
    operand1[j] = line[i];
    i++;
    j++;
} while (line[i] != ' ');
i++;
int k = 0;
do
{
    if(line[i] != ',' && line[i] != '#' && line[i] != 'x' && line[i] != 'O')
    {
    operand2[k] = line[i];
    k++;
    }
    i++;
} while (line[i] != ' ');
i++;
int l = 0;
do
{

    operand3[l] = line[i];
    i++;
    l++;
}while(line[i] != '\0');

}


string intToHex(int long long str)
{
  stringstream stream;
  stream << hex << str;
  return stream.str();
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

void setOperand(string r0, string r1, string r2, string r3, string r4, string r5, string r6, string r7, string &operand)
{
    switch(operand[1])
    {
        case '0':
            operand = r0;
        break;
        case '1':
            operand = r1;
        break;
        case '2':
            operand = r2;
        break;
        case '3':
            operand = r3;
        break;
        case '4':
            operand = r4;
        break;
        case '5':
            operand = r5;
        break;
        case '6':
            operand = r6;
        break;
        case '7':
            operand = r7;
        break;
    } 
}

void setResult(string &r0, string &r1, string &r2, string &r3, string &r4, string &r5, string &r6, string &r7, string operand, string set)
{
    switch(operand[1])
    {
        case '0':
            r0 = set;
        break;
        case '1':
            r1 = set;
        break;
        case '2':
            r2 = set;
        break;
        case '3':
            r3 = set;
        break;
        case '4':
            r4 = set;
        break;
        case '5':
            r5 = set;
        break;
        case '6':
            r6 = set;
        break;
        case '7':
            r7 = set;
        break;
    }      
}