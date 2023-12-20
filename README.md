# so_long_42
This project centers around the creation of an interactive 2D game controlled via keyboard input. The project is segmented into two components: the obligatory and the supplementary. Each segment is independently compiled and executed. The supplementary section encompasses all the features present in the mandatory part, supplemented by extra enhancements.

## Installation

Clone this repository to your computer:
```sh
git clone https://github.com/zelabbas/so_long_42.git
```

First compile and install library
```sh
make
```

if you want part bonus compile with 
```sh
make bonus 
```

## How to play
### Rule
Control your character to collect all items in the map. Collect all items in map before exit. Avoid the enemy nonetheless you would died.

### Command

Run game by execute `so_long` file.
```bash
./so_long
```

Run game with specific map file by add file name as argument
```
./so_long "map.ber"
```
for the part bonus Run 
```
./so_long_bonus "map.ber"
```
Recompile a game, After edit `so_long.h` setting
```bash
make re 
```

### Key control
You can control the main character with specific key below. 

|Key|Description|
|--|--|
| `A` or ⬅️ | Walk Left|
| `W` or ⬆️ | Walk Up|
| `S` or ⬇️ | Walk Down|
| `D` or ➡️ | Walk Right|
| `ESC`    | Destroy window|

### Map File
You can create your own map file as you like but need to follow these rules.
- map is covered with walls
- map is contained with 1 item, 1 player and 1 exit door.
- The map must be rectangular
- map file name need end with `.ber`
- place map file in `maps` directory

The character is defined in file follow like these
| Character |Description|
|--|--|
| `0` | Free space |
| `1` | Wall |
| `P` | Player |
| `E` | Exit door |
| `C` | Collectable item |

**Map file example**
```txt
1111111111111
10M100010CM01
10010100M00C1
100C011111001
1P0011E000001
1111111111111
```

## Resources
- [MiniLibX]
- [MiniLibX Document]
- [MiniLibX Tutorial]
- [Sprite Resources]

# by zelabbas (good luck).