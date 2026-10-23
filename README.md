*This project has been created as part of the 42 curriculum by anshuval, olmatske.*

# cub3D

## Description
cub3D is our take on the old Wolfenstein 3D (1992): a small first-person maze you can walk around in, written in C with MLX42.

There is no real 3D in here. The map is just a 2D grid of walls and floor, and for every column of the window we shoot a ray from the player until it hits a wall. The closer the wall, the taller we draw it. Do that 1200 times per frame and you get the 3D look. The method is called raycasting, and we used the DDA version from Lode's tutorial to step the ray through the grid.

We split the work in two parts:

**Parser**: reads the .cub file, checks the textures and colors, builds the map grid and makes sure the map is closed by walls. If anything is wrong the program prints `Error` and a message and exits.

**Raycaster**: the rays, the wall textures, the movement and drawing everything into the window with MLX42.

## Features
**Raycasting**: you can walk and look around in real time.

**Wall textures**: a different .png for each side the wall is facing (North, South, East, West).

**Floor and ceiling colors**: taken from the F and C lines of the .cub file.

**Shading**: walls get darker the further away they are, so the corridors have some depth.

**Map parsing**:
	Argument validation, .cub file access verification.
	Metadata verification handling blank lines in map and outside of it.
	Map boundary validation ensuring the playable grid is completely enclosed by walls (1).
	Explicit player spawn orientation (N, S, E, W).

###  Bonus features
**Minimap system**: a 2D map in the right hand top corner of the play screen with player compass indicator.

**Wall collisions**: the player has a small radius around him, so he stops a bit before the wall instead of touching it, and if you walk into a wall at an angle you slide along it instead of getting stuck.

## Scene File Specifications (.cub)
A scene file must contain 6 metadata identifiers followed by the grid layout. The map always has to be the last thing in the file, everything else can come in any order and with empty lines in between:

	NO ./textures/north.png
	SO ./textures/south.png
	WE ./textures/west.png
	EA ./textures/east.png

	F 220,100,0
	C 225,30,0

	        1111111111111
	        1000000000111
	        1011000001111
	111111111011000001101
	1000000000000000010N1
	111111111111111111111

## Metadata Identifiers
	NO <path>: Path to North wall .png texture
	SO <path>: Path to South wall .png texture
	WE <path>: Path to West wall .png texture
	EA <path>: Path to East wall .png texture
	F <R,G,B>: Floor color (0 to 255 per channel)
	C <R,G,B>: Ceiling color (0 to 255 per channel)

## Grid Characters
	1: Wall
	0: Empty walkable space
	(Space): Unreachable empty space
	N, S, E, W: Exactly one player spawn position and facing direction.

## Project Structure

	├── Makefile
	├── README.md
	├── includes/
	│   ├── cub3d.h
	│   ├── parser.h
	│   ├── raycast.h
	│   ├── libft/
	│   ├── get_next_line/
	│   └── MLX42/
	├── maps/
	│   ├── valid/
	│   └── invalid/
	├── textures/
	└── sources/
		├── main.c
		├── parser/
		│   ├── parser.c
		│   ├── all_about_errors.c
		│   ├── grid_building.c
		│   ├── verification_colors.c
		│   ├── verification_map.c
		│   ├── verification_path.c
		│   └── verification_player.c
		├── raycaster/
		│   ├── raycast.c
		│   ├── camera.c
		│   ├── graphics.c
		│   ├── textures.c
		│   ├── orientation.c
		│   ├── orientation_bonus.c
		│   └── wrapper_bonus.c
		├── render/
		│   ├── frame.c
		│   ├── frame_bonus.c
		│   └── minimap_bonus.c
		└── hooks/
			├── close_events.c
			└── key_events.c

## Instructions

### Installation & Compilation
	git clone <repository_url> cub3d
	cd cub3d
	make or make bonus

`make clean`, `make fclean`, `make re` and `make re_bonus` work as usual.

### Controls

	Key				Action
	W				Move forward
	S				Move backward
	A				Strafe left
	D				Strafe right
	Left Arrow		Rotate camera left
	Right Arrow		Rotate camera right
	ESC/Red Cross	Exit application cleanly

