#include <stdio.h>
#include <stdlib.h>

unsigned int numOfTrial = 0;
typedef struct TreeNode {
    int key;
    struct TreeNode *left, *right;
} treeNode;

typedef struct RootNode {
    treeNode *root;
    int size;
} rootNode;

void initRoot(rootNode *r, int n) {
    r->root = NULL;
    r->size = n;
}

treeNode *create(int key) {
    treeNode *new = (treeNode *) malloc(sizeof(treeNode));
    new->left = new->right = NULL;
    new->key = key;
    return new;
}

treeNode *insertNode(treeNode *r, int key) {
    if (r == NULL) {
        return create(key);
    }
    if (key < r->key)
        r->left = insertNode(r->left, key);
    else if (key > r->key)
        r->right = insertNode(r->right, key);
    return r;
}

void findKey(treeNode *r, int key) {
    if (r == NULL) {
        return;
    }
    if (r->key == key) return;
    if (key < r->key) {
        numOfTrial++;
        printf("%d ", r->key);
        findKey(r->left, key);
    } else if (key > r->key) {
        numOfTrial++;
        printf("%d ", r->key);
        findKey(r->right, key);
    }

}

int main() {
    int n, target;
    scanf("%d %d", &n, &target);
    int userInput[n];
    rootNode r;
    initRoot(&r, n);

    for (int i = 0; i < n; i++) {
        scanf("%d", &userInput[i]);
        r.root = insertNode(r.root, userInput[i]);
        r.size++;
    }
    findKey(r.root, target);
    printf("\n%d", numOfTrial);

    return 0;
}
