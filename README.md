# 42_minitalk

![Demo GIF](https://github.com/karisti/42_minitalk/blob/main/demo.gif?raw=true)

## Description
This project consists of creating a communication program in the form of a client and a server. The communication between client and server has to be done only using UNIX signals (SIGUSR1 and SIGUSR2). The server can receive strings from several clients in a row without needing to restart.

## Lessons
- UNIX Signals
- Processes
- Bitwise Operators
- Pause, sleep, exit

## Prerequisites
- Nothing needed

## Usage
1. `make`
2. Run `./server` on a shell and leave it running
3. Run `./client <SERVER_PID> <YOUR MESSAGE>` on another shell

## Resources
- [How signals work (es)](http://profesores.elo.utfsm.cl/~agv/elo330/2s08/lectures/signals.html "How signals work (es)")
- [More about signals (es)](http://www.chuidiang.org/clinux/senhales/senhales.php "More about signals (es)")
- [Even more about signals [VIDEO] (es)](https://www.youtube.com/watch?v=rNGlwqHpoGw "Even more about signals [VIDEO] (es)")
- [Bitwise Operators in C](https://www.programiz.com/c-programming/bitwise-operators "Bitwise Operators in C")
- [Using Pause](https://www.gnu.org/software/libc/manual/html_node/Using-Pause.html "Using Pause")
- [How to send a self-correcting message (Hamming codes) [VIDEO]](https://www.youtube.com/watch?v=X8jsijhllIA "How to send a self-correcting message (Hamming codes) [VIDEO]")

