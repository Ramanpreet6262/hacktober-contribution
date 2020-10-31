#include <assert.h>
#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* readline();


// Complete the braces function below.

// Please store the size of the string array to be returned in result_count pointer. For example,
// char a[2][6] = {"hello", "world"};
//
// *result_count = 2;
//
// return a;
//

typedef struct stack
{
    int value;
    struct stack *next;
}st;

int isEmpty(st *head){
    if(head == NULL){
        return 1;
    }
    return 0;
}

void push(st **head, char c){
    st *newNode = (st*)malloc(sizeof(st));
    newNode->value = c;
    newNode->next = *head;
    *head = newNode;
}

char top(st *head){
    return head->value;
}

char pop(st **head){
    char c = (*head)->value;
    st *temp = *head;
    *head = (*head)->next;
    free(temp);
    return c;
}

char** braces(int values_count, char** values, int* result_count) {
    char **ans = (char**)malloc(sizeof(char*)*values_count);
    for(int i=0; i<values_count; i++)
    {
        ans[i] = (char*)malloc(sizeof(char)*5);
    }
    st* head = NULL;

    for(int i=0; i<values_count; i++)
    {
        head = NULL;
        int j=0,flag = 1;
        while(values[i][j]!='\0')
        {
            flag = 1;
            if(values[i][j] == '(' || values[i][j] == '[' || values[i][j] == '{' )
            {
                push(&head,values[i][j]);
            }
            else
            {
                char z = values[i][j];
                if(isEmpty(head))
                {
                    flag = -1;
                    break;
                }
                char y = pop(&head);
                if(z=='}' && y!='{')
                {
                    flag = -1;
                    break;
                }
                if(z==']' && y!='[')
                {
                    flag = -1;
                    break;
                }
                if(z==')' && y!='(')
                {
                    flag = -1;
                    break;
                }
            }
            j++;
        }
        if(!isEmpty(head))
            flag = -1;
        if(flag == 1)
        {
            ans[i][0] = 'Y';
            ans[i][1] = 'E';
            ans[i][2] = 'S';
            ans[i][3] = '\0';
        }
        else
        {
            ans[i][0] = 'N';
            ans[i][1] = 'O';
            ans[i][2] = '\0';
        }
    }

    *result_count = values_count;
    return ans;
}

//Ignore int main and focus on function only

int main()
{
    FILE* fptr = fopen(getenv("OUTPUT_PATH"), "w");

    char* values_count_endptr;
    char* values_count_str = readline();
    int values_count = strtol(values_count_str, &values_count_endptr, 10);

    if (values_count_endptr == values_count_str || *values_count_endptr != '\0') { exit(EXIT_FAILURE); }

    char** values = malloc(values_count * sizeof(char*));

    for (int i = 0; i < values_count; i++) {
        char* values_item = readline();

        *(values + i) = values_item;
    }

    int res_count;
    char** res = braces(values_count, values, &res_count);

    for (int i = 0; i < res_count; i++) {
        fprintf(fptr, "%s", *(res + i));

        if (i != res_count - 1) {
            fprintf(fptr, "\n");
        }
    }

    fprintf(fptr, "\n");

    fclose(fptr);

    return 0;
}

char* readline() {
    size_t alloc_length = 1024;
    size_t data_length = 0;
    char* data = malloc(alloc_length);

    while (true) {
        char* cursor = data + data_length;
        char* line = fgets(cursor, alloc_length - data_length, stdin);

        if (!line) { break; }

        data_length += strlen(cursor);

        if (data_length < alloc_length - 1 || data[data_length - 1] == '\n') { break; }

        size_t new_length = alloc_length << 1;
        data = realloc(data, new_length);

        if (!data) { break; }

        alloc_length = new_length;
    }

    if (data[data_length - 1] == '\n') {
        data[data_length - 1] = '\0';
    }

    data = realloc(data, data_length);

    return data;
}
