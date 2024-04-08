#include "ui.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Helper function to remove newline character from a string
void remove_newline(char* str) {
    str[strcspn(str, "\n")] = 0;
}

// Improved error handling
FILE* open_file(const char* filename, const char* mode) {
    FILE* file = fopen(filename, mode);
    if (file == NULL) {
        printf("Error opening file: %s\n", filename);
        exit(EXIT_FAILURE);
    }
    return file;
}

void add_task() {
    char* task = get_task_name();
    printf("\nAdding task: ** %s **\n", task);
    FILE *file = open_file("tasks.txt", "a");
    fprintf(file, "%s\n", task);
    fclose(file);
    free(task);
    view_to_do_list();
}

void mark_task_as_complete() {
    char* task = get_task_name();
    char line[256];
    int task_found = 0;

    FILE *file = open_file("tasks.txt", "r");
    FILE *temp = open_file("temp.txt", "w");

    while (fgets(line, sizeof(line), file) != NULL) {
        remove_newline(line);
        if (strcmp(line, task) == 0) {
            fprintf(temp, "%s (Complete)\n", line);
            printf("\nMarking task as complete: ** %s **\n", line);
            task_found = 1;
        } else {
            fprintf(temp, "%s\n", line);
        }
    }

    fclose(file);
    fclose(temp);

    // delete original file and rename temp file to original file
    remove("tasks.txt");
    rename("temp.txt", "tasks.txt");

    if (!task_found) {
        printf("\nTask not found: ** %s **\n", task);
    }

    view_to_do_list();
}

void delete_task() {
    char* task = get_task_name();
    char line[256];
    char completed_task[256];
    int task_found = 0;

    sprintf(completed_task, "%s (Complete)", task);  // Create the completed task string

    FILE *file = open_file("tasks.txt", "r");
    FILE *temp = open_file("temp.txt", "w");

    while (fgets(line, sizeof(line), file) != NULL) {
        remove_newline(line);
        if (strcmp(line, task) != 0 && strcmp(line, completed_task) != 0) {
            fprintf(temp, "%s\n", line);
        } else {
            task_found = 1;
        }
    }

    fclose(file);
    fclose(temp);

    // Delete the original file and rename the temp file to the original file
    remove("tasks.txt");
    rename("temp.txt", "tasks.txt");

    if (!task_found) {
        printf("\nTask not found: ** %s **\n", task);
    }

    view_to_do_list();
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

int get_user_choice() {
    int choice;
    if (scanf("%d", &choice) != 1) {
        printf("Invalid input. Please enter a number.\n");
        handle_user_input();
    }
    return choice;
}

char* get_task_name() {
    char* task = malloc(256);
    if (task == NULL) {
        printf("Error allocating memory for task name.\n");
        exit(EXIT_FAILURE);
    }
    getchar();  // To consume the newline character left by scanf
    fgets(task, 256, stdin);
    remove_newline(task);
    return task;
}

void handle_user_input() {
    int choice;

    printf("\nEnter your choice: ");
    choice = get_user_choice();

    switch (choice) {
        case 1:
            printf("Enter the task name: ");
            add_task();
            break;
        case 2:
            printf("Enter the task name to mark as complete: ");
            mark_task_as_complete();
            break;
        case 3:
            printf("Enter the task name to delete: ");
            delete_task();
            break;
        case 4:
            view_to_do_list();
            break;
        case 5:
            exit_application();
            break;
        default:
            printf("Invalid choice. Please enter a number between 1 and 5.\n");
            handle_user_input();
            break;
    }
}
