1. I generaized my code. So most of my codes in tic-tac-toe and Gomoku​ are the same, and saved in base file(game.cpp).
In such case, I don't have virtual/ pure virtual method pair for turn, done,draw, prompt and play.
Print method is left to show the use of virtual/ pure virtual method pair.
2.The input x,y are reversed. First digit corresponding to y axis, and second to x axis.
3.According to:https://piazza.com/class/k58pv8mp2p52wh?cid=306. I am in same situation that I seperated classes to different .h and .cpp files,
and the derived class include the .h file of the base code. In such case, I defined the static method chooseGame() in my main .cpp file which is lab4.cpp.