//
//  main.cpp
//  Compiler
//
//  Created by 최용렬 on 2020/05/06.
//  Copyright © 2020 최용렬. All rights reserved.
//

#include <iostream>
#include <fstream>
#include "dfa.cpp"
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// enum Lex 의 값들은 인풋으로 들어온 char배열 또는 string이 우리가 정의한 DFA중 어떤 DFA를 통과하는가에 대한 정보를 저장한다. 어떠한 DFA도 통과하지 않는다면 Reject 이다.
enum Lex {Vtype, SignedInt, Floating_point_number, Identifier, Literal_String, Boolean_String, Keyword, WhiteSpace, Arithmetic_Operator, Bitwise_Operator, Comparison_Operator, Assignment, Terminating_symbol, LPAREN, RPAREN, LBPAREN, RBPAREN, COMMA, QUOTES, Reject};

bool is_Vtype(string buffer); // buffer 가 Variable Type DFA에 accept 되는지 확인하는 함수이다.
bool is_SignedInt(string buffer); // buffer 가 Signed Integer DFA에 accept 되는지 확인하는 함수이다.
bool is_floating_point_number(string buffer); // buffer 가 Floating Point Number DFA에 accept 되는지 확인하는 함수이다.
bool is_Identifier(string buffer); // buffer 가 Identifier DFA에 accept 되는지 확인하는 함수이다.
bool is_Literal_String(string buffer); // buffer 가 Literal String DFA에 accept 되는지 확인하는 함수이다.
bool is_Boolean_String(string buffer); // buffer 가 Boolean String DFA에 accept 되는지 확인하는 함수이다.
bool is_Keyword(string buffer); // buffer 가 Keyword DFA에 accept 되는지 확인하는 함수이다.
bool is_Arithmetic_Operator(string buffer); // buffer 가 Arithmetic Operator DFA에 accept 되는지 확인하는 함수이다.
bool is_Bitwise_Operator(string buffer); // buffer 가 Bitwise Operator DFA에 accept 되는지 확인하는 함수이다.
bool is_Comparison_Operator(string buffer); // buffer 가 Comparison Operator DFA에 accept 되는지 확인하는 함수이다.
bool is_White_Space(string buffer); // buffer 가 Whitespace DFA에 accept 되는지 확인하는 함수이다.
bool is_Assignment(string buffer); // buffer 가 Assignment DFA에 accept 되는지 확인하는 함수이다.
bool is_Terminating_symbol(string buffer); // buffer 가 Terminating symbol DFA에 accept 되는지 확인하는 함수이다.
bool is_LPAREN(string buffer); // buffer 가 Left_Parenthesis DFA에 accept 되는지 확인하는 함수이다.
bool is_RPAREN(string buffer); // buffer 가 Right_Parenthesis DFA에 accept 되는지 확인하는 함수이다.
bool is_LBPAREN(string buffer); // buffer 가 Left_Brace_Parenthesis DFA에 accept 되는지 확인하는 함수이다.
bool is_RBPAREN(string buffer); // buffer 가 Right_Brace_Parenthesis DFA에 accept 되는지 확인하는 함수이다.
bool is_COMMA(string buffer); // buffer 가 COMMA DFA에 accept 되는지 확인하는 함수이다.
bool is_QUOTES(string buffer); // buffer 가 Quotes DFA에 accept 되는지 확인하는 함수이다.
enum Lex lex_generator(string buffer); // 위의 buffer들을 전부 검사하는 함수이다. 즉 buffer가 우리가 정의한 DFA중 accept되는 DFA를 반환한다. 없다면 reject를 반환
enum Lex Lex;
void init_dfastate(); // dfastate를 초기화 시키기 위한 함수
vector<vector<string>> adjust_CV (vector<vector<string>> CV); // error handling 을 위한 함수, 2차원 벡터를 순회하여 에러가 발생하는 곳을 고치고, 올바른 2차원 벡터를 반환한다.
void Write_to_File (vector<vector<string>> CV); // output을 write하기 위한 함수이다.

int line = 0; // error line check

