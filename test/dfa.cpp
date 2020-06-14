//
//  dfa.cpp
//  Compiler
//
//  Created by 최용렬 on 2020/05/06.
//  Copyright © 2020 최용렬. All rights reserved.
//

#include "dfa.hpp"

// init dfastate to start state
inline enum State dfastate = state_start;
inline enum Vstate Vdfastate = Vstate_start;
inline enum BSstate BSdfastate = BSstate_start;
inline enum Kstate Kdfastate = Kstate_start;

// Signed Integer DFA의 전이들을 나타내기 위한 함수들 이다.

enum State SI_start(int c){
    if (c == '-') dfastate = state_q0;
    else if(c == '0') dfastate = state_q1;
    else if(c == '1' || c == '2' || c == '3' || c == '4' || c == '5' || c == '6' || c == '7' || c == '8' || c == '9' ) dfastate = state_q2;
    else dfastate = state_exit;
    return dfastate;
}

  enum State SI_q0(int c){
    if(c == '1' || c == '2' || c == '3' || c == '4' || c == '5' || c == '6' || c == '7' || c == '8' || c == '9' ) dfastate = state_q2;
    else dfastate = state_exit;
    return dfastate;
}

  enum State SI_q1(int c){
    dfastate = state_exit;
    return dfastate;
}

  enum State SI_q2(int c){
    if (c == '1' || c == '2' || c == '3' || c == '4' || c == '5' || c == '6' || c == '7' || c == '8' || c == '9' || c == '0') dfastate = state_q2;
    else dfastate = state_exit;
    return dfastate;
}

// Floating_Point_Number DFA의 전이들을 나타내기 위한 함수들 이다.

  enum State FPN_start(int c){
    if(c == '-') dfastate = state_q0;
    else if(c == '0') dfastate = state_q1;
    else if(c == '1' || c == '2' || c == '3' || c == '4' || c == '5' || c == '6' || c == '7' || c == '8' || c == '9' ) dfastate = state_q2;
    else dfastate = state_exit;
    return dfastate;
}

  enum State FPN_q0(int c){
    if(c == '0') dfastate = state_q1;
    else if(c == '1' || c == '2' || c == '3' || c == '4' || c == '5' || c == '6' || c == '7' || c == '8' || c == '9' ) dfastate = state_q2;
    else dfastate = state_exit;
    return dfastate;
}

  enum State FPN_q1(int c){
    if(c == '.' ) dfastate = state_q3;
    else dfastate = state_exit;
    return dfastate;

}
  enum State FPN_q2(int c){
    if(c == '1' || c == '2' || c == '3' || c == '4' || c == '5' || c == '6' || c == '7' || c == '8' || c == '9' || c == '0') dfastate = state_q2;
    else if(c == '.') dfastate = state_q3;
    else dfastate = state_exit;
    return dfastate;

}
 enum State FPN_q3(int c){
    if(c == '1' || c == '2' || c == '3' || c == '4' || c == '5' || c == '6' || c == '7' || c == '8' || c == '9') dfastate = state_q6;
    else if(c == '0') dfastate = state_q4;
    else dfastate = state_exit;
    return dfastate;

}
 enum State FPN_q4(int c){
    if(c == '1' || c == '2' || c == '3' || c == '4' || c == '5' || c == '6' || c == '7' || c == '8' || c == '9') dfastate = state_q6;
    else if(c == '0') dfastate = state_q5;
    else dfastate = state_exit;
    return dfastate;
}
 enum State FPN_q5(int c){
    if(c == '1' || c == '2' || c == '3' || c == '4' || c == '5' || c == '6' || c == '7' || c == '8' || c == '9') dfastate = state_q6;
    else if(c == '0') dfastate = state_q5;
    else dfastate = state_exit;
    return dfastate;
}

 enum State FPN_q6(int c){
    if(c == '1' || c == '2' || c == '3' || c == '4' || c == '5' || c == '6' || c == '7' || c == '8' || c == '9') dfastate = state_q6;
    else if(c == '0') dfastate = state_q5;
    else dfastate = state_exit;
    return dfastate;
}

