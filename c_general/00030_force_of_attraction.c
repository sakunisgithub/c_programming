#include<stdio.h>

float force(float);
float m, g = 9.8;

int main(){
    printf("Enter the mass of the body\n");
    scanf("%f", &m);
    printf("The force of attraction exerted by earth on the body of mass %f units is %f units", m, force(m));
    return 0;
}

float force(float m)
{
    return (m*g);
}