#include <iostream>
#include <string>
using namespace std;

int main()
{
    int a;
    string b;
    cin>>a;
    cin>>b;
   
    for(int i =2; i>=0;i--)
    {
        cout<< a * (b[i]-'0')<<endl;
    }
    cout<<a*stoi(b);
}