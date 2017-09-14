/**
 * For explainations about the solution implemented here, read the following
 * dicussion on developpez.net:
 * https://developpez.net/forums/d1623320/general-developpement/algorithme-mathematiques/mathematiques/visibilite-d-satellite-point-terre/
 */
#include <stdio.h>
#include <math.h>

typedef struct point {
    long double x, y, z;
} point;

const long double r  = 6378.0l;
const long double pi = 3.141592653589793238462643383279502884l;

int main()
{
    int  n, t;
    long double lat, lon, alt;
    long double  dx,  dy,  dz;
    point e, s;
    char  name[61];

    t = 1;
    while (scanf("%d", &n) != 0 && n > 0) {
        scanf("%Lf %Lf %Lf\n", &lat, &lon, &alt);

        s.x = (alt + r) * cosl(lat * pi / 180.0l) * cosl(lon * pi / 180.0l);
        s.y = (alt + r) * cosl(lat * pi / 180.0l) * sinl(lon * pi / 180.0l);
        s.z = (alt + r) * sinl(lat * pi / 180.0l);

        printf("Test case %d:\n", t);
        while (n > 0) {
            scanf("%s %Lf %Lf\n", name, &lat, &lon);
            e.x = r * cosl(lat * pi / 180.0l) * cosl(lon * pi / 180.0l);
            e.y = r * cosl(lat * pi / 180.0l) * sinl(lon * pi / 180.0l);
            e.z = r * sinl(lat * pi / 180.0l);

            dx  = s.x - e.x;
            dy  = s.y - e.y;
            dz  = s.z - e.z;
            if ((dx * dx + dy * dy + dz * dz) <= ((r + alt) * (r + alt) - r * r)) {
                printf("%s\n", name);
            }
            --n;
        }
        printf("\n");
        ++t;
    }

    return 0;
}
