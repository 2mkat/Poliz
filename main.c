#include "stack.c"
#include <stdbool.h>
#include <string.h>
#include <stdio.h>
#include <limits.h>
#include <assert.h>

#define ERR_OK 0
#define END_CODE -2
#define ERR_TOO_FEW_AGS -3
#define ERR_DIVISION_BY_ZERO -4
#define ERR_WRONG_INPUT_DATA -5
#define ERR_INPUT_DATA_EXISTS -6
#define ERR_INT_OVERFLOW -7
#define ERR_TOO_MANY_AGS -8
#define ERR_INVALID_CHAR -9

int bb_errno = ERR_OK;

bool is_number(char chr) {
    if (chr >= '0' && chr <= '9')
        return true;
    return false;
};
int overflow_check(int first, int second) {
    return (first > 0 && second > 0 && (INT_MAX - second < first) ||
        first < 0 && second < 0 && (INT_MIN - second > first));
};

int mul_overflow_check(int first, int second) {
    return (first > INT_MAX/second || first < INT_MIN/second);
};

int str_to_int(char *str, int *num) {
    if (!str) {
        return ERR_INPUT_DATA_EXISTS;
    }
    *num = 0;
    char *ptr = str;
    while(*ptr != '\0') {
        if (*ptr < '0' || *ptr > '9') {
            return ERR_WRONG_INPUT_DATA;
        }
        if (mul_overflow_check(*num, 10) || overflow_check((*ptr - 48), *num * 10)) {
            return ERR_INT_OVERFLOW;
        }
        *num = *num * 10 + (*ptr - 48);
        ptr++;
    }
    return ERR_OK;
};

int parse(stack *head, char* str){
    if (is_number(str[0])) {
        int number;
        int response = str_to_int(str, &number);

        if (response != ERR_OK) {
            return response;
        }

        stack_push(head, number);
        head->length += 1;
    }

    else if (str[0] != '='){
        if (strlen(str) > 1) {
            return ERR_WRONG_INPUT_DATA;
        }
        if (head->length < 2) {
            return ERR_TOO_FEW_AGS;
        }
        int num1 = stack_pop(head);
        int num2 = stack_pop(head);

        head->length -= 1;
        switch (str[0])
        {
        case '+':
            if (overflow_check(num1, num2)) {
                return ERR_INT_OVERFLOW;
            }
            stack_push(head, num1 + num2);
            break;
        case '-':
            if (overflow_check(-num1, -num2)) {
                return ERR_INT_OVERFLOW;
            }
            stack_push(head, num1 - num2);
            break;
        case '*':
            if (mul_overflow_check(num1, num2)) {
                return ERR_INT_OVERFLOW;
            }
            stack_push(head, num1 * num2);
            break;
        case '/':
            if (num1 == 0) {
                return ERR_DIVISION_BY_ZERO;
            }
            stack_push(head, num2/num1);
            break;
        default:
            return ERR_INVALID_CHAR;
        }
    } 
    else {
        if (head->length != 1) {
            return ERR_TOO_MANY_AGS;
        }
        printf("Result = %d\n", stack_pop(head));
        return END_CODE;
    }
    return ERR_OK;
};

int eval_str(char *str) {
    if (!str) {
        return ERR_INPUT_DATA_EXISTS;
    }
    stack head = stack_new();
    int position = 0;

    while(true) {
        char *tmp = (char*)malloc(sizeof(char)*255);
        int tmp_pos = 0;

        while(str[position] != ' ') {
            tmp[tmp_pos++] = str[position++];
        }
        position++;
        tmp[tmp_pos] = '\0';
        int response = parse(&head, tmp);
        if (response != ERR_OK) {
            return response;
        }
        free(tmp);
    }
};
int main(){
    bool by_hands = true;

    int response = 0;

    if (!by_hands) {
        assert( END_CODE == eval_str("12 12 + 18 * 12 + 40 + 11 / 4 / =\0") );
        assert( END_CODE == eval_str("1 2 + 1000 / 0 /=") );
    }

    else {
        stack head = stack_new();
        char *str_num = (char*)calloc(9, sizeof(char));
        while(scanf("%s", str_num) == 1) {
            response = parse(&head, str_num);
            if (response != ERR_OK)
            {
                printf("ERROR: %d;\n", response);
                return response;
            }
        }
    }
    return 0;
}
