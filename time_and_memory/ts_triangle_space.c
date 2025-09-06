#include <assert.h>
#include <stdio.h>


typedef struct
{
    int x, y;
} point_t;

typedef struct
{
    point_t pts[3];
} triangle_t;

int double_area(triangle_t tr)
{
}


int main()
{
    int x1, y1, x2, y2, x3, y3;

    const int res = scanf("%d %d %d %d %d %d", &x1, &y1, &x2, &y2, &x3, &y3);
    assert(res == 6);

    triangle_t triangle;
    triangle.pts[0].x = x1;
    triangle.pts[0].y = y1;
    triangle.pts[1].x = x2;
    triangle.pts[1].y = y2;
    triangle.pts[2].x = x3;
    triangle.pts[2].y = y3;

    const int space = double_area(triangle);

    printf("%d", space);

    return 0;
}
