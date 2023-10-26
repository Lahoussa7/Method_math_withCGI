#include <stdio.h>
#include <stdlib.h>
#include <math.h>


float f(float x){
	 return 4*(x)-1;
 }
float df(float x){
	 return 4;
}
void dichotomie(double a,double b){
		
		double c=0.0;
		double d=2.0;
		double fa,fb,fc;
		float eps = 0.0000001;
	//	printf("<div style=\"border:solid;color:white;\">");
         printf("<table ><tr><th>Methode dichotomie</th></tr>");
		while(fabs(b-a)>eps){
			c=(b+a)/d;
			fa=f(a)-1;
			fb=f(b)-1;
			fc=f(c)-1;
			if(fc*fa<0){
				b=c;
			}
			if(fb*fc<0){
				a=c;
			}
			   
		printf("<tr><td><font color=violet >~~~~~~~~~~~~~~~~~~~~~~~~</font></td></tr><tr><td>dicho = %lf\n</td></tr>",c);
		}
	       printf("</table>");
	       //printf("</div>");
	}
void calcul_daire(float a,float b,float d){
	  float aire=0.0;
	  float s=0.0;
	//  printf("<div style=\"border:solid;color:white;\">");
	  printf("<table ><tr><th>Methode rectangle/trapeze</th></tr>");
	  while((a+d)<b){
		  //aire de rectangle
		  s+=f(a)*d;
		//aire de trapeze

		  aire+=((f(a)+f(a+d))*(d)/2); 

		   a+=d;
		   printf("<tr><td><font color=turquoise >~~~~~~~~~~~~~~~~~~~~~~~~</font></td></tr><tr><td>rect = %lf and trap=%lf\n</td></tr>",s,aire);
      
	        
      }
     printf("</table>");
    // printf("</div>");
 }
 void meth_tang(float a,float b, float d){
	float x=2;
	//printf("<div style=\"border:solid;color:white;\">");
    printf("<table ><tr><th>Methode tangente</th></tr>");
		
	 while(fabs(f(x))>=d){
		x=(x-(f(x)/df(x)));
	    printf("<tr><td><font color=bisque>~~~~~~~~~~~~~~~~~~~~~~~~</font></td></tr><tr><td>dicho = %lf\n</td></tr>",x);
    
	}
	
	//printf("tangente = %f\n",x);
	
 
	printf("</table>");
 }

 void meth_secante (float a,float b, float d){
	 float xn=0.0;
	 float x1 = b,x0 = a;

	     printf("<table ><tr><th>Methode secante</th></tr>");
	 while(fabs(f(x0)-f(x1)) > d){
		xn = x1 -((x1-x0)*f(x1))/(f(x1) - f(x0));
		x0 = x1;
		x1 = xn;
	 
	 
	 printf("<tr><td><font color=gray>~~~~~~~~~~~~~~~~~~~~~~~~</font></td></tr><tr><td>dicho = %lf\n</td></tr>",xn);
     }
	printf("</table>");
	// printf("secante = %f\n",xn); 
 }
 void entrer_intevalle(){
	 printf("<div style=\"display:flex;justify-content:center;\"> les intervalles pour chercher la valeur de x et l'integrale avec une fonction f(x)=0");
     printf("<div style=\"display:flex;justify-content:center;\"><form ACTION=\"http://www.lahoussa.com/cgi-bin/version.cgi\" METHOD=\"GET\">");
     printf("<br>Borne inferieur:<br><input type=\"number\" name=\"num\" class=\"bloc3\">");
     printf("<br>Borne superieur:<br><input type=\"number\" name=\"noum\" class=\"bloc3\"><br>");
     printf(" <input type=\"submit\" class=\"bloc2\"value=\"search\">");
     printf(" </div>");
     printf(" </form>");
    
         
    printf("</div>");
         
   
 }

int main(){
       char*value=getenv("QUERY_STRING");
       printf("Content-type: text/html\n\n");
	   printf("<html lang=\"fr\"><head><meta charset=UTF-8><title>Les methodes de calcule des savants</title></head>");
	   	       printf("<body bgcolor=burlywood >");
           
	  char*recup=malloc(40); 
	  char*recup1=malloc(40);
int N=10000;
	 float a=0;
	 float b=0; 
	 float d=(b+a)/N;
	   sscanf(value,"%*[^=]=%[^&]&%*[^=]=%[^&]&",recup,recup1);
	    a=atof(recup);
	    b=atof(recup1);
        entrer_intevalle();
        
        printf("<H1>%sand %s</H1>",recup,recup1);
        printf("<div style=\"border:solid;color:white;\">");
        printf("<div style=\"display:flex;justify-content:space-between;\">");
	    dichotomie(a,b);
	     meth_tang( a, b, d);	
	     meth_secante(a,b,d);
	     calcul_daire(a, b, d);
	     printf("</div>");
	     printf("</div>");
      	       printf("</body>");
      	       printf("</html>");
           
           
	 return 0;
}
