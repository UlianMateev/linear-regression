#pragma once
#include <iostream>
#include <cmath>
#include"data.h"

#define lr 0.001f //learning rate
#define epoch 4000 

//function that normalizes the data
void normalize(float inp[], float size, float& mean, float& std_dev) {
	float sum = 0.0f;
	for (int i = 0; i < size; i++) {
		sum += inp[i];
	}
	mean = sum / size;

	float variance = 0.0f;

	for (int i = 0; i < size; i++) {
		variance += (inp[i] - mean) * (inp[i] - mean);
	}

	std_dev = sqrt(variance / size);

	for (int i = 0; i < size; i++) {
		inp[i] = (inp[i] - mean) / std_dev;
	}
}

//feeding the input to the equation of the line
void forward(float m, float inp[], float b, float outp[], float size) {
	for (int i = 0; i < size; i++) {
		outp[i] = (m * inp[i]) + b;
	}
}

//cost function
float costf(float pred[], float actual[], float size) {

	float cost = 0.0f;
	for (int i = 0; i < size; i++) {
		float d = actual[i] - pred[i];
		cost += d * d;
	}
	return cost / size;
}

//optimizing with gradient descent
void optimize(float pred[], float actual[], float inp[], float size, float& m, float& b) {

	float gradient_m = 0.0f;
	float gradient_b = 0.0f;

	for (int i = 0; i < size; i++) {
		gradient_m += (actual[i] - pred[i]) * inp[i];
		gradient_b += (actual[i] - pred[i]);
	}
	
	gradient_b *= -(2.0 / size);
	gradient_m *= -(2.0 / size);

	//std::cout << "GRad1 " << gradient_b << "\n";
	//std::cout << "GRad2 " << gradient_m << "\n";

	b -= static_cast<float>(lr) * gradient_b;
	m -= static_cast<float>(lr) * gradient_m;
}

//function that trains the model
void trainmodel(float mean_x, float mean_y, float std_x, float std_y) {

	normalize(properti, size, mean_x, std_x);
	normalize(price, size, mean_y, std_y);

	for (int i = 0; i < epoch; i++) {//training & optimizing the model

		forward(m, properti, b, y_pred, size);

		float cost = costf(y_pred, price, size);
		std::cout << "Cost=" << cost << " | m=" << m << " | b=" << b << "\n";

		optimize(y_pred, price, properti, size, m, b);
	}

	m *= std_y / std_x;//denormalizing the model
	b = (b * std_y) + mean_y - (m * mean_x);
	std::cout << "M:" << m << " B:" << b << "\n";
}

//function that calculates the accuracy of the model
void model_confidenciality(float y_data[], float y_pred[], float mean_y) {

	float variance_fit = 0.0f;
	float variance_mean = 0.0f;
	for (int i = 0; i < size; i++) {
		float d = y_data[i] - y_pred[i];
		variance_fit += d * d;
	}
	for (int i = 0; i < size; i++) {
		float d = y_data[i] - mean_y; //the mean of the price data
		variance_mean += d * d;
	}

	float R2 = (variance_mean - variance_fit) / variance_mean;
	std::cout << "R^2=" << R2 << "\n";

	float chisli = (variance_mean - variance_fit);
	float znam = variance_fit / (size - 2);
	float F = chisli / znam;
	std::cout << "F=" << F;
}