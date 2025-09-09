#pragma once

typedef struct
{
    int x, y;
} point_t;

typedef struct
{
    point_t pts[3];
} triangle_t;

struct sieve_t {
    int n;
    unsigned char *s;
};