int main(int argc, const char * argv[]) {
    ifstream fin("test.c");
    string buffer;
    vector<vector<string>> CV;
    vector<string> elemV;
    int j = 0;

    char ch;
    
    //file open
    if(!fin.is_open()){
        cout<<"Error while opening file\n";
        exit(0);
    }
    
    CV.push_back({"Value","Type"});
    
    
    while(!fin.eof()){
        
        //파일을 읽으면서 char를 읽어온뒤 buffer에 char를 추가해 준다.
        ch = fin.get();
        buffer += ch;
        
        //buffer에 저장되어 있는 값이 어떤 DFA에 accept되는가?
        Lex = lex_generator(buffer);
        //그 DFA에 따라서 switch문을 돌게 된다.
        switch(Lex){
                case Vtype:
                elemV = {buffer, "vtype"};
                CV.pop_back();
                CV.push_back(elemV);
                break;
            case SignedInt:
                elemV = {buffer, "num"};
                CV.pop_back();
                CV.push_back(elemV);
                break;
            case Floating_point_number:
                elemV = {buffer, "float"};
                CV.pop_back();
                CV.push_back(elemV);
                break;
            case Identifier:
                elemV = {buffer, "id"};
                CV.pop_back();
                CV.push_back(elemV);
                break;
            case Literal_String:
                elemV = {buffer, "literal"};
                CV.pop_back();
                CV.push_back(elemV);
                break;
            case Boolean_String:
                elemV = {buffer, "Boolean_String"};
                CV.pop_back();
                CV.push_back(elemV);
                break;
            case Keyword:
                elemV = {buffer, "Keyword"};
                CV.pop_back();
                CV.push_back(elemV);
                break;
            case WhiteSpace:
                if(ch == '\n') line++;
                elemV = {buffer, "WhiteSpace"};
                CV.pop_back();
                CV.push_back(elemV);
                break;
            case Arithmetic_Operator:
                elemV = {buffer, "Arithmetic_Operator"};
                CV.pop_back();
                CV.push_back(elemV);
                break;
            case Bitwise_Operator:
                elemV = {buffer, "Bitwise_Operator"};
                CV.pop_back();
                CV.push_back(elemV);
                break;
            case Comparison_Operator:
                elemV = {buffer, "comp"};
                CV.pop_back();
                CV.push_back(elemV);
                break;
            case Assignment:
                elemV = {buffer, "assign"};
                CV.pop_back();
                CV.push_back(elemV);
                break;
            case Terminating_symbol:
                elemV = {buffer, "semi"};
                CV.pop_back();
                CV.push_back(elemV);
                break;
            case LBPAREN:
                elemV = {buffer, "lbrace"};
                CV.pop_back();
                CV.push_back(elemV);
                break;
            case RBPAREN:
                elemV = {buffer, "rbrace"};
                CV.pop_back();
                CV.push_back(elemV);
                break;
            case LPAREN:
                elemV = {buffer, "lparen"};
                CV.pop_back();
                CV.push_back(elemV);
                break;
            case RPAREN:
                elemV = {buffer, "rparen"};
                CV.pop_back();
                CV.push_back(elemV);
                break;
            case COMMA:
                elemV = {buffer, "comma"};
                CV.pop_back();
                CV.push_back(elemV);
                break;
            case QUOTES:
                elemV = {buffer, "QUOTES"};
                CV.pop_back();
                CV.push_back(elemV);
                break;
            case Reject:
                if(buffer[buffer.length()-2] == '.'){
                    cout << "error at ." << endl << "Error line is " << line+1 << endl;
                    exit(2);
                }
                else{
                    if(ch == '.'){
                        if(buffer.front() != '0' && buffer.front() != '1' && buffer.front() != '2' && buffer.front() != '3' && buffer.front() != '4' && buffer.front() != '5' && buffer.front() != '6' && buffer.front() != '7' && buffer.front() != '8' && buffer.front() != '9' && buffer.front() != '-'){
                            cout << "error at " << ch << endl << "Error line is " << line+1 << endl;
                            exit(1);
                        }
                        break;
                    }
                    else if(ch == '0'){
                        if(buffer[buffer.length()-2] == '-'){
                            elemV = {buffer, "-0"};
                            CV.pop_back();
                            CV.push_back(elemV);
                            break;
                        }
                    }
                    
                    Lex = lex_generator(string(1,ch));
                    
                    switch(Lex){
                        case Vtype:
                            elemV = {string(1,ch), "Vtype"};
                            CV.push_back(elemV);
                            buffer = "";
                            buffer += ch;
                            break;
                        case SignedInt:
                            if(ch == '1' || ch == '2' || ch == '3' || ch == '4' || ch == '5' || ch == '6' || ch == '7' || ch == '8' || ch == '9' ){
                                
                                bool flag = false;
                                
                                while(!(CV[CV.size()-j-1][1] != "num")){
                                    if(CV[CV.size()-j-1][1] == "num" && CV[CV.size()-j-1][0] == "0"){
                                        j += 1;
                                    }
                                    else break;
                                    if(CV[CV.size()-j-1][1] == "float") {
                                        flag = true;
                                        break;
                                    }
                                    
                                }
                                

                                if(flag == true) {
                                    for(int a = 0; a < j; a++){
                                          CV.pop_back();
                                      }
                                      buffer = CV[CV.size()-1][0]+string(j,'0')+string(1,ch);
                                      elemV = {buffer, "float"};
                                      CV.pop_back();
                                      CV.push_back(elemV);
                                    j=0;
                                    break;
                                }
                                else if(flag == false){
                                    elemV = {string(1,ch), "num"};
                                    CV.push_back(elemV);
                                    buffer = "";
                                    buffer += ch;
                                    break;
                                }
                                else{break;}
                            }
                            
                            elemV = {string(1,ch), "num"};
                            CV.push_back(elemV);
                            buffer = "";
                            buffer += ch;
                            break;
                        case Floating_point_number:
                            elemV = {string(1,ch), "float"};
                            CV.push_back(elemV);
                            buffer = "";
                            buffer += ch;
                            break;
                        case Identifier:
                            elemV = {string(1,ch), "id"};
                            CV.push_back(elemV);
                            buffer = "";
                            buffer += ch;
                            break;
                        case Literal_String:
                            elemV = {string(1,ch), "literal"};
                            CV.push_back(elemV);
                            buffer = "";
                            buffer += ch;
                            break;
                        case Boolean_String:
                            elemV = {string(1,ch), "Boolean_String"};
                            CV.push_back(elemV);
                            buffer = "";
                            buffer += ch;
                            break;
                        case Keyword:
                            elemV = {string(1,ch), "Keyword"};
                            CV.push_back(elemV);
                            buffer = "";
                            buffer += ch;
                            break;
                        case WhiteSpace:
                            if(ch == '\n') line++;
                            elemV = {string(1,ch), "WhiteSpace"};
                            CV.push_back(elemV);
                            buffer = "";
                            buffer += ch;
                            break;
                        case Arithmetic_Operator:
                            elemV = {string(1,ch), "Arithmetic_Operator"};
                            CV.push_back(elemV);
                            buffer = "";
                            buffer += ch;
                            break;
                        case Bitwise_Operator:
                            elemV = {string(1,ch), "Bitwise_Operator"};
                            CV.push_back(elemV);
                            buffer = "";
                            buffer += ch;
                            break;
                        case Comparison_Operator:
                            elemV = {string(1,ch), "comp"};
                            CV.push_back(elemV);
                            buffer = "";
                            buffer += ch;
                            break;
                        case Assignment:
                            elemV = {string(1,ch), "assign"};
                            CV.push_back(elemV);
                            buffer = "";
                            buffer += ch;
                            break;
                        case Terminating_symbol:
                            elemV = {string(1,ch), "semi"};
                            CV.push_back(elemV);
                            buffer = "";
                            buffer += ch;
                            break;
                        case LBPAREN:
                            elemV = {string(1,ch), "lbrace"};
                            CV.push_back(elemV);
                            buffer = "";
                            buffer += ch;
                            break;
                        case RBPAREN:
                            elemV = {string(1,ch), "rbrace"};
                            CV.push_back(elemV);
                            buffer = "";
                            buffer += ch;
                            break;
                        case LPAREN:
                            elemV = {string(1,ch), "lparen"};
                            CV.push_back(elemV);
                            buffer = "";
                            buffer += ch;
                            break;
                        case RPAREN:
                            elemV = {string(1,ch), "rparen"};
                            CV.push_back(elemV);
                            buffer = "";
                            buffer += ch;
                            break;
                        case COMMA:
                            elemV = {string(1,ch), "comma"};
                            CV.push_back(elemV);
                            buffer = "";
                            buffer += ch;
                            break;
                        case QUOTES:
                            elemV = {string(1,ch), "QUOTES"};
                            CV.push_back(elemV);
                            buffer = "";
                            buffer += ch;
                            break;
                        case Reject:
                            if(ch == ' ' || ch == '\n' || ch == '\t'){
                                elemV = {buffer, "Reject"};
                                CV.push_back(elemV);
                                buffer = "";
                            }
                            else if(ch == '!') {
                                elemV = {string(1,ch), "Reject"};
                                CV.push_back(elemV);
                                buffer = "";
                                buffer += ch;
                            }

                                break;
                        default:
                            break;
                            }
                    }
                
                break;
            default:
                break;
        
        }
    }
    
    CV = adjust_CV(CV);
    
    for(int i = 0; i < CV.size(); i++){
        cout << i+1 << "row : ";
        for(int j = 0; j < CV[i].size(); j++){
            cout << CV[i][j] << " ";
        }
        cout << endl;
    }
    Write_to_File(CV);
    return 0;
}

