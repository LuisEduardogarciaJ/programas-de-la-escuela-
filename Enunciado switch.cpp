#include<iostream>
using namespace std ;
int main ()
{
cout<<"Give_me_a_ character _ : _" ;
char c ;
cin>>c ;
switch ( c )
{
 case �a� :
 case �A �:
 case �e�:
 case �E �:
 case �i�:
 case �I�:
 case �o�:
 case �O�:
case �u�:
case �U �:
cout<<"_a_vowel "<<endl;
break ;
case �0�:
case �1�:
case �2�:
case �3�:
case �4�:
case �5�:
case �6�:
case �7�:
case �8�:
case �9�:
cout<<"_a_digit "<<endl;
break ;
default:
cout<<"_ neither_vowel_nor_digit "<<endl;
}
cout<<" end"<<endl;
}


