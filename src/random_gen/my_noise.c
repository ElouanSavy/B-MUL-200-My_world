/*
** EPITECH PROJECT, 2022
** B-MUL-200-BDX-2-1-myworld-elouan.savy-camaret
** File description:
** my_noise
*/

#include <math.h>

int create_noise(int x, int y, int seed, int *hash)
{
    int temp = hash[(y + seed) % 256];
    return hash[(temp + x) % 256];
}

float smooth_points(float x, float y, float s)
{
    return ((s * s * (3 - 2 * s)) * (y - x) + x);
}

float create_2d_noise(float x, float y, int seed, int *hash)
{
    int int_x = x;
    int int_y = y;
    float fraction_x = x - int_x;
    float fraction_y = y - int_y;
    int noise1 = create_noise(int_x, int_y, seed, hash);
    int noise2 = create_noise(int_x + 1, int_y, seed, hash);
    int noise3 = create_noise(int_x, int_y + 1, seed, hash);
    int noise4 = create_noise(int_x + 1, int_y + 1, seed, hash);
    float low_point = smooth_points(noise1, noise2, fraction_x);
    float high_point = smooth_points(noise3, noise4, fraction_x);
    return (smooth_points(low_point, high_point, fraction_y));
}

float my_perlin(int x, int y, int seed, int *hash)
{
    float end = 0.0;
    float divisor = 0.0;
    float frequence = 0.1;
    int dep = 4;
    float x1 = x * frequence;
    float y1 = y * frequence;
    float amplitude = 1.0;

    for (int j = 0; j < dep; j++) {
        end += create_2d_noise(x1, y1, seed, hash) * amplitude;
        divisor += 256 * amplitude;
        amplitude = amplitude / 2;
        x1 = x1 * 2;
        y1 = y1 * 2;
    }
    return (end / divisor);
}