bool is_Vtype(string buffer){
    
    for(int i = 0; i < buffer.size(); i++){
        if(Vdfastate == Vstate_start) Vdfastate = VT_start(buffer[i]);
        else if(Vdfastate == Vstate_i) Vdfastate = VT_i(buffer[i]);
        else if(Vdfastate == Vstate_in) Vdfastate = VT_in(buffer[i]);
        else if(Vdfastate == Vstate_int) Vdfastate = VT_int(buffer[i]);
        else if(Vdfastate == Vstate_c) Vdfastate = VT_c(buffer[i]);
        else if(Vdfastate == Vstate_ch) Vdfastate = VT_ch(buffer[i]);
        else if(Vdfastate == Vstate_cha) Vdfastate = VT_cha(buffer[i]);
        else if(Vdfastate == Vstate_char) Vdfastate = VT_char(buffer[i]);
        else if(Vdfastate == Vstate_b) Vdfastate = VT_b(buffer[i]);
        else if(Vdfastate == Vstate_bo) Vdfastate = VT_bo(buffer[i]);
        else if(Vdfastate == Vstate_boo) Vdfastate = VT_boo(buffer[i]);
        else if(Vdfastate == Vstate_bool) Vdfastate = VT_bool(buffer[i]);
        else if(Vdfastate == Vstate_f) Vdfastate = VT_f(buffer[i]);
        else if(Vdfastate == Vstate_fl) Vdfastate = VT_fl(buffer[i]);
        else if(Vdfastate == Vstate_flo) Vdfastate = VT_flo(buffer[i]);
        else if(Vdfastate == Vstate_floa) Vdfastate = VT_floa(buffer[i]);
        else if(Vdfastate == Vstate_float) Vdfastate = VT_float(buffer[i]);
        else if(Vdfastate == Vstate_exit) break;
    }
    
    if(Vdfastate == Vstate_int || Vdfastate == Vstate_char || Vdfastate == Vstate_bool || Vdfastate == Vstate_float) {
        
        return true;
    }
    
    else{
        Vdfastate = Vstate_start;
        return false;
    }
}

