#include <stdio.h>

typedef struct Data {
    int val;
    void (*action)(struct Data *self);
} Data;

typedef void (*func_action)(Data *);

void print(Data *self) {
    printf("%i\n", self->val);
}

void double_value(Data *self) {
    self->val *= 2;
}

void increment_value(Data *self) {
    self->val++;
}

void apply_action(Data *self, void (*action)(Data *self)) {
    self->action = action;
    self->action(self);
}

int main() {
    Data data;
    data.val = 5;

    apply_action(&data, print);
    apply_action(&data, double_value);
    apply_action(&data, print);
    apply_action(&data, increment_value);
    apply_action(&data, print);

    printf("\n");

    Data d;
    d.val = 2;

    func_action actions[] = {
        print,
        double_value,
        print,
        increment_value,
        print
    };

    int func_len = sizeof(actions) / sizeof(actions[0]);
    for (int i = 0; i < func_len; i++) {
        apply_action(&d, actions[i]);
    }

    return 0;
}