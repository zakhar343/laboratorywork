#include <stdio.h>
#include <stdlib.h>
#include <complex.h>
void *createint(int a,int b){
void *arr;
arr=malloc((a)*(b+1)*sizeof(int));
return(arr);
}

void *createfloat(int a,int b){
void *arr;
arr=malloc((a)*(b+1)*sizeof(float));
return(arr);
}

void *createcomplex(int a,int b){
void *arr;
arr=malloc((a)*(b+1)*sizeof(float complex));
return(arr);
}

create(int a,int b,int c){
    if(c==1)createint(a,b);
    if(c==2)createfloat(a,b);
    if(c==3)createcomplex(a,b);
}

readint(int a,int b, void *arr){
    int i,j;
    for(i=0;i<b;i++)
    for(j=0;j<a;j++){
        printf("Введите %d координату %d вектора\n",j+1,i+1);
        scanf("%d",(int*)arr+j+a*(i));
    }
}

readfloat(int a,int b,void *arr){
    int i,j;
    for(i=0;i<b;i++)
    for(j=0;j<a;j++){
        printf("Введите %d координату %d вектора\n",j+1,i+1);
        scanf("%f",(float*)arr+j+a*(i));
    }
}

readcomplex(int a,int b,void *arr){
    int i,j;float x,y;
    for(i=0;i<b;i++)
    for(j=0;j<a;j++){
        printf("Введите %d действительную координату %d вектора\n",j+1,i+1);
        scanf("%f",&x);
        printf("Введите %d мнимую координату %d вектора\n",j+1,i+1);
        scanf("%f",&y);
        *((float complex*)arr+j+a*i)=x+y*I;
    }
}

read(int a,int b,int c,void *arr){
if(c==1)readint(a,b,arr);
if(c==2)readfloat(a,b,arr);
if(c==3)readcomplex(a,b,arr);
}

sumint(int a,int b,void *arr){
int i,j;
    for(i=0;i<a;i++){*((int*)arr+i+a*b)=0;
    for(j=0;j<b;j++){
    *((int*)arr+i+a*b)+=*((int*)arr+i+a*(j));
    }}
    }

sumfloat(int a,int b,void *arr){
int i,j;
    for(i=0;i<a;i++){
    *((float*)arr+i+a*b)=0;
    for(j=0;j<b;j++){
    *((float*)arr+i+a*b)+=*((float*)arr+i+a*(j));
    }};}

sumcomplex(int a,int b,void *arr){
int i,j;
    for(i=0;i<a;i++){
    *((float complex*)arr+i+a*b)=0;
    for(j=0;j<b;j++){
    *((float complex*)arr+i+a*b)+=*((float complex*)arr+i+a*(j));
    }};}

sum(int a, int b,int c,void *arr){;
    if(c==1)sumint(a,b,arr);
    if(c==2)sumfloat(a,b,arr);
    if(c==3)sumcomplex(a,b,arr);
}

multiplyint(int a,int b,void *arr){
int i,j;
 for(i=0;i<a;i++){*((int*)arr+i+a*b)=1;
    for(j=0;j<b;j++){
    *((int*)arr+i+a*b)*=*((int*)arr+i+a*(j));
    }};
    *((int*)arr)=0;
    for(i=0;i<a;i++)
            *((int*)arr)+=*((int*)arr+i+a*b);
    }

multiplyfloat(int a,int b,void *arr){
int i,j;
 for(i=0;i<a;i++){*((float*)arr+i+a*b)=1;
    for(j=0;j<b;j++){
    *((float*)arr+i+a*b)=*((float*)arr+i+a*(j))**((float*)arr+i+a*b);
    }};
    *((float*)arr)=0;
    for(i=0;i<a;i++)
        *((float*)arr)+=*((float*)arr+i+a*b);
    }

multiplycomplex(int a,int b,void *arr){
int i,j;
 for(i=0;i<a;i++){*((float complex*)arr+i+a*b)=1;
    for(j=0;j<b;j++){
    *((float complex*)arr+i+a*b)*=*((float complex*)arr+i+a*(j));
    }};
    *((float complex*)arr)=0;
    for(i=0;i<a;i++)
        *((float complex*)arr)+=*((float complex*)arr+i+a*b);
    }

multiply(int a,int b,int c,void *arr){
if(c==1)multiplyint(a,b,arr);
if(c==2)multiplyfloat(a,b,arr);
if(c==3)multiplycomplex(a,b,arr);
}

printintsum(int a,int b,void *arr){
    int i;
    printf("Координаты нового вектора (%d",*((int*)arr+a*b));
    for(i=1;i<a;i++)
            printf(",%d",*((int*)arr+a*b+i));
    printf(")");
}

printfloatsum(int a,int b,void *arr){
    int i;
    printf("Координаты нового вектора (%.2f",*((float*)arr+a*b));
    for(i=1;i<a;i++)
            printf(",%.2f",*((float*)arr+a*b+i));
    printf(")");
}

printcomplexsum(int a,int b,void *arr){
    int i;
    printf("Координаты нового вектора (%.2f + %.2fi",crealf(*((float complex*)arr+a*b)),cimagf(*((float complex*)arr+a*b)));
    for(i=1;i<a;i++)
            printf(",%.2f + %.2fi",crealf(*((float complex*)arr+a*b+i)),cimagf(*((float complex*)arr+a*b+i)));
    printf(")");
}

