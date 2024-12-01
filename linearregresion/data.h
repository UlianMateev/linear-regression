#pragma once

//properti - the square m. area of a the property & price - the price of the property
float properti[15] = { 95, 108, 145, 170, 106, 69, 105, 70, 120, 130, 131, 60, 139, 78, 50 };
float price[15] = { 228, 248, 312, 365, 220, 128, 223, 209, 264, 270, 246, 165, 250, 169, 90 };

//the same data for ploting on the graph
float x_data[15] = { 95, 108, 145, 170, 106, 69, 105, 70, 120, 130, 131, 60, 139, 78, 50 };
float y_data[15] = { 228, 248, 312, 365, 220, 128, 223, 209, 264, 270, 246, 165, 250, 169, 90 };

float size = sizeof(properti) / sizeof(properti[0]); //size of the data
float y_pred[15] = { 0 };

float m = 0.0f;
float b = 0.0f;