// Identifier DFA의 전이들을 나타내기 위한 함수들 이다.

 enum State ID_start(int c){
    if(c == '_') dfastate = state_q1;
    else if(c == 'a' || c == 'b' || c == 'c' || c == 'd' || c == 'e' || c == 'f' || c == 'g' || c == 'h' || c == 'i' || c == 'j' || c == 'k' || c == 'l' || c == 'm' || c == 'n' || c == 'o' || c == 'p' || c == 'q' || c == 'r' || c == 's' || c == 't' || c == 'u' || c == 'v' || c == 'w' || c == 'x' || c == 'y' || c == 'z' || c == 'A' || c == 'B' || c == 'C' || c == 'D' || c == 'E' || c == 'F' || c == 'G' || c == 'H' || c == 'I' || c == 'J' || c == 'K' || c == 'L' || c == 'M' || c == 'N' || c == 'O' || c == 'P' || c == 'Q' || c == 'R' || c == 'S' || c == 'T' || c == 'U' || c == 'V' || c == 'W' || c == 'X' || c == 'Y' || c == 'Z') dfastate = state_q0;
    else dfastate = state_exit;
    return dfastate;
}

 enum State ID_q0(int c){
    if(c == 'a' || c == 'b' || c == 'c' || c == 'd' || c == 'e' || c == 'f' || c == 'g' || c == 'h' || c == 'i' || c == 'j' || c == 'k' || c == 'l' || c == 'm' || c == 'n' || c == 'o' || c == 'p' || c == 'q' || c == 'r' || c == 's' || c == 't' || c == 'u' || c == 'v' || c == 'w' || c == 'x' || c == 'y' || c == 'z' || c == 'A' || c == 'B' || c == 'C' || c == 'D' || c == 'E' || c == 'F' || c == 'G' || c == 'H' || c == 'I' || c == 'J' || c == 'K' || c == 'L' || c == 'M' || c == 'N' || c == 'O' || c == 'P' || c == 'Q' || c == 'R' || c == 'S' || c == 'T' || c == 'U' || c == 'V' || c == 'W' || c == 'X' || c == 'Y' || c == 'Z') dfastate = state_q2;
    else if(c == '1' || c == '2' || c == '3' || c == '4' || c == '5' || c == '6' || c == '7' || c == '8' || c == '9' || c == '0') dfastate = state_q3;
    else if(c == '_') dfastate = state_q4;
    else dfastate = state_exit;
    return dfastate;
}

 enum State ID_q1(int c){
    if(c == 'a' || c == 'b' || c == 'c' || c == 'd' || c == 'e' || c == 'f' || c == 'g' || c == 'h' || c == 'i' || c == 'j' || c == 'k' || c == 'l' || c == 'm' || c == 'n' || c == 'o' || c == 'p' || c == 'q' || c == 'r' || c == 's' || c == 't' || c == 'u' || c == 'v' || c == 'w' || c == 'x' || c == 'y' || c == 'z' || c == 'A' || c == 'B' || c == 'C' || c == 'D' || c == 'E' || c == 'F' || c == 'G' || c == 'H' || c == 'I' || c == 'J' || c == 'K' || c == 'L' || c == 'M' || c == 'N' || c == 'O' || c == 'P' || c == 'Q' || c == 'R' || c == 'S' || c == 'T' || c == 'U' || c == 'V' || c == 'W' || c == 'X' || c == 'Y' || c == 'Z') dfastate = state_q2;
    else if(c == '1' || c == '2' || c == '3' || c == '4' || c == '5' || c == '6' || c == '7' || c == '8' || c == '9' || c == '0') dfastate = state_q3;
    else if(c == '_') dfastate = state_q4;
    else dfastate = state_exit;
    return dfastate;
}

 enum State ID_q2(int c){
    if(c == 'a' || c == 'b' || c == 'c' || c == 'd' || c == 'e' || c == 'f' || c == 'g' || c == 'h' || c == 'i' || c == 'j' || c == 'k' || c == 'l' || c == 'm' || c == 'n' || c == 'o' || c == 'p' || c == 'q' || c == 'r' || c == 's' || c == 't' || c == 'u' || c == 'v' || c == 'w' || c == 'x' || c == 'y' || c == 'z' || c == 'A' || c == 'B' || c == 'C' || c == 'D' || c == 'E' || c == 'F' || c == 'G' || c == 'H' || c == 'I' || c == 'J' || c == 'K' || c == 'L' || c == 'M' || c == 'N' || c == 'O' || c == 'P' || c == 'Q' || c == 'R' || c == 'S' || c == 'T' || c == 'U' || c == 'V' || c == 'W' || c == 'X' || c == 'Y' || c == 'Z') dfastate = state_q2;
    else if(c == '1' || c == '2' || c == '3' || c == '4' || c == '5' || c == '6' || c == '7' || c == '8' || c == '9' || c == '0') dfastate = state_q3;
    else if(c == '_') dfastate = state_q4;
    else dfastate = state_exit;
    return dfastate;
}

 enum State ID_q3(int c){
    if(c == 'a' || c == 'b' || c == 'c' || c == 'd' || c == 'e' || c == 'f' || c == 'g' || c == 'h' || c == 'i' || c == 'j' || c == 'k' || c == 'l' || c == 'm' || c == 'n' || c == 'o' || c == 'p' || c == 'q' || c == 'r' || c == 's' || c == 't' || c == 'u' || c == 'v' || c == 'w' || c == 'x' || c == 'y' || c == 'z' || c == 'A' || c == 'B' || c == 'C' || c == 'D' || c == 'E' || c == 'F' || c == 'G' || c == 'H' || c == 'I' || c == 'J' || c == 'K' || c == 'L' || c == 'M' || c == 'N' || c == 'O' || c == 'P' || c == 'Q' || c == 'R' || c == 'S' || c == 'T' || c == 'U' || c == 'V' || c == 'W' || c == 'X' || c == 'Y' || c == 'Z') dfastate = state_q2;
    else if(c == '1' || c == '2' || c == '3' || c == '4' || c == '5' || c == '6' || c == '7' || c == '8' || c == '9' || c == '0') dfastate = state_q3;
    else if(c == '_') dfastate = state_q4;
    else dfastate = state_exit;
    return dfastate;
}

 enum State ID_q4(int c){
    if(c == 'a' || c == 'b' || c == 'c' || c == 'd' || c == 'e' || c == 'f' || c == 'g' || c == 'h' || c == 'i' || c == 'j' || c == 'k' || c == 'l' || c == 'm' || c == 'n' || c == 'o' || c == 'p' || c == 'q' || c == 'r' || c == 's' || c == 't' || c == 'u' || c == 'v' || c == 'w' || c == 'x' || c == 'y' || c == 'z' || c == 'A' || c == 'B' || c == 'C' || c == 'D' || c == 'E' || c == 'F' || c == 'G' || c == 'H' || c == 'I' || c == 'J' || c == 'K' || c == 'L' || c == 'M' || c == 'N' || c == 'O' || c == 'P' || c == 'Q' || c == 'R' || c == 'S' || c == 'T' || c == 'U' || c == 'V' || c == 'W' || c == 'X' || c == 'Y' || c == 'Z') dfastate = state_q2;
    else if(c == '1' || c == '2' || c == '3' || c == '4' || c == '5' || c == '6' || c == '7' || c == '8' || c == '9' || c == '0') dfastate = state_q3;
    else if(c == '_') dfastate = state_q4;
    else dfastate = state_exit;
    return dfastate;
}