printintmulti(int a,int b,void *arr){
printf("Скалярное произведение равно = %d",*((int*)arr));
}

printfloatmulti(int a,int b,void *arr){
printf("Скалярное произведение равно = %.2f",*((float*)arr));
}

printcomplexmulti(int a,int b,void *arr){
printf("Скалярное произведение равно = %.2f + %.2fi",crealf(*((float complex*)arr)),cimagf(*((float complex*)arr)));
}

print(int a,int b,int c,int d,void *arr){
if(c==1 & d==1)printintsum(a,b,arr);
if(c==2 & d==1)printfloatsum(a,b,arr);
if(c==3 & d==1)printcomplexsum(a,b,arr);
if(c==1 & d==2)printintmulti(a,b,arr);
if(c==2 & d==2)printfloatmulti(a,b,arr);
if(c==3 & d==2)printcomplexmulti(a,b,arr);
}

fillint(int a,int b,void *arr){
 int i,j;
    for(i=0;i<b;i++)
    for(j=0;j<a;j++){
        *((int*)arr+j+a*(i))=j+a*i;
}
}

fillfloat(int a,int b,void *arr){
 int i,j;
    for(i=0;i<b;i++)
    for(j=0;j<a;j++){
        *((float*)arr+j+a*(i))=j+a*i;
    }
}

fillcomplex(int a,int b,void *arr){
 int i,j,k=0;
    for(i=0;i<b;i++)
    for(j=0;j<a;j++){
        *((float complex*)arr+j+a*i)=k+(k+1)*I;
        k++;
        k++;
    }
}

fill(int a,int b,int c,void *arr){
if(c==1)fillint(a,b,arr);
if(c==2)fillfloat(a,b,arr);
if(c==3)fillcomplex(a,b,arr);
}

test(int a,int b,int c,int d,void *arr){
int flag=0;
fill(a,b,c,arr);
sum(a,b,c,arr);
flag=checksum(a,b,c,arr);
if(flag==1)printf("Test addition OK\n"); else printf("Test addition failed\n");
multiply(a,b,c,arr);
flag=checkmulti(a,b,c,arr);
if(flag==1)printf("Test multiplication OK\n"); else printf("Test multiplication failed\n");
}

int checkmultiint(int a,int b,void *arr){
    int flag=0;
if(*((int*)arr)==396)flag=1;
return(flag);
}

int checkmultifloat(int a,int b,void *arr){
    int flag=0;
if(*((float*)arr)==396)flag=1;
return(flag);
}

int checkmulticomplex(int a,int b,void *arr){
    int flag=0;
if(crealf(*((float complex*)arr))==-8980 & cimagf(*((float complex*)arr))==6200)flag=1;
return(flag);
}

checkmulti(int a,int b,int c,void *arr){
if(c==1)checkmultiint(a,b,arr);
if(c==2)checkmultifloat(a,b,arr);
if(c==3)checkmulticomplex(a,b,arr);
}

int checksumint(int a,int b,void *arr){
    int flag=0;
if((*((int*)arr+a*b)==12) & (*((int*)arr+a*b+1)==15) & (*((int*)arr+a*b+2)==18) & (*((int*)arr+a*b+3)==21))flag=1;
return(flag);
}

int checksumfloat(int a,int b,void *arr){
    int flag=0;
if((*((float*)arr+a*b+0)==12) & (*((float*)arr+a*b+1)==15) & (*((float*)arr+a*b+2)==18) & (*((float*)arr+a*b+3)==21))flag=1;
return(flag);
}

int checksumcomplex(int a,int b,void *arr){
    int flag=0;
if(crealf(*((float complex*)arr+a*b+0))==24 & cimagf(*((float complex*)arr+a*b+0))==27 &
   crealf(*((float complex*)arr+a*b+1))==30 & cimagf(*((float complex*)arr+a*b+1))==33 &
    crealf(*((float complex*)arr+a*b+2))==36 & cimagf(*((float complex*)arr+a*b+2))==39 &
    crealf(*((float complex*)arr+a*b+3))==42 & cimagf(*((float complex*)arr+a*b+3))==45)flag=1;
return(flag);
}

checksum(int a,int b,int c,void *arr){
if(c==1)checksumint(a,b,arr);
if(c==2)checksumfloat(a,b,arr);
if(c==3)checksumcomplex(a,b,arr);
}

int main(){
    setlocale( 0,"Russian" );
    void *arr;
    int a,b,c,d;
    printf("Введите, что хотите сделать с векторами\n1.Складывать\n2.Скалярно умножать\n3.Тестировать программу\n");
    scanf("%d",&d);
    printf("Введите количество координат вектора(Для теста количество фиксировано и равно 4)");
    scanf("%d",&a);
    printf("Введите количество векторов(Для теста количество фиксировано и равно 3)\n");
    scanf("%d",&b);
    printf("Введите тип данных векторов\n1.Целые числа\n2.Вещественные числа\n3.Комплексные числа\n");
    scanf("%d",&c);
    if(d==3){a=4;b=3;}
    arr=create(a,b,c);
    if(d!=3){read(a,b,c,arr);
    if(d==1)sum(a,b,c,arr);
    if(d==2)multiply(a,b,c,arr);
    print(a,b,c,d,arr);}
    if(d==3)test(a,b,c,d,arr);
return (0);
}
