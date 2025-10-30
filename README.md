# Plants vs. Zombies

A lightweight remake of the classic *Plants vs. Zombies* game, implemented in C++ using basic graphics and object-oriented programming principles. This version includes core gameplay mechanics such as planting defensive units, spawning enemy waves, and managing resources.

## How to Play

- **Select Plants**:
  - Press **1** → **Peashooter**
  - Press **2** → **Wall-nut**
  - Press **3** → **Sunflower**

- **Sun Cost**: Each plant requires a specific amount of sun to place.

| Plant       | Role                          |
|-------------|-------------------------------|
| **Peashooter** | Primary offensive unit — shoots peas at zombies. |
| **Wall-nut**   | Defensive barrier — absorbs damage to protect lanes. |
| **Sunflower**  | Resource generator — produces additional sun over time. |

## Objective

- **Win**: Defeat all zombies before they reach your house.
- **Lose**: Zombies that enter the house reduce your health. If health reaches **0**, the game ends.

## Compilation instructions

The project is configured with CMake.

Terminal instructions:

1. Configuration step  
```sh
cmake -S . -B build -DCMAKE_BUILD_TYPE=Debug
# or ./scripts/cmake.sh configure
```

Or on Windows with GCC:
```sh
cmake -S . -B build -DCMAKE_BUILD_TYPE=Debug -G Ninja
# or ./scripts/cmake.sh configure -g Ninja
```
At this step, we can request the generation of project files for various development environments.