### Usage
Run the executable with a single .cub map file as an argument:

	Bash
	./cub3D maps/(in)valid/*.cub
	or
	Bash
	./cub3D_bonus maps/(in)valid/*.cub

There are test maps in `maps/valid/` and broken ones in `maps/invalid/`. To run all the invalid ones at once:

```bash
make test_invalid_maps
```

To check for leaks with valgrind (MLX/GLFW driver noise is suppressed with `sub.sub`):

```bash
make valgrind MAP=maps/valid/minimal.cub
make valgrind_bonus MAP=maps/valid/minimal.cub
```

## Resources
- [MLX42 documentation](https://github.com/codam-coding-college/MLX42): for the window, images, key hooks and loading png textures.
- [Lode's Computer Graphics Tutorial - Raycasting](https://lodev.org/cgtutor/raycasting.html): the tutorial basically everybody uses for cub3D. The DDA, the camera plane and the texture mapping all come from here.
- [Fabien Sanglard - Game Engine Black Book: Wolfenstein 3D](https://fabiensanglard.net/gebbwolf3d/): how the original game did it in 1992.
- [Rotation matrix (Wikipedia)](https://en.wikipedia.org/wiki/Rotation_matrix): for turning the direction and camera plane with the arrow keys.
- [Digital Differential Analyzer (Wikipedia)](https://en.wikipedia.org/wiki/Digital_differential_analyzer_(graphics_algorithm)): the general idea behind stepping a ray through a grid.

### AI usage
AI was used mostly for things around the code rather than the code itself:

- **Understanding the math.** Such as why the camera plane is perpendicular to the direction vector, how the rotation formulas with cos and sin work, why we use the perpendicular distance instead of the real one (no fisheye), and how to scale the minimap to the map size. After that we wrote and tested the code ourselves and checked it against the tutorial.
- **Reviewing and debugging.** Norm problems and to help us understand a few bugs (for example walls disappearing for a split second when standing right next to them).
- **Makefile.** Help structure and understand the twerks in the Makefile for our gamification purpose - terminal styling, ading the ANSI escape color codes, checkmark symbols, silencing the extra info and organizing the clean separation bewteen the chapters.
- **Maps.** Most of the maps are purely AI generated.
- **Mindmap.** Dividing mindmaps into readable structures.
- **This README.** Help with the wording and structure.

## Parser Mindmap

**1. Setup**
- [x] Outline the structs in the header (`t_game`, `t_map`, `t_player`, `t_keys`)
- [x] Init `t_game` and a basic `main`

**2. The argument and the file**
- [x] Exactly one argument
- [x] Has to end in `.cub`
- [x] Not a hidden file like `.cub` on its own
- [x] Not a directory (`open()` happily opens those too)
- [x] File opens, otherwise check the permissions

**3. Reading line by line**
- [x] Read with get_next_line
- [x] Cut off `\n` and `\r` at the end
- [x] Skip spaces at the start of the identifier lines
- [x] Look at the first character and send the line to the right check (texture / color / map)
- [x] Turn tabs into spaces straight away, so nothing after that has to care about them

**4. Textures (NO, SO, WE, EA)**
- [x] Identifier is spelled right and followed by exactly one path
- [x] ~~Path has to be `.xpm`~~ Path has to be `.png`
- [x] File exists, opens and isn't empty
- [x] No duplicate lines

**5. Colors (F, C)**
- [x] Count the commas first, exactly 2
- [x] Exactly 3 values, only digits
- [x] Every value between 0 and 255
- [x] A huge number can't overflow and wrap around into a "valid" one
- [x] No duplicate lines
- [x] Pack R, G, B into one color for MLX42
- [x] Color has to be with the 0x prefix for MLX42

**6. The map**
- [x] Map has to be the last thing in the file, so no identifiers after it
- [x] Linked list helpers added to libft
- [x] Store the map lines in a linked list - we don't know the height until EOF
- [x] Empty lines before the map: skip. inside the map: error. after the map: trim
- [x] Only allowed characters (`0`, `1`, space, `N`, `S`, `E`, `W`)
- [x] Linked list → `char **grid` (reusing the strings, only the nodes get freed)
- [x] Width = the longest row, height = number of rows

**7. Player**
- [x] Exactly one N, S, E or W
- [x] Spawn in the middle of the tile (`x + 0.5`, `y + 0.5`)
- [x] Set the direction vector and the camera plane from the letter

**8. Closed by walls**
- [x] Every walkable tile and the player can't touch a space or the edge of the map
- [x] Shorter rows count as open, so a `0` hanging past the row above is caught too

**9. Last check before the game starts**
- [x] All 4 textures, F, C and the map are there
- [x] `Error\n` + a message on stderr for every case
- [x] `error_message()` only prints so we can still free, `ft_error()` prints and exits (only used before anything is allocated)
- [x] Everything gets freed on every error path

**10. Hooks**
- [x] ~~Move the player directly in the key callback~~ → rewritten
- [x] Key press / release only flips a bool in `t_keys`, the game loop does the moving, so you can hold keys and press two at once
- [x] ESC and the red cross both go through `close_game()`
- [x] `close_game()` takes an exit status
- [x] `free_game()` frees paths, textures, images and the grid, then `ft_bzero` so a second call can't double free

**11. Minimap (bonus)**
- [x] Draw the grid in the loop
- [x] Move it to the top right corner, own colors for walls / floor / empty space
- [x] Tile size scales with the map so it always fits
- [x] ~~Square player~~ → it overlapped the walls
- [x] Round player: `x*x + y*y <= r*r`. Pyphagor's theorem
- [x] Compass dot in front of the player, showing where you're looking
- [x] ~~Minimap centered on the player~~ → it worked, but we didn't like it, so we went back
- [x] Frame around the minimap
- [x] Maps that are too big don't get a minimap (they used to wrap around to the other side of the screen)

**12. Breaking it on purpose**
- [x] Lots of broken maps in `maps/invalid/` (this found a few parser bugs)
- [x] `make test_invalid_maps` runs them all at once
- [x] Valgrind + a suppression file (`sub.sub`) for the MLX/GLFW leaks that aren't ours
- [x] Norminette
- [x] Split everything into mandatory and `_bonus` files

## Raycaster Mindmap