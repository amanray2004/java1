#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

struct Node {
    char data;
    struct Node* next;
};

struct Node* top = NULL;

void push(char c) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = c;
    newNode->next = top;
    top = newNode;
}

char pop() {
    if (top == NULL) {
        printf("Stack is empty\n");
        return '\0';
    }
    
    char c = top->data;
    struct Node* temp = top;
    top = top->next;
    free(temp);
    return c;
}

char peek() {
    if (top == NULL) {
        printf("Stack is empty\n");
        return '\0';
    }
    return top->data;
}

int isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/');
}

int precedence(char c) {
    if (c == '+' || c == '-')
        return 1;
    else if (c == '*' || c == '/')
        return 2;
    return 0;
}

void infixToPostfix(char infix[], char postfix[]) {
    int i = 0, j = 0;
    
    while (infix[i] != '\0') {
        char currentChar = infix[i];
        
        if (isalnum(currentChar)) {
            postfix[j++] = currentChar;
        }
        else if (isOperator(currentChar)) {
            while (top != NULL && precedence(peek()) >= precedence(currentChar)) {
                postfix[j++] = pop();
            }
            push(currentChar);
        }
        else if (currentChar == '(') {
            push(currentChar);
        }
        else if (currentChar == ')') {
            while (top != NULL && peek() != '(') {
                postfix[j++] = pop();
            }
            if (top != NULL && peek() == '(') {
                pop(); // Discard the '(' from stack
            }
            else {
                printf("Invalid expression: Unbalanced parentheses\n");
                return;
            }
        }
        
        i++;
    }
    
    while (top != NULL) {
        if (peek() == '(') {
            printf("Invalid expression: Unbalanced parentheses\n");
            return;
        }
        postfix[j++] = pop();
    }
    
    postfix[j] = '\0';
}

int main() {
    char infix[100];
    char postfix[100];
    
    printf("Enter an infix expression: ");
    scanf("%[^\n]s", infix);
    
    infixToPostfix(infix, postfix);
    
    printf("Postfix expression: %s\n", postfix);
    
    return 0;
}
