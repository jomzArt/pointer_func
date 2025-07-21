#include <stdio.h>

typedef struct Data {
    int value;
    void (*action)(struct Data *self);
} Data;

void print(Data *self) {
    printf("%i\n", self->value);
}

Data create_data(int val) {
    Data data = { val, print };
    return data;
}

int main() {
    Data data = create_data(40);
    Data d;
    d.value = 50;
    d.action = print;

    data.action(&data);
    d.action(&d);
    return 0;
}