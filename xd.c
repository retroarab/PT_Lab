#include <stdio.h>
#include <math.h>

/* Write the program. Ask the user how many shapes need to be provided and*/
#define pi 3.141
float AOT(float A, float B, float C)
{
    float side;
    side=((A+B+C)/2);
    return sqrt(side*(side-A)*(side-B)*(side-C));

}

float AOF(float r)
{
    return(pi*r*r);
}

struct global_shape{
	unsigned int shape_type;
	union {
		struct Circle{
			float center_x, center_y;
			float radius;
            float (*f)(float);
		}c; 
		struct Triangle{
			float x1, x2, x3;
			float y1, y2, y3;
            float (*f)(float, float, float);
		}t;
		struct Square{
			float x1, x2, x3, x4;
			float y1, y2, y3, y4;
		}s;
	}u;

}v[100];

int main(){
	unsigned int n;
	unsigned int aux;
	printf("How many shapes do you want to save? ");
	scanf("%u",&n);
	if(n>100){
		printf("The size is bigger than expected try something smaller than 100\n");
		return -1;	
	}
	printf("\n");
	for(unsigned int i=0;i<n;i++)
	{
		printf("What type of shape you want to save? (0-Circle, 1-Triangle, 2-Square)");
		scanf("%u",&aux);
		printf("%u\n",aux);
		printf("\n");
		if(aux<3)
			v[i].shape_type=aux;
		else{
			printf("The data inserted is not correct\n");
			return -1;
		}
		if(aux==0){
			printf("Please insert the coordinates of the center and the radius (Example '1 1 2'): ");
			if(scanf("%f %f %f", &v[i].u.c.center_x, &v[i].u.c.center_y, &v[i].u.c.radius)==3){
                v[i].u.c.f=AOF;
				printf("\n");
				continue;
			}
			else{
				printf("\nThe format placed is not correct!\n");
				return -1;
			}
		}
		else{
			if(aux==1){
				printf("Please insert the X axis coordinates of the triangle: ");
				if(scanf("%f %f %f",&v[i].u.t.x1,&v[i].u.t.x2,&v[i].u.t.x3)==3){
					printf("\n");
				}
				else{
					printf("\nThe format placed is not correct!\n");
					return -1;
				}
				printf("Please insert the Y axis coordinates of the triangle: ");
				if(scanf("%f %f %f", &v[i].u.t.y1, &v[i].u.t.y2, &v[i].u.t.y3)==3){
					printf("\n");
				}
				else{
					printf("\nThe format placed is not correct!\n");
					return -1;
				}
				continue;
			}
			if(aux==2){
				printf("Please insert the X axis coordinates of the square: ");
				if(scanf("%f %f %f %f", &v[i].u.s.x1, &v[i].u.s.x2, &v[i].u.s.x3, &v[i].u.s.x4)==4){
					printf("\n");	
				}
				else{
					printf("\nThe format placed is not correct!\n");
					return -1;
				}
				printf("Please insert the Y axis coordinates of the square: ");
				if(scanf("%f %f %f %f", &v[i].u.s.y1, &v[i].u.s.y2, &v[i].u.s.y3, &v[i].u.s.y4)==4){
					printf("\n");
				}
				else{
					printf("\nThe format placed is not correct!\n");
					return -1;
				}
				continue;
			}
		}
		
	}
	for(unsigned int i=0;i<n;i++){
		if(v[i].shape_type==0){
			printf("Circle: C%u(%.2f, %.2f) radius %.2f \n and area of %.2f", i+1, v[i].u.c.center_x ,v[i].u.c.center_y, v[i].u.c.radius,v[i].u.c.f(v[i].u.c.radius));
		}
		else if(v[i].shape_type == 1 )
        {
                float A=sqrt(((v[i].u.t.x2-v[i].u.t.x1)*(v[i].u.t.x2-v[i].u.t.x1))+((v[i].u.t.y2-v[i].u.t.y1)*(v[i].u.t.y2-v[i].u.t.y1)));
                float B=sqrt(((v[i].u.t.x3-v[i].u.t.x2)*(v[i].u.t.x3-v[i].u.t.x2))+((v[i].u.t.y3-v[i].u.t.y2)*(v[i].u.t.y3-v[i].u.t.y2)));
                float C=sqrt(((v[i].u.t.x1-v[i].u.t.x3)*(v[i].u.t.x1-v[i].u.t.x3))+((v[i].u.t.y1-v[i].u.t.y2)*(v[i].u.t.y1-v[i].u.t.y3))); 
                v[i].u.t.f=AOT;
                printf("Area is : %.2f",v[i].u.t.f(A,B,C));
        }
        // Same with square easy stuff...
	}
	return 0;
}