// WhiteSpace DFA의 전이들을 나타내기 위한 함수들 이다.

 enum State WS_start(int c){
    if(c == '\t') dfastate = state_q0;
    else if(c == '\n') dfastate = state_q1;
    else if(c == ' ') dfastate = state_q2;
    else dfastate = state_exit;
    return dfastate;
}

 enum State WS_q0(int c){
    if(c == '\t') dfastate = state_q0;
    else if(c == '\n') dfastate = state_q1;
    else if(c == ' ') dfastate = state_q2;
    else dfastate = state_exit;
    return dfastate;
}

 enum State WS_q1(int c){
    if(c == '\t') dfastate = state_q0;
    else if(c == '\n') dfastate = state_q1;
    else if(c == ' ') dfastate = state_q2;
    else dfastate = state_exit;
    return dfastate;
}

 enum State WS_q2(int c){
    if(c == '\t') dfastate = state_q0;
    else if(c == '\n') dfastate = state_q1;
    else if(c == ' ') dfastate = state_q2;
    else dfastate = state_exit;
    return dfastate;
}

// Literal String DFA의 전이들을 나타내기 위한 함수들 이다.

 enum State LS_start(int c){
    if(c =='\"') dfastate = state_q0;
    else dfastate = state_exit;
    return dfastate;
}

 enum State LS_q0(int c){
    if(c == 'a' || c == 'b' || c == 'c' || c == 'd' || c == 'e' || c == 'f' || c == 'g' || c == 'h' || c == 'i' || c == 'j' || c == 'k' || c == 'l' || c == 'm' || c == 'n' || c == 'o' || c == 'p' || c == 'q' || c == 'r' || c == 's' || c == 't' || c == 'u' || c == 'v' || c == 'w' || c == 'x' || c == 'y' || c == 'z' || c == 'A' || c == 'B' || c == 'C' || c == 'D' || c == 'E' || c == 'F' || c == 'G' || c == 'H' || c == 'I' || c == 'J' || c == 'K' || c == 'L' || c == 'M' || c == 'N' || c == 'O' || c == 'P' || c == 'Q' || c == 'R' || c == 'S' || c == 'T' || c == 'U' || c == 'V' || c == 'W' || c == 'X' || c == 'Y' || c == 'Z') dfastate = state_q1;
    else if(c == '1' || c == '2' || c == '3' || c == '4' || c == '5' || c == '6' || c == '7' || c == '8' || c == '9' || c == '0') dfastate = state_q2;
    else if(c == '\t' || c == '\n' || c == ' ') dfastate = state_q3;
    else dfastate = state_exit;
    return dfastate;
}

 enum State LS_q1(int c){
    if(c == 'a' || c == 'b' || c == 'c' || c == 'd' || c == 'e' || c == 'f' || c == 'g' || c == 'h' || c == 'i' || c == 'j' || c == 'k' || c == 'l' || c == 'm' || c == 'n' || c == 'o' || c == 'p' || c == 'q' || c == 'r' || c == 's' || c == 't' || c == 'u' || c == 'v' || c == 'w' || c == 'x' || c == 'y' || c == 'z' || c == 'A' || c == 'B' || c == 'C' || c == 'D' || c == 'E' || c == 'F' || c == 'G' || c == 'H' || c == 'I' || c == 'J' || c == 'K' || c == 'L' || c == 'M' || c == 'N' || c == 'O' || c == 'P' || c == 'Q' || c == 'R' || c == 'S' || c == 'T' || c == 'U' || c == 'V' || c == 'W' || c == 'X' || c == 'Y' || c == 'Z') dfastate = state_q4;
    else if(c == '1' || c == '2' || c == '3' || c == '4' || c == '5' || c == '6' || c == '7' || c == '8' || c == '9' || c == '0') dfastate = state_q5;
    else if(c == '\t' || c == '\n' || c == ' ') dfastate = state_q6;
    else dfastate = state_exit;
    return dfastate;
}

 enum State LS_q2(int c){
    if(c == 'a' || c == 'b' || c == 'c' || c == 'd' || c == 'e' || c == 'f' || c == 'g' || c == 'h' || c == 'i' || c == 'j' || c == 'k' || c == 'l' || c == 'm' || c == 'n' || c == 'o' || c == 'p' || c == 'q' || c == 'r' || c == 's' || c == 't' || c == 'u' || c == 'v' || c == 'w' || c == 'x' || c == 'y' || c == 'z' || c == 'A' || c == 'B' || c == 'C' || c == 'D' || c == 'E' || c == 'F' || c == 'G' || c == 'H' || c == 'I' || c == 'J' || c == 'K' || c == 'L' || c == 'M' || c == 'N' || c == 'O' || c == 'P' || c == 'Q' || c == 'R' || c == 'S' || c == 'T' || c == 'U' || c == 'V' || c == 'W' || c == 'X' || c == 'Y' || c == 'Z') dfastate = state_q4;
    else if(c == '1' || c == '2' || c == '3' || c == '4' || c == '5' || c == '6' || c == '7' || c == '8' || c == '9' || c == '0') dfastate = state_q5;
    else if(c == '\t' || c == '\n' || c == ' ') dfastate = state_q6;
    else dfastate = state_exit;
    return dfastate;
}

 enum State LS_q3(int c){
    if(c == 'a' || c == 'b' || c == 'c' || c == 'd' || c == 'e' || c == 'f' || c == 'g' || c == 'h' || c == 'i' || c == 'j' || c == 'k' || c == 'l' || c == 'm' || c == 'n' || c == 'o' || c == 'p' || c == 'q' || c == 'r' || c == 's' || c == 't' || c == 'u' || c == 'v' || c == 'w' || c == 'x' || c == 'y' || c == 'z' || c == 'A' || c == 'B' || c == 'C' || c == 'D' || c == 'E' || c == 'F' || c == 'G' || c == 'H' || c == 'I' || c == 'J' || c == 'K' || c == 'L' || c == 'M' || c == 'N' || c == 'O' || c == 'P' || c == 'Q' || c == 'R' || c == 'S' || c == 'T' || c == 'U' || c == 'V' || c == 'W' || c == 'X' || c == 'Y' || c == 'Z') dfastate = state_q4;
    else if(c == '1' || c == '2' || c == '3' || c == '4' || c == '5' || c == '6' || c == '7' || c == '8' || c == '9' || c == '0') dfastate = state_q5;
    else if(c == '\t' || c == '\n' || c == ' ') dfastate = state_q6;
    else dfastate = state_exit;
    return dfastate;
}

 enum State LS_q4(int c){
    if(c == 'a' || c == 'b' || c == 'c' || c == 'd' || c == 'e' || c == 'f' || c == 'g' || c == 'h' || c == 'i' || c == 'j' || c == 'k' || c == 'l' || c == 'm' || c == 'n' || c == 'o' || c == 'p' || c == 'q' || c == 'r' || c == 's' || c == 't' || c == 'u' || c == 'v' || c == 'w' || c == 'x' || c == 'y' || c == 'z' || c == 'A' || c == 'B' || c == 'C' || c == 'D' || c == 'E' || c == 'F' || c == 'G' || c == 'H' || c == 'I' || c == 'J' || c == 'K' || c == 'L' || c == 'M' || c == 'N' || c == 'O' || c == 'P' || c == 'Q' || c == 'R' || c == 'S' || c == 'T' || c == 'U' || c == 'V' || c == 'W' || c == 'X' || c == 'Y' || c == 'Z') dfastate = state_q4;
    else if(c == '1' || c == '2' || c == '3' || c == '4' || c == '5' || c == '6' || c == '7' || c == '8' || c == '9' || c == '0') dfastate = state_q5;
    else if(c == ' ' || c == '\n' || c == '\t') dfastate = state_q6;
    else if(c == '\"') dfastate = state_q7;
    else dfastate = state_exit;
    return dfastate;
}

 enum State LS_q5(int c){
    if(c == 'a' || c == 'b' || c == 'c' || c == 'd' || c == 'e' || c == 'f' || c == 'g' || c == 'h' || c == 'i' || c == 'j' || c == 'k' || c == 'l' || c == 'm' || c == 'n' || c == 'o' || c == 'p' || c == 'q' || c == 'r' || c == 's' || c == 't' || c == 'u' || c == 'v' || c == 'w' || c == 'x' || c == 'y' || c == 'z' || c == 'A' || c == 'B' || c == 'C' || c == 'D' || c == 'E' || c == 'F' || c == 'G' || c == 'H' || c == 'I' || c == 'J' || c == 'K' || c == 'L' || c == 'M' || c == 'N' || c == 'O' || c == 'P' || c == 'Q' || c == 'R' || c == 'S' || c == 'T' || c == 'U' || c == 'V' || c == 'W' || c == 'X' || c == 'Y' || c == 'Z') dfastate = state_q4;
    else if(c == '1' || c == '2' || c == '3' || c == '4' || c == '5' || c == '6' || c == '7' || c == '8' || c == '9' || c == '0') dfastate = state_q5;
    else if(c == '\t' || c == '\n' || c == ' ') dfastate = state_q6;
    else if(c == '\"') dfastate = state_q7;
    else dfastate = state_exit;
    return dfastate;
}

 enum State LS_q6(int c){
    if(c == 'a' || c == 'b' || c == 'c' || c == 'd' || c == 'e' || c == 'f' || c == 'g' || c == 'h' || c == 'i' || c == 'j' || c == 'k' || c == 'l' || c == 'm' || c == 'n' || c == 'o' || c == 'p' || c == 'q' || c == 'r' || c == 's' || c == 't' || c == 'u' || c == 'v' || c == 'w' || c == 'x' || c == 'y' || c == 'z' || c == 'A' || c == 'B' || c == 'C' || c == 'D' || c == 'E' || c == 'F' || c == 'G' || c == 'H' || c == 'I' || c == 'J' || c == 'K' || c == 'L' || c == 'M' || c == 'N' || c == 'O' || c == 'P' || c == 'Q' || c == 'R' || c == 'S' || c == 'T' || c == 'U' || c == 'V' || c == 'W' || c == 'X' || c == 'Y' || c == 'Z') dfastate = state_q4;
    else if(c == '1' || c == '2' || c == '3' || c == '4' || c == '5' || c == '6' || c == '7' || c == '8' || c == '9' || c == '0') dfastate = state_q5;
    else if(c == '\t' || c == '\n' || c == ' ') dfastate = state_q6;
    else if(c == '\"') dfastate = state_q7;
    else dfastate = state_exit;
    return dfastate;
}

 enum State LS_q7(int c){
    dfastate = state_exit;
    return dfastate;
}

