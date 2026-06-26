# Mini Pascal Compiler — Built from Scratch in C

A compiler for a hypothetical subset of Pascal, implemented in pure C without any compiler-generator tools (no lex, no yacc, no ANTLR). Every phase is hand-built, making the internal mechanics fully transparent.

---

## Architecture

The compiler follows the classic pipeline, split into independent modules:

```
Source file (program.txt)
        │
        ▼
┌─────────────────┐
│  Lexical Analysis│  src/lexer.c
│  DFA via goto   │  Deterministic Finite Automaton — recognizes tokens
└────────┬────────┘  character by character
         │  token stream
         ▼
┌─────────────────┐
│  Token Buffer   │  src/buffer.c
│  FIFO queue     │  Decouples lexer from parser
└────────┬────────┘
         │
         ▼
┌─────────────────┐
│  Syntactic      │  src/parser.c
│  Analysis       │  Recursive-descent parser — each grammar rule
│                 │  maps to one function
└────────┬────────┘
         │  identifiers + scopes
         ▼
┌─────────────────┐
│  Symbol Table   │  src/symtable.c
│  Hash table     │  O(1) expected insert/lookup (CLRS Ch. 11)
└─────────────────┘
```

### Lexer — Finite Automaton

The lexer (`lexer_scan()`) is a hand-coded DFA where each `Qn` label is a state. Transitions follow the character read; acceptance states return the corresponding token code. The DFA recognizes:

| Category | Tokens |
|---|---|
| Reserved words | `and begin boolean div do else end false if integer not or procedure program then true var while write` |
| Operators | `+ - * = := : < <= <> > >=` |
| Delimiters | `. , ; ( )` |
| Literals | integer numerals |
| Identifiers | any alphanumeric sequence not matching a keyword |

### Symbol Table — Hash Table with Chaining

Based on **Cormen, Leiserson, Rivest, Stein — "Introduction to Algorithms" (CLRS), 4th ed., Chapter 11**.

- **Hash function:** djb2 (`h = h*33 + c`), maps identifier names to `[0, 101)`.  
- **Bucket count:** 101 (prime — division method, CLRS §11.3.1).  
- **Collision resolution:** chaining via linked lists.  
- **Complexity:** O(1) expected insert and lookup vs. O(n) in the previous linked-list design.  
- **Scope management:** `symtable_remove_scope(scope)` removes all symbols from a closing block.

### Parser — Recursive Descent

Each production rule of the Mini Pascal grammar corresponds to one C function. The parser consumes tokens from the buffer using `buffer_match()`, which reports the source line number on mismatch.

**Grammar (simplified):**
```
<program>    ::= program <id> ; <block> .
<block>      ::= [<var-decl>] [<proc-decl>] <compound>
<compound>   ::= begin <cmd> { ; <cmd> } end
<cmd>        ::= <assign> | <proc-call> | <compound> | <if> | <while> | write(<id>)
<expr>       ::= <simple-expr> [ ( = | <> | < | <= | > | >= ) <simple-expr> ]
<simple-expr>::= [+|-] <term> { (+|-) <term> }
<term>       ::= <factor> { (* | div) <factor> }
<factor>     ::= <id> | <number> | true | false | ( <simple-expr> )
```

---

## Bugs Fixed in This Version

| # | Bug | Impact |
|---|-----|--------|
| 1 | `or` recognized as `_DO` — DFA state Q74 jumped to Q73 instead of Q75 | `or` was silently misclassified |
| 2 | `char linha[80]` with `fgets(..., 500, ...)` | Buffer overflow on long lines |
| 3 | `exit(0)` called on empty-buffer error | Parser failures reported as success |
| 4 | `=` operator (`_EQ`) never emitted by lexer | Equality comparisons were broken |
| 5 | `_LEQ` (`<=`) missing from expression loop | `<=` not parsed as a relational operator |
| 6 | `:=` used as relational operator in `parse_relop()` | Assignment token incorrectly matched `=` |
| 7 | Global `tam` shared between buffer and symbol table | Counter state corrupted across data structures |

---

## File Structure

```
src/
  tokens.h      — Token code definitions (#define constants)
  lexer.h / .c  — DFA-based lexical analyzer
  buffer.h / .c — Token FIFO queue
  symtable.h/.c — Hash table symbol table (Cormen Ch. 11)
  parser.h / .c — Recursive descent parser
  main.c        — Entry point; reads source, runs both phases

program.txt     — Sample Mini Pascal source
Makefile        — Build script
```

---

## Build and Run

**Requirements:** GCC, GNU Make.

```bash
# Build
make

# Run on the included sample
./compiler

# Run on a custom file
./compiler path/to/source.pas

# Clean build artifacts
make clean
```

The lexer writes the token stream to `output.txt`. The parser prints the symbol table to stdout.

---

## Sample Source (`program.txt`)

```pascal
program correto ;
var a , b , c : integer ;
var d , e , f : boolean ;
procedure proc ( var a1 : integer ) ;
var a , b , c : integer ;
begin
  a := 1 ;
  if ( a < 1 ) then
    a := 12 ;
end ;
begin
  a := 2 ;
  b := 10 ;
  ...
  while ( a > 1 ) do
  begin
    if ( b > 10 ) then b := 2 ;
    a := a - 1 ;
  end ;
end .
```
