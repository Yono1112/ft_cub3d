#include <stdio.h>
#include <math.h>

#define WINDOW_WIDTH 800
#define FOV 1.04719
#define TWO_PI 6.28318530718

#define NORTH 4.71238
#define SOUTH 1.57079
#define EAST 0
#define WEST 3.14159

double calculate_ray_angle(double direction, int x) {
	double angle = direction - (FOV / 2) + ((double)x / (double)WINDOW_WIDTH) * FOV;
	if (angle < 0)
		angle += TWO_PI;
	else if (angle > TWO_PI)
		angle -= TWO_PI;
	return angle;
}

int main() {
	int x_values[] = {0, 799};
	
	printf("NORTH:%f(%f°)\n", NORTH, NORTH * (180 / M_PI));
	for (int i = 0; i < 2; i++) {
		printf("x=%d: %f radians(%f°)\n", x_values[i], calculate_ray_angle(NORTH, x_values[i]), calculate_ray_angle(NORTH, x_values[i]) * (180 / M_PI));
	}

	printf("\nSOUTH%f(%f°):\n", SOUTH, SOUTH * (180 / M_PI));
	for (int i = 0; i < 2; i++) {
		printf("x=%d: %f radians(%f°)\n", x_values[i], calculate_ray_angle(SOUTH, x_values[i]), calculate_ray_angle(SOUTH, x_values[i]) * (180 / M_PI));
	}

	printf("\nEAST%d:(%f°)\n", EAST, EAST * (180 / M_PI));
	for (int i = 0; i < 2; i++) {
		printf("x=%d: %f radians(%f°)\n", x_values[i], calculate_ray_angle(EAST, x_values[i]), calculate_ray_angle(EAST, x_values[i]) * (180 / M_PI));
	}

	printf("\nWEST%f:(%f°)\n", WEST, WEST * (180 / M_PI));
	for (int i = 0; i < 2; i++) {
		printf("x=%d: %f radians(%f°)\n", x_values[i], calculate_ray_angle(WEST, x_values[i]), calculate_ray_angle(WEST, x_values[i]) * (180 / M_PI));
	}
	return 0;
}
