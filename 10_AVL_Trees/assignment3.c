#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

typedef struct _Node {
    bool isTerminal;
    struct _Node *children[26];
} Node;

Node *root;

Node* createNode() {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->isTerminal = false;
    for (int i = 0; i < 26; i++) {
        newNode->children[i] = NULL;
    }
    return newNode;
}

void insertWord(const char *word) {
    Node *current = root;
    for (int i = 0; word[i] != '\0'; i++) {
        int index = word[i] - 'a';
        if (index < 0 || index >= 26) {
            return;
        }
        if (current->children[index] == NULL) {
            current->children[index] = createNode();
        }
        current = current->children[index];
    }
    current->isTerminal = true;
}

bool isNodeEmpty(Node* node) {
    if (node == NULL) return true;
    for (int i = 0; i < 26; i++) {
        if (node->children[i] != NULL) {
            return false;
        }
    }
    return true;
}

Node* deleteWordRecursive(Node* currentNode, const char* word, int depth) {
    if (currentNode == NULL) {
        return NULL;
    }

    if (word[depth] == '\0') {
        if (currentNode->isTerminal) {
            currentNode->isTerminal = false;
            if (isNodeEmpty(currentNode)) {
                free(currentNode);
                return NULL;
            }
        }
        return currentNode;
    }

    int index = word[depth] - 'a';
    if (index < 0 || index >= 26) {
        return currentNode;
    }

    currentNode->children[index] = deleteWordRecursive(currentNode->children[index], word, depth + 1);

    if (currentNode != root && !currentNode->isTerminal && isNodeEmpty(currentNode)) {
        free(currentNode);
        return NULL;
    }

    return currentNode;
}

void deleteWord(const char *word) {
    if (root != NULL) {
        deleteWordRecursive(root, word, 0);
    }
}

void traverseAndAct(Node* currentNode, char* buffer, int depth,
                      int* wordCounter,
                      const char* targetWord,
                      int* foundIndex,
                      bool printMode,
                      bool* firstWordPrinted) {

    if (currentNode == NULL) {
        return;
    }

    if (currentNode->isTerminal) {
        buffer[depth] = '\0';
        if (printMode) {
            if (!(*firstWordPrinted)) {
                printf(" ");
            }
            printf("%s", buffer);
            *firstWordPrinted = false;
        } else {
            if (targetWord != NULL && strcmp(buffer, targetWord) == 0) {
                *foundIndex = *wordCounter;
            }
            (*wordCounter)++;
        }
    }

    for (int i = 0; i < 26; i++) {
        if (currentNode->children[i] != NULL) {
            buffer[depth] = 'a' + i;
            if (printMode || (targetWord == NULL) || (*foundIndex == -1) || (strncmp(buffer, targetWord, depth + 1) <= 0) ) {
                 traverseAndAct(currentNode->children[i], buffer, depth + 1,
                               wordCounter, targetWord, foundIndex,
                               printMode, firstWordPrinted);
            }
        }
    }
}

void findWord(const char *wordToFind) {
    char buffer[101];
    int wordCounter = 0;
    int foundIndex = -1;
    bool firstWordPrinted_dummy = true;

    if (root != NULL) {
        traverseAndAct(root, buffer, 0, &wordCounter, wordToFind, &foundIndex, false, &firstWordPrinted_dummy);
    }
    printf("%d\n", foundIndex);
}

void printWords() {
    char buffer[101];
    bool firstWordPrinted = true;
    int wordCounter_dummy = 0;
    int foundIndex_dummy = -1;

    if (root != NULL) {
        traverseAndAct(root, buffer, 0, &wordCounter_dummy, NULL, &foundIndex_dummy, true, &firstWordPrinted);
    }
    printf("\n");
}

void freeTreeRecursive(Node* currentNode) {
    if (currentNode == NULL) {
        return;
    }
    for (int i = 0; i < 26; i++) {
        if (currentNode->children[i] != NULL) {
            freeTreeRecursive(currentNode->children[i]);
        }
    }
    free(currentNode);
}

void freeTree() {
    if (root != NULL) {
        freeTreeRecursive(root);
        root = NULL;
    }
}

int main() {
    char op[10];
    char word[101];
    int N_ops;

    root = createNode();

    scanf("%d", &N_ops);
    while (N_ops--) {
        scanf("%s", op);
        if (strcmp(op, "insert") == 0) {
            scanf("%s", word);
            insertWord(word);
        } else if (strcmp(op, "delete") == 0) {
            scanf("%s", word);
            deleteWord(word);
        } else if (strcmp(op, "find") == 0) {
            scanf("%s", word);
            findWord(word);
        } else if (strcmp(op, "print") == 0) {
            printWords();
        }
    }

    freeTree();

    return 0;
}