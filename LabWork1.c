#include <stdio.h>
#include <stdlib.h>
#include <complex.h>
#include <malloc.h>
const float e = 0.000001;
void* multi;
struct data{
void* data;
int size;}
vector;
void *createint(int a,int b){
    vector.size=sizeof(int);
vector.data=calloc(a*(b+1),vector.size);
return(vector.data);
}

void *createfloat(int a,int b){
    vector.size=sizeof(float);
vector.data=calloc(a*(b+1),vector.size);
return(vector.data);
}

void *createcomplex(int a,int b){
    vector.size=sizeof(float complex);
vector.data=calloc(a*(b+1),vector.size);
return(vector.data);
}

create(int a,int b,int c){
    if(c==1)createint(a,b);
    if(c==2)createfloat(a,b);
    if(c==3)createcomplex(a,b);
};

readint(int a,int b,void *arr){
    int i,j;
    for(i=0;i<b;i++)
    for(j=0;j<a;j++){
        printf("Введите %d координату %d вектора\n",j+1,i+1);
        scanf("%d",(int*)vector.data+j+a*(i));
    }
}

readfloat(int a,int b,void *arr){
    int i,j;
    for(i=0;i<b;i++)
    for(j=0;j<a;j++){
        printf("Введите %d координату %d вектора\n",j+1,i+1);
        scanf("%f",(float*)vector.data+j+a*(i));
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
        *((float complex*)vector.data+j+a*i)=x+y*I;
    }
}

read(int a,int b,int c,void *arr){
if(c==1)readint(a,b,vector.data);
if(c==2)readfloat(a,b,vector.data);
if(c==3)readcomplex(a,b,vector.data);
}

sumint(int a,int b,int i,int j,void *arr){
    *((int*)vector.data+i+a*b)+=*((int*)vector.data+i+a*(j));
    }

sumfloat(int a,int b,int i,int j,void *arr){
    *((float*)vector.data+i+a*b)+=*((float*)vector.data+i+a*(j));
    };

sumcomplex(int a,int b,int i,int j,void *arr){
    *((float complex*)vector.data+i+a*b)+=*((float complex*)vector.data+i+a*(j));
    };

sum(int a, int b,void *arr,void*(func(int a,int b,int i,int j,void *arr))){;
int i,j;
    for(i=0;i<a;i++){
    for(j=0;j<b;j++){
    func(a,b,i,j,vector.data);
    }}
    }

summultiint(int a,int b,void *arr){
int i,j;
*((int*)vector.data)=0;
for(i=0;i<a;i++)
    *((int*)vector.data)=*((int*)vector.data)+*((int*)vector.data+i+a*b);
}

summultifloat(int a,int b,void *arr){
*((float*)vector.data)=0;
int i,j;
for(i=0;i<a;i++)
    *((float*)vector.data)+=*((float*)vector.data+i+a*b);
}

summulticomplex(int a,int b,void *arr){
*((float complex*)vector.data)=0+0*I;
int i,j;
for(i=0;i<a;i++)
    *((float complex*)vector.data)+=*((float complex*)vector.data+i+a*b);
}

summulti(int a,int b,int c,void *arr){
    if(c==1)summultiint(a,b,vector.data);
    if(c==2)summultifloat(a,b,vector.data);
    if(c==3)summulticomplex(a,b,vector.data);
}

multiplyint(int a,int b,int i,int j,void *arr){
    *((int*)vector.data+i+a*b)*=*((int*)vector.data+i+a*(j));
    };

multiplyfloat(int a,int b,int i,int j,void *arr){
    *((float*)vector.data+i+a*b)*=*((float*)vector.data+i+a*(j));
    };

multiplycomplex(int a,int b,int i,int j,void *arr){
*((float complex*)vector.data+i+a*b)*=*((float complex*)vector.data+i+a*(j));
    }

multiply(int a,int b,int c,void *arr,void *(func(int a,int b,int i,int j,void *arr))){
int i,j;
 for(i=0;i<a;i++){
    for(j=0;j<b;j++){
    func(a,b,i,j,vector.data);
    }};summulti(a,b,c,vector.data);};

