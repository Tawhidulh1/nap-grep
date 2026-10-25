# nap-grep
nap-grep is a tool that recursively searches directories and looks for a pattern. This tool is very very similar to [repgrep](https://github.com/BurntSushi/ripgrep), well actually it was made to be my own version of it.
Anyways, expect slower searches than repgrep.


This has only been tested on linux. 

### Building
Clone the repository, go into nap-grep and run make.
```bash
git clone https://github.com/tawhidulh1/nap-grep.git
cd nap-grep
make
```
To install to PATH:
```bash
make install (defaults to ~/.local/bin)
# or 
sudo make install PREFIX=/usr/local
```

### Usage
The Pattern must be the first value other than the OPTIONS and the FLAGS. After the pattern, the ordering do not matter since getopt_long does non-posix rearrangement for argv.
```bash
ng PATTERN [DIRS] [OPTIONS] [FLAGS]
# ex: ng "Hello World" ~/ / --hidden
```
*the --hidden above makes it so that hidden files and directories are included (those that begin in ".")*

PATTERN can be in the form of strings, such as "Hello World" or it can be a single expression: Hello

The [DIRS] (should really be called PATH) are the paths to the directories in 
which the search takes place. By default it is in the working directory. 