bool is_SignedInt(string buffer){
    
    for(int i = 0; i < buffer.size(); i++){
        if(dfastate == state_start) dfastate = SI_start(buffer[i]);
        else if(dfastate == state_q0) dfastate = SI_q0(buffer[i]);
        else if(dfastate == state_q1) dfastate = SI_q1(buffer[i]);
        else if(dfastate == state_q2) dfastate = SI_q2(buffer[i]);
        else if(dfastate == state_exit) break;
    }
    
    if(dfastate == state_q1 || dfastate == state_q2) {
        
        return true;
    }
    
    else{
        
        dfastate = state_start;
        return false;
    }
}

bool is_floating_point_number(string buffer){
    
    for(int i = 0; i < buffer.size(); i++){
        if(dfastate == state_start) dfastate = FPN_start(buffer[i]);
        else if(dfastate == state_q0) dfastate = FPN_q0(buffer[i]);
        else if(dfastate == state_q1) dfastate = FPN_q1(buffer[i]);
        else if(dfastate == state_q2) dfastate = FPN_q2(buffer[i]);
        else if(dfastate == state_q3) dfastate = FPN_q3(buffer[i]);
        else if(dfastate == state_q4) dfastate = FPN_q4(buffer[i]);
        else if(dfastate == state_q5) dfastate = FPN_q5(buffer[i]);
        else if(dfastate == state_q6) dfastate = FPN_q6(buffer[i]);
        else if(dfastate == state_exit) break;
    }
    
    if(dfastate == state_q4 || dfastate == state_q6) {
        
        return true;
    }
    else{
        dfastate = state_start;
        return false;
    }
}

