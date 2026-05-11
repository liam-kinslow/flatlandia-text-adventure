# Flatlandia

A terminal-based text adventure game written in C. Explore a procedurally placed 6×6 world, fight enemies using d20 dice-roll combat, collect items, and return the Goblet of Frenchay to your ship to win.

Built as a first-year coursework project at the University of the West of England (2023).

---

## Gameplay

You wash ashore an uncharted island. Your goal is to find the Goblet of Frenchay and return it to the starting beach.

To get it you'll need to:
1. Explore the 6×6 map to find the Dragon guarding a locked chest
2. Defeat the Dragon and it drops a key
3. Find the chest and open it with the key to retrieve the Goblet
4. Navigate back to the starting beach to win

Along the way you'll encounter four enemies — a Dragon, Orc, Ghoul, Gargoyle, and Leprechaun — each placed at random locations on every new game. Three items are also scattered across the map to aid you.

---

## Commands

| Command | Action |
|---|---|
| `move n/e/s/w` | Move north, east, south, or west |
| `look` | Examine your surroundings and nearby items |
| `collect` | Pick up an item at your current location |
| `inventory` | List items currently in your inventory |
| `health` | Check your current health |
| `controls` | Display the command list |
| `quit` | Exit the game |

---

## Combat

Combat triggers automatically when you move into a location occupied by an enemy. Rounds use a d20 roll-off:

- Both you and the enemy roll a d20
- Higher roll wins the exchange
- Winner deals a separate damage roll (d20 for player, d8 for enemy)
- A tie results in both attacks missing
- During combat you can attack (`a`) or use an item from your inventory (`i`)

Player starts with 100 health. Defeat all enemies to reach the Dragon safely.

---

## Items

| Item | Effect |
|---|---|
| Silver Sword | Defeats any enemy instantly in combat |
| Round Shield | Restores 25 health when used in combat |
| Health Potion | Restores 50 health when used in combat |

---

## World

The map is a 6×6 grid of named locations including beaches, forests, villages, mountains, a volcano, a harbour, and impassable terrain (cliffs, bogs, a towering mountain). Enemy and chest positions are randomised on each playthrough using a duplicate-location check to ensure no two entities share a tile.

---

## Development

The game was built iteratively across multiple versions of each module, with observations and testing documented at each stage. Key design decisions included:

- **Movement**: v1.0 used tag-based teleportation (`move forest`). Replaced in v2.0 with a 6×6 grid and cardinal direction movement (`move n/e/s/w`) using a switch statement and row/column tracking.
- **Passable terrain**: A `passable` field was added to the location struct in v2.0, blocking impassable tiles (cliffs, bogs, a towering mountain) while still printing their descriptions.
- **Object placement**: v3.0 introduced `objectLocations()` — a randomiser using a `duplicateLocation()` check to ensure no two entities share a tile and none land on impassable terrain. The dragon is always placed adjacent to the chest.
- **Inventory**: v1.0 had a pointer bug causing `listInventory()` to fail silently. Fixed in v2.0. Item use was added in v3.0; unusable items were incorrectly consumed, fixed in v4.0 by moving `removeItem()` into each usable item's branch only.
- **Combat**: v1.0 auto-rolled on enter. v2.0 added player choice (`a` to attack, `i` to use item) and the Dragon's key-drop mechanic.
- **Circular dependencies**: Header include order required careful management to avoid circular dependency issues across `object.h`, `inventory.h`, `location.h`, and `misc.h`.

---

## How to Build and Run

### Requirements
- GCC or any C99-compatible compiler

### Compile

```bash
gcc main.c -o flatlandia
```

### Run

```bash
./flatlandia
```

On Windows:
```bash
flatlandia.exe
```

---

## Project Structure

```
flatlandia/
├── main.c               # Entry point, game loop
├── object.h             # Location map, items, enemies, player struct
├── location.h           # Movement and look functions
├── combat.h             # d20 combat system
├── inventory.h          # Inventory management and item use
├── parse_and_execute.h  # Command parser
└── misc.h               # Win condition, chest condition, controls
```

---

## Author

**Liam Kinslow**  
MSc Advanced Microelectronic Systems Engineering, University of Bristol  
BEng Electronic Engineering (1st Class Honours), University of the West of England  
[GitHub](https://github.com/liam-kinslow) | [LinkedIn](https://linkedin.com/in/liam-kinslow-141733193)
