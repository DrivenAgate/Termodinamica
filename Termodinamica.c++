#include <stdio.h>
#include <iostream>
#include <stdio.h>
#include <math.h>

int main(){
	system("color 0B");
	int op2,op, u, w;
	do{
		float j=3 , k=7, l=101.325, R, T, Tb, Tc, Tr, Pc, P, b, a, B, A, teta, fomega, omega, Fc0, Fc1, Fc2, Fc3, Pc2, Pm, Fs0, Fs1, Fs2, Fs3;
		double z1, z2, z3, margen1, margen2, margen3;
    	int i=1;
		printf("\n\t%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c"
		,201,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,
		205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,187);
		printf("\n\t%c             TERMODINAMICA		 %c",186,186);
		printf("\n\t%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c"
		,200,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,
		205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,188);
		printf("\n\n\n1.- ECUACION VAN DER WAALS");
		printf("\n2.- ECUACION REDLICH-KWONG");
		printf("\n3.- ECUACION SOAVE");
		printf("\n4.- ECUACION PENG-ROBINSON");
		printf("\n5.- SALIR");
		printf("\n\nINGRESE LA OPCION: ");
		scanf("%i",&op);
		system("cls");
		switch(op){
			case 1:
				do{
				u=0;
				w=0;
				printf("\n\n\t                   *****SELECIONO ECUACION VAN DER WAALS*****");
				printf("\n\nSELECCIONA UNA OPCION");
				printf("\n\n1.- INICIAR");
				printf("\n2.- MENU PRINCIPAL");
				printf("\n\nINGRESA LA OPCION: ");
				scanf("%i",&op2);
				system("cls");
					switch(op2){
						case 1:
							system("cls");
							printf("\n\n\t                   *****ECUACION VAN DER WAALS*****");
							printf("\n\nDame el valor de R: ");
							scanf("%f",&R);
							printf("\nDame el valor de Tc: ");
							scanf("%f",&Tc);
							printf("\nDame el valor de Pc: ");
							scanf("%f",&Pc);
							
							//FORMULAS a y b
							a=((pow(R,2)*pow(Tc,2))/Pc)*0.421875;
							b=(R*Tc)/(8*Pc);
							
							printf("\nEl valor de a = %0.5f",a);
							printf("\nEl valor de b = %0.5f",b);
							
							printf("\n\n\t Calculando Factor de Comprensibilidad");
							printf("\n\nDame el valor de P: ");
							scanf("%f",&P);
							printf("\nDame el valor de T: ");
							scanf("%f",&T);
							
							//FORMULAS A y B
							A= (a*P)/(pow(R,2)*pow(T,2));
							B= (b*P)/(R*T);
							
							printf("\nEl valor de A = %0.5f",A);
							printf("\nEl valor de B = %0.5f",B);
							printf("\n\n");
	
							//FORMULAS PARA Z
							
							Fc3= 0;
					/*ax^2*/Fc2= -1*(1+B-u*B);
					/*bx*/	Fc1= A + w*pow(B,2) - u*B - u*pow(B,2);
					/*C*/	Fc0= -1*A*B - w*pow(B,2) - w*pow(B,3);
					
							Fs3= 0;
							Fs2= (1+B-u*B);
							Fs1= A + w*pow(B,2) - u*B - u*pow(B,2);
							Fs0= A*B - w*pow(B,2) - w*pow(B,3);
							
							//COMPARACION PARA IMPRESION DE LOS VALORES DE LA ECUACION
							printf("ECUACION GENERAL\n");
							if(Fc2<=0){
								printf("Z^3 %f",Fc2);
							}
							else{
								printf("Z^3 + %f",Fc2);
							}
							
							if(Fc1>=0){
								printf("Z^2 + %f",Fc1);
							}
							else{
								printf("Z^2 %f",Fc1);
							}
							
							if(Fc0<=0){
								printf("Z %f\n",Fc0);
							}
							else{
								printf("Z + %f\n",Fc0);
							}
							
							//FORMULA GENERAL PARA RESOLUCION DE UNA ECUACION DE TERCER GRADO
							z1 = -Fc2/3 + cbrt(-2*pow(Fc2,3) +9*Fc2*Fc1 -27*Fc0 + sqrt(pow(2*pow(Fc2,3) -9*Fc2*Fc1 +27*Fc0,2) + 4*pow(-pow(Fc2,2) +3*Fc1,3)) / 54) +
							cbrt(-2*pow(Fc2,3) +9*Fc2*Fc1 -27*Fc0 - sqrt(pow(2*pow(Fc2,3) -9*Fc2*Fc1 +27*Fc0,2) + 4*pow(-pow(Fc2,2) +3*Fc1,3)) / 54);
							
							z2 = -Fc2/3 - (1+sqrt(3)/2)*cbrt(-2*pow(Fc2,3) +9*Fc2*Fc1 -27*Fc0 + sqrt(pow(2*pow(Fc2,3) -9*Fc2*Fc1 +27*Fc0,2) + 4*pow(-pow(Fc2,2) +3*Fc1,3)) / 54) +
							(-1+sqrt(3)/2)*cbrt(-2*pow(Fc2,3) +9*Fc2*Fc1 -27*Fc0 - sqrt(pow(2*pow(Fc2,3) -9*Fc2*Fc1 +27*Fc0,2) + 4*pow(-pow(Fc2,2) +3*Fc1,3)) / 54);
							
							z3 = -Fc2/3 + (-1+sqrt(3)/2)*cbrt(-2*pow(Fc2,3) +9*Fc2*Fc1 -27*Fc0 + sqrt(pow(2*pow(Fc2,3) -9*Fc2*Fc1 +27*Fc0,2) + 4*pow(-pow(Fc2,2) +3*Fc1,3)) / 54) -
							(1+sqrt(3)/2)*cbrt(-2*pow(Fc2,3) +9*Fc2*Fc1 -27*Fc0 - sqrt(pow(2*pow(Fc2,3) -9*Fc2*Fc1 +27*Fc0,2) + 4*pow(-pow(Fc2,2) +3*Fc1,3)) / 54);
							
							z1 = 2;
							z2 = -2;
							z3 = -2;
							//EVALUACION Z1
							margen1 = pow(z1,3) - Fs2*pow(z1,2) + Fs1*z1 - Fs0;
							if(margen1>=1){
								do{
								margen1 = pow(z1,3) - Fs2*pow(z1,2) + Fs1*z1 - Fs0;
								z1 = z1-0.0000001;
								}while(margen1>=0.00000099);
							}
							else{
								do{
								margen1 = pow(z1,3) - Fs2*pow(z1,2) + Fs1*z1 - Fs0;
								z1 = z1+0.0000001;
								}while(margen1<=0.00000099);	
							}
							
							//EVALUACION Z2
							margen2 = pow(z2,3) - Fs2*pow(z2,2) + Fs1*z2 - Fs0;
							if(margen2>=1){
								do{
								margen2 = pow(z2,3) - Fs2*pow(z2,2) + Fs1*z2 - Fs0;
								z2 = z2-0.0000001;
								}while(margen2>=0.00000099);
							}
							else{
								do{
								margen2 = pow(z2,3) - Fs2*pow(z2,2) + Fs1*z2 - Fs0;
								z2 = z2+0.0000001;
								}while(margen2<=0.00000099);	
							}
							
							//EVALUACION Z3
							margen3 = pow(z3,3) - Fs2*pow(z3,2) + Fs1*z3 - Fs0;
							if(margen3>=1){
								do{
								margen3 = pow(z3,3) - Fs2*pow(z3,2) + Fs1*z3 - Fs0;
								z3 = z3-0.0000001;
								}while(margen3>=0.00000099);	
							}
							else{
								do{
								margen3 = pow(z3,3) - Fs2*pow(z3,2) + Fs1*z3 - Fs0;
								z3 = z3+0.0000001;
								}while(margen3<=0.00000099);	
							}
										
							printf("\n");
							printf("Z1 = %0.6lf\n",z1);
							printf("Z2 = %0.6lf\n",z2);
							printf("Z3 = %0.6lf\n",z3);
							printf("Resultado evaluado con Z1 = %0.6lf\n",margen1);
							printf("Resultado evaluado con Z2 = %0.6lf\n",margen2);
							printf("Resultado evaluado con Z3 = %0.6lf",margen3);
											
							printf("\n\n");
							system("PAUSE");
							system("cls");
							break;
						case 2:
							printf("\n\n\tREGRESANDO AL MENU PRINCIPAL");
							break;
						default:
							printf("\n\n\tLA OPCION ES INVALIDA");
							break;
					}
				}while(op2!=2);
				system("cls");
				break;
			case 2:
				do{
					u=1;
					w=0;
					printf("\n\n\t                   *****SELECIONO ECUACION REDLICH KWONG*****");
					printf("\n\nSELECCIONA UNA OPCION");
					printf("\n\n1.- INICIAR");
					printf("\n2.- MENU PRINCIPAL");
					printf("\n\nINGRESA LA OPCION: ");
					scanf("%i",&op2);
					system("cls");
					switch(op2){
						case 1:
							system("cls");
							printf("\n\n\t                   *****ECUACION REDLICH KWONG*****");
							printf("\n\nDame el valor de R: ");
							scanf("%f",&R);
							printf("\nDame el valor de Tc: ");
							scanf("%f",&Tc);
							printf("\nDame el valor de T: ");
							scanf("%f",&T);
							printf("\nDame el valor de Pc: ");
							scanf("%f",&Pc);
							
							a= (0.42748*pow(R,2)*pow(Tc,2.5))/(Pc*sqrt(T));
							b= (0.08664*R*Tc)/(Pc);
							
							printf("\nEl valor de a = %0.5f",a);
							printf("\nEl valor de b = %0.5f",b);
							
							printf("\n\n\t Calculando Factor de Comprensibilidad");
							printf("\n\nDame el valor de P: ");
							scanf("%f",&P);
							
							A= (a*P)/(pow(R,2)*pow(T,2));
							B= (b*P)/(R*T);
							
							printf("\nEl valor de A = %0.5f",A);
							printf("\nEl valor de B = %0.5f",B);
							printf("\n\n");
							
							//FORMULAS PARA Z
							Fc3= 0;
							Fc2= -1*(1+B-u*B);
							Fc1= A + w*pow(B,2) - u*B - u*pow(B,2);
							Fc0= -1*A*B - w*pow(B,2) - w*pow(B,3);
							
							Fs3= 0;
							Fs2= (1+B-u*B);
							Fs1= A + w*pow(B,2) - u*B - u*pow(B,2);
							Fs0= A*B - w*pow(B,2) - w*pow(B,3);
							
							//COMPARACION PARA IMPRESION DE LOS VALORES DE LA ECUACION
							printf("ECUACION GENERAL\n");
							if(Fc2<=0){
								printf("Z^3 %f",Fc2);
							}
							else{
								printf("Z^3 + %f",Fc2);
							}
							
							if(Fc1>=0){
								printf("Z^2 + %f",Fc1);
							}
							else{
								printf("Z^2 %f",Fc1);
							}
							
							if(Fc0<=0){
								printf("Z %f\n",Fc0);
							}
							else{
								printf("Z + %f\n",Fc0);
							}
							
							//FORMULA GENERAL PARA RESOLUCION DE UNA ECUACION DE TERCER GRADO
							z1 = -Fc2/3 + cbrt(-2*pow(Fc2,3) +9*Fc2*Fc1 -27*Fc0 + sqrt(pow(2*pow(Fc2,3) -9*Fc2*Fc1 +27*Fc0,2) + 4*pow(-pow(Fc2,2) +3*Fc1,3)) / 54) +
							cbrt(-2*pow(Fc2,3) +9*Fc2*Fc1 -27*Fc0 - sqrt(pow(2*pow(Fc2,3) -9*Fc2*Fc1 +27*Fc0,2) + 4*pow(-pow(Fc2,2) +3*Fc1,3)) / 54);
							
							z2 = -Fc2/3 - (1+sqrt(3)/2)*cbrt(-2*pow(Fc2,3) +9*Fc2*Fc1 -27*Fc0 + sqrt(pow(2*pow(Fc2,3) -9*Fc2*Fc1 +27*Fc0,2) + 4*pow(-pow(Fc2,2) +3*Fc1,3)) / 54) +
							(-1+sqrt(3)/2)*cbrt(-2*pow(Fc2,3) +9*Fc2*Fc1 -27*Fc0 - sqrt(pow(2*pow(Fc2,3) -9*Fc2*Fc1 +27*Fc0,2) + 4*pow(-pow(Fc2,2) +3*Fc1,3)) / 54);
							
							z3 = -Fc2/3 + (-1+sqrt(3)/2)*cbrt(-2*pow(Fc2,3) +9*Fc2*Fc1 -27*Fc0 + sqrt(pow(2*pow(Fc2,3) -9*Fc2*Fc1 +27*Fc0,2) + 4*pow(-pow(Fc2,2) +3*Fc1,3)) / 54) -
							(1+sqrt(3)/2)*cbrt(-2*pow(Fc2,3) +9*Fc2*Fc1 -27*Fc0 - sqrt(pow(2*pow(Fc2,3) -9*Fc2*Fc1 +27*Fc0,2) + 4*pow(-pow(Fc2,2) +3*Fc1,3)) / 54);
							
							z1 = 2;
							z2 = -2;
							z3 = -2;
							//EVALUACION Z1
							margen1 = pow(z1,3) - Fs2*pow(z1,2) + Fs1*z1 - Fs0;
							if(margen1>=1){
								do{
								margen1 = pow(z1,3) - Fs2*pow(z1,2) + Fs1*z1 - Fs0;
								z1 = z1-0.0000001;
								}while(margen1>=0.00000099);
							}
							else{
								do{
								margen1 = pow(z1,3) - Fs2*pow(z1,2) + Fs1*z1 - Fs0;
								z1 = z1+0.0000001;
								}while(margen1<=0.00000099);	
							}
							
							//EVALUACION Z2
							margen2 = pow(z2,3) - Fs2*pow(z2,2) + Fs1*z2 - Fs0;
							if(margen2>=1){
								do{
								margen2 = pow(z2,3) - Fs2*pow(z2,2) + Fs1*z2 - Fs0;
								z2 = z2-0.0000001;
								}while(margen2>=0.00000099);
							}
							else{
								do{
								margen2 = pow(z2,3) - Fs2*pow(z2,2) + Fs1*z2 - Fs0;
								z2 = z2+0.0000001;
								}while(margen2<=0.00000099);	
							}
							
							//EVALUACION Z3
							margen3 = pow(z3,3) - Fs2*pow(z3,2) + Fs1*z3 - Fs0;
							if(margen3>=1){
								do{
								margen3 = pow(z3,3) - Fs2*pow(z3,2) + Fs1*z3 - Fs0;
								z3 = z3-0.0000001;
								}while(margen3>=0.00000099);	
							}
							else{
								do{
								margen3 = pow(z3,3) - Fs2*pow(z3,2) + Fs1*z3 - Fs0;
								z3 = z3+0.0000001;
								}while(margen3<=0.00000099);	
							}
										
							printf("\n");
							printf("Z1 = %0.6lf\n",z1);
							printf("Z2 = %0.6lf\n",z2);
							printf("Z3 = %0.6lf\n",z3);
							printf("Resultado evaluado con Z1 = %0.6lf\n",margen1);
							printf("Resultado evaluado con Z2 = %0.6lf\n",margen2);
							printf("Resultado evaluado con Z3 = %0.6lf",margen3);
							
							printf("\n\n");
							system("PAUSE");
							system("cls");
							break;
						case 2:
							printf("\n\n\tREGRESANDO AL MENU PRINCIPAL");
							break;
						default:
							printf("\n\n\tLA OPCION ES INVALIDA");
							break;
					}
				}while(op2!=2);
				system("cls");
				break;
			case 3:
				do{
					u=1;
					w=0;
					printf("\n\n\t                   *****SELECIONO ECUACION SOAVE*****");
					printf("\n\nSELECCIONA UNA OPCION");
					printf("\n\n1.- INICIAR");
					printf("\n2.- MENU PRINCIPAL");
					printf("\n\nINGRESA LA OPCION: ");
					scanf("%i",&op2);
					system("cls");
					switch(op2){
						case 1:
							system("cls");
							printf("\n\n\t                   *****ECUACION SOAVE*****");
							printf("\n\nDame el valor de R: ");
							scanf("%f",&R);
							printf("\nDame el valor de T: ");
							scanf("%f",&T);
							printf("\nDame el valor de Tc: ");
							scanf("%f",&Tc);
							printf("\nDame el valor de Pc: ");
							scanf("%f",&Pc);
							printf("\nDame el valor de Pm: ");
							scanf("%f",&Pm);
							
							//Tb= (-1*Tc + 50.2 + 0.16*Pm) / 1.41;
							Tb= (Tc - 50.2 + 0.16*Pm) / 1.41;
							teta= Tb/Tc;
							Tr= T/Tc;
							Pc2= Pc/l;
							omega = ((0.428571*(teta/(1-teta)))*(log10(Pc2))) - 1;
							fomega = 0.48+(1.574*omega)-(0.176*pow(omega,2));
							a= ((0.42748*pow(R,2)*pow(Tc,2))/Pc)*pow(1+fomega*(1-sqrt(Tr)),2);
							b= (0.08664*R*Tc)/(Pc);
							
							printf("\nEl valor de omega = %0.5f",omega);
							printf("\nEl valor de Fomega = %0.5f",fomega);
							printf("\nEl valor de Tb = %0.5f",Tb);
							printf("\nEl valor de a = %0.5f",a);
							printf("\nEl valor de b = %0.5f",b);
							
							printf("\n\n\t Calculando Factor de Comprensibilidad");
							printf("\n\nDame el valor de P: ");
							scanf("%f",&P);
							
							A= (a*P)/(pow(R,2)*pow(T,2));
							B= (b*P)/(R*T);
							
							printf("\nEl valor de A = %0.5f",A);
							printf("\nEl valor de B = %0.5f",B);
							printf("\n\n");
					
							//FORMULAS PARA Z
							Fc3= 0;
							Fc2= -1*(1+B-u*B);
							Fc1= A + w*pow(B,2) - u*B - u*pow(B,2);
							Fc0= -1*A*B - w*pow(B,2) - w*pow(B,3);
							
							Fs3= 0;
							Fs2= (1+B-u*B);
							Fs1= A + w*pow(B,2) - u*B - u*pow(B,2);
							Fs0= A*B - w*pow(B,2) - w*pow(B,3);
							
							//COMPARACION PARA IMPRESION DE LOS VALORES DE LA ECUACION
							printf("ECUACION GENERAL\n");
							if(Fc2<=0){
								printf("Z^3 %f",Fc2);
							}
							else{
								printf("Z^3 + %f",Fc2);
							}
							
							if(Fc1>=0){
								printf("Z^2 + %f",Fc1);
							}
							else{
								printf("Z^2 %f",Fc1);
							}
							
							if(Fc0<=0){
								printf("Z %f\n",Fc0);
							}
							else{
								printf("Z + %f\n",Fc0);
							}
							
							//FORMULA GENERAL PARA RESOLUCION DE UNA ECUACION DE TERCER GRADO
							z1 = -Fc2/3 + cbrt(-2*pow(Fc2,3) +9*Fc2*Fc1 -27*Fc0 + sqrt(pow(2*pow(Fc2,3) -9*Fc2*Fc1 +27*Fc0,2) + 4*pow(-pow(Fc2,2) +3*Fc1,3)) / 54) +
							cbrt(-2*pow(Fc2,3) +9*Fc2*Fc1 -27*Fc0 - sqrt(pow(2*pow(Fc2,3) -9*Fc2*Fc1 +27*Fc0,2) + 4*pow(-pow(Fc2,2) +3*Fc1,3)) / 54);
							
							z2 = -Fc2/3 - (1+sqrt(3)/2)*cbrt(-2*pow(Fc2,3) +9*Fc2*Fc1 -27*Fc0 + sqrt(pow(2*pow(Fc2,3) -9*Fc2*Fc1 +27*Fc0,2) + 4*pow(-pow(Fc2,2) +3*Fc1,3)) / 54) +
							(-1+sqrt(3)/2)*cbrt(-2*pow(Fc2,3) +9*Fc2*Fc1 -27*Fc0 - sqrt(pow(2*pow(Fc2,3) -9*Fc2*Fc1 +27*Fc0,2) + 4*pow(-pow(Fc2,2) +3*Fc1,3)) / 54);
							
							z3 = -Fc2/3 + (-1+sqrt(3)/2)*cbrt(-2*pow(Fc2,3) +9*Fc2*Fc1 -27*Fc0 + sqrt(pow(2*pow(Fc2,3) -9*Fc2*Fc1 +27*Fc0,2) + 4*pow(-pow(Fc2,2) +3*Fc1,3)) / 54) -
							(1+sqrt(3)/2)*cbrt(-2*pow(Fc2,3) +9*Fc2*Fc1 -27*Fc0 - sqrt(pow(2*pow(Fc2,3) -9*Fc2*Fc1 +27*Fc0,2) + 4*pow(-pow(Fc2,2) +3*Fc1,3)) / 54);
							
							z1 = 2;
							z2 = -2;
							z3 = -2;
							//EVALUACION Z1
							margen1 = pow(z1,3) - Fs2*pow(z1,2) + Fs1*z1 - Fs0;
							if(margen1>=1){
								do{
								margen1 = pow(z1,3) - Fs2*pow(z1,2) + Fs1*z1 - Fs0;
								z1 = z1-0.0000001;
								}while(margen1>=0.00000099);
							}
							else{
								do{
								margen1 = pow(z1,3) - Fs2*pow(z1,2) + Fs1*z1 - Fs0;
								z1 = z1+0.0000001;
								}while(margen1<=0.00000099);	
							}
							
							//EVALUACION Z2
							margen2 = pow(z2,3) - Fs2*pow(z2,2) + Fs1*z2 - Fs0;
							if(margen2>=1){
								do{
								margen2 = pow(z2,3) - Fs2*pow(z2,2) + Fs1*z2 - Fs0;
								z2 = z2-0.0000001;
								}while(margen2>=0.00000099);
							}
							else{
								do{
								margen2 = pow(z2,3) - Fs2*pow(z2,2) + Fs1*z2 - Fs0;
								z2 = z2+0.0000001;
								}while(margen2<=0.00000099);	
							}
							
							//EVALUACION Z3
							margen3 = pow(z3,3) - Fs2*pow(z3,2) + Fs1*z3 - Fs0;
							if(margen3>=1){
								do{
								margen3 = pow(z3,3) - Fs2*pow(z3,2) + Fs1*z3 - Fs0;
								z3 = z3-0.0000001;
								}while(margen3>=0.00000099);	
							}
							else{
								do{
								margen3 = pow(z3,3) - Fs2*pow(z3,2) + Fs1*z3 - Fs0;
								z3 = z3+0.0000001;
								}while(margen3<=0.00000099);	
							}
										
							printf("\n");
							printf("Z1 = %0.6lf\n",z1);
							printf("Z2 = %0.6lf\n",z2);
							printf("Z3 = %0.6lf\n",z3);
							printf("Resultado evaluado con Z1 = %0.6lf\n",margen1);
							printf("Resultado evaluado con Z2 = %0.6lf\n",margen2);
							printf("Resultado evaluado con Z3 = %0.6lf",margen3);
							
							printf("\n\n");
							system("PAUSE");
							system("cls");
							break;
						case 2:
							printf("\n\n\tREGRESANDO AL MENU PRINCIPAL");
							break;
						default:
							printf("\n\n\tLA OPCION ES INVALIDA");
							break;
					}
				}while(op2!=2);
				system("cls");
				break;
				case 4:
				do{
					u=2;
					w=-1;
					printf("\n\n\t                   *****SELECIONO ECUACION PENG-ROBINSON*****");
					printf("\n\nSELECCIONA UNA OPCION");
					printf("\n\n1.- INICIAR");
					printf("\n2.- MENU PRINCIPAL");
					printf("\n\nINGRESA LA OPCION: ");
					scanf("%i",&op2);
					system("cls");
					switch(op2){
						case 1:
							system("cls");
							printf("\n\n\t                   *****ECUACION PENG-ROBINSON*****");
							printf("\n\nDame el valor de R: ");
							scanf("%f",&R);
							printf("\nDame el valor de T: ");
							scanf("%f",&T);
							printf("\nDame el valor de Tc: ");
							scanf("%f",&Tc);
							printf("\nDame el valor de Pc: ");
							scanf("%f",&Pc);
							printf("\nDame el valor de Pm: ");
							scanf("%f",&Pm);
							
							
							//Tb= (-1*Tc + 50.2 + 0.16*Pm) / 1.41
							Tb= (Tc - 50.2+ 0.16*Pm) / 1.41;
							teta= Tb/Tc;
							Tr= T/Tc;
							Pc2= Pc/l;
							omega= (((j/k)*(teta/(1-teta)))*(log10(Pc2))) - 1;
							fomega= 0.37464 + (1.54226*omega) - (0.26992*pow(omega,2));
							a=((0.45724*pow(R,2)*pow(Tc,2))/Pc)*pow(1+fomega*(1-sqrt(Tr)),2);
							b=(0.07780*R*Tc)/Pc;
							
							printf("\nEl valor de omega = %0.5f",omega);
							printf("\nEl valor de Fomega = %0.5f",fomega);
							printf("\nEl valor de Tb = %0.5f",Tb);
							printf("\nEl valor de a = %0.5f",a);
							printf("\nEl valor de b = %0.5f",b);
							
							printf("\n\n\t Calculando Factor de Comprensibilidad");
							printf("\n\nDame el valor de P: ");
							scanf("%f",&P);
							
							A= (a*P)/(pow(R,2)*pow(T,2));
							B= (b*P)/(R*T);
							
							printf("\nEl valor de A = %0.5f",A);
							printf("\nEl valor de B = %0.5f",B);
							printf("\n\n");
		
							//FORMULAS PARA Z
							Fc3= 0;
							Fc2= -1*(1+B-u*B);
							Fc1= A + w*pow(B,2) - u*B - u*pow(B,2);
							Fc0= -1*A*B - w*pow(B,2) - w*pow(B,3);
							
							Fs3= 0;
							Fs2= (1+B-u*B);
							Fs1= A + w*pow(B,2) - u*B - u*pow(B,2);
							Fs0= A*B - w*pow(B,2) - w*pow(B,3);
							
							//COMPARACION PARA IMPRESION DE LOS VALORES DE LA ECUACION
							printf("ECUACION GENERAL\n");
							if(Fc2<=0){
								printf("Z^3 %f",Fc2);
							}
							else{
								printf("Z^3 + %f",Fc2);
							}
							
							if(Fc1>=0){
								printf("Z^2 + %f",Fc1);
							}
							else{
								printf("Z^2 %f",Fc1);
							}
							
							if(Fc0<=0){
								printf("Z %f\n",Fc0);
							}
							else{
								printf("Z + %f\n",Fc0);
							}
							
							//FORMULA GENERAL PARA RESOLUCION DE UNA ECUACION DE TERCER GRADO
							z1 = -Fc2/3 + cbrt(-2*pow(Fc2,3) +9*Fc2*Fc1 -27*Fc0 + sqrt(pow(2*pow(Fc2,3) -9*Fc2*Fc1 +27*Fc0,2) + 4*pow(-pow(Fc2,2) +3*Fc1,3)) / 54) +
							cbrt(-2*pow(Fc2,3) +9*Fc2*Fc1 -27*Fc0 - sqrt(pow(2*pow(Fc2,3) -9*Fc2*Fc1 +27*Fc0,2) + 4*pow(-pow(Fc2,2) +3*Fc1,3)) / 54);
							
							z2 = -Fc2/3 - (1+sqrt(3)/2)*cbrt(-2*pow(Fc2,3) +9*Fc2*Fc1 -27*Fc0 + sqrt(pow(2*pow(Fc2,3) -9*Fc2*Fc1 +27*Fc0,2) + 4*pow(-pow(Fc2,2) +3*Fc1,3)) / 54) +
							(-1+sqrt(3)/2)*cbrt(-2*pow(Fc2,3) +9*Fc2*Fc1 -27*Fc0 - sqrt(pow(2*pow(Fc2,3) -9*Fc2*Fc1 +27*Fc0,2) + 4*pow(-pow(Fc2,2) +3*Fc1,3)) / 54);
							
							z3 = -Fc2/3 + (-1+sqrt(3)/2)*cbrt(-2*pow(Fc2,3) +9*Fc2*Fc1 -27*Fc0 + sqrt(pow(2*pow(Fc2,3) -9*Fc2*Fc1 +27*Fc0,2) + 4*pow(-pow(Fc2,2) +3*Fc1,3)) / 54) -
							(1+sqrt(3)/2)*cbrt(-2*pow(Fc2,3) +9*Fc2*Fc1 -27*Fc0 - sqrt(pow(2*pow(Fc2,3) -9*Fc2*Fc1 +27*Fc0,2) + 4*pow(-pow(Fc2,2) +3*Fc1,3)) / 54);
							
							z1 = 2;
							z2 = -2;
							z3 = -2;
							//EVALUACION Z1
							margen1 = pow(z1,3) - Fs2*pow(z1,2) + Fs1*z1 - Fs0;
							if(margen1>=1){
								do{
								margen1 = pow(z1,3) - Fs2*pow(z1,2) + Fs1*z1 - Fs0;
								z1 = z1-0.0000001;
								}while(margen1>=0.00000099);
							}
							else{
								do{
								margen1 = pow(z1,3) - Fs2*pow(z1,2) + Fs1*z1 - Fs0;
								z1 = z1+0.0000001;
								}while(margen1<=0.00000099);	
							}
							
							//EVALUACION Z2
							margen2 = pow(z2,3) - Fs2*pow(z2,2) + Fs1*z2 - Fs0;
							if(margen2>=1){
								do{
								margen2 = pow(z2,3) - Fs2*pow(z2,2) + Fs1*z2 - Fs0;
								z2 = z2-0.0000001;
								}while(margen2>=0.00000099);
							}
							else{
								do{
								margen2 = pow(z2,3) - Fs2*pow(z2,2) + Fs1*z2 - Fs0;
								z2 = z2+0.0000001;
								}while(margen2<=0.00000099);	
							}
							
							//EVALUACION Z3
							margen3 = pow(z3,3) - Fs2*pow(z3,2) + Fs1*z3 - Fs0;
							if(margen3>=1){
								do{
								margen3 = pow(z3,3) - Fs2*pow(z3,2) + Fs1*z3 - Fs0;
								z3 = z3-0.0000001;
								}while(margen3>=0.00000099);	
							}
							else{
								do{
								margen3 = pow(z3,3) - Fs2*pow(z3,2) + Fs1*z3 - Fs0;
								z3 = z3+0.0000001;
								}while(margen3<=0.00000099);	
							}		
							
							printf("\n");
							printf("Z1 = %0.6lf\n",z1);
							printf("Z2 = %0.6lf\n",z2);
							printf("Z3 = %0.6lf\n",z3);
							printf("Resultado evaluado con Z1 = %0.6lf\n",margen1);
							printf("Resultado evaluado con Z2 = %0.6lf\n",margen2);
							printf("Resultado evaluado con Z3 = %0.6lf",margen3);
							
							printf("\n\n");
							system("PAUSE");
							system("cls");
							break;
						case 2:
							printf("\n\n\tREGRESANDO AL MENU PRINCIPAL");
							break;
						default:
							printf("\n\n\tLA OPCION ES INVALIDA");
							break;
					}
				}while(op2!=2);
				system("cls");
				break;
			case 5:
				printf("\n\nSALIENDO CON EXITO");
				break;
			case 666:
				system("cls");
				printf("\n\nVIVA AMLO\n");
				printf("POWER BY TKQCUMPANY\n\n");
				system("pause");
				system("cls");
				break;
			default:
				printf("\n\nLA OPCION ES INVALIDAD");
				printf("\n\n");
				system("pause");
				system("cls");
				break;
		}		
	}while(op!=5);
	printf("\n\n");
	system("pause");
	
	return 0;
}