#include "ui.h"

int main() {
    display_menu();

    while (1) {
        handle_user_input();
    }

    return 0;
}