bool is_Identifier(string buffer){
    
    for(int i = 0; i < buffer.size(); i++){
        if(dfastate == state_start) dfastate = ID_start(buffer[i]);
        else if(dfastate == state_q0) dfastate = ID_q0(buffer[i]);
        else if(dfastate == state_q1) dfastate = ID_q1(buffer[i]);
        else if(dfastate == state_q2) dfastate = ID_q2(buffer[i]);
        else if(dfastate == state_q3) dfastate = ID_q3(buffer[i]);
        else if(dfastate == state_q4) dfastate = ID_q4(buffer[i]);
        else if(dfastate == state_exit) break;
    }
    
    if(dfastate == state_q0 || dfastate == state_q1 || dfastate == state_q2 ||dfastate == state_q3 ||dfastate == state_q4) {
        
        return true;
    }
    else{
        dfastate = state_start;
        return false;
    }
}

bool is_Literal_String(string buffer){
    
    for(int i = 0; i < buffer.size(); i++){
        if(dfastate == state_start) dfastate = LS_start(buffer[i]);
        else if(dfastate == state_q0) dfastate = LS_q0(buffer[i]);
        else if(dfastate == state_q1) dfastate = LS_q1(buffer[i]);
        else if(dfastate == state_q2) dfastate = LS_q2(buffer[i]);
        else if(dfastate == state_q3) dfastate = LS_q3(buffer[i]);
        else if(dfastate == state_q4) dfastate = LS_q4(buffer[i]);
        else if(dfastate == state_q5) dfastate = LS_q5(buffer[i]);
        else if(dfastate == state_q6) dfastate = LS_q6(buffer[i]);
        else if(dfastate == state_q7) dfastate = LS_q7(buffer[i]);
        else if(dfastate == state_exit) break;
    }
    
    if(dfastate == state_q7){
        
        return true;
    }
    else{
        dfastate = state_start;
        return false;
    }
}

bool is_Arithmetic_Operator(string buffer){
    
    for(int i = 0; i < buffer.size(); i++){
        if(dfastate == state_start) dfastate = AO_start(buffer[i]);
        else if(dfastate == state_q0) dfastate = AO_q0(buffer[i]);
        else if(dfastate == state_q1) dfastate = AO_q1(buffer[i]);
        else if(dfastate == state_q2) dfastate = AO_q2(buffer[i]);
        else if(dfastate == state_q3) dfastate = AO_q3(buffer[i]);
        else if(dfastate == state_exit) break;
    }
    
    if(dfastate == state_q0 || dfastate == state_q1 || dfastate == state_q2 || dfastate == state_q3){
        
        return true;
    }
    else{
        dfastate = state_start;
        return false;
    }
}

bool is_Bitwise_Operator(string buffer){
    
    for(int i = 0; i<buffer.size();i++){
        if(dfastate == state_start) dfastate = BO_start(buffer[i]);
        else if(dfastate == state_q0) dfastate = BO_q0(buffer[i]);
        else if(dfastate == state_q1) dfastate = BO_q1(buffer[i]);
        else if(dfastate == state_q2) dfastate = BO_q2(buffer[i]);
        else if(dfastate == state_exit) break;
    }
    
    if(dfastate == state_q2){
        
        return true;
    }
    else{
        dfastate = state_start;
        return false;
    }
    
}

bool is_Comparison_Operator(string buffer){
    
    for(int i = 0; i<buffer.size();i++){
        if(dfastate == state_start) dfastate = CO_start(buffer[i]);
        else if(dfastate == state_q0) dfastate = CO_q0(buffer[i]);
        else if(dfastate == state_q1) dfastate = CO_q1(buffer[i]);
        else if(dfastate == state_q2) dfastate = CO_q2(buffer[i]);
        else if(dfastate == state_exit) break;
    }
    
    if(dfastate == state_q0 || dfastate == state_q2){
        
        return true;
    }
    else{
        dfastate = state_start;
        return false;
    }
    
}

bool is_Boolean_String(string buffer){
    
    for(int i = 0; i < buffer.size(); i++){
        if(BSdfastate == BSstate_start) BSdfastate = BS_start(buffer[i]);
        else if(BSdfastate == BSstate_t) BSdfastate = BS_t(buffer[i]);
        else if(BSdfastate == BSstate_tr) BSdfastate = BS_tr(buffer[i]);
        else if(BSdfastate == BSstate_tru) BSdfastate = BS_tru(buffer[i]);
        else if(BSdfastate == BSstate_true) BSdfastate = BS_true(buffer[i]);
        else if(BSdfastate == BSstate_f) BSdfastate = BS_f(buffer[i]);
        else if(BSdfastate == BSstate_fa) BSdfastate = BS_fa(buffer[i]);
        else if(BSdfastate == BSstate_fal) BSdfastate = BS_fal(buffer[i]);
        else if(BSdfastate == BSstate_fals) BSdfastate = BS_fals(buffer[i]);
        else if(BSdfastate == BSstate_false) BSdfastate = BS_false(buffer[i]);
        else if(BSdfastate == BSstate_exit) break;
    }
    
    if(BSdfastate == BSstate_true || BSdfastate == BSstate_false){
        
        return true;
    }
    else{
        BSdfastate = BSstate_start;
        return false;
    }
}

