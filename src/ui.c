#include <stdio.h>

void add_task(char* task) {
    FILE *file = fopen("tasks.txt", "a");
    if (file == NULL) {
        printf("Error opening file!\n");
        return;
    }

    fprintf(file, "%s\n", task);
    fclose(file);
}

void mark_task_as_complete(char* task) {

}

void delete_task(char* task) {

}

void view_to_do_list() {
    char task[256];
    FILE *file = fopen("tasks.txt", "r");
    if (file == NULL) {
        printf("Error opening file!\n");
        return;
    }

    while (fgets(task, sizeof(task), file) != NULL) {
        printf("%s", task);
    }

    fclose(file);
}

void display_menu() {
    printf("1. Add Task\n");
    printf("2. Mark Task as Complete\n");
    printf("3. Delete Task\n");
    printf("4. View To-Do List\n");
    printf("5. Exit\n");
}

void handle_user_input() {
    int choice;
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            printf("Add Task\n");
            // Call add_task function
            break;
        case 2:
            printf("Mark Task as Complete\n");
            // Call mark_task_as_complete function
            break;
        case 3:
            printf("Delete Task\n");
            // Call delete_task function
            break;
        case 4:
            printf("View To-Do List\n");
            // Call view_to_do_list function
            break;
        case 5:
            printf("Exit\n");
            // Call exit function
            break;
        default:
            printf("Invalid choice. Please enter a number between 1 and 5.\n");
            display_menu();
            handle_user_input();
    }
}

void main() {
    display_menu();
    handle_user_input();
}