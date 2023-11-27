#include<bits/stdc++.h>
using namespace std;
int top=-1;

void push(char val, char container[])
{
    top++;
    container[top]= val;
}

void pop()
{
    top--;
}

bool isempty()
{
  if(top<0) return true;
  else return false;
}

int solve(string s, char stackk[])
{
    int flag=0;
    for(int i=0; i<s.size(); i++)
    {
        if(s[i]=='(' || s[i]=='[' || s[i]=='{')
            {
                push(s[i], stackk);
            }
            else if( (s[i]==')' && stackk[top]!='(') || (s[i]=='}' && stackk[top]!='{') || (s[i]==']' && stackk[top]!='['))
                {
                    flag=1;
                    break;
                }

            else if( (s[i]==')' && stackk[top]=='(') || (s[i]=='}' && stackk[top]=='{') || (s[i]==']' && stackk[top]=='['))
                {
                    pop();
                }
    }
    return flag;
}

int main()
{
    string s;
    cout<<"Enter the arithmetic expression : ";
    cin>>s;
    int len=0;
    for(int i=0; i<s.size(); i++)
    {
        if(s[i]=='(' || s[i]=='[' || s[i]=='{')
         len++;
    }
    char stackk[len];
    int res = solve(s,stackk);

    if(res==1) cout<<"It's invalid";
    else if(isempty()==1) cout<<"It's valid";
    else cout<<"It's invalid";
}