bool is_Keyword(string buffer){
    
    for(int i = 0; i < buffer.size(); i++){
        if(Kdfastate == Kstate_start) Kdfastate = K_start(buffer[i]);
        else if(Kdfastate == Kstate_i) Kdfastate = K_i(buffer[i]);
        else if(Kdfastate == Kstate_if) Kdfastate = K_if(buffer[i]);
        else if(Kdfastate == Kstate_e) Kdfastate = K_e(buffer[i]);
        else if(Kdfastate == Kstate_el) Kdfastate = K_el(buffer[i]);
        else if(Kdfastate == Kstate_els) Kdfastate = K_els(buffer[i]);
        else if(Kdfastate == Kstate_else) Kdfastate = K_else(buffer[i]);
        else if(Kdfastate == Kstate_w) Kdfastate = K_w(buffer[i]);
        else if(Kdfastate == Kstate_wh) Kdfastate = K_wh(buffer[i]);
        else if(Kdfastate == Kstate_whi) Kdfastate = K_whi(buffer[i]);
        else if(Kdfastate == Kstate_whil) Kdfastate = K_whil(buffer[i]);
        else if(Kdfastate == Kstate_while) Kdfastate = K_while(buffer[i]);
        else if(Kdfastate == Kstate_f) Kdfastate = K_f(buffer[i]);
        else if(Kdfastate == Kstate_fo) Kdfastate = K_fo(buffer[i]);
        else if(Kdfastate == Kstate_for) Kdfastate = K_for(buffer[i]);
        else if(Kdfastate == Kstate_r) Kdfastate = K_r(buffer[i]);
        else if(Kdfastate == Kstate_re) Kdfastate = K_re(buffer[i]);
        else if(Kdfastate == Kstate_ret) Kdfastate = K_ret(buffer[i]);
        else if(Kdfastate == Kstate_retu) Kdfastate = K_retu(buffer[i]);
        else if(Kdfastate == Kstate_retur) Kdfastate = K_retur(buffer[i]);
        else if(Kdfastate == Kstate_return) Kdfastate = K_return(buffer[i]);
        else if(Kdfastate == Kstate_exit) break;
    }
    
    if(Kdfastate == Kstate_if || Kdfastate == Kstate_else || Kdfastate == Kstate_while || Kdfastate == Kstate_for || Kdfastate == Kstate_return){
        return true;
    }
    
    else{
        Kdfastate = Kstate_start;
        return false;
    }
    
}

bool is_White_Space(string buffer){
    
    for(int i = 0; i < buffer.size(); i++){
        if(dfastate == state_start) dfastate = WS_start(buffer[i]);
        else if(dfastate == state_q0) dfastate = WS_q0(buffer[i]);
        else if(dfastate == state_q1) dfastate = WS_q1(buffer[i]);
        else if(dfastate == state_q2) dfastate = WS_q2(buffer[i]);
        else if(dfastate == state_exit) break;
    }
    
    if(dfastate == state_q0 || dfastate == state_q1 || dfastate == state_q2){
        return true;
    }
    
    else{
        dfastate = state_start;
        return false;
    }
}

bool is_Assignment(string buffer){
    
    for(int i = 0; i < buffer.size(); i++){
        if(dfastate == state_start) dfastate = Asmt_start(buffer[i]);
        else if(dfastate == state_q0) dfastate = Asmt_q0(buffer[i]);
        else if(dfastate == state_exit) break;
    }
    
    if(dfastate == state_q0){
        return true;
    }
    
    else{
        dfastate = state_start;
        return false;
    }
}

bool is_Terminating_symbol(string buffer){
    
    for(int i = 0; i < buffer.size(); i++){
        if(dfastate == state_start) dfastate = Ter_start(buffer[i]);
        else if(dfastate == state_q0) dfastate = Ter_q0(buffer[i]);
        else if(dfastate == state_exit) break;
    }
    
    if(dfastate == state_q0){
        return true;
    }
    
    else{
        dfastate = state_start;
        return false;
    }
}

