 #include <assert.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

float mc_pi(int);

float frandom() {
  long int q = random();
  float ret = (float)q/(float)RAND_MAX;
  return ret;
}

float mc_pi(int n)
{  
  float x,y,pie,z;
  int count=0;
  for(int i=0;i<n;i++)
   {
      x=frandom();
     
      y=frandom();
      
      z=x*x+y*y;
    
      if(z<=1)
        count++;
     }
   pie=(float)count/n*4.0;
   
   return pie;
 }  
   
int main(void) {
  float pi0;
  float pi1;
  
  pi0 = mc_pi(25000);
  pi1 = mc_pi(25000);
  printf("%f %f\n", pi0, pi1);
  
  if (pi0 == pi1) {
      printf("Two separate estimates of pi are exactly the same. This is unlikely.\n");
      abort();
    }

  if (fabs(pi0 - pi1) > 0.05) {
      printf("Two separate estima…
[12:54 PM, 6/4/2021] Yash Nitc: monte carlo vala
[12:54 PM, 6/4/2021] Yash Nitc: #include <assert.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

float wallis_pi(int n);

int main(void) {
  float pi;
  for (int i=0; i<5; i++) {
    pi = wallis_pi(i);
    if (!(fabs(pi - M_PI) > 0.15)) {
      printf("Estimate with just %d iterations is %f which is too accurate.\n", i, pi);
      abort();
    }
  }

  for (int i=500; i<3000; i++) {
    pi = wallis_pi(i);
    if (!(fabs(pi - M_PI) < 0.01)) {
      printf("Estimate with even %d iterations is %f which is not accurate enough.\n", i, pi);
      abort();
    }
  }
}

float wallis_pi(int n)
{
 float pie=1.0;
 float num;
 for(int i=1;i<n;i++)
 {
   num=4.0*i*i;
   pie=pie*num/(num-1.0);
 }
   pie=pie*2.0;
   return pie;
}

