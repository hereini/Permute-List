# PermuteList
A command line tool that finds all permutations of a list.

## Usage
```
./PermuteList.exe --input a b c --output results.txt
```

This will generate all permutations of the input list, and will write them to the output file.

## Command Line Arguments
| Argument | Description |
|---|---|
| `--input` | The list of space separated items to find the permutations of. |
| `--output` | The file where the results will be written. |
| `--count` | Instead of generating the permutations, output only the total number of permutations. |
| `-h`, `--help` | Display the command line options. |

## Examples
### Getting all permutations
Using the input:
```
a b c
```
Run:
```
./PermuteList.exe --input a b c --output results.txt
```
And ```results.txt``` will contain:
```
a b c
b a c
c a b
a c b
b c a
c b a
```
### Getting the number of permutations
Using the input:
```
a b c d e f
```
Run:
```
./PermuteList.exe --input a b c d e f --output results.txt --count
```
And ```results.txt``` will contain:
```
720
```
## Building
Clone the repository:
```
git clone https://github.com/hereini/Permute-List.git
```
Then build the project:
```
cmake -S . -B build
cmake --build build
```