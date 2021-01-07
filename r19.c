//R19
//Ryuta Sato
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define fileName "R19_in.txt"
void inputData(PersonalInfo *);
void serchId(PersonalInfo *);
void serchName(PersonalInfo *);
void outputData(PersonalInfo *);

typedef struct{
    double height;
    double weight;
} PersonalInfo;

typedef struct member{
    struct member *next;
    int id;
    char name[30];
    PersonalInfo personalInfo;
}MEMBER;

/*-------------------------------------------*/
int main(void){
    PersonalInfo endPoint = {NULL};
    PersonalInfo* strPoint = &endPoint;
    inputData(strPoint);
    serchId(strPoint);
    serchName(strPoint);
    outputData(strPoint);
    return 0;
}
/*-------------------------------------------*/

void inputData(PersonalInfo *data){
    FILE *fp;
    char str[200];
    PersonalInfo *tmp={NULL},*keep;
    fp=fopen(fileName,"r");
    if(fp==NULL){
        printf("ERROR EXIT(1)\n");
        exit(1)
    }
    fgets(str,200,fp);
    do{
        if(tmp!=NULL){ //maybe error
            PersonalInfo *allocatedSpace=(PersonalInfo *)calloc(1,sizeof(PersonalInfo));
            if(allocatedSpace==NULL){
                printf("ERROR EXIT(2)\n");
                exit(2);
            }
            allocatedSpace=tmp;
            for(keep=start;keep!=NULL;keep=keep->next){
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
    }while(fscanf(fp,"%d %s %lf %lf",tmp->id,tmp->name,tmp->personalInfo->height,tmp->personalInfo->weight)==0);

    fclose(fp);
}
void serchId(PersonalInfo *){
    
}
void serchName(PersonalInfo *){
    
}
void outputData(PersonalInfo *){
    
}