/* Arithmatic Operator */

 enum State AO_start(int c){
    if(c == '+') dfastate = state_q0;
    else if(c == '-') dfastate = state_q1;
    else if(c == '*') dfastate = state_q2;
    else if(c == '/') dfastate = state_q3;
    else dfastate = state_exit;
    return dfastate;
}

 enum State AO_q0(int c){
    dfastate = state_exit;
    return dfastate;
}

 enum State AO_q1(int c){
    dfastate = state_exit;
    return dfastate;
}

 enum State AO_q2(int c){
    dfastate = state_exit;
    return dfastate;
}

 enum State AO_q3(int c){
    dfastate = state_exit;
    return dfastate;
}

// Bitwise Operator DFA의 전이들을 나타내기 위한 함수들 이다.

 enum State BO_start(int c){
    if(c == '<') dfastate = state_q0;
    else if(c == '>') dfastate = state_q1;
    else if(c == '&') dfastate = state_q2;
    else if(c == '|') dfastate = state_q2;
    else dfastate = state_exit;
    return dfastate;
}

 enum State BO_q0(int c){
    if(c == '<') dfastate = state_q2;
    else dfastate = state_exit;
    return dfastate;
}

 enum State BO_q1(int c){
    if(c == '>') dfastate = state_q2;
    else dfastate = state_exit;
    return dfastate;
}

 enum State BO_q2(int c){
    dfastate = state_exit;
    return dfastate;
}

