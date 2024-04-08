# To-Do List Application Documentation
## Building the Application
This application uses a Makefile for building. To build the application, navigate to the project directory in your terminal and run the following command:
```bash
make
```
This command will compile the source files and link them to create an executable file.

## Running the Application
After building the application, you can run it using the following command:
```bash
./todo_list
```
This command will start the application.

## Using the Application
Upon starting the application, you will be presented with a menu of options:
```bash
-------------------------
To-Do List Application
-------------------------
1. Add Task
2. Mark Task as Complete
3. Delete Task
4. View To-Do List
5. Exit
-------------------------
```
Here's how to use each option:

1. Add Task: To add a task, enter `1` and press `Enter`. You will be prompted to enter the task name. After entering the task name, press `Enter` to add the task to the to-do list.

2. Mark Task as Complete: To mark a task as complete, enter `2` and press `Enter`. You will be prompted to enter the ID of the task. After entering the ID, press `Enter` to mark the task as complete.

3. Delete Task: To delete a task, enter `3` and press `Enter`. You will be prompted to enter the ID of the task. After entering the ID, press `Enter` to delete the task from the to-do list.

4. View To-Do List: To view the to-do list, enter `4` and press `Enter`. This will display the list of tasks, including both incomplete and completed tasks.

5. Exit: To exit the application, enter `5` and press `Enter`.

Please note that task IDs are unique and automatically assigned by the application. When you view the to-do list, each task is displayed with its ID, description, and status (complete or incomplete).