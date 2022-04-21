/*
*author:Technician13
*date:2020.4.10
*/
#include"QuadrupedInverseKinematic.h"
#include<iostream>
#include<cmath>

QuadrupedInverseKinematic::QuadrupedInverseKinematic()
{
    std::cout<<"Please input parameters:";
    std::cout<<std::endl<<"X-axis:  ";
    std::cin>>pos_x;

    std::cout<<std::endl<<"Y-axis:  ";
    std::cin>>pos_y;

    std::cout<<std::endl<<"Z-axis:  ";
    std::cin>>pos_z;

    std::cout<<std::endl<<"The length of the first link:  ";
    std::cin>>h;

    std::cout<<std::endl<<"The length of the second link:  ";
    std::cin>>hu;

    std::cout<<std::endl<<"The length of the third link:  ";
    std::cin>>hl;
}

QuadrupedInverseKinematic::~QuadrupedInverseKinematic()
{
    std::cout<<"The result is:  "<<std::endl
             <<"LEFT:"<<std::endl
             <<"The first joint angle rotation angle gamma:  "
             <<L_gamma<<std::endl
             <<"The second joint angle rotation angle alpha:  "
             <<alpha<<std::endl
             <<"The third joint angle rotation angle beta:  "
             <<beta<<std::endl

             <<"RIGHT:"<<std::endl
             <<"The first joint angle rotation angle gamma:  "
             <<R_gamma<<std::endl
             <<"The second joint angle rotation angle alpha:  "
             <<alpha<<std::endl
             <<"The third joint angle rotation angle beta:  "
             <<beta<<std::endl;
}

double QuadrupedInverseKinematic::calc_dyz()
{
    dyz = sqrt(pos_y*pos_y+pos_z*pos_z);
    std::cout<<dyz<<std::endl;
    return dyz;
}

double QuadrupedInverseKinematic::calc_lyz()
{
    lyz = sqrt(dyz*dyz-h*h);
    std::cout<<lyz<<std::endl;
    return lyz;
}

float QuadrupedInverseKinematic::calc_R_gamma()
{
    float gamma_1, gamma_2;
    gamma_1=atan(pos_y/pos_z);
    gamma_2=atan(h/lyz);
    R_gamma = gamma_1 - gamma_2;
    std::cout<<R_gamma<<std::endl;
    return R_gamma;
}

float QuadrupedInverseKinematic::calc_L_gamma()
{
    float gamma_1, gamma_2;
    gamma_1=atan(pos_y/pos_z);
    gamma_2=atan(h/lyz);
    L_gamma = gamma_1 + gamma_2;
    std::cout<<L_gamma<<std::endl;
    return L_gamma;
}

double QuadrupedInverseKinematic::calc_lxz()
{
    lxz = sqrt(lyz*lyz+pos_x*pos_x);
    std::cout<<lxz<<std::endl;
    return lxz;
}

double QuadrupedInverseKinematic::calc_n()
{
    n = (lxz*lxz-hl*hl-hu*hu)/(2*hu);
    std::cout<<n<<std::endl;
    return n;
}

float QuadrupedInverseKinematic::calc_beta()
{
    beta = acos(n/hl);
    std::cout<<beta<<std::endl;
    return beta;
}

float QuadrupedInverseKinematic::calc_alpha()
{
    float alpha_1, alpha_2;
    alpha_1 = atan(pos_x/lyz);
    alpha_2 = -acos((hu+n)/lxz);
    alpha = alpha_1 + alpha_2;
    std::cout<<alpha<<std::endl;
    return alpha;
}
