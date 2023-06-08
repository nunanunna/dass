
#include <stdio.h>
// case of struct
enum {
    MARGIN = 1
};
 typedef struct InputData {
    int impact;         // 단위 N*s
    int acceleration;   // 단위 m/s^2
    int wheel_speed;    // 단위 rpm
    int temperature;    // 단위 c
    int speed;          // 단위 m/s
    int mass;           // 단위 kg
} InputData;
void calculate_impact(InputData* data);
void print_output(InputData* data);
int main() {
    InputData data = {
        .impact = 2,
        .acceleration = 1,
        .wheel_speed = 250,
        .temperature = 25,
        .speed = 1,
        .mass = 2
    };
    calculate_impact(&data);
    print_output(&data);
    return 0;
}
 void calculate_impact(InputData* data) {
    int impact = data->mass * data->speed;
    if (impact - data->impact > MARGIN || impact - data->impact < -MARGIN) {
        printf("Error: The measured impact value does not match the expected value.\n");
    }
    data->impact = impact;
}
 void print_output(InputData* data) {
    printf("Expected impact: %d\n", data->impact);
    printf("Measured acceleration: %d\n", data->acceleration);
    printf("Measured wheel speed: %d\n", data->wheel_speed);
    printf("Measured temperature: %d\n", data->temperature);
    printf("Measured speed: %d\n", data->speed);
    printf("Measured mass: %d\n", data->mass);
    printf("Measured impact: %d\n", data->impact);
}


// case of array
// #include <stdio.h>
// enum {
//     MARGIN = 1
// };

// void calculate_impact(int* data);
// void print_output(int* data);

// int main() {
//     int data[] = {2, 1, 250, 25, 1, 2};
//     calculate_impact(data);
//     print_output(data);
//     return 0;
// }

// void calculate_impact(int* data) {
//     int impact = data[5] * data[4];
//     if (impact - data[0] > MARGIN || impact - data[0] < -MARGIN) {
//         printf("Error: The measured impact value does not match the expected value.\n");
//     }
//     data[0] = impact;
// }

// void print_output(int* data) {
//     printf("Expected impact: %d\n", data[0]);
//     printf("Measured acceleration: %d\n", data[1]);
//     printf("Measured wheel speed: %d\n", data[2]);
//     printf("Measured temperature: %d\n", data[3]);
//     printf("Measured speed: %d\n", data[4]);
//     printf("Measured mass: %d\n", data[5]);
//     printf("Measured impact: %d\n", data[0]);
// }