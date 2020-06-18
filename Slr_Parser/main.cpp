#include "slr_table.h"

int line = 0;

int main() {

    /*input file*/
    ifstream fin("output.txt");

    string term;
    
    /* locate of . */
    int bar = 0;
    vector <int> input_to_int;

    /* error handling */
    if (!fin.is_open()) {
        cout << "Error while opening file" << endl;
        exit(0);
    }

    /* save the input terminal in vector */
    while (!fin.eof()) {
        getline(fin, term);
        for (int i = 0; i < 37; i++) {
                if (term == term_and_non[i]) {
                    input_to_int.push_back(i);
                }
        }
    }

    /* convert stirng to integer in parsing table */
    for (int i = 0; i < 84; i++) {
        for (int j = 0; j < 36; j++) {
            int_table[i][j] = string_to_num(input_table[i][j]);
        }
    }

    /* push 0 state in stack first */
    state.push(0);

    /* check whether previous level is reduce or not */
    bool is_reduce = false;

    /* next input in parsing table */
    int input;

    /* action information : shift or reduce or goto */
    int table_info;

    /* left hand side (non-terminal) in production */
    int lhs;

    /* number of right hand side in production */
    int rhs_num;

    while (true) {

        if (is_reduce) {
            /* change next input if previous level is reduce */
            input = lhs;
            if (lhs == ACCEPT) {
                /* ACCEPT */
                cout << "ACCEPT!!" << endl;
                break;
            }
        }
        else{
            if(input_to_int[bar] == 36){
                line++;
                input_to_int.erase(input_to_int.begin() + (bar-1));
            }
            input = input_to_int[bar];
        }
            /* ex) .id * id -> input_str[0]=id */

        /* load the value in parsing table */
        table_info = int_table[state.top()][input];
        cout << "current state is : " <<state.top() + 1 << endl;
        cout << "next input is : " << input << endl;
        cout << "bar is : " << bar << endl;

        if (table_info % 3 == 1) {
            cout << "action is : shift" << table_info / 3 << endl << endl;;
        }
        else if (table_info % 3 == 2) {
            cout << "action is : reduce" << table_info / 3 << endl<<endl;
        }
        else if (table_info % 3 == 0) {
            cout << "action is : goto" << table_info / 3 << endl<<endl;
        }

        /* REJECT */
        if (table_info == 0) {
            cout << "Reject!!" << endl << "Error at line " << line << endl;
            break;
        }

        /* GOTO */
        else if (table_info % 3 == 0) {
            state.push(table_info / 3 - 1);
            is_reduce = false;
        }

        /* SHIFT */
        else if (table_info % 3 == 1) {
            bar++;
            state.push(table_info / 3 - 1);
            is_reduce = false;
        }

        else if (table_info % 3 == 2) {
            switch (table_info / 3) {
            case 1:
                /* CODE -> VDECL CODE */
                lhs = ACCEPT;
                rhs_num = 2;
                break;
            case 2:
                /* CODE -> FDECL CODE */
                lhs = ACCEPT;
                rhs_num = 2;
                break;
            case 3:
                /* CODE -> epsion */
                lhs = ACCEPT;
                rhs_num = 0;
                break;
            case 4:
                /* VDECL -> vtype id semi */
                lhs = 22;
                rhs_num = 3;
                break;
            case 5:
                /* VDECL -> vtype ASSIGN semi */
                lhs = 22;
                rhs_num = 3;
                break;
            case 6:
                /* ASSIGN -> id assign RHS */
                lhs = 28;
                rhs_num = 3;
                break;
            case 7:
                /* FDECL -> vtype id lparen ARG rparen lbrace BLOCK RETURN rbrace */
                lhs = 23;
                rhs_num = 9;
                break;
            case 8:
                /* ARG -> vtype id MOREARGS */
                lhs = 24;
                rhs_num = 3;
                break;
            case 9:
                /* ARG -> epsilon */
                lhs = 24;
                rhs_num = 0;
                break;
            case 10:
                /* MOREARGS -> comma vtype id MOREARGS */
                lhs = 25;
                rhs_num = 4;
                break;
            case 11:
                /* MOREARGS -> epsilon */
                lhs = 25;
                rhs_num = 0;
                break;
            case 12:
                /* BLOCK -> STMT BLOCK */
                lhs = 26;
                rhs_num = 2;
                break;
            case 13:
                /* BLOCK -> epsilon */
                lhs = 26;
                rhs_num = 0;
                break;
            case 14:
                /* STMT -> VDECL */
                lhs = 27;
                rhs_num = 1;
                break;
            case 15:
                /* STMT -> ASSIGN semi */
                lhs = 27;
                rhs_num = 2;
                break;
            case 16:
                /* STMT -> if lparen COND rparen lbrace BLOCK rbrace ELSE */
                lhs = 27;
                rhs_num = 8;
                break;
            case 17:
                /* STMT -> while lparen COND rparen lbrace BLOCK rbrace */
                lhs = 27;
                rhs_num = 7;
                break;
            case 18:
                /* STMT -> for lparen ASSIGN semi COND semi ASSIGN rparen lbrace BLOCK rbrace */
                lhs = 27;
                rhs_num = 11;
                break;
            case 19:
                /* ELSE -> else lbrace BLOCK rbrace */
                lhs = 35;
                rhs_num = 4;
                break;
            case 20:
                /* ELSE -> epsilon */
                lhs = 35;
                rhs_num = 0;
                break;
            case 21:
                /* RHS -> EXPR */
                lhs = 29;
                rhs_num = 1;
                break;
            case 22:
                /* RHS -> literal */
                lhs = 29;
                rhs_num = 1;
                break;
            case 23:
                /* EXPR -> TERM addsub EXPR */
                lhs = 30;
                rhs_num = 3;
                break;
            case 24:
                /* EXPR -> TERM */
                lhs = 30;
                rhs_num = 1;
                break;
            case 25:
                /* TERM -> FACTOR multdiv TERM */
                lhs = 31;
                rhs_num = 3;
                break;
            case 26:
                /* TERM -> FACTOR */
                lhs = 31;
                rhs_num = 1;
                break;
            case 27:
                /* FACTOR -> lparen EXPR rparen */
                lhs = 32;
                rhs_num = 3;
                break;
            case 28:
                /* FACTOR -> id */
                lhs = 32;
                rhs_num = 1;
                break;
            case 29:
                /* FACTOR -> num */
                lhs = 32;
                rhs_num = 1;
                break;
            case 30:
                /* FACTOR -> float */
                lhs = 32;
                rhs_num = 1;
                break;
            case 31:
                /* COND -> FACTOR comp FACTOR */
                lhs = 33;
                rhs_num = 3;
                break;
            case 32:
                /* RETURN -> return FACTOR semi */
                lhs = 34;
                rhs_num = 3;
                break;
            default:
                /* error handling */
                cout << "error in reduce" << endl;
                return 0;
            }

            if (rhs_num != 0) {
                for (int i = 0; i < rhs_num; i++) {
                    /* pop the state in stack size of (right hand side) times */
                    state.pop();
                }
            }
            is_reduce = true;
        }
    }
    return 0;
}

int string_to_num(string s) {
    int num;
    if (s.front() == 'S')
        num = stoi(s.substr(1)) * 3 + 1;
    else if (s.front() == 'R')
        num = stoi(s.substr(1)) * 3 + 2;
    else
        num = stoi(s) * 3;
    return num;
}
