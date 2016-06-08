#include<iostream>
using namespace std;
#include"x_y.cpp"
#include"r_t.cpp"
int main()
{
   double x1,x2;
   double y1,y2;
   cout <<"enter x and y coordinate of first complex number: ";
   cin >>x1 >>y1 ;
   cout <<" enter x and y coordiates of 2nd complex number: ";
   cin >>x2 >> y2;
   cp cp1,cp2;
   cp1.x=x1;cp2.x=x2;
   cp1.y=y1; cp2.y=y2;
   cp ret_var=add(cp1,cp2);
   cout <<"result of the addition is(in x-y): " <<ret_var.x;
   if(ret_var.y>=0)cout  <<" + " <<ret_var.y <<"i" <<endl;
   else cout <<ret_var.y<<"i" <<endl;
   ret_var=sub(cp1,cp2);
   cout <<"result of the sutraction is(in x-y): " <<ret_var.x ;
   if(ret_var.y>=0)cout  <<" + " <<ret_var.y <<"i" <<endl;
   else cout <<ret_var.y <<"i"<<endl;
   ret_var=mul(cp1,cp2);
   cout <<"result of the multiplication is(in x-y): " <<ret_var.x ;
      if(ret_var.y>=0)cout  <<" + " <<ret_var.y <<"i" <<endl;
   else cout <<ret_var.y <<"i"<<endl;
   ret_var=div(cp1,cp2);
   if(cp2.x==0&& cp2.y==0) {
     cout <<"Division not possible:\n";
     return 0;
    }
   cout <<"result of the division is(in x-y): " <<ret_var.x ;
      if(ret_var.y>=0)cout  <<" + " <<ret_var.y <<"i" <<endl;
   else cout <<ret_var.y <<"i" <<endl;
   
   double r1,t1;
   double r2,t2;
   cout <<"Enter Polar coordinates of first complex number: ";
   cin >>r1 >>t1;
   cout <<"Enter polar coordinates of the second complex number: ";
   cin >> r2 >>t2;
   cprt rt1,rt2;
   rt1.r=r1;
   rt1.t=t1;
   rt2.r=r2;
   rt2.t=t2;
   cprt rt3=add_rt(rt1,rt2);
   cout <<"result of summation: r=" <<rt3.r <<" theta=" <<rt3.t <<endl;
   rt3=sub_rt(rt1,rt2);
   cout <<"result of subtraction: r=" <<rt3.r <<" theta=" <<rt3.t <<endl;
   rt3=mul_rt(rt1,rt2);
   cout <<"result of multiplication: r="<<rt3.r <<" theta=" <<rt3.t <<endl;
   rt3=div_rt(rt1,rt2);
   cout <<"result of division is: r=" <<rt3.r <<" theta=" <<rt3.t <<endl;
   return 0;
}

