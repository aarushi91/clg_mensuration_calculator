#include <stdio.h>
#include <math.h>

// Function prototypes
float area_circle(float radius);
float circumference_circle(float radius);
float area_rectangle(float length, float width);
float perimeter_rectangle(float length, float width);
float area_triangle(float base, float height);
float perimeter_triangle(float a, float b, float c);

int main() {
    int choice;
    float r, l, w, b, h, a, side1, side2, side3;

    while (1) {
        printf("\n--- Mensuration Calculator ---\n");
        printf("1. Circle\n");
        printf("2. Rectangle\n");
        printf("3. Triangle\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter radius: ");
                scanf("%f", &r);
                if (r <= 0) {
                    printf("Invalid radius!\n");
                    break;
                }
                printf("Area: %.2f\n", area_circle(r));
                printf("Circumference: %.2f\n", circumference_circle(r));
                break;

            case 2:
                printf("Enter length and width: ");
                scanf("%f %f", &l, &w);
                if (l <= 0 || w <= 0) {
                    printf("Invalid dimensions!\n");
                    break;
                }
                printf("Area: %.2f\n", area_rectangle(l, w));
                printf("Perimeter: %.2f\n", perimeter_rectangle(l, w));
                break;

            case 3:
                printf("Choose triangle type:\n1. Area (base & height)\n2. Perimeter (3 sides)\n");
                int tri_choice;
                scanf("%d", &tri_choice);
                if (tri_choice == 1) {
                    printf("Enter base and height: ");
                    scanf("%f %f", &b, &h);
                    if (b <= 0 || h <= 0) {
                        printf("Invalid dimensions!\n");
                        break;
                    }
                    printf("Area: %.2f\n", area_triangle(b, h));
                } else if (tri_choice == 2) {
                    printf("Enter 3 sides: ");
                    scanf("%f %f %f", &side1, &side2, &side3);
                    if (side1 <= 0 || side2 <= 0 || side3 <= 0 ||
                        (side1 + side2 <= side3) || (side1 + side3 <= side2) || (side2 + side3 <= side1)) {
                        printf("Invalid side lengths!\n");
                        break;
                    }
                    printf("Perimeter: %.2f\n", perimeter_triangle(side1, side2, side3));
                } else {
                    printf("Invalid option!\n");
                }
                break;

            case 4:
                printf("Exiting...\n");
                return 0;

            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}

// Function definitions
float area_circle(float radius) {
    return M_PI * radius * radius;
}

float circumference_circle(float radius) {
    return 2 * M_PI * radius;
}

float area_rectangle(float length, float width) {
    return length * width;
}

float perimeter_rectangle(float length, float width) {
    return 2 * (length + width);
}

float area_triangle(float base, float height) {
    return 0.5 * base * height;
}

float perimeter_triangle(float a, float b, float c) {
    return a + b + c;
}
