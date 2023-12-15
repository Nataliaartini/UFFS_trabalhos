{
module Parser where

import Lexer 
}

%name parser 
%tokentype { Token }
%error { parserError } 

%left '+'

%token 
    num         { TokenNum $$ }
    '+'         { TokenAdd }
    "&&"        { TokenAnd }
    true        { TokenTrue }
    false       { TokenFalse }
    if          { TokenIf }
    then        { TokenThen }
    else        { TokenElse }
    var         { TokenVar $$ }
    '\\'        { TokenLam }
    "->"        { TokenArrow }
    '('         { TokenLParen }
    ')'         { TokenRParen }
    '='         { TokenEq }
    let         { TokenLet }
    in          { TokenIn }
    Bool        { TokenBoolean }
    Num         { TokenNumber }
    ':'         { TokenColon }
    '-'         { TokenDecrement }
    '*'         { TokenMultiply }
    '/'         { TokenDivide }
    '!'         { TokenNegate }
    for         { TokenFor }

%%

Exp         : num                               { Num $1 }
            | true                              { BTrue }
            | false                             { BFalse }
            | Exp '+' Exp                       { Add $1 $3 }
            | Exp "&&" Exp                      { And $1 $3 }
            | if Exp then Exp else Exp          { If $2 $4 $6 }
            | var                               { Var $1 }
            | '\\' var ':' Type "->" Exp        { Lam $2 $4 $6 }
            | Exp Exp                           { App $1 $2 }
            | '(' Exp ')'                       { Paren $2 }
            | let var '=' Exp in Exp            { Let $2 $4 $6 }
            | Exp '-' Exp                       { Decrement $1 $3 }
            | Exp '*' Exp                       { Multiply $1 $3 }
            | Exp '/' Exp                       { Divide $1 $3 }
            | '!' Exp                           { Negate $2 }
            | for Exp '=' Exp "->" Exp ':' Exp  { For $2 $4 $6 $8}

Type    : Bool                                  { TBool }
        | Num                                   { TNum }
        | '(' Type "->" Type ')'                { TFun $2 $4 }

{

parserError :: [Token] -> a 
parserError _ = error "Syntax error!"

}