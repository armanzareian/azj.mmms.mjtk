
#include <stdio.h>
#include <stdlib.h>
typedef struct player{
    unsigned int number;
    char name[100];
    unsigned int age;
    char post;
    unsigned int goals;
}player_s;

typedef struct team{
    char name[100];
    char group;
    unsigned int rank;
    char conname[50];
    unsigned int seed;
    char filename[100];
    player_s *player;
    unsigned int total;
    unsigned int goals;
    
}team_s;

int countlines(char *filelocation){
    FILE *fp=fopen(filelocation, "r");
    int ch=0;
    int lines=0;
    
    if(fp==NULL){
        perror("can't open file");
        return 0;
    }
    while(!feof(fp))
    {
        ch = fgetc(fp);
        if(ch == '\n')
        {
            lines++;
        }
    }
    fclose(fp);
    return lines;
}

int load(team_s a[], int len){
    FILE *f=fopen("/Users/arman/desktop/project/project 2/project 2/Teams.csv","r");
    if(f==NULL){
        perror("can't open file");
        return 0;
    }
    
    
    for(int i=0;i<len;i++){
        char str[100];
        char str1[6][20];
        char *h;
        fgets(str, 100*sizeof(char), f);
        h=strtok(str,",");
        int j=0;
        while (h != NULL)
        {
            sprintf(str1[j], "%s ",h);
            h = strtok (NULL, ",");
            j++;
        }
        char address[150];
        sscanf(str1[0], "%s",a[i].name);
        sscanf(str1[1], "%c",&a[i].group);
        sscanf(str1[2], "%u",&a[i].rank);
        sscanf(str1[3], "%s",a[i].conname);
        sscanf(str1[4], "%u",&a[i].seed);
        sscanf(strtok(str1[5],"\n"), "%s",a[i].filename);
        sprintf(address, "/Users/arman/desktop/project/project 2/project 2/%s",a[i].filename);
        a[i].total=countlines(address);
        
        
        
        
        a[i].player=calloc(a[i].total,sizeof(player_s));
        FILE *w=fopen(address,"r");
        if(w==NULL){
            perror("can't open file");
            return 0;
        }
        
        
        for(int k=0;k<a[i].total;k++){
            h=0;
            char str3[5][20];
            
            
            
            fgets(str, 100*sizeof(char), w);
            h=strtok(str,",");
            j=0;
            while (h != NULL)
            {
                sprintf(str3[j], "%s ",h);
                h = strtok (NULL, ",");
                j++;
            }
            h=strtok(str3[1],". ");
            sprintf(str3[4], "%s",h);
            h = strtok (NULL, " .");
            sprintf(str3[1], "%s",h);
            strcat(str3[4],".");
            strcat(str3[4],str3[1]);
            sscanf(str3[0], "%u",&a[i].player[k].number);
            sscanf( str3[4],"%s",a[i].player[k].name);
            sscanf(str3[2], "%u",&a[i].player[k].age);
            sscanf(str3[3], "%s",&a[i].player[k].post);
            
        }
        fclose(w);
        w=0;
    }
    fclose(f);
    f=0;
    return 1;
}

//#define address /Users/arman/desktop/project/project 2/project 2/


int save(team_s a[],int len){
    FILE *f=fopen("/Users/arman/desktop/project/project 2/project 2/saved/Teams.csv","w");
    if(f==NULL){
        perror("can't open file");
        return 0;
    }
    for(int i=0;i<len;i++){
        fprintf(f, "%s,%c,%u,%s,%u,%s,%u,%u\n",a[i].name,a[i].group,a[i].rank,a[i].conname,a[i].seed,a[i].filename,a[i].total,a[i].goals);
        char address[150];
        sprintf(address,"/Users/arman/desktop/project/project 2/project 2/saved/%s",a[i].filename);
        FILE *w=fopen(address,"w");
        if(w==NULL){
            perror("can't open file");
            return 0;
        }
        
        for(int j=0;j<a[i].total;j++){
            char *h=strtok(a[i].player[j].name, ".");
            char str[20];
            sprintf(str, "%s",h);
            h=strtok(NULL, ".");
            char str1[20];
            sprintf(str1, "%s",h);
            char str2[100];
            sprintf(str2, "%s. %s",str,str1);
            fprintf(w, "%u,%s,%u,%c,%u\n",a[i].player[j].number,str2,a[i].player[j].age,a[i].player[j].post,a[i].player[j].goals);
        }
        fclose(w);
        w=NULL;
    }
    fclose(f);
    f=NULL;
    return 1;
}



int main() {
    team_s a[32];
    team_s b[32];
    int z=load(a,32);
    if (z==0)
        return 0;
    int k=save(a, 32);
    if (k==0)
        return 0;
    z=load(a,32);
    if (z==0)
        return 0;
    printf("%s",b[13].player[5].name);
    
    
    
    
    
}



