#pragma once

typedef struct
{
    int x, y;
} point_t;

typedef struct
{
    point_t pts[3];
} triangle_t;

// struct sieve_t {
//     int long long n;
//     char *s;
// };


// struct sieve_t {
//     int n;
//     unsigned char *s;
// };

struct sieve_t {
    int n;
    unsigned char *mod1;
    unsigned char *mod5;
};