// Comparison Operator DFA의 전이들을 나타내기 위한 함수들 이다.

 enum State CO_start(int c){
    if(c == '<') dfastate = state_q0;
    else if(c == '>') dfastate = state_q0;
    else if(c == '=') dfastate = state_q1;
    else if(c == '!') dfastate = state_q1;
    else dfastate = state_exit;
    return dfastate;
}

 enum State CO_q0(int c){
    if(c == '=') dfastate = state_q2;
    else dfastate = state_exit;
    return dfastate;
}

 enum State CO_q1(int c){
    if(c == '=') dfastate = state_q2;
    else dfastate = state_exit;
    return dfastate;
}

 enum State CO_q2(int c){
    dfastate = state_exit;
    return dfastate;
}

// Variable Type DFA의 전이들을 나타내기 위한 함수들 이다.

 enum Vstate VT_start(int c){
    if( c == 'i') Vdfastate = Vstate_i;
    else if (c == 'c') Vdfastate = Vstate_c;
    else if (c == 'b') Vdfastate = Vstate_b;
    else if (c == 'f') Vdfastate = Vstate_f;
    else Vdfastate = Vstate_exit;
    return Vdfastate;
}

 enum Vstate VT_i(int c){
    if(c == 'n') Vdfastate = Vstate_in;
    else Vdfastate = Vstate_exit;
    return Vdfastate;
}

 enum Vstate VT_in(int c){
    if(c == 't') Vdfastate = Vstate_int;
    else Vdfastate = Vstate_exit;
    return Vdfastate;
}

 enum Vstate VT_int(int c){
    Vdfastate = Vstate_exit;
    return Vdfastate;
}

 enum Vstate VT_c(int c){
    if(c == 'h') Vdfastate = Vstate_ch;
    else Vdfastate = Vstate_exit;
    return Vdfastate;
}

 enum Vstate VT_ch(int c){
    if(c == 'a') Vdfastate = Vstate_cha;
    else Vdfastate = Vstate_exit;
    return Vdfastate;
}

 enum Vstate VT_cha(int c){
    if(c == 'r') Vdfastate = Vstate_char;
    else Vdfastate = Vstate_exit;
    return Vdfastate;
}

 enum Vstate VT_char(int c){
    Vdfastate = Vstate_exit;
    return Vdfastate;
}

 enum Vstate VT_b(int c){
    if(c == 'o') Vdfastate = Vstate_bo;
    else Vdfastate = Vstate_exit;
    return Vdfastate;
}

 enum Vstate VT_bo(int c){
    if(c == 'o') Vdfastate = Vstate_boo;
    else Vdfastate = Vstate_exit;
    return Vdfastate;
}

 enum Vstate VT_boo(int c){
    if(c == 'l') Vdfastate = Vstate_bool;
    else Vdfastate = Vstate_exit;
    return Vdfastate;
}

 enum Vstate VT_bool(int c){
    Vdfastate = Vstate_exit;
    return Vdfastate;
}

 enum Vstate VT_f(int c){
    if(c == 'l') Vdfastate = Vstate_fl;
    else Vdfastate = Vstate_exit;
    return Vdfastate;
}

 enum Vstate VT_fl(int c){
    if(c == 'o') Vdfastate = Vstate_flo;
    else Vdfastate = Vstate_exit;
    return Vdfastate;
}

 enum Vstate VT_flo(int c){
    if(c == 'a') Vdfastate = Vstate_floa;
    else Vdfastate = Vstate_exit;
    return Vdfastate;
}

 enum Vstate VT_floa(int c){
    if(c == 't') Vdfastate = Vstate_float;
    else Vdfastate = Vstate_exit;
    return Vdfastate;
}

 enum Vstate VT_float(int c){
    Vdfastate = Vstate_exit;
    return Vdfastate;
}

