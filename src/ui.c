#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void add_task(char* task) {
    printf("\nAdding task: ** %s **\n", task);
    FILE *file = fopen("tasks.txt", "a");
    if (file == NULL) {
        printf("Error opening file!\n");
        return;
    }

    fprintf(file, "%s\n", task);
    fclose(file);
}

void mark_task_as_complete(char* task) {
    char line[256];
    FILE *file = fopen("tasks.txt", "r");
    FILE *temp = fopen("temp.txt", "w");

    if (file == NULL || temp == NULL) {
        printf("Error opening file!\n");
        return;
    }

    while (fgets(line, sizeof(line), file) != NULL) {
        line[strcspn(line, "\n")] = 0;
        if (strcmp(line, task) == 0) {
            fprintf(temp, "%s (Complete)\n", line);
            printf("\nMarking task as complete: ** %s **\n", line);
        } else {
            fprintf(temp, "%s\n", line);
            printf("\nTask not found: ** %s **\n", task);
        }
    }

    fclose(file);
    fclose(temp);

    // delete original file and rename temp file to original file
    remove("tasks.txt");
    rename("temp.txt", "tasks.txt");
}

void delete_task(char* task) {
    char line[256];
    char completed_task[256];
    sprintf(completed_task, "%s (Complete)", task);  // Create the completed task string

    FILE *file = fopen("tasks.txt", "r");
    FILE *temp = fopen("temp.txt", "w");

    if (file == NULL || temp == NULL) {
        printf("Error opening file!\n");
        return;
    }

    while (fgets(line, sizeof(line), file) != NULL) {
        line[strcspn(line, "\n")] = 0;
        if (strcmp(line, task) != 0 && strcmp(line, completed_task) != 0) {
            fprintf(temp, "%s\n", line);
            printf("\nTask not found: ** %s **\n", task);
        }
        printf("\nDeleting task: ** %s **\n", task);
    }

    fclose(file);
    fclose(temp);

    // Delete the original file and rename the temp file to the original file
    remove("tasks.txt");
    rename("temp.txt", "tasks.txt");
}

void view_to_do_list() {
    char task[256];
    FILE *file = fopen("tasks.txt", "r");
    if (file == NULL) {
        printf("Error opening file!\n");
        return;
    }

    printf("\nTo-Do List:\n");
    printf("-----------\n");
    while (fgets(task, sizeof(task), file) != NULL) {
        printf("%s", task);
    }

    fclose(file);
}

void exit_application() {
    printf("\nExiting application... Goodbye!\n");
    exit(0);
}

void display_menu() {
    printf("\n-------------------------\n");
    printf("To-Do List Application\n");
    printf("-------------------------\n");
    printf("1. Add Task\n");
    printf("2. Mark Task as Complete\n");
    printf("3. Delete Task\n");
    printf("4. View To-Do List\n");
    printf("5. Exit\n");
    printf("-------------------------\n");
}

void handle_user_input() {
    int choice;
    printf("\nEnter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            add_task("Task 1");
            break;
        case 2:
            mark_task_as_complete("Task 1");
            break;
        case 3:
            delete_task("Task 1");
            break;
        case 4:
            view_to_do_list();
            break;
        case 5:
            exit_application();
            break;
        default:
            printf("Invalid choice. Please enter a number between 1 and 5.\n");
            break;
    }
}

void main() {
    display_menu();

    while (1) {
        handle_user_input();
    }
}