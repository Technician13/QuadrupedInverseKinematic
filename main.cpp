/*
*author:Technician13
*date:2020.4.10
*function:This program realizes the inverse kinematics solution of the legs of the 
          quadruped robot. For a leg with three degrees of freedom, the angle of joint 
          space will be output after give the position coordinates of the toe
*/
#include <iostream>
//Eigen is not used in this project , however it is reserved for enhanced extensibility
#include <D:/CplusplusLibrary/eigen337/Eigen/Dense>
#include"QuadrupedInverseKinematic.h"
#include"QuadrupedInverseKinematic.cpp"

//using namespace Eigen;

int main()
{
    QuadrupedInverseKinematic *p=new QuadrupedInverseKinematic;
    p->calc_dyz();
    p->calc_lyz();
    p->calc_L_gamma();
    p->calc_R_gamma();
    p->calc_lxz();
    p->calc_n();
    p->calc_beta();
    p->calc_alpha();

    delete p;
    p = nullptr;
    system("pause");
    return 0;
}