bool is_LPAREN(string buffer){
    
    for(int i = 0; i < buffer.size(); i++){
        if(dfastate == state_start) dfastate = LP_start(buffer[i]);
        else if(dfastate == state_q0) dfastate = LP_q0(buffer[i]);
        else if(dfastate == state_exit) break;
    }
    
    if(dfastate == state_q0){
        return true;
    }
    
    else{
        dfastate = state_start;
        return false;
    }
}

bool is_RPAREN(string buffer){
    
    for(int i = 0; i < buffer.size(); i++){
        if(dfastate == state_start) dfastate = RP_start(buffer[i]);
        else if(dfastate == state_q0) dfastate = RP_q0(buffer[i]);
        else if(dfastate == state_exit) break;
    }
    
    if(dfastate == state_q0){
        return true;
    }
    
    else{
        dfastate = state_start;
        return false;
    }
}

bool is_LBPAREN(string buffer){
    
    for(int i = 0; i < buffer.size(); i++){
        if(dfastate == state_start) dfastate = LBP_start(buffer[i]);
        else if(dfastate == state_q0) dfastate = LBP_q0(buffer[i]);
        else if(dfastate == state_exit) break;
    }
    
    if(dfastate == state_q0){
        return true;
    }
    
    else{
        dfastate = state_start;
        return false;
    }
}

bool is_RBPAREN(string buffer){
    
    for(int i = 0; i < buffer.size(); i++){
        if(dfastate == state_start) dfastate = RBP_start(buffer[i]);
        else if(dfastate == state_q0) dfastate = RBP_q0(buffer[i]);
        else if(dfastate == state_exit) break;
    }
    
    if(dfastate == state_q0){
        return true;
    }
    
    else{
        dfastate = state_start;
        return false;
    }
}

bool is_COMMA(string buffer){
    
    for(int i = 0; i < buffer.size(); i++){
        if(dfastate == state_start) dfastate = CM_start(buffer[i]);
        else if(dfastate == state_q0) dfastate = CM_q0(buffer[i]);
        else if(dfastate == state_exit) break;
    }
    
    if(dfastate == state_q0){
        return true;
    }
    
    else{
        dfastate = state_start;
        return false;
    }
}

bool is_QUOTES(string buffer){
    
    for(int i = 0; i < buffer.size(); i++){
        if(dfastate == state_start) dfastate = QT_start(buffer[i]);
        else if(dfastate == state_q0) dfastate = QT_q0(buffer[i]);
        else if(dfastate == state_exit) break;
    }
    
    if(dfastate == state_q0){
        return true;
    }
    
    else{
        dfastate = state_start;
        return false;
    }
}


void init_dfastate(){
    dfastate = state_start;
    Vdfastate = Vstate_start;
    BSdfastate = BSstate_start;
    Kdfastate = Kstate_start;
}

enum Lex lex_generator(string buffer){
    if(is_Vtype(buffer)) {
        init_dfastate();
        return Vtype;
    }
    else if(is_floating_point_number(buffer)) {
        init_dfastate();
        return Floating_point_number;
    }
    else if(is_SignedInt(buffer)) {
        init_dfastate();
        return SignedInt;
    }
    else if(is_Keyword(buffer)) {
        init_dfastate();
        return Keyword;
    }
    else if(is_Boolean_String(buffer)) {
        init_dfastate();
        return Boolean_String;
    }
    else if(is_Literal_String(buffer)) {
        init_dfastate();
        return Literal_String;
    }
    else if(is_Identifier(buffer)) {
        init_dfastate();
        return Identifier;
    }
    else if(is_White_Space(buffer)){
        init_dfastate();
        return WhiteSpace;
    }
    else if(is_Arithmetic_Operator(buffer)){
        init_dfastate();
        return Arithmetic_Operator;
    }
    else if(is_Bitwise_Operator(buffer)){
        init_dfastate();
        return Bitwise_Operator;
    }
    else if(is_Comparison_Operator(buffer)){
        init_dfastate();
        return Comparison_Operator;
    }
    else if(is_Assignment(buffer)){
        init_dfastate();
        return Assignment;
    }
    else if(is_Terminating_symbol(buffer)){
        init_dfastate();
        return Terminating_symbol;
    }
    else if(is_LPAREN(buffer)){
        init_dfastate();
        return LPAREN;
    }
    else if(is_RPAREN(buffer)){
        init_dfastate();
        return RPAREN;
    }
    else if(is_LBPAREN(buffer)){
        init_dfastate();
        return LBPAREN;
    }
    else if(is_RBPAREN(buffer)){
        init_dfastate();
        return RBPAREN;
    }
    else if(is_COMMA(buffer)){
        init_dfastate();
        return COMMA;
    }
    else if(is_QUOTES(buffer)){
        init_dfastate();
        return QUOTES;
    }
    else {
        init_dfastate();
        return Reject;
    }
}

