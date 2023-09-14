#include<stdio.h>
#include<stdlib.h>
struct node{
    int coeff;
    int power;
    struct node*next;
};
struct node*p1=NULL;
struct node*p2=NULL;
struct node*res=NULL;
struct node*create(int coeff,int power,struct node*head)
{
    struct node*newnode=(struct node*)malloc(sizeof(struct node));
    struct node*temp;
    newnode->coeff=coeff;
    newnode->power=power;
    newnode->next=NULL;
    if(head==NULL)
    {
        head=newnode;
        temp=head;
    }
    else
    {
        temp->next=newnode;
        temp=temp->next;
    }
    return head;
}
void sum(struct node*ptr1,struct node*ptr2)
{
    int power,coeff;
    while((ptr1!=NULL)&&(ptr2!=NULL))
    {
        if(ptr1->power>ptr2->power)
        {
            power=ptr1->power;
            coeff=ptr2->coeff;
            ptr1=ptr1->next;
        }
        else if(ptr2->power>ptr1->power)
        {
            power=ptr2->power;
            coeff=ptr2->coeff;
            ptr2=ptr2->next;
        }
        else
        {
            coeff=ptr1->coeff+ptr2->coeff;
            power=ptr1->power;
            res=create(coeff,power,res);
            ptr1=ptr1->next;
            ptr2=ptr2->next;
        }
    }
    while(ptr1!=NULL){
        res=create(ptr1->coeff,ptr1->power,res);
        ptr1=ptr1->next;
    }
    while(ptr2!=NULL){
        res=create(ptr2->coeff,ptr2->power,res);
        ptr2=ptr2->next;
    }
}
void display()
{
    struct node*temp;
    temp=res;
    while(temp!=NULL)
    {
        printf("%dx^%d",temp->coeff,temp->power);
        if(temp->next!=NULL)
        printf("+");
        temp=temp->next;
    }
}
int main(){
    int deg,val,deg1;
    printf("Enter the maximum degree of polynomial 1: ");
    scanf("%d",&deg);
    for(int i=0;i<=deg;i++){
        printf("The coefficient of X^%d: ",deg-i);
        scanf("%d",&val);
        if(val!=0){
        p1=create(val,deg-i,p1);
        }
    }
    printf("Enter the maximum degree of polynomial 2: ");
    scanf("%d",&deg1);
    for(int i=0;i<=deg1;i++){
        printf("The coefficient of X^%d: ",deg1-i);
        scanf("%d",&val);
        if(val!=0){
        p2=create(val,deg1-i,p2);
        }
    }
    sum(p1,p2);
    printf("The resultant polynomial is: ");
    display();
}
