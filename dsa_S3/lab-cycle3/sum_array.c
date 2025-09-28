#include <stdio.h>

int main() {
    int deg1, deg2, maxDeg, i;
    int poly1[20] = {0}, poly2[20] = {0}, result[20] = {0};

    // Read first polynomial
    printf("Enter degree of first polynomial: ");
    scanf("%d", &deg1);
    printf("Enter coefficients from constant term to highest degree:\n");
    for(i = 0; i <= deg1; i++) {
        scanf("%d", &poly1[i]);
    }

    // Read second polynomial
    printf("Enter degree of second polynomial: ");
    scanf("%d", &deg2);
    printf("Enter coefficients from constant term to highest degree:\n");
    for(i = 0; i <= deg2; i++) {
        scanf("%d", &poly2[i]);
    }

    // Determine maximum degree
    maxDeg = (deg1 > deg2) ? deg1 : deg2;

    // Add polynomials
    for(i = 0; i <= maxDeg; i++) {
        result[i] = poly1[i] + poly2[i];
    }

    // Display first polynomial
    printf("\nFirst Polynomial: ");
    for(i = deg1; i >= 0; i--) {
        if(poly1[i] != 0)
            printf("%dx^%d ", poly1[i], i);
    }

    // Display second polynomial
    printf("\nSecond Polynomial: ");
    for(i = deg2; i >= 0; i--) {
        if(poly2[i] != 0)
            printf("%dx^%d ", poly2[i], i);
    }

    // Display resultant polynomial
    printf("\nResultant Polynomial (Sum): ");
    for(i = maxDeg; i >= 0; i--) {
        if(result[i] != 0)
            printf("%dx^%d ", result[i], i);
    }

    printf("\n");
    return 0;
}

