*This project has been created as part of the 42 curriculum by anshuval, olmatske.*

# cub3D

## Description
A dynamic 3D raycasting maze renderer built in C using MiniLibX, inspired by the classic 1992 game Wolfenstein 3D.

cub3D explores practical computer graphics by projecting a 2D map layout into a first-person 3D perspective in real time using the **Digital Differential Analysis (DDA) raycasting algorithm**.

The project was split into two categories:

**Parser & Validator**: File ingestion, syntax verification, RGB extraction, and map boundary closedness validation.

**Raycaster & Engine**: Vector math, DDA collision calculation, wall texture mapping, and frame-buffered rendering via MiniLibX.

## Features
**Real-time Raycasting**: Smooth first-person camera movement and rotation.

**Directional Wall Textures**: Dynamic orientation mapping displaying unique .xpm textures for North, South, East, and West wall faces.

**Customizable Environments**: Solid ceiling and floor colors parsed from standard RGB values.

**Robust Map Parsing**:
	Argument validation and .cub file format verification.
	Resilient metadata extraction handling arbitrary order and blank lines.
	Map boundary validation ensuring the playable grid is completely enclosed by walls (1).
	Explicit player spawn orientation (N, S, E, W).
	
## Scene File Specifications (.cub)
A scene file must contain 6 metadata identifiers followed by the grid layout:

	NO ./textures/north.xpm
	SO ./textures/south.xpm
	WE ./textures/west.xpm
	EA ./textures/east.xpm

	F 220,100,0
	C 225,30,0

    	    1111111111111
        	1000000000111
	        1011000001111
	111111111011000001101
	1000000000000000010N1
	111111111111111111111

## Metadata Identifiers
	NO <path>: Path to North wall .xpm texture.

	SO <path>: Path to South wall .xpm texture.

	WE <path>: Path to West wall .xpm texture.

	EA <path>: Path to East wall .xpm texture.

	F <R,G,B>: Floor color (0 to 255 per channel).

	C <R,G,B>: Ceiling color (0 to 255 per channel).

## Grid Characters
	1: Wall.

	0: Empty walkable space.

	(Space): Unreachable empty space.

	N, S, E, W: Exactly one player spawn position and facing direction.

## Project Structure
	
	├── Makefile
	├── README.md
	├── includes/
	│   └── cub3d.h
	│   └── parser.h
	├── libft/
	├── get_next_line/
	├── MLX42/
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
		│   ├── raycaster.c
		│   ├── dda.c
		│   └── texture_mapping.c
		├── render/
		│   ├── frame_drawing.c
		│   └── framebuffer.c
		└── hooks/
			├── key_events.c
			└── close_events.c

## Installation & Compilation
	git clone <repository_url> cub3d
	cd cub3d
	make

## Controls

	Key				Action
	W				Move forward
	S				Move backward
	A				Strafe left
	D				Strafe right
	Left Arrow		Rotate camera left
	Right Arrow		Rotate camera right
	ESC/Red Cross	Exit application cleanly

## Usage
Run the executable with a single .cub map file as an argument:

	Bash
	./cub3D maps/valid/subject_map.cub