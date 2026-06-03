# Custom Compiler Implementation in C

### 🏗️ Formal Languages & Compilation Engineering Portfolio

This repository features a robust, modular **Compiler** engineered from scratch in pure C. It showcases the practical application of formal language theory, finite automata, and syntax-directed translation to process, validate, and translate source code.

The architecture emphasizes strict memory management, complex pointer manipulation, and hierarchical tree data structures to manage the classic compilation phases.

---

## ⚙️ Compilation Pipeline Architecture

The system is designed following a highly decoupled, standard compiler pipeline:

1. **Lexical Analysis (Scanner):** Tokenizes the raw input stream, identifying keywords, identifiers, operators, and literals while filtering out whitespace and comments.
2. **Syntactic Analysis (Parser):** Validates the token stream against a defined context-free grammar (CFG) to construct an Abstract Syntax Tree (AST) or parse tree.
3. **Symbol Table Management:** Tracks scopes, variable declarations, and type signatures to ensure semantic integrity.
4. **Code Generation / Interpretation (Optional/Context Dependent):** Translates the verified AST into an intermediate representation, target assembly, or executes it directly via an evaluation engine.

---

## 🛠️ How to Compile and Build

An automated `Makefile` is provided to seamlessly handle dependency tracking and binary generation.

### Prerequisites
- GCC Compiler (`gcc`)
- GNU Make (`make`)

### Building the Compiler
To compile the source files and generate the final compiler executable, run:
```bash
make
