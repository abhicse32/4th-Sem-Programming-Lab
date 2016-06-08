#include<cmath>
#include"r_t.h"
cprt add_rt(cprt rt1,cprt rt2)
{
   cprt rt3;
   // calculating the length of the resulting complex number
   rt3.r=sqrt(rt1.r*rt1.r+rt2.r*rt2.r+2*rt1.r*rt2.r*cos(rt1.t-rt2.t));
   double p1,p2,t=0;
   
   // p2 and p1 are the real and complex parts of the resulting complex number respectively
   p1=rt1.r*sin(rt1.t)+rt2.r*sin(rt2.t);
   p2=rt1.r*cos(rt1.t)+rt2.r*cos(rt2.t);
   double pi=atan(1)*4;
   
   // checking if the resulting complex number lies in the IInd quadrant
   if(p1>0 && p2<0)
   t=pi+atan(p1/p2);
   
   //checking for third quatdrant
   else if(p1<0 && p2<0)
   t=-pi+atan(p1/p2);
   else t=atan(p1/p2);
   rt3.t=t;
            return rt3;
}
  
 cprt sub_rt(cprt rt1,cprt rt2)
 { 
 cprt rt3;
   rt3.r=sqrt(rt1.r*rt1.r+rt2.r*rt2.r-2*rt1.r*rt2.r*cos(rt1.t-rt2.t));
   double p1,p2,t=0;
   p1=rt1.r*sin(rt1.t)+rt2.r*sin(rt2.t);
   p2=rt1.r*cos(rt1.t)+rt2.r*cos(rt2.t);
   double pi=atan(1)*4;
   if(p1>0 && p2<0)
   t=pi+atan(p1/p2);
   else if(p1<0 && p2<0)
   t=-pi+atan(p1/p2);
   else t=atan(p1/p2);
   rt3.t=t;
            return rt3;
}
   
 cprt mul_rt(cprt rt1,cprt rt2)
 {
    cprt rt3;
    rt3.r=rt1.r*rt2.r;
    rt3.t=rt1.t+rt2.t;
    return rt3;
 }
 cprt div_rt(cprt rt1,cprt rt2)
 {
   cprt rt3;
    rt3.r=rt1.r/rt2.r;
    rt3.t=rt1.t-rt2.t;
    return rt3;
 }
      
