//R19
//Ryuta Sato
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define fileName "R19_in.txt"
#define SetSerchBMI 25
typedef struct{
    double height;
    double weight;
} Status;

typedef struct personalInfo{
    struct personalInfo *next;
    int id;
    char name[30];
    Status status;
}PersonalInfo;

int menu(void);
void inputData(PersonalInfo *data);
void searchId(PersonalInfo *data);
void searchName(PersonalInfo *data);
void outputAllData(PersonalInfo *data);
void bmi25AboveData(PersonalInfo *data);
/*-------------------------------------------*/
int main(void){
    jump(menu());
    return 0;
}
/*-------------------------------------------*/

void jump(int select){
    PersonalInfo endPoint = {NULL};
    PersonalInfo *strPoint = &endPoint;
    inputData(strPoint);
    switch(select){
        case 1:
            outputAllData();
            break;
        case 2:
            searchId(strPoint);
            break;
        case 3:
            searchName(strPoint);
            break;
        case 4:
            bmi25AboveData(PersonalInfo *data);
            break;
        default:
            free(strPoint);
            free(endPoint);
            jump(menu());
            break;
    }
    
}
int menu(void){
    int select;
    do{
        printf("-------Menu---------\n");
        printf("1:Display all data\n");
        printf("2:Search ID\n");
        printf("3:Search NAME\n");
        printf("4:Display data for BMI 25 and above\n");
        printf("SELECT:")
        
    }while(scanf("%d",&select) != 0);
    return select;
}

void inputData(PersonalInfo *data){
    FILE *fp;
    char str[200];
    PersonalInfo *tmp={NULL},*keep;
    
    fp=fopen("R19_in.txt","r");
    if(fp==NULL){
        printf("ERROR EXIT(1)\n");
        exit(1);
    }
    
    while(fscanf(fp,"%d %s %lf %lf",tmp->id,tmp->name,tmp->status.height,tmp->status.weight)!=EOF){
        
        PersonalInfo *allocatedSpace=(PersonalInfo *)calloc(1,sizeof(PersonalInfo));
        if(allocatedSpace==NULL){
            printf("ERROR EXIT(2)\n");
            exit(2);
        }
        allocatedSpace=tmp;
        for(keep=data;keep!=NULL;keep=keep->next){
            if(allocatedSpace->id < allocatedSpace->next->id){
                allocatedSpace->next=keep->next;
                keep->next=allocatedSpace;
                break;
            }
        }
        if(keep->next==NULL){
            keep->next=keep;
            keep->next=NULL;
        }
    }
    printf("line80\n");
    fclose(fp);
    
}
void searchId(PersonalInfo *data){
    
    
}
void searchName(PersonalInfo *data){
    
}
void outputAllData(PersonalInfo *data){
    PersonalInfo *tmp=data;
    while(tmp->next !=NULL){
        printf("%5d %s %5.1f %5.1f\n",tmp->id,tmp->name,tmp->status.height,tmp->status.weight);
        tmp=tmp->next;
    }
}
