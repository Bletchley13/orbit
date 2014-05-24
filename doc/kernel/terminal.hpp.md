terminal.hpp
============

### Description
Functions for managing the terminal.

### Functions
| Function Name | Usage/Description |
| --- | --- |
| `Terminal::initialize()` | Initializes the terminal. Must be invoked before any other `Terminal` functions are called. |
| `Terminal::putchar(char chr)` | Places the character `chr` at the current cursor position. |
| `Terminal::puts(const char *str)` | Writes the string `str` at the current cursor position, and prints a newline (`\n`). |
| `Terminal::scroll()` | Scrolls the terminal up one line. |
| `Terminal::set_color(enum Colors foreground, enum Colors background)` | Sets the terminal color to `foreground` `background`. |
| `Terminal::clear()` | Clears the terminal and resets the cursor position. |
| `Terminal::cursor_update()` | Moves the cursor to the current position, if `move_cursor` is true. |

### Variables
| Variable Name | Usage/Description |
| --- | --- |
| `Terminal::cursor_move` | If `true`, the VGA cursor will move after writing to the terminal. If `false`, the cursor will not move. |

### Enums
| Enum Name | Usage/Description |
| --- | --- |
| `Color` | Colors for use in the terminal. |