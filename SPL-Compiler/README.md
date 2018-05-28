# 说明

* 使用1：该文件夹目录下输入**make**即可生成可执行文件tcc和其它[.ch]文件，另外，bison 会将语法产生式以及符号优先级转化为一个 C 语言的 LALR(1) 动作表，并输出到 y.tab.c 文件中去，另外，还会将这个动作表以及语法中的相关要素以可读的文字形式输出到 y.output 文件中去。
* 使用2：生成的tcc可执行文件中，可以运行并打印，具体运行方式为：

```shell
./tcc < text_example/test1.spl //运行test1.spl，并打印在终端
./tcc < text_example/test1.spl > test1.asm  //运行并将内容重定向到test1.asm中
```

具体显示内容自定义，目前如有语法错误，则显示如下：

```shell
line 5: syntax error //在文件的第5行中出现了语法错误
```





* 注意1：目前从y.output文件可以看出存在冲突，但冲突优先走的是shift，可以检查语法是否有问题

```bison
state 177 conflicts: 1 shift/reduce
...
State 177

   83 if_stmt: IF expression THEN stmt .
   84        | IF expression THEN stmt . ELSE stmt

    ELSE  shift, and go to state 214

    ELSE      [reduce using rule 83 (if_stmt)]
    $default  reduce using rule 83 (if_stmt)
```



* 注意2：目前的语法分析中，对于例子**test_example/array.spl**的parse仍然存在错误；
* 注意3：目前spl.y文件中所有语法规则尚无action，在花括号内实现action：

```c
program_stmt: program_head  routine  DOT {
    printf("program_stmt\n");
}
;
```





* 建议1：通用操作在util.h中实现，树的相关数据结构在tree.h(tree.c)中实现，符号表的相关数据结构在symbol.h(symbol.c)中实现。具体，可自行修改；