# so_long | 42KL

*And thanks for all the fish! 🐟*

![so_long.gif](https://github.com/mseong123/so_long/blob/main/maps/so_long.gif)

## Introduction
This project is a very small 2D game. It is built to make you work with textures, sprites and it incorporates some very basic gameplay elements. It is built using [MiniLibX library](https://github.com/42Paris/minilibx-linux) and C Language. The game we choose must follow a set of rules. The executable ``so_long`` will receive a map as the only argument, and this map will have a ``.ber`` filetype.

The file also must follow these rules:
- Only ``P`` *(player)*, ``1`` *(wall)*, ``0`` *(empty)*, ``C`` *(collectible)*, and ``E`` *(exit)* will be accepted characters in our map (except if you add enemy sprites as bonus)
- The map must be rectangular, i.e. all rows must have the same length
- There must be at least one exit, one player, and one collectible on the map
- The map must be closed, i.e. surrounded by walls

If any of these checks fail, the game must end with ``Error\n`` followed by a custom message.

The goal is for the player(s) to collect all the collectibles on the map before going to an exit in the least possible number of steps.

## Status

Validated 14/6/2023. Grade: 125%. Project duration: 1 week.

## Clone

Clone the repository including the MiniLibX (for macOS) library:

```
git clone https://github.com/mseong123/so_long.git
```

## Compile and Run

The program is split into a mandatory part and a bonus part. The bonus part adds wall collision, a rotating minimap, a (Sonic!) sprite and the ability to rotate the view by moving the mouse.

To compile the mandatory part, `cd` into the cloned directory and:

```
make
```

To run the program:

```
./so_long ./map1.ber
```
*(There's other maps in the ./map folder that can be used and the program can parse any other map configurations as long as it that meets the above rules)*

Controls for movement are:

- `W`: move forward
- `S`: move backward
- `A`: move left
- `D`: move right

## Useful Resources
- MinilibX tutorial : [harm-smits.github.io](https://harm-smits.github.io/42docs/libs/minilibx.html)
- [Subject PDF](https://github.com/mseong123/so_long/blob/main/en.subject.pdf)

