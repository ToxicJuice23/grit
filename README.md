# Grit: a C project initializer
### Instructions
 - `# ./name-project.sh {project name}`
 
##### run these to make your own repo (otherwise you won't be able to save your progress)
 - `# rm -r .git`
 - `$ git init .`
 - `$ git add .`
 - `$ git commit -m "initial commit"`
 - `$ gh repo create` (optional)
 - `git push`


#### if name-project.sh was ran by accident:
`$ ./name-project.sh reset`
##### WARNING: THIS WILL RESET LOCAL TO REMOTE. YOU WILL LOSE ALL UNSAVED PROGRESS.

### Testing framework instructions
- edit `test.c` to create or modify tests
- no need to include more files in test.c
- every test function must follow the convention:
- - To define a test: 
```c++
TEST_FUNCTION(test_{fn})
    int fails = 0;
    int n_cases = 0;
    TEST_CASE (critical_condition) {
        CRITICAL_FAIL
    }
    TEST_CASE (condition) {
        FAIL
    }
    RETURN_PERCENTAGE
}
```
- instead of using an if statement, use the macro `TEST_CASE`
- make sure you increment the `N_TESTS` macro as you add tests
- make sure to add `test_{fn}` in the main function's array of functions. It is marked with a comment