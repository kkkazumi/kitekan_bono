#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <iostream>

double gauss(double coe[3], double factor, double mental) {
	double val_1 = coe[0] * (factor - coe[1]) * (factor - coe[1]);
	double val_2 = coe[2];
	double val = std::exp(-val_1 / val_2);
	return val;
}
double sigmoid(double coe[3], double factor, double mental) {
	double val_1 = coe[0];//coe[0]*mental
	double val_2 = coe[1]*factor-coe[2];//coe[2]/mental
	double val = 1.0 / (1.0 + std::exp(val_1 * val_2));
	return val;
}
void timing_coe(double mental, double* coe) {
	coe[0] = 2;
	coe[1] = 0.5;
	coe[2] = mental;
}
void oqtype_coe(double mental, double* coe) {
	coe[0] = 1.5;
	coe[1] = -1.0;
	coe[2] = 0.5 / mental;
}
void topic_coe(double mental, double* coe) {
	coe[0] = -0.5 * (mental - 0.5);
	coe[1] = 10;
	coe[2] = 0.5 / pow(mental, mental);
}
void turn_coe(double mental, double* coe) {
	coe[0] = -3.0;
	coe[1] = 1.0;
	coe[2] = 0.5 / mental;
}

void out_turn(){
	double coe[3];
	double val[100];
	for (int f = 0; f < 100; f++) {
		double factor = f / 100.0;
		for (int m = 0; m < 3; m++) {
			double mental = m * 0.45 + 0.05;
			turn_coe(mental,coe);
			val[f] = sigmoid(coe,factor,mental);
			std::cout<<val[f];
			if(m<2){
				std::cout<<",";
			}
		}
		std::cout<<"\n";
	}
}


void out_topic(){
	double coe[3];
	double val[100];
	for (int f = 0; f < 100; f++) {
		double factor = f / 100.0;
		for (int m = 0; m < 3; m++) {
			double mental = m * 0.45 + 0.05;
			topic_coe(mental,coe);
			val[f] = sigmoid(coe,factor,mental);
			std::cout<<val[f];
			if(m<2){
				std::cout<<",";
			}
		}
		std::cout<<"\n";
	}
}


void out_oqtype(){
	double coe[3];
	double val[100];
	for (int f = 0; f < 100; f++) {
		double factor = f / 100.0;
		for (int m = 0; m < 3; m++) {
			double mental = m * 0.45 + 0.05;
			oqtype_coe(mental,coe);
			val[f] = sigmoid(coe,factor,mental);
			std::cout<<val[f];
			if(m<2){
				std::cout<<",";
			}
		}
		std::cout<<"\n";
	}
}

void out_timing(){
	double coe[3];
	double val[100];
	for (int f = 0; f < 100; f++) {
		double factor = f / 100.0;
		for (int m = 0; m < 3; m++) {
			double mental = m * 0.45 + 0.05;
			timing_coe(mental,coe);
			val[f] = gauss(coe,factor,mental);
			std::cout<<val[f];
			if(m<2){
				std::cout<<",";
			}
		}
		std::cout<<"\n";
	}
}

int main(void) {
	out_turn();
	return 0;
}
