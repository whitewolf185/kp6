#include <stdio.h>

enum boolean{true=1, false=0};
typedef enum boolean bool;

enum gender{female=1, male=0};
typedef enum gender gndr;

struct graduate{
    char surname[32];
    char name;
    char patron;
    gndr gender;
    int group_number;
    char group_letter;
    char higher_education[32];
    char work[32];
    char army[32];
};
typedef struct graduate graduate;

struct group{
    int number;
    char letter;
    int girls;
};
typedef struct group group;

void clear(char x[], int size){
    for(int i=0; i<size; i++) x[i]=0;
}

void let_str_str(char x[], char y[], int size){
    for(int i=0; i<size; i++) x[i]=y[i];
}

int str_to_int(char x[], int size){
    int ans=0;
    int pos=1;
    for(int i=size-1; i>=0; i--){
        if(x[i]<'0' || x[i]>'9') return -1;
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

bool exist(char x[]){
    FILE *y=NULL;
    y=fopen(x, "rb");
    if(y==NULL) return false;
    else return true;
}

int main(int argc, char *argv[]){

    if(argc==1){
        printf("Missing arguments!\n");
        return 1;
    }

    // Help message
    if(argc==2 && argv[1][0]=='-' && argv[1][1]=='h'){
        FILE *help=NULL;
        help=fopen("Help_KP_6.txt", "r");
        char s;
        while(fread(&s, sizeof(char), 1, help)>0) printf("%c", s);
        return 0;
    }

    // Add record to database
    if(argc==12 && argv[1][0]=='-' && argv[1][1]=='a'){
        if(exist(argv[argc-1])==false){
            printf("File does not exist\n");
            return 3;
        }

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
            if(param==4){
                if(argv[param+1][0]=='m' || argv[param+1][0]=='f') record.gender=(argv[param+1][0]=='f'? female:male);
                else{
                    printf("Invalid gender. Check your input\n");
                    return 4;
                }
            }
            if(param==5){
                int number=str_to_int(argv[param+1], j);
                if(number==-1){
                    printf("Invalid group number. Check your input\n");
                    return 4;
                }
                else record.group_number=str_to_int(argv[param+1], j);
            }
            if(param==6) record.group_letter=argv[param+1][0];
            if(param==7) let_str_str(record.higher_education, argv[param+1], j);
            if(param==8) let_str_str(record.work, argv[param+1], j);
            if(param==9) let_str_str(record.army, argv[param+1], j);
        }

        FILE *base=NULL;
        base=fopen(argv[argc-1], "ab");
        fwrite(&record, sizeof(graduate), 1, base);
        fclose(base);
        printf("Successfully added %s %c %c to %s\n", record.surname, record.name, record.patron, argv[argc-1]);
        return 0;
    }

    // Print all the database
    if(argc==3 && argv[1][0]=='-' && argv[1][1]=='p'){
        if(exist(argv[argc-1])==false){
            printf("File does not exist\n");
            return 3;
        }

        FILE *base=NULL;
        base=fopen(argv[argc-1], "rb");
        int j=1;
        graduate record;
        while(fread(&record, sizeof(graduate), 1, base)>0){
            printf("%d | %s %c %c %c %d %c %s %s %s\n", j, record.surname, record.name, record.patron, (record.gender==female? 'f':'m'), record.group_number, record.group_letter, record.higher_education, record.work, record.army);
            j++;
        }
        fclose(base);
        return 0;
    }

    // Create database file
    if(argc==3 && argv[1][0]=='-' && argv[1][1]=='c'){
        if(exist(argv[argc-1])==true){
            printf("File already exist\n");
            return 3;
        }
        FILE *base=NULL;
        base=fopen(argv[argc-1], "ab");
        fclose(base);
        printf("Successfully created %s\n", argv[argc-1]);
        return 0;
    }

    // Print group number and litter with max amount of girls
    if(argc==3 && argv[1][0]=='-' && argv[1][1]=='m'){
        if(exist(argv[argc-1])==false){
            printf("File does not exist\n");
            return 3;
        }
        FILE *base=NULL;
        base=fopen(argv[argc-1], "rb");
        int i=0;
        graduate a;
        FILE *tmp1=NULL, *tmp2=NULL;
        tmp1=fopen("tmp_file1_11235813", "ab");
        tmp2=fopen("tmp_file2_11235813", "ab");
        fclose(tmp1);
        fclose(tmp2);
        while(fread(&a, sizeof(graduate), 1, base)>0){
            if(a.gender==male) continue;
            int j=0;
            group b;
            int count;
            bool exist=false;
            tmp1=fopen("tmp_file1_11235813", "rb");
            tmp2=fopen("tmp_file2_11235813", "wb");
            while(fread(&b, sizeof(group), 1, tmp1)>0){
                if(a.group_number==b.number && a.group_letter==b.letter){
                    b.girls++;
                    exist=true;
                }
                fwrite(&b, sizeof(group), 1, tmp2);
            }
            if(!exist){
                b.number=a.group_number;
                b.letter=a.group_letter;
                b.girls=1;
                fwrite(&b, sizeof(group), 1, tmp2);
            }
            fclose(tmp1);
            fclose(tmp2);
            tmp1=fopen("tmp_file1_11235813", "wb");
            tmp2=fopen("tmp_file2_11235813", "rb");
            while(fread(&b, sizeof(group), 1, tmp2)>0) fwrite(&b, sizeof(group), 1, tmp1);
            fclose(tmp1);
            fclose(tmp2);
        }
        int ans_n=0, count=0;
        char ans_l=0;
        tmp2=fopen("tmp_file2_11235813", "rb");
        group b;
        while(fread(&b, sizeof(group), 1, tmp2)>0){
            if(b.girls>count){
                ans_n=b.number;
                ans_l=b.letter;
                count=b.girls;
            }
        }
        fclose(tmp2);
        remove("tmp_file1_11235813");
        remove("tmp_file2_11235813");
        printf("%d girls in group %d %c\n", count, ans_n, ans_l);
        return 0;
    }

    // Remove database file
    if(argc==3 && argv[1][0]=='-' && argv[1][1]=='r'){
        if(exist(argv[argc-1])==false){
            printf("File does not exist\n");
            return 3;
        }
        remove(argv[argc-1]);
        printf("Successfully removed %s\n", argv[argc-1]);
        return 0;
    }

    // Request information in database
    if(argc==4 && argv[1][0]=='-' && argv[1][1]=='q'){
        if(exist(argv[argc-1])==false){
            printf("File does not exist\n");
            return 3;
        }
        FILE *base=NULL;
        base=fopen(argv[argc-1], "rb");
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
        if(exist(argv[argc-1])==false){
            printf("File does not exist\n");
            return 3;
        }
        FILE *base=NULL;
        base=fopen(argv[argc-1], "rb");
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

    printf("Something went wrong. Try -h\n");
    return 2;
}