# How to Contribute

### Step 1: Fork the Repository

Start by forking this repository to your own GitHub account. You'll need it to make your contributions.

### Step 2: Solve a Challenge

Choose a coding challenge from your preferred platform (e.g., LeetCode, CodeForces, CodeChef) and write a solution in your favorite programming language. Follow our naming convention:

`<question_number>_<question_name>.<file_extension>`

For example: `1_hello_world.cpp`

If the question does not have any question number, name it as:

`<question_name>.<file_extension>`

Save the file in the <b>platform specific</b> folder.

For example: You are solving a coding challenge from LeetCode, save the file into the `LeetCode` folder.

If the folder for your platform does not exists, create a new folder and rename it according to your platform and add your files.

### Step 3: Add Comments

Inside your code file, add the URL of the question as a comment at the top. Additionally, provide a clear explanation of your approach using block comments. Don't forget to mention the time and space complexity.

```cpp
/*
Question URL: https://leetcode.com/problems/hello-world/
Approach:
1. Start by...
2. Then, we...
3. Finally, ...
Time Complexity: O(1)
Space Complexity: O(1)
*/
// Your code goes here
```

### Step 4: Commit and Push

Commit your code with a meaningful commit message, like "Solved Hello World" and push it to your forked repository.

### Step 5: Make a Pull Request

Create a Pull Request (PR) to our main repository with a detailed description of your contribution. Follow this format for your PR title:

```
[Platform] Challenge Name - Your GitHub Username
```

For example:

```
[LeetCode] Hello World - johndoe
```

### Step 6: Celebrate!

Sit back, relax, and wait for your PR to be reviewed and merged. Congratulations, you've contributed to AlgoVerse's Hacktoberfest celebration!

# How to Contribute Optimized Code
### Follow these steps to contribute to any existing solution by optimizing them:

* <b>Identify Opportunities</b>: Review the existing code to identify opportunities for optimization. This can include improving time complexity, reducing memory usage, or enhancing code readability.

* <b>Comment out existing code</b>: Comment out the existing code that you plan to optimize and place it at the bottom of the code file. This preserves the original implementation for reference.

* <b>Add new logic</b>: At the top of the code file, write your new, optimized code. Ensure that your code is well-documented and follows our coding standards and guidelines mentioned above.

After completing, your file structure must look like this.

```cpp
/*
Question URL: https://leetcode.com/problems/hello-world/

New Approach:
1. Start by...
2. Then, we...
3. Finally, ...
Time Complexity: O(1)
Space Complexity: O(1)
*/
// Your optimized code goes here

/*
Old Approach:
1. Start by...
2. Then, we...
3. Finally, ...
Time Complexity: O(1)
Space Complexity: O(1)

// Existing code goes here (Within block comments)
*/
```

* <b>Commit and submit a pull request</b>: Commit your code with a meaningful message and submit a pull request (PR) with your optimized code. Follow the PR guidelines mentioned above. Now sit back and relax and wait for your PR to be reviewed and merged.