// Boolean String DFA의 전이들을 나타내기 위한 함수들 이다.

 enum BSstate BS_start(int c){
    if(c == 't') BSdfastate = BSstate_t;
    else if(c == 'f') BSdfastate = BSstate_f;
    else BSdfastate = BSstate_exit;
    return BSdfastate;
}

 enum BSstate BS_t(int c){
    if(c == 'r') BSdfastate = BSstate_tr;
    else BSdfastate = BSstate_exit;
    return BSdfastate;
}

 enum BSstate BS_tr(int c){
    if(c == 'u') BSdfastate = BSstate_tru;
    else BSdfastate = BSstate_exit;
    return BSdfastate;
}

 enum BSstate BS_tru(int c){
    if(c == 'e') BSdfastate = BSstate_true;
    else BSdfastate = BSstate_exit;
    return BSdfastate;
}

 enum BSstate BS_true(int c){
    BSdfastate = BSstate_exit;
    return BSdfastate;
}

 enum BSstate BS_f(int c){
    if(c == 'a') BSdfastate = BSstate_fa;
    else BSdfastate = BSstate_exit;
    return BSdfastate;
}

 enum BSstate BS_fa(int c){
    if(c == 'l') BSdfastate = BSstate_fal;
    else BSdfastate = BSstate_exit;
    return BSdfastate;
}

 enum BSstate BS_fal(int c){
    if(c == 's') BSdfastate = BSstate_fals;
    else BSdfastate = BSstate_exit;
    return BSdfastate;
}

 enum BSstate BS_fals(int c){
    if(c == 'e') BSdfastate = BSstate_false;
    else BSdfastate = BSstate_exit;
    return BSdfastate;
}

 enum BSstate BS_false(int c){
    BSdfastate = BSstate_exit;
    return BSdfastate;
}

