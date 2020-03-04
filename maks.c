#include <stdio.h>

enum boolean{true=1, false=0};
typedef enum boolean bool;

struct graduate{
    char surname[32];
    char name;
    char patron;
    int gender;
    int class_number;
    char class_letter;
    char higher_education[32];
    char work[32];
    char army[32];
};
typedef struct graduate graduate;

void clear(char x[], int size){
    for(int i=0; i<size; i++) x[i]=0;
}

void let_str_str(char x[], char y[], int size){
    for(int i=0; i<size; i++) x[i]=y[i];
}

int str_to_int(char x[], int size){
    int ans=0;
    int pos=1;
    for(int i=0; i<size; i++){
        //printf("%d\n", x[i]);
        ans+=pos*(x[i]-'0');
        pos*=10;
    }
    return ans;
}

bool compare_str(char x[], char y[]){
    for(int i=0; i<32; i++){
        if(x[i]==0 && y[i]==0) break;
        if(x[i]!=y[i]) return false;
    }
    return true;
}

int main(int argc, char *argv[]){

    if(argc==1){
        printf("Missing arguments!\n");
        return 1;
    }

    // Add record to database
    if(argc==12 && argv[1][0]=='-' && argv[1][1]=='a'){
        FILE *base=NULL;
        base=fopen(argv[argc-1], "rb");
        if(base==NULL){
            printf("File does not exist\n");
            return 3;
        }
        fclose(base);

        graduate record;
        clear(record.surname, 32);
        clear(record.higher_education, 32);
        clear(record.work, 32);
        clear(record.army, 32);
        for(int param=1; param<10; param++){
            int j=0;
            while(argv[param+1][j]>0) j++;
            if(param==1) let_str_str(record.surname, argv[param+1], j);
            if(param==2) record.name=argv[param+1][0];
            if(param==3) record.patron=argv[param+1][0];
            if(param==4) record.gender=(argv[param+1][0]=='f'? 1:0);
            if(param==5) record.class_number=str_to_int(argv[param+1], j);
            if(param==6) record.class_letter=argv[param+1][0];
            if(param==7) let_str_str(record.higher_education, argv[param+1], j);
            if(param==8) let_str_str(record.work, argv[param+1], j);
            if(param==9) let_str_str(record.army, argv[param+1], j);
        }

        base=fopen(argv[argc-1], "ab");
        fwrite(&record, sizeof(graduate), 1, base);
        fclose(base);
        printf("Successfully added %s %c %c to %s\n", record.surname, record.name, record.patron, argv[argc-1]);
        return 0;
    }

    // Print all the database
    if(argc==3 && argv[1][0]=='-' && argv[1][1]=='p'){
        FILE *base=NULL;
        base=fopen(argv[argc-1], "rb");
        if(base==NULL){
            printf("File does not exist\n");
            return 3;
        }
        int j=1;
        graduate record;
        while(fread(&record, sizeof(graduate), 1, base)>0){
            printf("%d | %s %c %c %c %d %c %s %s %s\n", j, record.surname, record.name, record.patron, (record.gender==1? 'f':'m'), record.class_number, record.class_letter, record.higher_education, record.work, record.army);
            j++;
        }
        fclose(base);
        return 0;
    }

    // Create database file
    if(argc==3 && argv[1][0]=='-' && argv[1][1]=='c'){
        FILE *base=NULL;
        base=fopen(argv[argc-1], "rb");
        if(base!=NULL){
            printf("File already exist\n");
            return 3;
        }
        fclose(base);
        base=fopen(argv[argc-1], "ab");
        fclose(base);
        printf("Successfully created %s\n", argv[argc-1]);
        return 0;
    }

    // Remove database file
    if(argc==3 && argv[1][0]=='-' && argv[1][1]=='r'){
        FILE *base=NULL;
        base=fopen(argv[argc-1], "rb");
        if(base==NULL){
            printf("File does not exist\n");
            return 3;
        }
        fclose(base);
        remove(argv[argc-1]);
        printf("Successfully removed %s\n", argv[argc-1]);
        return 0;
    }

    // Request information in database
    if(argc==4 && argv[1][0]=='-' && argv[1][1]=='q'){
        FILE *base=NULL;
        base=fopen(argv[argc-1], "rb");
        if(base==NULL){
            printf("File does not exist\n");
            return 3;
        }
        graduate a;
        int j=1;
        while(fread(&a, sizeof(graduate), 1, base)>0){
            if(compare_str(a.surname, argv[2])==true){
                printf("Found %d | %s %c %c in %s\n", j, a.surname, a.name, a.patron, argv[argc-1]);
                return 0;
            }
            j++;
        }
        printf("Record with surname %s does not exist in %s\n", argv[2], argv[argc-1]);
        return 0;
    }

    // Delete record N from database
    if(argc==4 && argv[1][0]=='-' && argv[1][1]=='d'){
        FILE *base=NULL;
        base=fopen(argv[argc-1], "rb");
        if(base==NULL){
            printf("File does not exist\n");
            return 3;
        }
        FILE *tmp=NULL;
        tmp=fopen("tmp_file_11235813", "ab");
        int size=0;
        while(argv[2][size]>0) size++;
        int n=str_to_int(argv[2], size);
        int j=1;
        graduate record;
        while(fread(&record, sizeof(graduate), 1, base)>0){
            if(j!=n) fwrite(&record, sizeof(graduate), 1, tmp);
            j++;
        }
        if(n>=j || 1>n){
            printf("Record %d in %s does not exist\n", n, argv[argc-1]);
            return 4;
        }else{
            fclose(base);
            base=fopen(argv[argc-1], "wb");
            fclose(tmp);
            tmp=fopen("tmp_file_11235813", "rb");
            while(fread(&record, sizeof(graduate), 1, tmp)>0) fwrite(&record, sizeof(graduate), 1, base);
            fclose(base);
            fclose(tmp);
            remove("tmp_file_11235813");
            printf("Successfully removed %d record from %s\n", n, argv[argc-1]);
            return 0;
        }
    }

    printf("Something went wrong\n");
    return 2;
}