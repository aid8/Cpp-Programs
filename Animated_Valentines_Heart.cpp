//Valentines code by aid
#include<iostream>
#include<windows.h>
using namespace std;

int main()
{
    //463 size, only messages can be edited
    int i, j, k, heartSpace = 4, heartWidth = 6, heartHeight1 = 3, heartHeight2 = 9, light = 0, text = 0;
    char textC = '0';
    string message = "Happy Valentines Day", message2 = "";
    system("COLOR 4");
    cout <<  "Happy Valentines Greeting!" << endl << "Enter Name: ";
    getline(cin,message2);
    while(true)
    {
         cout << endl << endl << endl;
        //FirstLayer
        for(i = 0; i < heartSpace; ++i) cout << "  ";
        for(i = 0; i < heartWidth;  ++i) i == heartWidth-1 - (light-2) ? cout << textC << " "  : cout << "* ";
        for(i = 0; i < heartWidth/2; ++i) cout << "  ";
        for(i = 0; i < heartWidth; ++i) i == light-2 ? cout << textC << " " : cout << "* ";
        cout << endl;
        //SecondLayer
        for(i = 0; i < heartHeight1; ++i)
        {
            for(j = 0; j < heartSpace-1; ++j) cout << "  ";
            if(i == 0 && light == 8) cout << textC << " ";
            else if(i == 1 && light == 9) cout << textC << " ";
            else if(i == 2 && light == 10) cout << textC << " ";
            else cout << "* ";
            if(i < heartHeight1-1)
            {
                for(j = 0; j < heartWidth+i; ++j) cout << "  ";
                if(i == 1 && light == 0) cout << textC << "  ";
                else if(i == 0 && light == 1) cout << textC << "  ";
                else cout << "*  ";
                if(i == 0) light == 1 ? cout << " " << textC : cout << " *";
                for(j = 0; j < heartWidth; ++j) cout << "  ";
                if(i == 0 && light == 8) cout << " " << textC << " ";
                else if(i == 1 && light == 9) cout << " " << textC << " ";
                else cout << " * ";
            }
            else
            {
                for(j = 0; j < (heartWidth*2 + heartHeight1); ++j) cout << "  ";
                if(i == 2 && light == 10) cout << textC << " ";
               else cout << "* ";
            }
            cout << endl;
        }
        //Last layer
        for(i = 0; i < heartHeight2; ++i)
        {
            for(j = 0; j < heartSpace-1+i; ++j) cout << "  ";
            i == light-11 ? cout << textC << " " : cout << "* ";
            if(i == 1)
            {
                message.length() % 2 == 0 ? k  = 1 : k = 0;
                for(j = 0; j < (heartWidth*4.5 - message.length())/2 - k; ++j) cout << " ";
                for(j = 0; j < message.length(); ++j) message[j] = tolower(message[j]);
                if(text < message.length()) message[text] = toupper(message[text]);
                cout << message;
                for(j = 0; j < (heartWidth*4.5 - message.length())/2 - k; ++j) cout << " ";
                if(i < heartHeight2-1) i == light-11 ? cout << textC << " " << endl : cout << "* " << endl;
            }
            else if (i == 2)
            {
                for(j = 0; j < (heartWidth*3.5 - message2.length())/2; ++j) cout << " ";
                for(j = 0; j < message2.length(); ++j) message2[j] = tolower(message2[j]);
                if(text > message.length()) message2[text-message.length() - 1] = toupper(message2[text-message.length() - 1]);
                cout << message2;
                message2.length() % 2 == 0 ? k  = 1 : k = 0;
                for(j = 0; j < (heartWidth*3.5 - message2.length())/2 - k + 1; ++j) cout << " ";
                if(i < heartHeight2-1) i == light-11 ? cout << textC << " " << endl : cout << "* " << endl;
            }
            else
            {
                for(j = (heartHeight2-i-1)*2; j > 1; --j) cout << "  ";
                if(i < heartHeight2-1) i == light-11 ? cout << textC << " " << endl : cout << "* " << endl;
            }
        }
        system("CLS");
        light < 19 ? light++ : light = 0;
        text < message.length()+message2.length() ? text++ : text = 0;
    }
    return 0;
}