// Keyword DFA의 전이들을 나타내기 위한 함수들 이다.

 enum Kstate K_start(int c){
    if(c == 'i') Kdfastate = Kstate_i;
    else if(c == 'e') Kdfastate = Kstate_e;
    else if(c == 'w') Kdfastate = Kstate_w;
    else if(c == 'f') Kdfastate = Kstate_f;
    else if(c == 'r') Kdfastate = Kstate_r;
    else Kdfastate = Kstate_exit;
    return Kdfastate;
}

 enum Kstate K_i(int c){
    if(c == 'f') Kdfastate = Kstate_if;
    else Kdfastate = Kstate_exit;
    return Kdfastate;
}

 enum Kstate K_if(int c){
    Kdfastate = Kstate_exit;
    return Kdfastate;
}

 enum Kstate K_e(int c){
    if(c == 'l') Kdfastate = Kstate_el;
    else Kdfastate = Kstate_exit;
    return Kdfastate;
}

 enum Kstate K_el(int c){
    if(c == 's') Kdfastate = Kstate_els;
    else Kdfastate = Kstate_exit;
    return Kdfastate;
}

 enum Kstate K_els(int c){
    if(c == 'e') Kdfastate = Kstate_else;
    else Kdfastate = Kstate_exit;
    return Kdfastate;
}

 enum Kstate K_else(int c){
    Kdfastate = Kstate_exit;
    return Kdfastate;
}

 enum Kstate K_w(int c){
    if(c == 'h') Kdfastate = Kstate_wh;
    else Kdfastate = Kstate_exit;
    return Kdfastate;
}

 enum Kstate K_wh(int c){
    if(c == 'i') Kdfastate = Kstate_whi;
    else Kdfastate = Kstate_exit;
    return Kdfastate;
}

 enum Kstate K_whi(int c){
    if(c == 'l') Kdfastate = Kstate_whil;
    else Kdfastate = Kstate_exit;
    return Kdfastate;
}

 enum Kstate K_whil(int c){
    if(c == 'e') Kdfastate = Kstate_while;
    else Kdfastate = Kstate_exit;
    return Kdfastate;
}

 enum Kstate K_while(int c){
    Kdfastate = Kstate_exit;
    return Kdfastate;
}

 enum Kstate K_f(int c){
    if(c == 'o') Kdfastate = Kstate_fo;
    else Kdfastate = Kstate_exit;
    return Kdfastate;
}

 enum Kstate K_fo(int c){
    if(c == 'r') Kdfastate = Kstate_for;
    else Kdfastate = Kstate_exit;
    return Kdfastate;
}

 enum Kstate K_for(int c){
    Kdfastate = Kstate_exit;
    return Kdfastate;
}

 enum Kstate K_r(int c){
    if(c == 'e') Kdfastate = Kstate_re;
    else Kdfastate = Kstate_exit;
    return Kdfastate;
}

 enum Kstate K_re(int c){
    if(c == 't') Kdfastate = Kstate_ret;
    else Kdfastate = Kstate_exit;
    return Kdfastate;
}

 enum Kstate K_ret(int c){
    if(c == 'u') Kdfastate = Kstate_retu;
    else Kdfastate = Kstate_exit;
    return Kdfastate;
}

 enum Kstate K_retu(int c){
    if(c == 'r') Kdfastate = Kstate_retur;
    else Kdfastate = Kstate_exit;
    return Kdfastate;
}

 enum Kstate K_retur(int c){
    if(c == 'n') Kdfastate = Kstate_return;
    else Kdfastate = Kstate_exit;
    return Kdfastate;
}

 enum Kstate K_return(int c){
    Kdfastate = Kstate_exit;
    return Kdfastate;
}

