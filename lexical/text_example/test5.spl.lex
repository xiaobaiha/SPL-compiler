TOKEN-TYPE          TOKEN-VALUE
-------------------------------------------------
PROGRAM             program
NAME                hello
SEMI                ;
CONST               const
NAME                ta
EQUAL               =
INTEGER             3
SEMI                ;
TYPE                type
NAME                ar
EQUAL               =
ARRAY               array
LB                  [
INTEGER             0
DOTDOT              ..
INTEGER             10
RB                  ]
OF                  of
SYS_TYPE            real
SEMI                ;
VAR                 var
NAME                c
COLON               :
NAME                ar
SEMI                ;
NAME                i
COLON               :
SYS_TYPE            integer
SEMI                ;
NAME                j
COLON               :
SYS_TYPE            integer
SEMI                ;
NAME                k
COLON               :
SYS_TYPE            integer
SEMI                ;
BEGIN_TOKEN         begin
NAME                c
LB                  [
INTEGER             0
RB                  ]
ASSIGN              :=
FLOAT_NUM           0.1
SEMI                ;
NAME                c
LB                  [
INTEGER             1
RB                  ]
ASSIGN              :=
FLOAT_NUM           0.2
SEMI                ;
NAME                c
LB                  [
INTEGER             2
RB                  ]
ASSIGN              :=
FLOAT_NUM           0.3
SEMI                ;
NAME                c
LB                  [
INTEGER             3
RB                  ]
ASSIGN              :=
FLOAT_NUM           0.4
SEMI                ;
NAME                c
LB                  [
INTEGER             4
RB                  ]
ASSIGN              :=
FLOAT_NUM           0.5
SEMI                ;
NAME                c
LB                  [
INTEGER             5
RB                  ]
ASSIGN              :=
FLOAT_NUM           0.6
SEMI                ;
NAME                c
LB                  [
INTEGER             6
RB                  ]
ASSIGN              :=
FLOAT_NUM           0.7
SEMI                ;
NAME                c
LB                  [
INTEGER             7
RB                  ]
ASSIGN              :=
FLOAT_NUM           0.8
SEMI                ;
NAME                c
LB                  [
INTEGER             8
RB                  ]
ASSIGN              :=
FLOAT_NUM           0.9
SEMI                ;
NAME                c
LB                  [
INTEGER             9
RB                  ]
ASSIGN              :=
FLOAT_NUM           1.0
SEMI                ;
NAME                c
LB                  [
INTEGER             10
RB                  ]
ASSIGN              :=
FLOAT_NUM           1.1
SEMI                ;
FOR                 for
NAME                i
ASSIGN              :=
INTEGER             0
TO                  to
INTEGER             10
DO                  do
BEGIN_TOKEN         begin
NAME                c
LB                  [
NAME                i
RB                  ]
ASSIGN              :=
NAME                c
LB                  [
NAME                i
RB                  ]
MUL                 *
NAME                c
LB                  [
NAME                i
RB                  ]
SEMI                ;
SYS_PROC            writeln
LP                  (
NAME                c
LB                  [
NAME                i
RB                  ]
RP                  )
SEMI                ;
END                 end
SEMI                ;
END                 end
DOT                 .