class Solution {
public:
    void inorder(TreeNode* root,vector<int> &ans){
        if(root==NULL){
            return;
        }
        inorder(root->left,ans);
        ans.push_back(root->val);
        inorder(root->right,ans);
    }
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        inorder(root,ans);
        return ans;
    }
};
,
                {
                    "subject": "English",
                    "classes": [
                        "Class 1",
                        "Class 2",
                        "Class 3",
                        "Class 4",
                        "Class 5",
                        "Class 6",
                        "Class 7",
                        "Class 8",
                        "Class 9",
                        "Class 10"
                    ],
                    "streams": [
                        {
                            "stream": ["Medical", "Non-Medical", "Commerce Stream", "Humanities (Arts) Stream"],
                            "class": "Class 11"
                        }
                    ]
                },
                {
                    "subject": "Hindi",
                    "classes": [
                        "Class 1",
                        "Class 2",
                        "Class 3",
                        "Class 4",
                        "Class 5",
                        "Class 6",
                        "Class 7",
                        "Class 8",
                        "Class 9",
                        "Class 10"
                    ],
                    "streams": [
                        {
                            "stream": [""],
                            "class": ""
                        }
                    ]
                },
                {
                    "subject": "Environmental Studies",
                    "classes": [
                        "Class 1",
                        "Class 2",
                        "Class 3",
                        "Class 4",
                        "Class 5"
                    ],
                    "streams": [
                        {
                            "stream": [""],
                            "class": ""
                        }
                    ]
                },
                {
                    "subject": "General Science",
                    "classes": [
                        "Class 1",
                        "Class 2",
                        "Class 3",
                        "Class 4",
                        "Class 5"
                    ],
                    "streams": [
                        {
                            "stream": [""],
                            "class": ""
                        }
                    ]
                },
                {
                    "subject": "Social Studies",
                    "classes": [
                        "Class 1",
                        "Class 2",
                        "Class 3",
                        "Class 4",
                        "Class 5",
                        "Class 6",
                        "Class 7",
                        "Class 8",
                        "Class 9",
                        "Class 10"
                    ],
                    "streams": [
                        {
                            "stream": [""],
                            "class": ""
                        }
                    ]
                },
                {
                    "subject": "Art and Craft",
                    "classes": [
                        "Class 1",
                        "Class 2",
                        "Class 3",
                        "Class 4",
                        "Class 5",
                        "Class 6",
                        "Class 7",
                        "Class 8"
                    ],
                    "streams": [
                        {
                            "stream": [""],
                            "class": ""
                        }
                    ]
                },
                {
                    "subject": "Physical Education",
                    "classes": [
                        "Class 1",
                        "Class 2",
                        "Class 3",
                        "Class 4",
                        "Class 5",
                        "Class 6",
                        "Class 7",
                        "Class 8",
                        "Class 9",
                        "Class 10"
                    ],
                    "streams": [
                        {
                            "stream": [""],
                            "class": ""
                        }
                    ]
                },
                {
                    "subject": "Music and Dance",
                    "classes": [
                        "Class 1",
                        "Class 2",
                        "Class 3",
                        "Class 4",
                        "Class 5",
                        "Class 6",
                        "Class 7",
                        "Class 8"
                    ],
                    "streams": [
                        {
                            "stream": [""],
                            "class": ""
                        }
                    ]
                },
                {
                    "subject": "Moral Science or Value Education",
                    "classes": [
                        "Class 1",
                        "Class 2",
                        "Class 3",
                        "Class 4",
                        "Class 5"
                    ],
                    "streams": [
                        {
                            "stream": [""],
                            "class": ""
                        }
                    ]
                },
                {
                    "subject": "Computer Science",
                    "classes": [
                        "Class 6",
                        "Class 7",
                        "Class 8",
                        "Class 9",
                        "Class 10"
                    ],
                    "streams": [
                        {
                            "stream": [""],
                            "class": ""
                        }
                    ]
                }