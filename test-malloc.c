#include <stdio.h>
#include <stdlib.h>

#define MSG(foo) fprintf(stderr, "Line %d: %s\n", __LINE__, foo)

int main(int argc, char *argv[])
{
    char *p, *q;
    double *d;

    MSG("-- Test malloc() for unusual situations");

    MSG("Allocate small block of 17 bytes ");
    p = malloc(17);
    if (p == NULL)
        MSG("* ERROR: Can't allocate even 17 bytes.");
    MSG("Write on allocated block");
    p[0] = p[16] = 17;

    MSG("Allocate big block of 4711 bytes");
    q = malloc(4711);
    if (q == NULL)
        MSG("* ERROR: Could not allocate big block");
    MSG("Write on allocated block");
    q[4710] = 47;
    MSG("Free big block");
    free(q);

    MSG("Free small block");
    free(p);

    MSG("Free NULL");
    free(NULL);

    MSG("Allocate zero");
    if ((p = malloc(0)) != NULL)
        MSG("* ERROR: malloc(0) returned non NULL pointer!");

    MSG("Free pointer from malloc(0)");
    free(p);

    MSG("Test alignment for double");
    if ((d = malloc(2 * sizeof(double))) == NULL)
        MSG("* ERROR: malloc(2 * sizeof(double)) returned NULL");
    d[0] = d[1] = (double) 4711.4711;
    free(d);

    return 0;
}
