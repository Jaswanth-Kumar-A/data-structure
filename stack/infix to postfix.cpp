#include<stdio.h>
#include <ctype.h>
char a[20];
int top=-1;
void push(char x){
    if(top==19){
        printf("The stack is overflow:");
    }
    top++;
    a[top]=x;
}
char pop(){
    if(top==-1){
       return -1;
    }
    else{
        return a[top--];
    }
}
int pirority(char x){
    if(x=='(')
    return 0;
    else if(x=='+'||x=='-')
    return 1;
    else if(x=='*'||x=='/')
    return 2;
}
int main(){
    char ex[10];
    char *e,x;
    printf("Enter The expression:");
    scanf("%s",ex);
    e=ex;
    while(*e!='\0'){
        if(isalnum(*e))
        printf("%c",*e);
        else if(*e=='(')
        push(*e);
        else if(*e==')'){
            while((x=pop())!='(')
            printf("%c ",x);
        }
        else{
            while(top==-1&&pirority(a[top])>=pirority(*e))
            printf("%c ",pop());
        push(*e);
        }
        e++;
    }
    while(top!=-1){
        printf("%c",pop());
    }
}
