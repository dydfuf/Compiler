//
//  dfa.hpp
//  Compiler
//
//  Created by 최용렬 on 2020/05/06.
//  Copyright © 2020 최용렬. All rights reserved.
//
#ifndef dfa_hpp
#define dfa_hpp
#include <stdio.h>
#include <stdlib.h>

using namespace std;

/*inline enum value 를 선언한 것입니다.
 우리가 그린 dfa에는 최대 8가지의 스테이트가 있다고 할 수 있는데, 여기에 start state, 그리고 dfa를 빠져나오기 위한 state_exit*/
enum State {state_start, state_q0, state_q1, state_q2, state_q3, state_q4, state_q5, state_q6, state_q7, state_exit};

/*위와는 다르게 Variable type, Boolean String, Keyword 는 dfa를 그린다면 정해진 순서대로 가지만, 많은 스테이트들이 생성된다.
 따라서 코딩시에 가독성을 위해, 그리고 디버깅의 용이성을 위해 아래와 같이 선언해 주었다.*/
enum Vstate {Vstate_start, Vstate_i, Vstate_in, Vstate_int, Vstate_b, Vstate_bo, Vstate_boo, Vstate_bool, Vstate_c, Vstate_ch, Vstate_cha, Vstate_char, Vstate_f, Vstate_fl, Vstate_flo, Vstate_floa, Vstate_float, Vstate_exit};

enum BSstate {BSstate_start, BSstate_t, BSstate_tr, BSstate_tru, BSstate_true, BSstate_f, BSstate_fa, BSstate_fal, BSstate_fals, BSstate_false, BSstate_exit};

enum Kstate {Kstate_start, Kstate_i, Kstate_if, Kstate_e, Kstate_el, Kstate_els, Kstate_else, Kstate_w, Kstate_wh, Kstate_whi, Kstate_whil, Kstate_while, Kstate_f, Kstate_fo, Kstate_for, Kstate_r, Kstate_re, Kstate_ret, Kstate_retu, Kstate_retur, Kstate_return, Kstate_exit};

// For signed Integer
inline enum State SI_start(int c);
inline enum State SI_q0(int c);
inline enum State SI_q1(int c);
inline enum State SI_q2(int c);

// For Floating_Point_number
inline enum State FPN_start(int c);
inline enum State FPN_q0(int c);
inline enum State FPN_q1(int c);
inline enum State FPN_q2(int c);
inline enum State FPN_q3(int c);
inline enum State FPN_q4(int c);
inline enum State FPN_q5(int c);
inline enum State FPN_q6(int c);

// For Identifier
inline enum State ID_start(int c);
inline enum State ID_q0(int c);
inline enum State ID_q1(int c);
inline enum State ID_q2(int c);
inline enum State ID_q3(int c);
inline enum State ID_q4(int c);

// For WhiteSpace
inline enum State WS_start(int c);
inline enum State WS_q0(int c);
inline enum State WS_q1(int c);
inline enum State WS_q2(int c);

// For Literal String
inline enum State LS_start(int c);
inline enum State LS_q0(int c);
inline enum State LS_q1(int c);
inline enum State LS_q2(int c);
inline enum State LS_q3(int c);
inline enum State LS_q4(int c);
inline enum State LS_q5(int c);
inline enum State LS_q6(int c);
inline enum State LS_q7(int c);

// For Arithmetic Operator
inline enum State AO_start(int c);
inline enum State AO_q0(int c);
inline enum State AO_q1(int c);
inline enum State AO_q2(int c);
inline enum State AO_q3(int c);

// For Bitwise Operator
inline enum State BO_start(int c);
inline enum State BO_q0(int c);
inline enum State BO_q1(int c);
inline enum State BO_q2(int c);

// For Comparison
inline enum State CO_start(int c);
inline enum State CO_q0(int c);
inline enum State CO_q1(int c);
inline enum State CO_q2(int c);

// For Assignment operator
inline enum State Asmt_start(int c);
inline enum State Asmt_q0(int c);

// For Terminating symbol
inline enum State Ter_start(int c);
inline enum State Ter_q0(int c);

// For Left_Brace_Parenthesis
inline enum State LBP_start(int c);
inline enum State LBP_q0(int c);

// For Right_Brace_Parenthesis
inline enum State RBP_start(int c);
inline enum State RBP_q0(int c);

// For Left_Parenthesis
inline enum State LP_start(int c);
inline enum State LP_q0(int c);

// For Right_Parenthesis
inline enum State RP_start(int c);
inline enum State RP_q0(int c);

// For Comma
inline enum State CM_start(int c);
inline enum State CM_q0(int c);

// For Quotes
inline enum State QT_start(int c);
inline enum State QT_q0(int c);

/* VType */
inline enum Vstate VT_start(int c);
inline enum Vstate VT_i(int c);
inline enum Vstate VT_in(int c);
inline enum Vstate VT_int(int c);
inline enum Vstate VT_b(int c);
inline enum Vstate VT_bo(int c);
inline enum Vstate VT_boo(int c);
inline enum Vstate VT_bool(int c);
inline enum Vstate VT_c(int c);
inline enum Vstate VT_ch(int c);
inline enum Vstate VT_cha(int c);
inline enum Vstate VT_char(int c);
inline enum Vstate VT_f(int c);
inline enum Vstate VT_fl(int c);
inline enum Vstate VT_flo(int c);
inline enum Vstate VT_floa(int c);
inline enum Vstate VT_float(int c);

/* Boolean String */
inline enum BSstate BS_start(int c);
inline enum BSstate BS_t(int c);
inline enum BSstate BS_tr(int c);
inline enum BSstate BS_tru(int c);
inline enum BSstate BS_true(int c);
inline enum BSstate BS_f(int c);
inline enum BSstate BS_fa(int c);
inline enum BSstate BS_fal(int c);
inline enum BSstate BS_fals(int c);
inline enum BSstate BS_false(int c);

/* Keyword */
inline enum Kstate K_start(int c);
inline enum Kstate K_i(int c);
inline enum Kstate K_if(int c);
inline enum Kstate K_e(int c);
inline enum Kstate K_el(int c);
inline enum Kstate K_els(int c);
inline enum Kstate K_else(int c);
inline enum Kstate K_w(int c);
inline enum Kstate K_wh(int c);
inline enum Kstate K_whi(int c);
inline enum Kstate K_whil(int c);
inline enum Kstate K_while(int c);
inline enum Kstate K_f(int c);
inline enum Kstate K_fo(int c);
inline enum Kstate K_for(int c);
inline enum Kstate K_r(int c);
inline enum Kstate K_re(int c);
inline enum Kstate K_ret(int c);
inline enum Kstate K_retu(int c);
inline enum Kstate K_retur(int c);
inline enum Kstate K_return(int c);

#endif /* dfa_hpp */
