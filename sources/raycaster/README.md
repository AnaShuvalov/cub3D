# Roadmap to the Execution part of Cub3d

### Roadmap

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
- [X] make buffer between walls
- [X] lines of floor and ceiling on top and bottom
- [X] remove FPS counter
- [X] Norminette
- [X] bonus directory
	- [X] wall collision (mandatory: upon wall, stop - bonus: upon wall, slide)
- [ ] BONUS MAKEFILE ARGUMENT
- [ ] Cheat Sheet in Readme

- buffer between player and wall
- protect corners
- fisheye at first, must be hardcoded
- raycast can 'glitch' through walls

- [X] do we need to have up and down key movements too?

## Cheatsheet

- **DDA:** Digital Differential Analysis, basically a grid traversal algorithm that moves a ray from one map cell to the next, checking whether it crosses an X or Y grid boundary first, until it detects a wall
- **ray_dir_x, ray_dir_y:** direction of the current ray that's being cast
- **map_x, map_y:** current integer map-cell coordinates for DDA
- **step_x, step_y:** whether DDA should move in positive or negative X or Y direction
- **side_dist_x, side_dist_y:** distance of the ray's current position to the next x or y grid line. DDA needs them to decide which grid boundary the ray reaches fist.
- **delta_dist_x, delta_dist_y:** distance which the ray must travel to cross an additional vertical or horizontal grid line. Repeatedly added to side_dist_x and _y during DDA
- **wall_hit:** whether a ray has reached a wall. If yes, DDA loop stops
- **side:** records which kind of grid boundary the ray crossed to hit a wall:
	- 0: ray hit a vertical wall after crossing an X boundary
	- 1: ray hit horizontal wall side after crossing a Y boundary
- **perp_wall_dist:** perpendicular distance from player to wall. Prevents fish eye effect
- **line_height:** how tall the wall-column should be drawn depending on distance to the wall
- **draw_start:** first vertical piel row where wall slice begins. Pixels above this point are drawn as the ceiling
- **draw_end:** final vertical pixel boundary of the wall slice. Pixels below this point are drawn as the floor
- **texture_x:** horizontal x-coordinate in the selected wall texture. Determines which vertical texture column is mapped onto the current wall slice 