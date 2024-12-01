#include<iostream>
#include"visual.h"
#include"model.h"

int main()
{
	InitWindow(WIDTH, HEIGHT, "Linear Regresion Visualization");
	SetTargetFPS(1);


	float mean_prop = 0.0f;  float std_dev_prop = 0.0f;
	float mean_price = 0.0f;     float std_dev_price = 0.0f;

	trainmodel(mean_prop, mean_price, std_dev_prop, std_dev_price);

	forward(m, x_data, b, y_pred, size);

	model_confidenciality(y_data, y_pred, mean_price);

	while (!WindowShouldClose()) {//ploting the data and fit line
		BeginDrawing();
		{
			ClearBackground(RAYWHITE);

			draw_graph();

			for (int i = 0; i < size; i++) {
				plot_data_points(x_data[i], y_data[i]);
			}

			fit_the_line(m, b);
		}
		EndDrawing();
	}
	CloseWindow();
}