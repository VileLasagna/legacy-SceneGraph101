
#include "Matrix44.h"
//#ifdef WIN32
#include <windows.h>
//#endif
#include <GL/gl.h>

//   PI/180

#define DEGTORAD  0.017453292519943295769


void Matrix44::setIdentity()
{
	elements[0] = 1;
	elements[5] = 1;
	elements[10] = 1;
	elements[15] = 1;
	elements [1] = 0;
	elements [2] = 0;
	elements [3] = 0;
	elements [4] = 0;
	elements [6] = 0;
	elements [7] = 0;
	elements [8] = 0;
	elements [9] = 0;
	elements [11] = 0;
	elements [12] = 0;
	elements [13] = 0;
	elements [14] = 0;

}

Matrix44::Matrix44()
{
	this->setIdentity();
}

Matrix44::Matrix44(float* mat)
{

	elements[0] = mat[0];
	elements[1] = mat[1];
	elements[2] = mat[2];
	elements[3] = mat[3];
	elements[4] = mat[4];
	elements[5] = mat[5];
	elements[6] = mat[6];
	elements[7] = mat[7];
	elements[8] = mat[8];
	elements[9] = mat[9];
	elements[10] = mat[10];
	elements[11] = mat[11];
	elements[12] = mat[12];
	elements[13] = mat[13];
	elements[14] = mat[14];
	elements[15] = mat[15];
}

void Matrix44::Multiply(const Matrix44 &rhs)
{

	//Brace for long maths!
	float result[16];
	result[0] = elements[0]*rhs.elements[0] + elements[4]*rhs.elements[1] + elements[8]*rhs.elements[2] + elements[12]*rhs.elements[3];
	result[1] = elements[1]*rhs.elements[0] + elements[5]*rhs.elements[1] + elements[9]*rhs.elements[2] + elements[13]*rhs.elements[3];
	result[2] = elements[2]*rhs.elements[0] + elements[6]*rhs.elements[1] + elements[10]*rhs.elements[2] + elements[14]*rhs.elements[3];
	result[3] = elements[3]*rhs.elements[0] + elements[7]*rhs.elements[1] + elements[11]*rhs.elements[2] + elements[15]*rhs.elements[3];
	result[4] = elements[0]*rhs.elements[4] + elements[4]*rhs.elements[5] + elements[8]*rhs.elements[6] + elements[12]*rhs.elements[7];
	result[5] = elements[1]*rhs.elements[4] + elements[5]*rhs.elements[5] + elements[9]*rhs.elements[6] + elements[13]*rhs.elements[7];
	result[6] = elements[2]*rhs.elements[4] + elements[6]*rhs.elements[5] + elements[10]*rhs.elements[6] + elements[14]*rhs.elements[7];
	result[7] = elements[3]*rhs.elements[4] + elements[7]*rhs.elements[5] + elements[11]*rhs.elements[6] + elements[15]*rhs.elements[7];
	result[8] = elements[0]*rhs.elements[8] + elements[4]*rhs.elements[9] + elements[8]*rhs.elements[10] + elements[12]*rhs.elements[11];
	result[9] = elements[1]*rhs.elements[8] + elements[5]*rhs.elements[9] + elements[9]*rhs.elements[10] + elements[13]*rhs.elements[11];
	result[10] = elements[2]*rhs.elements[8] + elements[6]*rhs.elements[9] + elements[10]*rhs.elements[10] + elements[14]*rhs.elements[11];
	result[11] = elements[3]*rhs.elements[8] + elements[7]*rhs.elements[9] + elements[11]*rhs.elements[10] + elements[15]*rhs.elements[11];
	result[12] = elements[0]*rhs.elements[12] + elements[4]*rhs.elements[13] + elements[8]*rhs.elements[14] + elements[12]*rhs.elements[15];
	result[13] = elements[1]*rhs.elements[12] + elements[5]*rhs.elements[13] + elements[9]*rhs.elements[14] + elements[13]*rhs.elements[15];
	result[14] = elements[2]*rhs.elements[12] + elements[6]*rhs.elements[13] + elements[10]*rhs.elements[14] + elements[14]*rhs.elements[15];
	result[15] = elements[3]*rhs.elements[12] + elements[7]*rhs.elements[13] + elements[11]*rhs.elements[14] + elements[15]*rhs.elements[15];

	elements[0] = result[0];
	elements[1] = result[1];
	elements[2] = result[2];
	elements[3] = result[3];
	elements[4] = result[4];
	elements[5] = result[5];
	elements[6] = result[6];
	elements[7] = result[7];
	elements[8] = result[8];
	elements[9] = result[9];
	elements[10] = result[10];
	elements[11] = result[11];
	elements[12] = result[12];
	elements[13] = result[13];
	elements[14] = result[14];
	elements[15] = result[15];
}


void Matrix44::setRotation(float degx, float degy, float degz)
{
	
	float radx = degx* DEGTORAD;
	float rady = degy* DEGTORAD;
	float radz = degz* DEGTORAD;

	this->setRotationRad(radx,rady,radz);

}

void Matrix44::applyMatrix()
{
	glMultMatrixf(elements);
}

void Matrix44::setMatrix()
{
	glLoadIdentity();
	this->applyMatrix();
}


void Matrix44::setRotationRad(float radx, float rady, float radz)
{
	this->setIdentity();
	float ch = cos(rady);
	float cp = cos(radx);
	float cb = cos(radz);
	float sh = sin(rady);
	float sp = sin(radx);
	float sb = sin(radz);

	this->elements[0] = (ch*cb)+(sh*sp*sb);
	this->elements[1] = sb*cp;
	this->elements[2] = ((-sh)*cb)+(ch*sp*sb);
	this->elements[4] = ((-ch)*sb)+(sh*sp*cb);
	this->elements[5] = cb*cp;
	this->elements[6] = (sb*sh)+(ch*sp*cb);
	this->elements[8] = sh*cp;
	this->elements[9] = (-sh);
	this->elements[10] = ch*cp;

}

void Matrix44::setTranslation(float x, float y, float z)
{
	elements[12] += x;
	elements[13] += y;
	elements[14] += z;


}

