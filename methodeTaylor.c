#include<stdio.h>
#include<math.h>

double f(float t, float y)
{
    return (pow(y,2)+y)/t; 
}

double fprim(float t, float y)
{
    return 2*(pow(y,3)+pow(y,2))/pow(t,2);
}

void affichage(int i,float t, float y)
{
    printf("%d\t%.6f\t%.6f\n",i,t,y);
}

double tseconde(float t, float y,float h)
{
    return f(t,y)+(h*fprim(t,y))/2;
} 
void main(){
     float a,b,n,alpha;
     
     //valeur de a
     printf("Entrer la valeur de a: ");scanf("%f",&a);
	 
	 //valeur de b
	 printf("Entrer la valeur de b: ");scanf("%f",&b);

     //valeur de n:nombre d'iteration
     printf("Entrer la valeur de n: ");scanf("%f",&n);

     //valeur de alpha:condition initiale
     printf("Entrer la valeur de alpha(condition initiale): ");scanf("%f",&alpha);

     //valeur de h:ecart entre 2 xi
     float h=(b-a)/n;
     
     //valeur de w0: premiere valeur
     int j=0;
     float t=a,w=alpha;

     //affichage premiere valeur
     affichage(j,t,w);
     
     for(j=1;j<=n;j++)
     {
        w+=h*tseconde(t,w,h);
        t=a+j*h;
        affichage(j,t,w);
     }
}
