# Pipex

<p align="center">
  <img src="https://game.42sp.org.br/static/assets/achievements/pipexm.png" alt="Pipex Achievement" width="200" height="200">
  <img src="https://res.cloudinary.com/dfjub9qt4/image/upload/v1708631992/pipex_42.png" alt="Pipex Square" width="200" height="200">
</p>

## Introduction
Pipex is a project aimed at simulating the functionality of pipes in the Bash shell. The program reads from a file, processes the data through a series of commands, and writes the output to another file. Here are the instructions on how to compile and use the Pipex program, including both the main and bonus parts.

## Compilation
o compile the Pipex program, simply run make. This will generate the executable file pipex for the main part and pipex_bonus for the bonus part.

## Usage (Main Part)
It is built to behave exactly the same as the shell command bellow:
```bash
< input.txt cat | grep a output.txt
```

To use the Pipex program for the main part, follow the syntax:
```bash
./pipex input.txt "cmd1" "cmd2" output.txt
```

This command reads the contents of input.txt, processes it through cmd1 and cmd2, and writes the output to output.txt. For example:
```bash
./pipex input.txt "cat" "grep a" output.txt
```

## Usage (Bonus Part)
It is built to behave exactly the same as the shell command bellow:
```bash
< input.txt tr -d '!' | grep -v '!' | sed 's/Hello/Salut/g' | grep 'Salut' | wc -l > output.txt
```

To use the Pipex program for the bonus part, follow the syntax:
```bash
make bonus
```

```bash
./pipex_bonus input.txt "cmd1" "cmd2" ... output.txt
```
This command reads the contents of `input.txt`, processes it through multiple commands, and writes the output to `output.txt`. For example:
```bash
./pipex_bonus input.txt "tr -d '!'" "grep -v '!'" "sed 's/Hello/Salut/g'" "grep 'Salut'" "wc -l" output.txt
```

## Usage (Bonus Part with Here Doc):
It is built to behave exactly the same as the shell command bellow:
```bash
cmd << LIMITER | cmd1 >> file
```

To use the Pipex program for the bonus part with here doc functionality, follow the syntax:
```bash
./pipex_bonus here_doc LIMITER "cmd1" "cmd2" output.txt
```
This command takes input from a here doc delimited by `LIMITER`, processes it through 2 commands, and appends the output to `output.txt`. For example:
```bash
./pipex_bonus here_doc "EOF" "cat" "grep a" output.txt
```


**Note:** Ensure that you replace `LIMITER` with your desired delimiter for the here doc, and use a unique one that does not appear in your input data. Also, make sure to enclose the commands in double quotes ("") and separate them by spaces.


