#include "../headers/header.h"

/**
 * distanceBetweenPoints - To find the horizontal intersection with the wall
 * @x1: The x coordinate of the starting point
 * @y1: The y coordinate oh the starting point
 * @x2: The x coordinate of the end point
 * @y2: The y coordinate of the end point
 * Return: The distance between two points
 */

float distanceBetweenPoints(float x1, float y1, float x2, float y2)
{
	return (sqrt(pow((x2 - x1), 2) + pow((y2 - y1), 2)));
}

/**
 * isRayFacingDown - To check if the ray is facing down
 * @angle: The current ray angle
 * Return: true or false
 */

bool isRayFacingDown(float angle)
{
	return (angle > 0 && angle < PI);
}

/**
 * isRayFacingUp - To check if the ray is facing up
 * @angle: The current ray angle
 * Return: true or false
 */

bool isRayFacingUp(float angle)
{
	return (!isRayFacingDown(angle));
}

/**
 * isRayFacingRight - To check if the ray is facing your right
 * @angle: The current ray angle
 * Return: true or false
 */

bool isRayFacingRight(float angle)
{
	return (angle < 0.5 * PI || angle > 1.5 * PI);
}

/**
 * isRayFacingLeft - check if the ray is facing to the right
 * @angle: current ray angle
 * Return: true or false
 */

bool isRayFacingLeft(float angle)
{
	return (!isRayFacingRight(angle));
}

