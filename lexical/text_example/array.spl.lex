TOKEN-TYPE          TOKEN-VALUE
-------------------------------------------------
PROGRAM             program
NAME                arrayprog
LP                  (
NAME                input
COMMA               ,
NAME                output
RP                  )
SEMI                ;
LP                  (
MUL                 *
MUL                 *
MUL                 *
NAME                Demonstrate
ARRAY               array
NAME                usage
DOT                 .
MUL                 *
MUL                 *
MUL                 *
RP                  )
TYPE                type
NAME                array1D
EQUAL               =
ARRAY               array
LB                  [
INTEGER             1
DOTDOT              ..
INTEGER             5
RB                  ]
OF                  of
SYS_TYPE            integer
SEMI                ;
NAME                array3D
EQUAL               =
ARRAY               array
LB                  [
INTEGER             1
DOTDOT              ..
INTEGER             5
COMMA               ,
INTEGER             2
DOTDOT              ..
INTEGER             3
COMMA               ,
INTEGER             0
DOTDOT              ..
INTEGER             2
RB                  ]
OF                  of
SYS_TYPE            integer
SEMI                ;
VAR                 var
NAME                a
COLON               :
NAME                array3D
SEMI                ;
NAME                b
COLON               :
ARRAY               array
LB                  [
INTEGER             0
DOTDOT              ..
INTEGER             3
RB                  ]
OF                  of
NAME                array1D
SEMI                ;
NAME                i
COMMA               ,
NAME                j
COMMA               ,
NAME                k
COLON               :
SYS_TYPE            integer
SEMI                ;
BEGIN_TOKEN         begin
FOR                 for
NAME                i
ASSIGN              :=
INTEGER             1
TO                  to
INTEGER             5
DO                  do
FOR                 for
NAME                j
ASSIGN              :=
INTEGER             2
TO                  to
INTEGER             3
DO                  do
FOR                 for
NAME                k
ASSIGN              :=
INTEGER             0
TO                  to
INTEGER             2
DO                  do
NAME                a
LB                  [
NAME                i
COMMA               ,
NAME                j
COMMA               ,
NAME                k
RB                  ]
ASSIGN              :=
NAME                i
SEMI                ;
FOR                 for
NAME                i
ASSIGN              :=
INTEGER             0
TO                  to
INTEGER             3
DO                  do
FOR                 for
NAME                j
ASSIGN              :=
INTEGER             1
TO                  to
INTEGER             5
DO                  do
NAME                b
LB                  [
NAME                i
COMMA               ,
NAME                j
RB                  ]
ASSIGN              :=
NAME                i
PLUS                +
NAME                j
SEMI                ;
FOR                 for
NAME                i
ASSIGN              :=
INTEGER             5
DOWNTO              downto
INTEGER             1
DO                  do
FOR                 for
NAME                j
ASSIGN              :=
INTEGER             3
DOWNTO              downto
INTEGER             2
DO                  do
BEGIN_TOKEN         begin
FOR                 for
NAME                k
ASSIGN              :=
INTEGER             0
TO                  to
INTEGER             2
DO                  do
SYS_PROC            write
LP                  (
NAME                a
LB                  [
NAME                i
COMMA               ,
NAME                j
COMMA               ,
NAME                k
RB                  ]
COMMA               ,
''RP                  )
SEMI                ;
SYS_PROC            writeln
SEMI                ;
END                 end
SEMI                ;
SYS_PROC            writeln
SEMI                ;
FOR                 for
NAME                i
ASSIGN              :=
INTEGER             0
TO                  to
INTEGER             3
DO                  do
BEGIN_TOKEN         begin
FOR                 for
NAME                j
ASSIGN              :=
INTEGER             1
TO                  to
INTEGER             5
DO                  do
SYS_PROC            write
LP                  (
NAME                b
LB                  [
NAME                i
COMMA               ,
NAME                j
RB                  ]
COMMA               ,
''RP                  )
SEMI                ;
SYS_PROC            writeln
SEMI                ;
END                 end
SEMI                ;
END                 end
DOT                 .