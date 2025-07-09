# 🛠️ Local DSA Development Setup (VS Code + GitHub)

This guide documents how to set up a clean local development environment for solving DSA problems in C++, using VS Code, GitHub, and reusable code templates.

---

## ✅ 1. Project Structure

```bash
DSA/
│
├── arrays/
├── linked_list/
├── trees/
├── graphs/
├── strings/
│
├── README.md
├── .gitignore
└── setup.md
```

Optional:
- Add `notes.md` or `README.md` inside each topic folder for problem notes or patterns.

---

## 💻 2. VS Code Setup

### 2.1 Open Folder in VS Code

```bash
code ~/DSA
```

Or use **File → Open Folder** in VS Code.

### 2.2 Install Extensions

- `C/C++` by Microsoft
- `Code Runner` (optional, to run code quickly)
- (Optional) `Better C++ Syntax`

---

## ⚙️ 3. Compile and Run in VS Code

Create a `.vscode` folder and add a `tasks.json` file:

**→ `.vscode/tasks.json`**

```json
{
  "version": "2.0.0",
  "tasks": [
    {
      "label": "Build and Run C++",
      "type": "shell",
      "command": "g++",
      "args": [
        "-std=c++17",
        "${file}",
        "-o",
        "${fileDirname}/${fileBasenameNoExtension}.out"
      ],
      "group": {
        "kind": "build",
        "isDefault": true
      },
      "problemMatcher": ["$gcc"]
    },
    {
      "label": "Run Executable",
      "type": "shell",
      "command": "${fileDirname}/${fileBasenameNoExtension}.out"
    }
  ]
}
```

### To Use:
- Press `Ctrl + Shift + B` to **Build**
- Press `F1 → Run Task → Run Executable` to **Run**

---

## 🧠 4. Snippet Template (Boilerplate)

To quickly create boilerplate C++ files for problems:

### Add a Custom Snippet:

1. Press `Ctrl + Shift + P` → "Configure User Snippets"
2. Choose `cpp.json`
3. Add this:

```json
"DSA Question Template": {
  "prefix": "dsatemp",
  "body": [
    "#include <bits/stdc++.h>",
    "using namespace std;",
    "",
    "class Solution {",
    "public:",
    "    vector<int> solve(vector<int>& nums, int target) {",
    "        int n = nums.size();",
    "        vector<int> ans;",
    "        for (int i = 0; i < n; i++) {",
    "            for (int j = i + 1; j < n; j++) {",
    "                if (nums[i] + nums[j] == target) {",
    "                    ans.push_back(i);",
    "                    ans.push_back(j);",
    "                    return ans;",
    "                }",
    "            }",
    "        }",
    "        return {-1, -1};",
    "    }",
    "};",
    "",
    "int main() {",
    "    int n = 5;",
    "    vector<int> nums = {2, 6, 5, 8, 11};",
    "    int target = 14;",
    "    Solution sol;",
    "    vector<int> ans = sol.solve(nums, target);",
    "    cout << "This is the answer: [" << ans[0] << ", " << ans[1] << "]" << endl;",
    "    return 0;",
    "}"
  ],
  "description": "C++ DSA Question Template"
}
```

### Use It:
- Type `dsatemp` in any `.cpp` file and press `Tab`

---

## 📂 5. GitHub Setup

### Add `.gitignore`

```gitignore
*.out
*.exe
*.o
.vscode/
```

### Initialize Git

```bash
cd DSA
git init
git remote add origin https://github.com/your-username/dsa-practice.git
git add .
git commit -m "Initial DSA setup"
git push -u origin main
```

---

## 📌 Tips

- Use one `.cpp` file per problem inside topic folders.
- Name files descriptively: `detect_cycle.cpp`, `reverse_list.cpp`, etc.
- Add a `README.md` to explain the structure and maybe log progress.
- Optional: Maintain a `progress.md` or `.csv` tracker file.

---