vector<vector<string>> adjust_CV (vector<vector<string>> CV){
    vector<vector<string>> new_CV = CV;
    int quotes_cnt = 0;
    vector<int> list;
    
    // Find Literal String and merge
    for(int i = 0; i < new_CV.size(); i++){
        if(new_CV[i][0] == "\"") {
            quotes_cnt++;}
    }
    
    if(quotes_cnt%2 == 0){
        for(int i = 0; i < new_CV.size(); i++){
            if(new_CV[i][0] == "\""){
                list.push_back(i);
            }
        }
        while(!(list.empty())){
            int start, end;
            end = list.back();
            list.pop_back();
            start = list.back();
            list.pop_back();
            for(int j = 1; j < end-start-1; j++){
                new_CV[start+1] = {string(new_CV[start+1][0]+new_CV[start+1+j][0]), "literal"};
            }
            new_CV[start+1] = {"\"" + string(new_CV[start+1][0]) + "\"","literal"};
            new_CV.erase(new_CV.begin()+start+2,new_CV.begin()+end);
        }
    }

    // IF there is Odd Quotes "ERROR"
    else if(quotes_cnt%2 == 1){
        cout << "Quotes not match" << endl << "Error line is " << line+1 << endl;
        exit(3);
    }
    
    // Reduce QUOTES And WhiteSpace in CV
    for(int i = 0; i < new_CV.size(); i++){
        if(new_CV[i][1] == "QUOTES" || new_CV[i][1] == "WhiteSpace"){
            list.push_back(i);
        }
    }
    
    while(!(list.empty())){
        int index;
        index = list.back();
        list.pop_back();
        new_CV.erase(new_CV.begin()+index);
    }
    
    // Rejecting if only '!' appeared
    for(int i = 0; i < new_CV.size(); i++){
        if(new_CV[i][1] == "Reject") {
            cout << "There is '!' error!" << endl << "Error line is " << line+1 << endl;
            exit(4);
        }
    }
    
    // Translate -0 to - and 0
    for(int i = 0; i < new_CV.size(); i++){
        if(new_CV[i][1] == "-0"){
            list.push_back(i);
        }
    }
    
    while(!(list.empty())){
        int index;
        index = list.back();
        list.pop_back();
        new_CV[index] = {"-","Arithmetic_Operator"};
        new_CV.insert(new_CV.begin()+index+1, {"0","num"});
    }
    
    for(int i = 0; i < list.size(); i++){
        cout << i << "th list" << list[i] << endl;
    }
    
    // Check '-' is Operator or minus for signed integer
    for(int i = 0; i < new_CV.size(); i++){
        if(new_CV[i][1] == "num" && new_CV[i][0].front() == '-'){
            list.push_back(i);
        }
    }
    
    while(!(list.empty())){
        int index;
        index = list.back();
        list.pop_back();
        string temp;
        if(new_CV[index-1][1] == "num" || new_CV[index-1][1] == "float" || new_CV[index-1][1] == "id"){
            temp = string(new_CV[index][0]);
            new_CV[index] = {"-","Arithmetic_Operator"};
            new_CV.insert(new_CV.begin()+index+1, {temp.substr(1,temp.length()),"num"});
        }
    }
    return new_CV;
}

void Write_to_File(vector<vector<string>> CV){
    ofstream writeFile;
    writeFile.open("output.txt");
    writeFile.clear();
    
    for(int i = 0; i < CV.size(); i++){
        if(CV[i][0] == "if") writeFile << "if" << endl;
        else if(CV[i][0] == "else") writeFile << "else" << endl;
        else if(CV[i][0] == "for") writeFile << "for" << endl;
        else if(CV[i][0] == "while") writeFile << "while" << endl;
        else if(CV[i][0] == "return") writeFile << "return" << endl;
        else if(CV[i][0] == "+" || CV[i][0] == "-") writeFile << "addsub" << endl;
        else if(CV[i][0] == "*" || CV[i][0] == "/") writeFile << "multdiv" << endl;

        else writeFile << CV[i][1] << endl;
    }
    writeFile << "$";
    writeFile.close();
    cout << "File is Written and Closed" << endl;
}