printintsum(int a,int b,void *arr){
    int i;
    printf("Координаты нового вектора (%d",*((int*)vector.data+a*b));
    for(i=1;i<a;i++)
            printf(",%d",*((int*)vector.data+a*b+i));
    printf(")");
}

printfloatsum(int a,int b,void *arr){
    int i;
    printf("Координаты нового вектора (%.2f",*((float*)vector.data+a*b));
    for(i=1;i<a;i++)
            printf(",%.2f",*((float*)vector.data+a*b+i));
    printf(")");
}

printcomplexsum(int a,int b,void *arr){
    int i;
    printf("Координаты нового вектора (%.2f + %.2fi",crealf(*((float complex*)vector.data+a*b)),cimagf(*((float complex*)vector.data+a*b)));
    for(i=1;i<a;i++)
            printf(",%.2f + %.2fi",crealf(*((float complex*)vector.data+a*b+i)),cimagf(*((float complex*)vector.data+a*b+i)));
    printf(")");
}

printintmulti(int a,int b,void *arr){
printf("Скалярное произведение равно = %d",*((int*)vector.data));
}

printfloatmulti(int a,int b,void *arr){
printf("Скалярное произведение равно = %.2f",*((float*)vector.data));
}

printcomplexmulti(int a,int b,void *arr){
printf("Скалярное произведение равно = %.2f + %.2fi",crealf(*((float complex*)vector.data)),cimagf(*((float complex*)vector.data)));
}

print(int a,int b,int c,int d,void *arr){
if(c==1 & d==1)printintsum(a,b,vector.data);
if(c==2 & d==1)printfloatsum(a,b,vector.data);
if(c==3 & d==1)printcomplexsum(a,b,vector.data);
if(c==1 & d==2)printintmulti(a,b,vector.data);
if(c==2 & d==2)printfloatmulti(a,b,vector.data);
if(c==3 & d==2)printcomplexmulti(a,b,vector.data);
}

fillint(int a,int b,void *arr){
 int i,j;
    for(i=0;i<b;i++)
    for(j=0;j<a;j++){
        *((int*)vector.data+j+a*(i))=j+a*i;
}
}

fillfloat(int a,int b,void *arr){
 int i,j;
    for(i=0;i<b;i++)
    for(j=0;j<a;j++){
        *((float*)vector.data+j+a*(i))=j+a*i;
    }
}

fillcomplex(int a,int b,void *arr){
 int i,j,k=0;
    for(i=0;i<b;i++)
    for(j=0;j<a;j++){
        *((float complex*)vector.data+j+a*i)=k+(k+1)*I;
        k++;
        k++;
    }
}

fill(int a,int b,int c,void *arr){
if(c==1)fillint(a,b,vector.data);
if(c==2)fillfloat(a,b,vector.data);
if(c==3)fillcomplex(a,b,vector.data);
}

test(int a,int b,int c,int d,void *arr){
int flag=0;
fill(a,b,c,vector.data);
int i;
            if(c==1)sum(a,b,vector.data,sumint);
            if(c==2)sum(a,b,vector.data,sumfloat);
            if(c==3)sum(a,b,vector.data,sumcomplex);
            flag=checksum(a,b,c,vector.data);
            if(flag==1)printf("Test addition OK\n"); else printf("Test addition failed\n");

           if(c==1){for(i=0;i<a;i++)*((int*)vector.data+i+a*b)=1;multiply(a,b,c,vector.data,multiplyint);};
            if(c==2){for(i=0;i<a;i++)*((float*)vector.data+i+a*b)=1;multiply(a,b,c,vector.data,multiplyfloat);};
            if(c==3){for(i=0;i<a;i++)*((float complex*)vector.data+i+a*b)=1+1*I;multiply(a,b,c,vector.data,multiplycomplex);};
flag=checkmulti(a,b,c,vector.data);
if(flag==1)printf("Test multiplication OK\n"); else printf("Test multiplication failed\n");
}