// Assignment DFA의 전이들을 나타내기 위한 함수들 이다.

 enum State Asmt_start(int c){
    if(c == '=') dfastate = state_q0;
    else dfastate = state_exit;
    return dfastate;
}

 enum State Asmt_q0(int c){
    dfastate = state_exit;
    return dfastate;
}

// Terminating symbol DFA의 전이들을 나타내기 위한 함수들 이다.

 enum State Ter_start(int c){
    if(c == ';') dfastate = state_q0;
    else dfastate = state_exit;
    return dfastate;
}

 enum State Ter_q0(int c){
    dfastate = state_exit;
    return dfastate;
}

// Left_Brace_Parenthesis DFA의 전이들을 나타내기 위한 함수들 이다.

 enum State LBP_start(int c){
    if(c == '{') dfastate = state_q0;
    else dfastate = state_exit;
    return dfastate;
}

 enum State LBP_q0(int c){
    dfastate = state_exit;
    return dfastate;
}

// Right_Brace_Parenthesis DFA의 전이들을 나타내기 위한 함수들 이다.

 enum State RBP_start(int c){
    if(c == '}') dfastate = state_q0;
    else dfastate = state_exit;
    return dfastate;
}

 enum State RBP_q0(int c){
    dfastate = state_exit;
    return dfastate;
}

// Left_Parenthesis DFA의 전이들을 나타내기 위한 함수들 이다.

 enum State LP_start(int c){
    if(c == '(') dfastate = state_q0;
    else dfastate = state_exit;
    return dfastate;
}

 enum State LP_q0(int c){
    dfastate = state_exit;
    return dfastate;
}

// Right_Parenthesis DFA의 전이들을 나타내기 위한 함수들 이다.

 enum State RP_start(int c){
    if(c == ')') dfastate = state_q0;
    else dfastate = state_exit;
    return dfastate;
}

 enum State RP_q0(int c){
    dfastate = state_exit;
    return dfastate;
}

// COMMA DFA의 전이들을 나타내기 위한 함수들 이다.

 enum State CM_start(int c){
    if(c == ',') dfastate = state_q0;
    else dfastate = state_exit;
    return dfastate;
}

 enum State CM_q0(int c){
    dfastate = state_exit;
    return dfastate;
}

// Quotes DFA의 전이들을 나타내기 위한 함수들 이다.

 enum State QT_start(int c){
    if(c == '\"') dfastate = state_q0;
    else dfastate = state_exit;
    return dfastate;
}

 enum State QT_q0(int c){
    dfastate = state_exit;
    return dfastate;
}
