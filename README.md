# CISC 3142 Assignments Fall 2022

The following are completed lab exercises for course CISC 3142, **Programming Paradigms in C++**

# Lab Exercises

### **Pre-requisites**
Before running individual exercises, it is recommended that you have `g++` (the c++ compiler used for the assignments) and `GNU make` installed on your local machine. 
Installation information can be found in the __software.txt__ file.

Download the recommended software and then _clone_ the repository to your local machine.

### **Running a lab exercise**
To run an individual lab exercise, navigate to the root directory of the repository and run the following command, replacing the `<lab-folder>` placeholder with the name of the directory for the exercise that you would like to run.

```bash
# template
make <lab-folder>

# example for running lab exercise 1
make lab1

# example for running lab exercise 2
make lab2
```
The executables and object files generated from compiling the lab exercises will be removed when the program terminates normally. **HOWEVER**, in the event of an interrupt where the program terminates early, the executables and object files may still be present. 

In this case, you can run the following command to remove any files that are not source files ending in `.cpp`. When running the below command, make sure to replace the `<lab-folder>` placeholder with the name of the directory for the exercise that you would like to clean.
```bash
# remove object and executable files
make clean_<lab-folder>

# example for removing non-source files from lab exercise 1
make clean_lab1

# example for removing non-source files from lab exercise 2
make clean_lab2
```

_Note: The following labs do not have a runnable program and will exit silently when running the make commmands_
- lab3