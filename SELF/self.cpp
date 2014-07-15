#include<iostream>
#include<string>
using namespace std;
int main()
{
int n,i;char q=34;string::reverse_iterator it;
string l[]={
"#include<iostream>",
"#include<string>",
"using namespace std;",
"int main()",
"{",
"int n,i;char q=34;string::reverse_iterator it;",
"string l[]={",
"};",
"cin>>n;",
"if(n>=0){",
"while(n-->0){",
"for(i=0;i<=6;i++)",
"cout<<l[i]<<endl;",
"for(i=0;i<=39;i++)",
"cout<<q<<l[i]<<q<<','<<endl;",
"for(i=7;i<=39;i++)",
"cout<<l[i]<<endl;",
"}",
"}else{",
"while(n++<0){",
"for(i=39;i>=7;i--){",
"cout<<endl;",
"for(it=l[i].rbegin();it!=l[i].rend();++it)",
"cout<<*it;",
"}",
"for(i=39;i>=0;i--){",
"cout<<endl<<','<<q;",
"for(it=l[i].rbegin();it!=l[i].rend();++it)",
"cout<<*it;",
"cout<<q;",
"}",
"for(i=6;i>=0;i--){",
"cout<<endl;",
"for(it=l[i].rbegin();it!=l[i].rend();++it)",
"cout<<*it;",
"}",
"}",
"}",
"return 0;",
"}",
};
cin>>n;
if(n>=0){
while(n-->0){
for(i=0;i<=6;i++)
cout<<l[i]<<endl;
for(i=0;i<=39;i++)
cout<<q<<l[i]<<q<<','<<endl;
for(i=7;i<=39;i++)
cout<<l[i]<<endl;
}
}else{
while(n++<0){
for(i=39;i>=7;i--){
cout<<endl;
for(it=l[i].rbegin();it!=l[i].rend();++it)
cout<<*it;
}
for(i=39;i>=0;i--){
cout<<endl<<','<<q;
for(it=l[i].rbegin();it!=l[i].rend();++it)
cout<<*it;
cout<<q;
}
for(i=6;i>=0;i--){
cout<<endl;
for(it=l[i].rbegin();it!=l[i].rend();++it)
cout<<*it;
}
}
}
return 0;
}
