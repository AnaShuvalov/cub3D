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
- [Cub3D documentation](https://harm-smits.github.io/42docs/projects/cub3d)
- [Jun Han Ng's Approach and Explanation (Was very useful!)](https://hackmd.io/@nszl/H1LXByIE2#dda-algorithm)
- Of course a whole lot of help from peers, from introduction to helpful tips on how to make the game more efficient using good practices in ame development (lot of credits to jkauker!)

### AI usage
AI was used mostly for things around the code rather than the code itself:

- **Understanding the math.** Such as why the camera plane is perpendicular to the direction vector, how the rotation formulas with cos and sin work, why we use the perpendicular distance instead of the real one (no fisheye), and how to scale the minimap to the map size. After that we wrote and tested the code ourselves and checked it against the tutorial.
- **Reviewing and debugging.** Norm problems and to help us understand a few bugs (for example walls disappearing for a split second when standing right next to them).
- **Makefile.** Help structure and understand the twerks in the Makefile for our gamification purpose - terminal styling, ading the ANSI escape color codes, checkmark symbols, silencing the extra info and organizing the clean separation bewteen the chapters.
- **Maps.** Most of the maps are purely AI generated.
- **This README.** Help with the wording and structure.

## Parser Roadmap

- [X] structs in header (t_game, t_map, t_player, t_keys) & basic main
- [X] .cub file verification
	- [X] extension check (.cub, not hidden, not a directory)
	- [X] permissions & file opens
- [X] gnl line by line reading
	- [X] strip newline / CR
	- [X] replace tabs with spaces right away
- [X] texture identifiers (NO, SO, WE, EA)
	- [X] only .png textures
	- [X] file exists, readable, not empty
	- [X] no duplicates
- [X] colors (F, C)
	- [X] count commas first (exactly 2, so split doesn't swallow empty values)
	- [X] 0-255 per channel, no int overflow wrapping
	- [X] pack RGB into single uint32 for MLX42
- [X] map parsing
	- [X] map must come last in the file
	- [X] read into linked list first (don't know height until EOF)
	- [X] list to grid (char **grid)
	- [X] empty lines: skip before map, error inside, trim trailing
- [X] player setup
	- [X] exactly one spawn (N, S, E, W)
	- [X] set player pos (tile center + 0.5) and dir/plane vectors
- [X] enclosed by walls check (spaces & shorter adjacent rows count as open)
- [X] error handling & clean exits
	- [X] error_message() prints Error + message, ft_error() exits directly
	- [X] free_game() cleans paths, textures, grid, framebuffer + bzero for safety
- [X] key hooks & window close
	- [X] press/release boolean flags (for smooth walking without key delay)
	- [X] ESC & red cross cleanly close window
- [X] minimap & compass (bonus)
	- [X] tile size scaling so it fits on screen
	- [X] round player dot with Pythagoras theorem (x*x + y*y <= r*r)
	- [X] compass indicator dot
	- [X] frame around minimap & skip if map exceeds 160 tiles
	- ~~centered minimap on player~~ -> tried it, didn't like it, reverted
- [X] testing & leaks
	- [X] automated test_invalid_maps in Makefile
	- [X] valgrind suppression file (sub.sub) for MLX driver noise
	- [X] Norminette

**Notes**
- ft_split eats double commas (255,,0), so comma count is checked first
- open() happily opens directories, so check if it's a folder explicitly
- map must be last so we know when empty lines become invalid
- trailing empty lines at end of map took two commits to get right


## Raycaster Roadmap

- [X] Minimap with walls n stuff
- [X] raycaster
- [X] movement (vector with normalization, meaning the speed is the same)
- [X] vector addition -> movement speed and rotational speed
- [X] wall collisiion
- [X] shader
- [x] hook up textures
- [X] sticky walls
- [X] is there a check for textures?
- [X] hook up floor and ceiling colors from map sruct
- [X] why does the camera/view slow down when I get closer to the walls?
	-> it's to be expected in raycasting
- [X] make buffer between walls and player
- [X] fix lines of floor and ceiling on top and bottom
- [X] remove FPS counter
- [X] Norminette
- [X] bonus directory
	- [X] wall collision (mandatory: upon wall, stop - bonus: upon wall, slide)
- [X] bonus makefile argument
- [ ] Cheat Sheet in Readme

**Notes**
- buffer between player and wall
- protect corners
- fisheye at first, must be hardcoded
- raycast can 'glitch' through walls