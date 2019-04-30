#include <stdio.h>
#include <stdlib.h>

#define MSG(foo) fprintf(stderr, "Line %d: %s", __LINE__, foo)

int main(int argc, char *argv[])
{
    char *p, *q;
    double *d;

    MSG("-- Test malloc() for unusual situations\n");

    MSG("Allocate small block of 17 bytes \n");
    p = malloc(17);
    if (p == NULL)
        MSG("* ERROR: Can't allocate even 17 bytes. Must be bug in malloc\n");
    MSG("Write on allocated block\n");
    p[0] = p[16] = 17;

    MSG("Allocate big block of 4711 bytes\n");
    q = malloc(4711);
    if (q == NULL)
        MSG("* ERROR: Could not allocate big block\n");
    MSG("Write on allocated block\n");
    q[4710] = 47;
    MSG("Free big block\n");
    free(q);

    MSG("Free small block\n");
    free(p);

    MSG("Free NULL\n");
    free(NULL);

    MSG("Allocate zero\n");
    if ((p = malloc(0)) != NULL)
        MSG("* ERROR: malloc(0) returned non NULL pointer!\n");

    MSG("Free pointer from malloc(0)\n");
    free(p);

    MSG("Test alignment for double\n");
    if ((d = malloc(2 * sizeof(double))) == NULL)
        MSG("* ERROR: malloc(2 * sizeof(double)) returned NULL\n");
    d[0] = d[1] = (double) 4711.4711;
    free(d);

    return 0;
}
