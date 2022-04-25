#include <iostream>
#include <stdio.h>
#include <string.h>
#include<iomanip>
#include <ctype.h>
using namespace std;

int stack[100], list[20];
char postfix[100];
int op,top=-1,n,ns, item;
string sc;
// this is comment

void push(int var);
int pop();
int prec(char m);
class stack_APP
{
    public:
    void operations(){
        do{
        cout<<endl<<"Enter your operation \n 1.Normal_Stack \n 2.balancing_Parenthesis \n 3.evaluation_of_Postfix \n 4.infix_to_postfix \n 5.Exit \n Here :";
        cin>>op;
        switch (op){
        case 1:
            normal_stack();
            break;
        case 2:
            balancingParenthesis();
            break;
        case 3:
            evaluation_of_Postfix();
            break;
        case 4:
            infix_to_postfix();
            break;
        case 5:
            break;
        default:
            cout<<"Enter Correct choice"<<endl;
        }
        
        }while (op!=5);
        
    }

    void normal_stack()
    {
	int top=-1,n,ns;
	// int list[20];
	cout<<"Enter the size of Stack: ";
 	cin>>n;
 		do
        {
 			cout<<"Enter your operation \n 1. Push \n 2.Pop \n 3.Display \n 4.Exit \n Here :";
 			cin>>ns;
 			switch(ns)
            {
 			case 1:
            if(top==n-1){
 			cout<<"Stack Overflow! Element cannot be added"<<endl;}
            else{
                cout<<"Enter Element: ";
                int element;
                cin>>element;
                top=top+1;
                list[top]=element;
                cout<<"Element is inserted at index "+top<<endl;}
 			break;
 			case 2:
 			if(top==-1){
			    cout<<"Stack Underflow! Element cannot be removed"<<endl;}
		    else{
			    int delelement= list[top];
			    top=top-1;
			    cout<<delelement+" is deleted, Top is at Index "+top<<endl;
		    }
 			break;
 			case 3:
 			if(top==-1){
			    cout<<"Stack is Empty! Enter Values first"<<endl;}
		    else{
			for(int i=top;i>=0;i--){
				cout<<list[i];
				cout<<endl;}
		    }   
 			break;
 			case 4:
 				break;
 			default:
 				cout<<"Enter Correct choice"<<endl;
            }
 		}while(ns!=4);

    }

    void balancingParenthesis()
    {
    cout<<"Enter the String: ";
    cin>>sc;
    int top=-1;
    string balance[20];
    for(int i=0;i<sc.length();i++)
    {

        if(sc[0] == ')'){
            cout<<"Wrong Format!";
            break;
        }
        else{
            if(sc[i]=='('){
                top=top+1;
                balance[top]="(";
            }
            else if(sc[i]==')'){
                top=top-1;
            }
        }
        if(i==sc.length()-1 && top==-1){
            cout<<"ALL IS WELL"<<endl;
            break;
        }
        else if(i==sc.length()-1 && top!=-1)
        {
            cout<<"Parenthesis Needs to be Balanced"<<endl;
        }
        
    }
    }



    void evaluation_of_Postfix()
    {
    char postfix[100];
    cout<<" Enter PostFix Expression for postfix Conversion: ";
	cin>>sc;
    for (int i = 0; i <= sc.length(); i++) {
		postfix[i]=sc[i];

        if (postfix[i] == ')')
        {
            break;
        }
    }
    for(int i=0;i<sc.length();i++){
        cout<<postfix[i]<<" ";
    }
    EvalPostfix(postfix);
    }
    void EvalPostfix(char postfix[])
    {
    char ch;
    int val;
    int A, B;

    for (int i = 0; postfix[i] != ')'; i++) {
        ch = postfix[i];
        if (isdigit(ch)) {
            push(ch - '0');
        }
        else if (ch == '+' || ch == '-' || ch == '*' || ch == '/') {
                A = pop();
                B = pop();

            switch (ch)
            {
            case '*':
                val = B * A;
                break;

            case '/':
                val = B / A;
                break;

            case '+':
                val = B + A;
                break;

            case '-':
                val = B - A;
                break;
            }
            push(val);
        }
    }
    cout<<endl<<"Result of expression evaluation "<<pop()<<endl;
    }




    void infix_to_postfix()
    {
    string stack, p;
    cout<<"Enter Expression: ";
    cin>>sc;
    sc=sc+')';
    stack='(';
    top=0;

    for(int i=0; i<sc.length();i++)
    {
        if((sc[i] >= 'a' && sc[i] <= 'z') || (sc[i] >= 'A' && sc[i] <= 'Z') || (sc[i] >= '0' && sc[i] <= '9')){
            p=p+sc[i];
        }
        else if(sc[i]=='(')
        {
            top=top+1;
            stack[top]='(';
        }
        else if (sc[i]==')')
        {
            while (stack[top]!='(')
            {
                p=p+stack[top];
                top=top-1;
            }
            top=top-1;
        }
            
        else{
            while(top!=-1 && prec(sc[i]) <= prec(stack[top])) {
                p=p+stack[top];
                top=top-1; 
            }
        top=top+1;
        stack[top]=sc[i];
        }
    }
    cout<<p<<endl;

    }
};
int main(){
    string bp ="(A+B(*(C/D)";


    stack_APP mm;
    mm.operations();
    
    return 0;
}

void push(int var)
{
    if(top==100-1){
 			    cout<<"Stack Overflow! Element cannot be added"<<endl;
    }
    else{
        top=top+1;
        stack[top]=var;
    }
}
int pop()
{
    if (top < 0) {
        printf("stack under flow");
    }
    else {
        item = stack[top];
        top = top - 1;
        return item;
    }
}

int prec(char m){ 
    if(m == '^'){
        return 3; 
    }
    else if(m == '*' || m == '/'){
        return 2; 
    }
    else if(m == '+' || m == '-'){
        return 1;
    } 
    return 0;
} 

