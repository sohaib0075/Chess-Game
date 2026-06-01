# ♟️ Chess Game

A **two-player console chess game** built in **C++** that runs in the terminal. Players take turns entering moves in algebraic notation, with real-time board validation for each piece type and a checkmate detection system.

---

## 📌 Overview

This is a terminal-based chess implementation where two players play on the same machine, alternating turns. The 8×8 board is rendered in ASCII, pieces are represented by standard letter symbols, and move validation is enforced per piece type.

---

## 🎮 How to Play

1. Run the program — the board displays with **White's turn** first
2. Enter moves in the format: `a1 - a6` (source square → destination square)
   - Columns: `a` to `h`
   - Rows: `1` to `8`
3. The board updates and clears the screen after each move
4. The game ends when a **King is captured** (checkmate condition)

### Example Move
```
enter your move
for Example ( a1 - a6 ) : a2 - a4
```

---

## ♟️ Piece Symbols

| Symbol | Piece | Color |
|---|---|---|
| `K` | King | White |
| `Q` | Queen | White |
| `R` | Rook | White |
| `B` | Bishop | White |
| `N` | Knight | White |
| `k` | King | Black |
| `q` | Queen | Black |
| `r` | Rook | Black |
| `b` | Bishop | Black |
| `n` | Knight | Black |
| `.` | Empty square | — |

---

## ✅ Move Validation

| Piece | Rule Enforced |
|---|---|
| **Rook (R/r)** | Must move horizontally or vertically only |
| **Bishop (B/b)** | Must move diagonally only (`|ΔRow| == |ΔCol|`) |
| **Knight (N/n)** | Must move in L-shape (2+1 or 1+2 squares) |
| **Empty square** | Cannot select an empty square as source |
| **Turn order** | Cannot move opponent's pieces on your turn |

---

## 🏁 Win Condition

The game detects **checkmate** by checking if either King (`K` or `k`) has been **captured** (removed from the board). When a King is missing, the game announces the winner:

```
Shah Mat! White wins.
```
or
```
Shah Mat! black wins.
```

---

## 🛠️ Tech Stack

- **Language:** C++
- **Library:** `<windows.h>` — used for `system("CLS")` to clear the screen after each move
- **I/O:** Standard console input/output

> ⚠️ Note: `system("CLS")` is Windows-specific. To run on Linux/Mac, replace it with `system("clear")`.

---

## 🚀 Getting Started

### Compile

```bash
g++ chessgame.cpp -o chess
```

### Run

```bash
./chess
```

> On Windows: `chess.exe`

---

## 📂 Project Structure

```
Chess-Game/
├── chessgame.cpp    # Full source code
└── README.md
```

---

## 📋 Functions

| Function | Description |
|---|---|
| `chessboard()` | Initializes board with starting piece positions |
| `chessgrid()` | Renders the 8×8 board with row/column labels |
| `entermove()` | Reads player input and updates board position |
| `makingmoves()` | Validates move legality for each piece type |
| `checkmate()` | Detects if either King has been captured |

---

## 👤 Author

**Sohaib Shahzad (sohaib0075)**  
[GitHub Profile](https://github.com/sohaib0075)

---

## 📄 License

This project is open source and available under the [MIT License](LICENSE).
