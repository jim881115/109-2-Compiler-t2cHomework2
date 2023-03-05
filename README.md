# Programming Languages and Compilers t2c Homework 2
## Question decription
Augment your T parser with semantic actions for constructing parse trees, write a C code generator and make it a workable T-to-C compiler.
* See an attached package for the reference files.
* You are requested to separate the C code, the Lex specification, the Yacc specification into distinct files.

# Report
## Problem description
　　建構解析樹的語意動作來增強 T 解析器，並編寫一個 C 語言產生器，實現 T-to-C 的編譯器

## Highlight of the way you write the program
　　這次只要修改老師給的資料夾裡的 t_parse.y 與 t2c_tree.c 就可以，不過在編寫前要先理解運算式在幹麻(t_parse.y)及建立資料型態裡的內容(t2c_tree.c)<br/>
* t_parse.y <br/>
![](https://i.imgur.com/7yJbn0N.png) <br/>
　　$$就是代表指 Left hand side 的 nonterminal A，而$k 是指 Right hand side 的 nonterminal 或 terminal X_k <br/>
![](https://i.imgur.com/Sv92zY9.png) <br/>
　　這部分只要依照上面的規則，與參考老師上面打的範例就能完成，也要參考 t2c_tree.c 裡的 case，來看是要 create_stm()或 create_exp() <br/>
![](https://i.imgur.com/mBqfCsf.png) <br/>
　　比較有問題的是在 pexpr 這裡，那時找不太到 exp_id 要去指定到哪個 case，找了一段時間試了好幾遍才 debug 完，這部分細心就好，debug 沒用很久就完成了 <br/>
* t2c_tree.c <br/>
![](https://i.imgur.com/sXeLeX4.png) <br/>
這部分就參照著 t_parse.y 打好的規則與老師上面打好的範例，就能完成。不過有個地方比較特別 <br/>
![](https://i.imgur.com/loKP0ew.png) <br/>
這裡是 C 語言 printf 的部分，當初只有打%s 字串的部分，然後發現 printf 也有其他資料型態的資料要印出，所以就令一個 test 變數，透過 if else 去判斷要到哪個 case 去輸出 <br/>

## The program listing
* t_parse.y
* t2c_tree.c

## Test run results
　　將上面兩個檔案完成後，接下來要進行以下步驟：
1. 用 bison 將 t_parse.y 編譯成 t_parse.c 和生成標頭檔 t_parse.h
2. 用 flex 將 t_lex.l 編譯成 t_lex.c
3. 用 gcc 將 t_parse.c、t2c_tree.c、t_lex.c 與 t2c.c 分別編譯成 t_parse.o、t2c_tree.o、t_lex.o 與 t2c.o
4. 用 gcc 將 3.編譯後的.o 檔進行 link，並生成 t2c.exe
5. 使用 t2c.exe 將 test.t 轉為 C 語言 <br/>
![](https://i.imgur.com/VAMuALj.png) <br/>
6. 用 gcc 編譯 test.c，生成可執行的 test.exe <br/>
![](https://i.imgur.com/UY4K0N7.png) <br/>
程式執行結果是沒問題的！

## Discussion
　　經過第一次作業的練習，在打這次的 t_pares.y 與 t2c_tree.c 沒有這麼混亂了，不過過程中還是會遇到一些小 bug，但所幸都沒花很久的時間就解決了。透過這兩次的作業讓我更了解一個編譯器在進行語言的編譯時，會經過的步驟，雖然有些地方不太好懂，這與同學討論後才比較清楚是想要表達啥。