int checkmultiint(int a,int b,void *arr){
    int flag=0;
if(*((int*)vector.data)==396)flag=1;
return(flag);
}

int checkmultifloat(int a,int b,void *arr){
    int flag=1;
if(fabs(*((float*)vector.data)-396)>e)flag=0;
return(flag);
}

int checkmulticomplex(int a,int b,void *arr){
    int flag=1;
if(fabs(crealf(*((float complex*)vector.data))+15180.00)>e & fabs(cimagf(*((float complex*)vector.data))+2780.00)>e)flag=0;
return(flag);
}

checkmulti(int a,int b,int c,void *arr){
if(c==1)checkmultiint(a,b,vector.data);
if(c==2)checkmultifloat(a,b,vector.data);
if(c==3)checkmulticomplex(a,b,vector.data);
}

int checksumint(int a,int b,void *arr){
    int flag=0;printf("HI");
if((*((int*)vector.data+a*b)==12) & (*((int*)vector.data+a*b+1)==15) & (*((int*)vector.data+a*b+2)==18) & (*((int*)vector.data+a*b+3)==21))flag=1;
return(flag);
}

int checksumfloat(int a,int b,void *arr){
    int flag=1;
if((*((float*)vector.data+a*b+0)-12)>e | (*((float*)vector.data+a*b+1)-15)>e | (*((float*)vector.data+a*b+2)-18)>e | (*((float*)vector.data+a*b+3)-21)>e)flag=0;
return(flag);
}

int checksumcomplex(int a,int b,void *arr){
    int flag=1;
if(crealf((*((float complex*)vector.data+a*b+0))-24)>e | (cimagf(*((float complex*)vector.data+a*b+0))-27)>e |
   (crealf(*((float complex*)vector.data+a*b+1))-30)>e | (cimagf(*((float complex*)vector.data+a*b+1))-33)>e |
    (crealf(*((float complex*)vector.data+a*b+2))-36)>e | (cimagf(*((float complex*)vector.data+a*b+2))-39)>e |
    (crealf(*((float complex*)vector.data+a*b+3))-42)>e | (cimagf(*((float complex*)vector.data+a*b+3))-45)>e)flag=0;
return(flag);
}

checksum(int a,int b,int c,void *arr){
if(c==1)checksumint(a,b,vector.data);
if(c==2)checksumfloat(a,b,vector.data);
if(c==3)checksumcomplex(a,b,vector.data);
}

int main(){
    setlocale(0,"Russian" );
    struct data vector;
    int a,b,c,d,i;
    printf("Введите, что хотите сделать с векторами\n1.Складывать\n2.Скалярно умножать\n3.Тестировать программу\n");
    scanf("%d",&d);
    printf("Введите количество координат вектора(Для теста количество фиксировано и равно 4)");
    scanf("%d",&a);
    printf("Введите количество векторов(Для теста количество фиксировано и равно 3)\n");
    scanf("%d",&b);
    printf("Введите тип данных векторов\n1.Целые числа\n2.Вещественные числа\n3.Комплексные числа\n");
    scanf("%d",&c);
    if(d==3){a=4;b=3;}
    vector.data=create(a,b,c);
    if(d!=3){read(a,b,c,vector.data);
    if(d==1){
            if(c==1)sum(a,b,vector.data,sumint);
            if(c==2)sum(a,b,vector.data,sumfloat);
            if(c==3)sum(a,b,vector.data,sumcomplex);}
    if(d==2){

            if(c==1){for(i=0;i<a;i++)*((int*)vector.data+i+a*b)=1;multiply(a,b,c,vector.data,multiplyint);};
            if(c==2){for(i=0;i<a;i++)*((float*)vector.data+i+a*b)=1;multiply(a,b,c,vector.data,multiplyfloat);};
            if(c==3){for(i=0;i<a;i++)*((float complex*)vector.data+i+a*b)=1+1*I;multiply(a,b,c,vector.data,multiplycomplex);};}
    print(a,b,c,d,vector.data);}
    if(d==3)test(a,b,c,d,vector.data);
return (0);
}
