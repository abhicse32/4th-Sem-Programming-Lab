#include"x_y.h"
#include<iostream>
 
   cp add(cp cmp1,cp cmp2)
   {
   
      cp cmp_loc;
      cmp_loc.x=cmp1.x+cmp2.x;
      cmp_loc.y=cmp2.y+cmp1.y;
      return cmp_loc;   
   }
   cp sub(cp cmp1, cp cmp2)
   {
      cp cmp_loc;
      cmp_loc.x=cmp1.x-cmp2.x;
      cmp_loc.y=cmp1.y-cmp2.y;
      return cmp_loc; 
   }
   
   cp mul(cp cmp1, cp cmp2)
   {
      cp cmp_loc;
      cmp_loc.x=cmp1.x*cmp2.x-cmp1.y*cmp2.y;
      cmp_loc.y=cmp1.x*cmp2.y+cmp2.x*cmp1.y;
      return cmp_loc;
   }
   
   cp div(cp cmp1, cp cmp2)
   {
      cp cmp_loc;
      double var;
      if(cmp2.x!=0 ||cmp2.y!=0)
      {
         cmp2.y= -1*cmp2.y;
         cmp_loc=mul(cmp1,cmp2);
         var=cmp2.x*cmp2.x+cmp2.y*cmp2.y;
         cmp_loc.x/=var;
         cmp_loc.y/=var;
      }
      return cmp_loc;
    }
