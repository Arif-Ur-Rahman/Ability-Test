#include <iostream>
#include <string>
#include <sstream>
using namespace std;
string words[26][2];
int size = 26;
void convertToList(string str)
{
	string word = "";
	int count = 0;

	for (int i = 0; i<str.length();i++)
	{

		if (str[i] == ',')
		{
		     string number;
		     stringstream ss;
              ss <<  count+1;
              ss >> number;
		    words[count][0]= number;
		     words[count][1] = word;
		  	word = "";
		  	count++;
		}
		else {
			word = word + str[i];
		}
	}

	        string number;
		     stringstream ss;
              ss <<  count+1;
              ss >> number;
		    words[count][0]= number;
		     words[count][1] = word;

}

void print()
{
    for (int i = 0; i<size;i++)
	{
	    cout << words[i][0]<< " "<< words[i][1] <<endl;
	}

	cout << "\n ____________________***____________________\n\n";
}

int main()
{

    int num=999;
	string str = "ALFA,BRAVO,CHARLIE,DELTA,ECHO,FOXTROT,GOLF,HOTEL,INDIA,JULIETT,KILO,LIMA,MIKE,NOVEMBER,OSCAR,PAPA,QUEBEC,ROMEO,SIERRA,TANGO,UNIFORM,VICTOR,WHISKEY,X-RAY,YANKEE,ZULU";
    convertToList(str);
    print();

    while(num!=0)
    {
        if(size>0)
        {

       // string num;
        int flag = 0;
        cout << "Enter a number from the list to eleminate: ";
        cin>>num;
    if(num>=1 && num<=26){
           for(int i=0; i<size; i++)
            {
                string number;
		     stringstream ss;
              ss <<  num;
              ss >> number;
                if(words[i][0] == number)
                {
                    flag = 1;
                    size--;
                }
                 if(flag == 1)
                {
                    words[i][0] = words[i+1][0];
                    words[i][1] =words[i+1][1];

                }
            }
            if(flag==0)
            {
                cout <<"this number is already deleted!\n\n\n";
            }
                 print();
        }
        else if(num==0){
            cout << "\n\n ____________________*Thank You*____________________\n";
        }
        else{
            cout << "\n ____________________***____________________\n";
             cout << "\nInvalid Number! \n\nPlease enter 0 to exit\nOR\n";
        }
            flag = 0;
    }
    else
    {
        cout << "All numbers are eleminated. Enter 0 to exit:   ";
        cin>>num;
    }
}

	return 0;
}
