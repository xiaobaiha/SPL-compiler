TOKEN-TYPE          TOKEN-VALUE
-------------------------------------------------
PROGRAM             program
NAME                hello
SEMI                ;
VAR                 var
NAME                i
COLON               :
SYS_TYPE            integer
SEMI                ;
FUNCTION            function
NAME                go
LP                  (
NAME                a
COLON               :
SYS_TYPE            integer
RP                  )
COLON               :
SYS_TYPE            integer
SEMI                ;
BEGIN_TOKEN         begin
IF                  if
NAME                a
EQUAL               =
INTEGER             1
THEN                then
BEGIN_TOKEN         begin
NAME                go
ASSIGN              :=
INTEGER             1
SEMI                ;
END                 end
ELSE                else
BEGIN_TOKEN         begin
IF                  if
NAME                a
EQUAL               =
INTEGER             2
THEN                then
BEGIN_TOKEN         begin
NAME                go
ASSIGN              :=
INTEGER             1
SEMI                ;
END                 end
ELSE                else
BEGIN_TOKEN         begin
NAME                go
ASSIGN              :=
NAME                go
LP                  (
NAME                a
MINUS               -
INTEGER             1
RP                  )
PLUS                +
NAME                go
LP                  (
NAME                a
MINUS               -
INTEGER             2
RP                  )
SEMI                ;
END                 end
SEMI                ;
END                 end
SEMI                ;
END                 end
SEMI                ;
BEGIN_TOKEN         begin
NAME                i
ASSIGN              :=
NAME                go
LP                  (
INTEGER             10
RP                  )
SEMI                ;
SYS_PROC            writeln
LP                  (
NAME                i
RP                  )
SEMI                ;
END                 end
DOT                 .
