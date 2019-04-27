#include<math.h>
#include<string.h>
#include<stdio.h>
#include<conio.h>
#include<graphics.h>
#include<stdlib.h>
#define pi 3.1415
resistance();
int main()
{
int gd=DETECT,gm;
clrscr();
initgraph(&gd,&gm,"C:\\TC\\BGI");
resistance();
getch();
cleardevice();
return 0;
}
resistance()
{
int i,n,Rs=0,res[10],V,F;
float Cs=0,Ls=0,w,freq,Xl,Xc,C[10],L[10],Z;
char r[10], f[10],c[10],v[10],l[10],xl[10],xc[10],z[10];
printf("Enter the voltage and frequency\n");
scanf("%d%d",&V,&F);
printf("Enter the no. of resistances\n");     /*RESISTANCE*/
scanf("%d",&n);
printf("Enter the value of each resistance\n");
for(i=0;i<n;i++)
 {
 printf("\R%d=",i+1);
 scanf("%d",&res[i]);
 }
for(i=0;i<n;i++)
 {
 Rs+=res[i];
 }
clrscr();
cleardevice();
printf("\nEnter the no. of capacitances\n");    /*CAPACITANCE*/
scanf("%d",&n);
printf("Enter the value of each capacitance\n");
for(i=0;i<n;i++)
 {
 printf("\C%d=",i+1);
 scanf("%f",&C[i]);
 }
for(i=0;i<n;i++)
 {
Cs+=1/C[i];
 }
 Cs=1/Cs;
clrscr();
cleardevice();
printf("Enter the no. of inductances\n");       /*INDUCTANCE*/
scanf("%d",&n);
printf("Enter the value of each inductance\n");
for(i=0;i<n;i++)
 {
printf("\L%d=",i+1);
scanf("%f",&L[i]);
 }
for(i=0;i<n;i++)
 {
Ls=L[i]+Ls;
 }
 clrscr();
 cleardevice();
w=2*pi*F;
Xl=w*Ls;
Xc=1/(w*Cs);
 Z=sqrt(pow(Rs,2)+pow((Xl-Xc),2));
line(100,70,100,200);  /*vertical wire #1*/
line(100,200,280,200); /*horizontal wire #1*/
circle(290,200,10);    /*battery*/
line(300,200,480,200); /*horizontal wire #2*/
line(480,70,480,200);  /*vertical wire #2*/
line(100,70,170,70);   /*wire*/
line(170,70,180,60);   /*resistance*/
line(180,60,190,70);   /*resistance*/
line(190,70,200,60);   /*resistance*/
line(200,60,210,70);   /*resistance*/
line(210,70,220,60);   /*resistance*/
line(220,60,230,70);   /*resistance*/
line(230,70,280,70);   /*wire*/
line(280,50,280,90);   /*capacitor*/
line(300,50,300,90);   /*capacitor*/
line(300,70,335,70);   /*inductor loop1*/
arc(350,70,0,180,15);  /*inductor*/
arc(360,70,180,360,5); /*inductor loop2*/
arc(370,70,0,180,15);  /*inductor*/
arc(380,70,180,360,5); /*inductor loop3*/
arc(390,70,0,180,15);  /*inductor*/
arc(400,70,180,360,5);
arc(410,70,0,180,15);
line(425,70,480,70);   /*wire*/
outtextxy(287,200,"~");
sprintf(c,"C=%0.2f F",Cs);
outtextxy(280,35,c);
sprintf(v,"%dV",V);
outtextxy(270,220,v);
sprintf(f,",%dHz",F);
outtextxy(300,220,f);
sprintf(r,"R=%d ohm",Rs);
outtextxy(190,35,r);
sprintf(l,"L=%0.2f H",Ls);
outtextxy(380,35,l);
sprintf(xl,"Xl=%0.3f ohm",Xl);
outtextxy(200,270,xl);
sprintf(xc,"Xc=%0.3f ohm",Xc);
outtextxy(200,280,xc);
sprintf(z,"Z=%0.3f ohm",Z);
outtextxy(200,290,z);
outtextxy(200,250,"Equivalent Circuit Diagram");
return 0;
}
