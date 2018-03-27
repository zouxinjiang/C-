#include<stdio.h>
#include<stdlib.h>

typedef struct TreeNode{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

//先序数组建立二叉树.为了方便，数组中0，当成null处理
TreeNode * arrToTree(const int const * arr,int len)
{
    TreeNode * res = (TreeNode *)malloc(sizeof(TreeNode));
    if(len == 0){
        return NULL;
    }
    res->val = arr[0];
    for(int i = 1; i < len;i++){
        

    }
};


int main()
{

    return 0;
}
