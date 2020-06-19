#include<iostream>
using namespace std;

int romanNum(char n)
{
    switch(n)
    {
        case 'I': return 1;
        case 'V': return 5;
        case 'X': return 10;
        case 'L': return 50;
        case 'C': return 100;
        case 'D': return 500;
        case 'M': return 1000;
    }
}

int main()
{
    string s;
    cout << "Roman Numeral to Integer Converter" << endl;
    cout << "Enter Roman Numeral: ";
    cin >> s;

    int i, totalNum = 0, smallE = 0, j, rep = 0, vCount = 0, lCount = 0, dCount = 0;
    char lastC = ' ';
    bool hasError = false;

    //Check if it is a valid roman numeral

    for(i = s.length()-1; i >= 0; --i)
    {
        //If non numeral letter is entered it is invalid
        if(s[i] != 'I' && s[i] != 'V' && s[i] != 'X' && s[i] != 'L' && s[i] != 'C' && s[i] != 'D' && s[i] != 'M')
        {
            hasError = true;
            break;
        }

        //If there are more than 2 roman numeral that are less than the last roman numeral then it is invalid. EXAMPLE: IIX
        if(s.length() > 2)
            for(j = i; j >= 1; --j)
            {
                if(romanNum(s[i]) > romanNum(s[j-1]))
                {
                    hasError = true;
                    break;
                }
            }
        //If 4 I", "X", "C", and "M are used repeatedly then error
        if(s[i] == s[i-1]) rep++;
        else rep = 0;

        //3 since it remains number 3 when counting at the end
        if(rep >= 3)
        {
            hasError = true;
            break;
        }

        //If V, L and D are repeated, then it is an error
        if(s[i] == 'V') vCount++;
        if(s[i] == 'L') lCount++;
        if(s[i] == 'D') dCount++;

        if(vCount > 1 || lCount > 1 || dCount > 1)
        {
            hasError = true;
            break;
        }
    }

    if(!hasError)
    {
        //Compute if there are no errors
        //Start counting from  end to the start
        for(i = s.length()-1; i >= 0; --i)
        {
            //Subtract if the end letter is greater than the total sum of the current added roman numerals and non repeating
            if(romanNum(s[i]) < totalNum && lastC != s[i])
            {
                totalNum -= romanNum(s[i]);
            }
            //Add if all is well organized and no reverse letters
            else
            {
                totalNum += romanNum(s[i]);
            }
            lastC = s[i];
        }
        cout << totalNum;
    }
    else cout << "Invalid Roman Numeral Entered!!";
    return 0;
}
