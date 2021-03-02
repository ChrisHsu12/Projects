#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bmp.h"

typedef enum{
	up,
	right,
	down,
	left
} direction;

void draw(int x, int y, direction move, int step, int w, RGB* im, RGB c)
{
#define I(i, j) im[(i)*w + j]
    int j;
    if (move == up)
        for (j = 0; j < step; j++)
            I(x + j, y) = c;
    if (move == down)
        for (j = 0; j < step; j++)
            I(x - j, y) = c;
    if (move == right)
        for (j = 0; j < step; j++)
            I(x, y + j) = c;
    if (move == left)
        for (j = 0; j < step; j++)
            I(x, y - j) = c;
#undef I
}

int fib(int n, int x, int y, int step, RGB bc, RGB fc, int w, int h, RGB *image)
{
		char *prev = malloc(2);
		strcpy(prev, "1");
		char *current = malloc(2);
		strcpy(current, "0");
		int i = 0;
		for (i = 2; i < n; i++)
		{
			char *next = malloc(strlen(current) + strlen(prev) + 1);
			strcpy(next,current);
			strcat(next,prev);
			free(prev);
			prev = current;
			current = next;
		}
		int digit = 0;
		int num = 0;
		int newm = up;
		int newx = x;
		int newy = y;
		int k = 0;
		for (k = 0; k < w * h; k++)
		{
			image[k] = bc;
		}
		int l;
		int len = strlen(current);
		for (l = 0; l < len; l++)
		{
			switch (newm)
			{
				case up:
						newx += step;
						if (newx > w || newx < 0 || newy > h || newy < 0)
						{
							return 0;
						}
						else
						{
							draw (x, y, newm, step, w, image, fc);
							x += step;
							newx = x;
						}
						break;
				case right:
						newy += step;
						if (newx > w || newx < 0 || newy > h || newy < 0)
						{
							return 0;
						}
						else
						{
							draw (x, y, newm, step, w, image, fc);
							y += step;
							newy = y;
						}
						break;
				case left:
						newy -= step;
						if (newx > w || newx < 0 || newy > h || newy < 0)
						{
							return 0;
						}
						else
						{
							draw (x, y, newm, step, w, image, fc);
							y -= step;
							newy = y;
						}
						break;
				case down:
						newx -= step;
						if (newx > w || newx < 0 || newy > h || newy < 0)
						{
							return 0;
						}
						else
						{
							draw (x, y, newm, step, w, image, fc);
							x -= step;
							newx = x;
						}
						break;
			}
			num = current[l] - '0';
			if (num == 0)
			{
				if (digit % 2 == 0)
				{
					newm++;
					newm = (newm + 4) % 4;
				}
				if (digit % 2 != 0)
				{
					newm--;
					newm = (newm + 4) % 4;
				}
			}
			digit++;
		}
		digit--;
	return digit;
}