#pragma once
#include <raylib.h>

#define WIDTH 1000 //size of the screen
#define HEIGHT 1000

//coordinates of x & y for the origin of the graph (0 ; 0)
int origin_x = WIDTH / 10;
int origin_y = HEIGHT - (HEIGHT / 10);

//function that draws a graph
void draw_graph() {

	int w_x = WIDTH - (WIDTH / 10);
	int w_y = HEIGHT - (HEIGHT / 10);

	int h_x = WIDTH / 10;
	int h_y = HEIGHT / 10;

	DrawLine(origin_x, origin_y, w_x, w_y, BLACK);
	DrawLine(origin_x, origin_y, h_x, h_y, BLACK);

	DrawCircle(50 * 2 + 100, HEIGHT - (HEIGHT / 10), 4, BLACK);
	DrawCircle(100 * 2 + 100, HEIGHT - (HEIGHT / 10), 4, BLACK);
	DrawCircle(150 * 2 + 100, HEIGHT - (HEIGHT / 10), 4, BLACK);
	DrawCircle(200 * 2 + 100, HEIGHT - (HEIGHT / 10), 4, BLACK);
	DrawCircle(250 * 2 + 100, HEIGHT - (HEIGHT / 10), 4, BLACK);
	DrawCircle(300 * 2 + 100, HEIGHT - (HEIGHT / 10), 4, BLACK);
	DrawCircle(350 * 2 + 100, HEIGHT - (HEIGHT / 10), 4, BLACK);
	DrawCircle(400 * 2 + 100, HEIGHT - (HEIGHT / 10), 4, BLACK);
	DrawCircle(100, 100, 4, BLACK);
	DrawCircle(100, 200, 4, BLACK);
	DrawCircle(100, 300, 4, BLACK);
	DrawCircle(100, 400, 4, BLACK);
	DrawCircle(100, 500, 4, BLACK);
	DrawCircle(100, 600, 4, BLACK);
	DrawCircle(100, 700, 4, BLACK);
	DrawCircle(100, 800, 4, BLACK);
}

//function that plots the data points on the graph
void plot_data_points(int data_x, int data_y) {

	int x = (data_x * 2) + 100;
	int y = (HEIGHT - (HEIGHT / 10)) - data_y;
	int r = 4;

	DrawCircle(x, y, r, BLUE);
}

//function that draws the fiting line
void fit_the_line(float m, float b) {

	DrawLine(origin_x, origin_y - b, WIDTH - (WIDTH / 10), ((HEIGHT / 10) * m) - b, BLACK);
}


//gafggdfgyuagyufa
void draw_layer(int x, int y, int r, int n_neurons) {

	int space = 0;
	for (int i = 0; i < n_neurons; i++) {
		if (i > 0) {
			space += (HEIGHT - y) / n_neurons;
		}
		DrawCircle(x, y + space, r, RED);
	}
}

void connect_layers(int x1, int y1, int x2, int y2, int r, int n_neurons1, int n_neurons2) {

	int space = 0;
	int space1 = 0;
	for (int i = 0; i < n_neurons1; i++) {
		space = 0;
		for (int j = 0; j < n_neurons2; j++) {
			if (j > 0) {
				space += (HEIGHT - y2) / n_neurons2;
			}
			DrawLine(x1 + r, y1 + space1, x2 - r, y2 + space, BLACK);
		}
		space1 += (HEIGHT - y2) / n_neurons1;
	}
}

