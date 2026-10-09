## THOUGHTS HOW TO PROCEED

[x] stop checking for empty lines once the map starts.
[ ] check if the textures, coloros have been populated at this stage already
[x] store all the map in one place
[x] check if there are empty lines inside the map
[x] if empty line is encountered check if there are no filled lines till the end of the map
[x] if there is an empty line and there is no other characteres till the end of the file than the empty lines can be ignored
[ ] if i still stick to the linked list after this - delete the nodes with the empty lines
[ ] 

## help with the raycasting - the colors of the walls should be different for every wall
## to do after vacation
[ ] the player square is overlapping wit he walls till it hits the middle of the square.
[ ] check the minimap file - the functions are duplicated for sme pointrs. check the math (minimap compass get player and minimap)
[ ] check the minimap player size
[ ] why the view dot drwas an oval (up and down more than left and right) and not a circle
[ ] make the empty space between the vie dot and the player square less

==561567== Memcheck, a memory error detector
==561567== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==561567== Using Valgrind-3.18.1 and LibVEX; rerun with -h for copyright info
==561567== Command: ./cub3d maps/valid/first_map.cub
==561567== 
==561567== 
==561567== HEAP SUMMARY:
==561567==     in use at exit: 423,722 bytes in 3,108 blocks
==561567==   total heap usage: 71,757 allocs, 68,649 frees, 69,758,344 bytes allocated
==561567== 
==561567== 0 bytes in 1 blocks are definitely lost in loss record 1 of 2,246
==561567==    at 0x4848899: malloc (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
==561567==    by 0x4005A22: malloc (rtld-malloc.h:56)
==561567==    by 0x4005A22: _dl_find_object_update (dl-find_object.c:791)
==561567==    by 0x400ECCF: dl_open_worker_begin (dl-open.c:735)
==561567==    by 0x4BBAB57: _dl_catch_exception (dl-error-skeleton.c:208)
==561567==    by 0x400DF99: dl_open_worker (dl-open.c:782)
==561567==    by 0x4BBAB57: _dl_catch_exception (dl-error-skeleton.c:208)
==561567==    by 0x400E34D: _dl_open (dl-open.c:883)
==561567==    by 0x4AD65FB: dlopen_doit (dlopen.c:56)
==561567==    by 0x4BBAB57: _dl_catch_exception (dl-error-skeleton.c:208)
==561567==    by 0x4BBAC22: _dl_catch_error (dl-error-skeleton.c:227)
==561567==    by 0x4AD60ED: _dlerror_run (dlerror.c:138)
==561567==    by 0x4AD6687: dlopen_implementation (dlopen.c:71)
==561567==    by 0x4AD6687: dlopen@@GLIBC_2.34 (dlopen.c:81)
==561567== 
==561567== 20 bytes in 1 blocks are definitely lost in loss record 20 of 2,246
==561567==    at 0x4848899: malloc (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
==561567==    by 0x406AC1: ft_strdup (in /home/anshuval/Documents/GIT/cub3D/cub3D/cub3d)
==561567==    by 0x40388C: path_allocation (verification_path.c:22)
==561567==    by 0x403663: verify_path (verification_path.c:79)
==561567==    by 0x402B1E: populate_game (parser.c:51)
==561567==    by 0x40296C: convert_map_to_list (parser.c:74)
==561567==    by 0x4027EA: read_map (parser.c:90)
==561567==    by 0x4027B1: parser (parser.c:113)
==561567==    by 0x4025D7: main (main.c:47)
==561567== 
==561567== 20 bytes in 1 blocks are definitely lost in loss record 21 of 2,246
==561567==    at 0x4848899: malloc (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
==561567==    by 0x406AC1: ft_strdup (in /home/anshuval/Documents/GIT/cub3D/cub3D/cub3d)
==561567==    by 0x4038CB: path_allocation (verification_path.c:24)
==561567==    by 0x403663: verify_path (verification_path.c:79)
==561567==    by 0x402B1E: populate_game (parser.c:51)
==561567==    by 0x40296C: convert_map_to_list (parser.c:74)
==561567==    by 0x4027EA: read_map (parser.c:90)
==561567==    by 0x4027B1: parser (parser.c:113)
==561567==    by 0x4025D7: main (main.c:47)
==561567== 
==561567== 21 bytes in 1 blocks are definitely lost in loss record 34 of 2,246
==561567==    at 0x4848899: malloc (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
==561567==    by 0x406AC1: ft_strdup (in /home/anshuval/Documents/GIT/cub3D/cub3D/cub3d)
==561567==    by 0x40380E: path_allocation (verification_path.c:18)
==561567==    by 0x403663: verify_path (verification_path.c:79)
==561567==    by 0x402B1E: populate_game (parser.c:51)
==561567==    by 0x40296C: convert_map_to_list (parser.c:74)
==561567==    by 0x4027EA: read_map (parser.c:90)
==561567==    by 0x4027B1: parser (parser.c:113)
==561567==    by 0x4025D7: main (main.c:47)
==561567== 
==561567== 21 bytes in 1 blocks are definitely lost in loss record 35 of 2,246
==561567==    at 0x4848899: malloc (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
==561567==    by 0x406AC1: ft_strdup (in /home/anshuval/Documents/GIT/cub3D/cub3D/cub3d)
==561567==    by 0x40384D: path_allocation (verification_path.c:20)
==561567==    by 0x403663: verify_path (verification_path.c:79)
==561567==    by 0x402B1E: populate_game (parser.c:51)
==561567==    by 0x40296C: convert_map_to_list (parser.c:74)
==561567==    by 0x4027EA: read_map (parser.c:90)
==561567==    by 0x4027B1: parser (parser.c:113)
==561567==    by 0x4025D7: main (main.c:47)
==561567== 
==561567== 112 (56 direct, 56 indirect) bytes in 1 blocks are definitely lost in loss record 2,203 of 2,246
==561567==    at 0x484DA83: calloc (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
==561567==    by 0x663486E: ???
==561567==    by 0x6106293: ???
==561567==    by 0x60EEDB8: ???
==561567==    by 0x60EEF6A: ???
==561567==    by 0x60A1109: ???
==561567==    by 0x60A3C24: ???
==561567==    by 0x609E9FC: ???
==561567==    by 0x604DAB7: ???
==561567==    by 0x608AEAD: ???
==561567==    by 0x608743C: ???
==561567==    by 0x601E61A: ???
==561567== 
==561567== 1,024 bytes in 1 blocks are definitely lost in loss record 2,223 of 2,246
==561567==    at 0x4848899: malloc (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
==561567==    by 0x40F918: lodepng_decode (in /home/anshuval/Documents/GIT/cub3D/cub3D/cub3d)
==561567==    by 0x4109C6: lodepng_decode_file (in /home/anshuval/Documents/GIT/cub3D/cub3D/cub3d)
==561567==    by 0x409442: mlx_load_png (in /home/anshuval/Documents/GIT/cub3D/cub3D/cub3d)
==561567==    by 0x405C2B: load_textures (textures.c:20)
==561567==    by 0x406228: start_game (frame.c:26)
==561567==    by 0x40267A: main (main.c:57)
==561567== 
==561567== 1,024 bytes in 1 blocks are definitely lost in loss record 2,224 of 2,246
==561567==    at 0x4848899: malloc (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
==561567==    by 0x40F9C6: lodepng_decode (in /home/anshuval/Documents/GIT/cub3D/cub3D/cub3d)
==561567==    by 0x4109C6: lodepng_decode_file (in /home/anshuval/Documents/GIT/cub3D/cub3D/cub3d)
==561567==    by 0x409442: mlx_load_png (in /home/anshuval/Documents/GIT/cub3D/cub3D/cub3d)
==561567==    by 0x405C5E: load_textures (textures.c:23)
==561567==    by 0x406228: start_game (frame.c:26)
==561567==    by 0x40267A: main (main.c:57)
==561567== 
==561567== 1,024 bytes in 1 blocks are definitely lost in loss record 2,225 of 2,246
==561567==    at 0x4848899: malloc (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
==561567==    by 0x40F918: lodepng_decode (in /home/anshuval/Documents/GIT/cub3D/cub3D/cub3d)
==561567==    by 0x4109C6: lodepng_decode_file (in /home/anshuval/Documents/GIT/cub3D/cub3D/cub3d)
==561567==    by 0x409442: mlx_load_png (in /home/anshuval/Documents/GIT/cub3D/cub3D/cub3d)
==561567==    by 0x405C91: load_textures (textures.c:26)
==561567==    by 0x406228: start_game (frame.c:26)
==561567==    by 0x40267A: main (main.c:57)
==561567== 
==561567== 102,400 bytes in 1 blocks are definitely lost in loss record 2,246 of 2,246
==561567==    at 0x4848899: malloc (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
==561567==    by 0x40F918: lodepng_decode (in /home/anshuval/Documents/GIT/cub3D/cub3D/cub3d)
==561567==    by 0x4109C6: lodepng_decode_file (in /home/anshuval/Documents/GIT/cub3D/cub3D/cub3d)
==561567==    by 0x409442: mlx_load_png (in /home/anshuval/Documents/GIT/cub3D/cub3D/cub3d)
==561567==    by 0x405BF8: load_textures (textures.c:17)
==561567==    by 0x406228: start_game (frame.c:26)
==561567==    by 0x40267A: main (main.c:57)
==561567== 
==561567== LEAK SUMMARY:
==561567==    definitely lost: 105,610 bytes in 10 blocks
==561567==    indirectly lost: 56 bytes in 1 blocks
==561567==      possibly lost: 0 bytes in 0 blocks
==561567==    still reachable: 318,056 bytes in 3,097 blocks
==561567==         suppressed: 0 bytes in 0 blocks
==561567== Reachable blocks (those to which a pointer was found) are not shown.
==561567== To see them, rerun with: --leak-check=full --show-leak-kinds=all
==561567== 
==561567== For lists of detected and suppressed errors, rerun with: -s
==561567== ERROR SUMMARY: 10 errors from 10 contexts (suppressed: 0 from 0)


==573572== Memcheck, a memory error detector
==573572== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==573572== Using Valgrind-3.18.1 and LibVEX; rerun with -h for copyright info
==573572== Command: ./cub3d maps/valid/first_map.cub
==573572== 
==573572== Invalid read of size 8
==573572==    at 0x40286A8: strncmp (strcmp.S:172)
==573572==    by 0x400668D: is_dst (dl-load.c:216)
==573572==    by 0x400810E: _dl_dst_count (dl-load.c:253)
==573572==    by 0x400810E: expand_dynamic_string_token (dl-load.c:395)
==573572==    by 0x40082B7: fillin_rpath.isra.0 (dl-load.c:483)
==573572==    by 0x4008602: decompose_rpath (dl-load.c:654)
==573572==    by 0x400ABF5: cache_rpath (dl-load.c:696)
==573572==    by 0x400ABF5: cache_rpath (dl-load.c:677)
==573572==    by 0x400ABF5: _dl_map_object (dl-load.c:2165)
==573572==    by 0x4003494: openaux (dl-deps.c:64)
==573572==    by 0x4BBAB57: _dl_catch_exception (dl-error-skeleton.c:208)
==573572==    by 0x4003C7B: _dl_map_object_deps (dl-deps.c:248)
==573572==    by 0x400EA0E: dl_open_worker_begin (dl-open.c:592)
==573572==    by 0x4BBAB57: _dl_catch_exception (dl-error-skeleton.c:208)
==573572==    by 0x400DF99: dl_open_worker (dl-open.c:782)
==573572==  Address 0x509fa99 is 9 bytes inside a block of size 15 alloc'd
==573572==    at 0x4848899: malloc (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
==573572==    by 0x40271DF: malloc (rtld-malloc.h:56)
==573572==    by 0x40271DF: strdup (strdup.c:42)
==573572==    by 0x4008594: decompose_rpath (dl-load.c:629)
==573572==    by 0x400ABF5: cache_rpath (dl-load.c:696)
==573572==    by 0x400ABF5: cache_rpath (dl-load.c:677)
==573572==    by 0x400ABF5: _dl_map_object (dl-load.c:2165)
==573572==    by 0x4003494: openaux (dl-deps.c:64)
==573572==    by 0x4BBAB57: _dl_catch_exception (dl-error-skeleton.c:208)
==573572==    by 0x4003C7B: _dl_map_object_deps (dl-deps.c:248)
==573572==    by 0x400EA0E: dl_open_worker_begin (dl-open.c:592)
==573572==    by 0x4BBAB57: _dl_catch_exception (dl-error-skeleton.c:208)
==573572==    by 0x400DF99: dl_open_worker (dl-open.c:782)
==573572==    by 0x4BBAB57: _dl_catch_exception (dl-error-skeleton.c:208)
==573572==    by 0x400E34D: _dl_open (dl-open.c:883)
==573572== 
==573572== Invalid read of size 8
==573572==    at 0x40286A8: strncmp (strcmp.S:172)
==573572==    by 0x400668D: is_dst (dl-load.c:216)
==573572==    by 0x4007F79: _dl_dst_substitute (dl-load.c:295)
==573572==    by 0x40082B7: fillin_rpath.isra.0 (dl-load.c:483)
==573572==    by 0x4008602: decompose_rpath (dl-load.c:654)
==573572==    by 0x400ABF5: cache_rpath (dl-load.c:696)
==573572==    by 0x400ABF5: cache_rpath (dl-load.c:677)
==573572==    by 0x400ABF5: _dl_map_object (dl-load.c:2165)
==573572==    by 0x4003494: openaux (dl-deps.c:64)
==573572==    by 0x4BBAB57: _dl_catch_exception (dl-error-skeleton.c:208)
==573572==    by 0x4003C7B: _dl_map_object_deps (dl-deps.c:248)
==573572==    by 0x400EA0E: dl_open_worker_begin (dl-open.c:592)
==573572==    by 0x4BBAB57: _dl_catch_exception (dl-error-skeleton.c:208)
==573572==    by 0x400DF99: dl_open_worker (dl-open.c:782)
==573572==  Address 0x509fa99 is 9 bytes inside a block of size 15 alloc'd
==573572==    at 0x4848899: malloc (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
==573572==    by 0x40271DF: malloc (rtld-malloc.h:56)
==573572==    by 0x40271DF: strdup (strdup.c:42)
==573572==    by 0x4008594: decompose_rpath (dl-load.c:629)
==573572==    by 0x400ABF5: cache_rpath (dl-load.c:696)
==573572==    by 0x400ABF5: cache_rpath (dl-load.c:677)
==573572==    by 0x400ABF5: _dl_map_object (dl-load.c:2165)
==573572==    by 0x4003494: openaux (dl-deps.c:64)
==573572==    by 0x4BBAB57: _dl_catch_exception (dl-error-skeleton.c:208)
==573572==    by 0x4003C7B: _dl_map_object_deps (dl-deps.c:248)
==573572==    by 0x400EA0E: dl_open_worker_begin (dl-open.c:592)
==573572==    by 0x4BBAB57: _dl_catch_exception (dl-error-skeleton.c:208)
==573572==    by 0x400DF99: dl_open_worker (dl-open.c:782)
==573572==    by 0x4BBAB57: _dl_catch_exception (dl-error-skeleton.c:208)
==573572==    by 0x400E34D: _dl_open (dl-open.c:883)
==573572== 
==573572== Invalid read of size 8
==573572==    at 0x409623: mlx_delete_texture (in /home/anshuval/Documents/GIT/cub3D/cub3D/cub3d)
==573572==    by 0x4061F7: free_textures (close_events.c:18)
==573572==    by 0x406134: free_game (close_events.c:39)
==573572==    by 0x4062DF: close_game (close_events.c:65)
==573572==    by 0x405F1B: key_reaction (key_events.c:53)
==573572==    by 0x488E728: ??? (in /usr/lib/x86_64-linux-gnu/libglfw.so.3.3)
==573572==    by 0x408B4F: mlx_loop (in /home/anshuval/Documents/GIT/cub3D/cub3D/cub3d)
==573572==    by 0x40647D: start_game (frame.c:44)
==573572==    by 0x4025CA: main (main.c:40)
==573572==  Address 0x203b8280 is 16 bytes inside a block of size 24 free'd
==573572==    at 0x484B27F: free (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
==573572==    by 0x4060D7: free_game (close_events.c:32)
==573572==    by 0x4062DF: close_game (close_events.c:65)
==573572==    by 0x405F1B: key_reaction (key_events.c:53)
==573572==    by 0x488E728: ??? (in /usr/lib/x86_64-linux-gnu/libglfw.so.3.3)
==573572==    by 0x408B4F: mlx_loop (in /home/anshuval/Documents/GIT/cub3D/cub3D/cub3d)
==573572==    by 0x40647D: start_game (frame.c:44)
==573572==    by 0x4025CA: main (main.c:40)
==573572==  Block was alloc'd at
==573572==    at 0x4848899: malloc (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
==573572==    by 0x409530: mlx_load_png (in /home/anshuval/Documents/GIT/cub3D/cub3D/cub3d)
==573572==    by 0x405B48: load_textures (textures.c:17)
==573572==    by 0x406338: start_game (frame.c:26)
==573572==    by 0x4025CA: main (main.c:40)
==573572== 
==573572== Invalid free() / delete / delete[] / realloc()
==573572==    at 0x484B27F: free (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
==573572==    by 0x409459: mlx_freen (in /home/anshuval/Documents/GIT/cub3D/cub3D/cub3d)
==573572==    by 0x4061F7: free_textures (close_events.c:18)
==573572==    by 0x406134: free_game (close_events.c:39)
==573572==    by 0x4062DF: close_game (close_events.c:65)
==573572==    by 0x405F1B: key_reaction (key_events.c:53)
==573572==    by 0x488E728: ??? (in /usr/lib/x86_64-linux-gnu/libglfw.so.3.3)
==573572==    by 0x408B4F: mlx_loop (in /home/anshuval/Documents/GIT/cub3D/cub3D/cub3d)
==573572==    by 0x40647D: start_game (frame.c:44)
==573572==    by 0x4025CA: main (main.c:40)
==573572==  Address 0x203b8270 is 0 bytes inside a block of size 24 free'd
==573572==    at 0x484B27F: free (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
==573572==    by 0x4060D7: free_game (close_events.c:32)
==573572==    by 0x4062DF: close_game (close_events.c:65)
==573572==    by 0x405F1B: key_reaction (key_events.c:53)
==573572==    by 0x488E728: ??? (in /usr/lib/x86_64-linux-gnu/libglfw.so.3.3)
==573572==    by 0x408B4F: mlx_loop (in /home/anshuval/Documents/GIT/cub3D/cub3D/cub3d)
==573572==    by 0x40647D: start_game (frame.c:44)
==573572==    by 0x4025CA: main (main.c:40)
==573572==  Block was alloc'd at
==573572==    at 0x4848899: malloc (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
==573572==    by 0x409530: mlx_load_png (in /home/anshuval/Documents/GIT/cub3D/cub3D/cub3d)
==573572==    by 0x405B48: load_textures (textures.c:17)
==573572==    by 0x406338: start_game (frame.c:26)
==573572==    by 0x4025CA: main (main.c:40)
==573572== 
==573572== Invalid read of size 8
==573572==    at 0x409623: mlx_delete_texture (in /home/anshuval/Documents/GIT/cub3D/cub3D/cub3d)
==573572==    by 0x406213: free_textures (close_events.c:20)
==573572==    by 0x406134: free_game (close_events.c:39)
==573572==    by 0x4062DF: close_game (close_events.c:65)
==573572==    by 0x405F1B: key_reaction (key_events.c:53)
==573572==    by 0x488E728: ??? (in /usr/lib/x86_64-linux-gnu/libglfw.so.3.3)
==573572==    by 0x408B4F: mlx_loop (in /home/anshuval/Documents/GIT/cub3D/cub3D/cub3d)
==573572==    by 0x40647D: start_game (frame.c:44)
==573572==    by 0x4025CA: main (main.c:40)
==573572==  Address 0x203ca1d0 is 16 bytes inside a block of size 24 free'd
==573572==    at 0x484B27F: free (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
==573572==    by 0x4060F3: free_game (close_events.c:34)
==573572==    by 0x4062DF: close_game (close_events.c:65)
==573572==    by 0x405F1B: key_reaction (key_events.c:53)
==573572==    by 0x488E728: ??? (in /usr/lib/x86_64-linux-gnu/libglfw.so.3.3)
==573572==    by 0x408B4F: mlx_loop (in /home/anshuval/Documents/GIT/cub3D/cub3D/cub3d)
==573572==    by 0x40647D: start_game (frame.c:44)
==573572==    by 0x4025CA: main (main.c:40)
==573572==  Block was alloc'd at
==573572==    at 0x4848899: malloc (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
==573572==    by 0x409530: mlx_load_png (in /home/anshuval/Documents/GIT/cub3D/cub3D/cub3d)
==573572==    by 0x405B7B: load_textures (textures.c:20)
==573572==    by 0x406338: start_game (frame.c:26)
==573572==    by 0x4025CA: main (main.c:40)
==573572== 
==573572== Invalid free() / delete / delete[] / realloc()
==573572==    at 0x484B27F: free (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
==573572==    by 0x409459: mlx_freen (in /home/anshuval/Documents/GIT/cub3D/cub3D/cub3d)
==573572==    by 0x406213: free_textures (close_events.c:20)
==573572==    by 0x406134: free_game (close_events.c:39)
==573572==    by 0x4062DF: close_game (close_events.c:65)
==573572==    by 0x405F1B: key_reaction (key_events.c:53)
==573572==    by 0x488E728: ??? (in /usr/lib/x86_64-linux-gnu/libglfw.so.3.3)
==573572==    by 0x408B4F: mlx_loop (in /home/anshuval/Documents/GIT/cub3D/cub3D/cub3d)
==573572==    by 0x40647D: start_game (frame.c:44)
==573572==    by 0x4025CA: main (main.c:40)
==573572==  Address 0x203ca1c0 is 0 bytes inside a block of size 24 free'd
==573572==    at 0x484B27F: free (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
==573572==    by 0x4060F3: free_game (close_events.c:34)
==573572==    by 0x4062DF: close_game (close_events.c:65)
==573572==    by 0x405F1B: key_reaction (key_events.c:53)
==573572==    by 0x488E728: ??? (in /usr/lib/x86_64-linux-gnu/libglfw.so.3.3)
==573572==    by 0x408B4F: mlx_loop (in /home/anshuval/Documents/GIT/cub3D/cub3D/cub3d)
==573572==    by 0x40647D: start_game (frame.c:44)
==573572==    by 0x4025CA: main (main.c:40)
==573572==  Block was alloc'd at
==573572==    at 0x4848899: malloc (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
==573572==    by 0x409530: mlx_load_png (in /home/anshuval/Documents/GIT/cub3D/cub3D/cub3d)
==573572==    by 0x405B7B: load_textures (textures.c:20)
==573572==    by 0x406338: start_game (frame.c:26)
==573572==    by 0x4025CA: main (main.c:40)
==573572== 
==573572== Invalid read of size 8
==573572==    at 0x409623: mlx_delete_texture (in /home/anshuval/Documents/GIT/cub3D/cub3D/cub3d)
==573572==    by 0x40622F: free_textures (close_events.c:22)
==573572==    by 0x406134: free_game (close_events.c:39)
==573572==    by 0x4062DF: close_game (close_events.c:65)
==573572==    by 0x405F1B: key_reaction (key_events.c:53)
==573572==    by 0x488E728: ??? (in /usr/lib/x86_64-linux-gnu/libglfw.so.3.3)
==573572==    by 0x408B4F: mlx_loop (in /home/anshuval/Documents/GIT/cub3D/cub3D/cub3d)
==573572==    by 0x40647D: start_game (frame.c:44)
==573572==    by 0x4025CA: main (main.c:40)
==573572==  Address 0x2040ec80 is 16 bytes inside a block of size 24 free'd
==573572==    at 0x484B27F: free (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
==573572==    by 0x40610F: free_game (close_events.c:36)
==573572==    by 0x4062DF: close_game (close_events.c:65)
==573572==    by 0x405F1B: key_reaction (key_events.c:53)
==573572==    by 0x488E728: ??? (in /usr/lib/x86_64-linux-gnu/libglfw.so.3.3)
==573572==    by 0x408B4F: mlx_loop (in /home/anshuval/Documents/GIT/cub3D/cub3D/cub3d)
==573572==    by 0x40647D: start_game (frame.c:44)
==573572==    by 0x4025CA: main (main.c:40)
==573572==  Block was alloc'd at
==573572==    at 0x4848899: malloc (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
==573572==    by 0x409530: mlx_load_png (in /home/anshuval/Documents/GIT/cub3D/cub3D/cub3d)
==573572==    by 0x405BE1: load_textures (textures.c:26)
==573572==    by 0x406338: start_game (frame.c:26)
==573572==    by 0x4025CA: main (main.c:40)
==573572== 
==573572== Invalid free() / delete / delete[] / realloc()
==573572==    at 0x484B27F: free (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
==573572==    by 0x409459: mlx_freen (in /home/anshuval/Documents/GIT/cub3D/cub3D/cub3d)
==573572==    by 0x40622F: free_textures (close_events.c:22)
==573572==    by 0x406134: free_game (close_events.c:39)
==573572==    by 0x4062DF: close_game (close_events.c:65)
==573572==    by 0x405F1B: key_reaction (key_events.c:53)
==573572==    by 0x488E728: ??? (in /usr/lib/x86_64-linux-gnu/libglfw.so.3.3)
==573572==    by 0x408B4F: mlx_loop (in /home/anshuval/Documents/GIT/cub3D/cub3D/cub3d)
==573572==    by 0x40647D: start_game (frame.c:44)
==573572==    by 0x4025CA: main (main.c:40)
==573572==  Address 0x2040ec70 is 0 bytes inside a block of size 24 free'd
==573572==    at 0x484B27F: free (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
==573572==    by 0x40610F: free_game (close_events.c:36)
==573572==    by 0x4062DF: close_game (close_events.c:65)
==573572==    by 0x405F1B: key_reaction (key_events.c:53)
==573572==    by 0x488E728: ??? (in /usr/lib/x86_64-linux-gnu/libglfw.so.3.3)
==573572==    by 0x408B4F: mlx_loop (in /home/anshuval/Documents/GIT/cub3D/cub3D/cub3d)
==573572==    by 0x40647D: start_game (frame.c:44)
==573572==    by 0x4025CA: main (main.c:40)
==573572==  Block was alloc'd at
==573572==    at 0x4848899: malloc (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
==573572==    by 0x409530: mlx_load_png (in /home/anshuval/Documents/GIT/cub3D/cub3D/cub3d)
==573572==    by 0x405BE1: load_textures (textures.c:26)
==573572==    by 0x406338: start_game (frame.c:26)
==573572==    by 0x4025CA: main (main.c:40)
==573572== 
==573572== Invalid read of size 8
==573572==    at 0x409623: mlx_delete_texture (in /home/anshuval/Documents/GIT/cub3D/cub3D/cub3d)
==573572==    by 0x40624B: free_textures (close_events.c:24)
==573572==    by 0x406134: free_game (close_events.c:39)
==573572==    by 0x4062DF: close_game (close_events.c:65)
==573572==    by 0x405F1B: key_reaction (key_events.c:53)
==573572==    by 0x488E728: ??? (in /usr/lib/x86_64-linux-gnu/libglfw.so.3.3)
==573572==    by 0x408B4F: mlx_loop (in /home/anshuval/Documents/GIT/cub3D/cub3D/cub3d)
==573572==    by 0x40647D: start_game (frame.c:44)
==573572==    by 0x4025CA: main (main.c:40)
==573572==  Address 0x203d1840 is 16 bytes inside a block of size 24 free'd
==573572==    at 0x484B27F: free (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
==573572==    by 0x40612B: free_game (close_events.c:38)
==573572==    by 0x4062DF: close_game (close_events.c:65)
==573572==    by 0x405F1B: key_reaction (key_events.c:53)
==573572==    by 0x488E728: ??? (in /usr/lib/x86_64-linux-gnu/libglfw.so.3.3)
==573572==    by 0x408B4F: mlx_loop (in /home/anshuval/Documents/GIT/cub3D/cub3D/cub3d)
==573572==    by 0x40647D: start_game (frame.c:44)
==573572==    by 0x4025CA: main (main.c:40)
==573572==  Block was alloc'd at
==573572==    at 0x4848899: malloc (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
==573572==    by 0x409530: mlx_load_png (in /home/anshuval/Documents/GIT/cub3D/cub3D/cub3d)
==573572==    by 0x405BAE: load_textures (textures.c:23)
==573572==    by 0x406338: start_game (frame.c:26)
==573572==    by 0x4025CA: main (main.c:40)
==573572== 
==573572== Invalid free() / delete / delete[] / realloc()
==573572==    at 0x484B27F: free (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
==573572==    by 0x409459: mlx_freen (in /home/anshuval/Documents/GIT/cub3D/cub3D/cub3d)
==573572==    by 0x40624B: free_textures (close_events.c:24)
==573572==    by 0x406134: free_game (close_events.c:39)
==573572==    by 0x4062DF: close_game (close_events.c:65)
==573572==    by 0x405F1B: key_reaction (key_events.c:53)
==573572==    by 0x488E728: ??? (in /usr/lib/x86_64-linux-gnu/libglfw.so.3.3)
==573572==    by 0x408B4F: mlx_loop (in /home/anshuval/Documents/GIT/cub3D/cub3D/cub3d)
==573572==    by 0x40647D: start_game (frame.c:44)
==573572==    by 0x4025CA: main (main.c:40)
==573572==  Address 0x203d1830 is 0 bytes inside a block of size 24 free'd
==573572==    at 0x484B27F: free (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
==573572==    by 0x40612B: free_game (close_events.c:38)
==573572==    by 0x4062DF: close_game (close_events.c:65)
==573572==    by 0x405F1B: key_reaction (key_events.c:53)
==573572==    by 0x488E728: ??? (in /usr/lib/x86_64-linux-gnu/libglfw.so.3.3)
==573572==    by 0x408B4F: mlx_loop (in /home/anshuval/Documents/GIT/cub3D/cub3D/cub3d)
==573572==    by 0x40647D: start_game (frame.c:44)
==573572==    by 0x4025CA: main (main.c:40)
==573572==  Block was alloc'd at
==573572==    at 0x4848899: malloc (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
==573572==    by 0x409530: mlx_load_png (in /home/anshuval/Documents/GIT/cub3D/cub3D/cub3d)
==573572==    by 0x405BAE: load_textures (textures.c:23)
==573572==    by 0x406338: start_game (frame.c:26)
==573572==    by 0x4025CA: main (main.c:40)
==573572== 
==573572== Invalid read of size 8
==573572==    at 0x407F1B: mlx_delete_image (in /home/anshuval/Documents/GIT/cub3D/cub3D/cub3d)
==573572==    by 0x40616B: free_game (close_events.c:43)
==573572==    by 0x4062DF: close_game (close_events.c:65)
==573572==    by 0x405F1B: key_reaction (key_events.c:53)
==573572==    by 0x488E728: ??? (in /usr/lib/x86_64-linux-gnu/libglfw.so.3.3)
==573572==    by 0x408B4F: mlx_loop (in /home/anshuval/Documents/GIT/cub3D/cub3D/cub3d)
==573572==    by 0x40647D: start_game (frame.c:44)
==573572==    by 0x4025CA: main (main.c:40)
==573572==  Address 0x4f9ad98 is 8 bytes inside a block of size 32 free'd
==573572==    at 0x484B27F: free (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
==573572==    by 0x409459: mlx_freen (in /home/anshuval/Documents/GIT/cub3D/cub3D/cub3d)
==573572==    by 0x4062D6: close_game (close_events.c:64)
==573572==    by 0x405F1B: key_reaction (key_events.c:53)
==573572==    by 0x488E728: ??? (in /usr/lib/x86_64-linux-gnu/libglfw.so.3.3)
==573572==    by 0x408B4F: mlx_loop (in /home/anshuval/Documents/GIT/cub3D/cub3D/cub3d)
==573572==    by 0x40647D: start_game (frame.c:44)
==573572==    by 0x4025CA: main (main.c:40)
==573572==  Block was alloc'd at
==573572==    at 0x484DA83: calloc (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
==573572==    by 0x408206: mlx_init (in /home/anshuval/Documents/GIT/cub3D/cub3D/cub3d)
==573572==    by 0x402557: main (main.c:32)
==573572== 
==573572== Invalid read of size 8
==573572==    at 0x409088: mlx_lstremove (in /home/anshuval/Documents/GIT/cub3D/cub3D/cub3d)
==573572==    by 0x407F31: mlx_delete_image (in /home/anshuval/Documents/GIT/cub3D/cub3D/cub3d)
==573572==    by 0x40616B: free_game (close_events.c:43)
==573572==    by 0x4062DF: close_game (close_events.c:65)
==573572==    by 0x405F1B: key_reaction (key_events.c:53)
==573572==    by 0x488E728: ??? (in /usr/lib/x86_64-linux-gnu/libglfw.so.3.3)
==573572==    by 0x408B4F: mlx_loop (in /home/anshuval/Documents/GIT/cub3D/cub3D/cub3d)
==573572==    by 0x40647D: start_game (frame.c:44)
==573572==    by 0x4025CA: main (main.c:40)
==573572==  Address 0x4f9ae18 is 40 bytes inside a block of size 288,216 free'd
==573572==    at 0x484B27F: free (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
==573572==    by 0x409459: mlx_freen (in /home/anshuval/Documents/GIT/cub3D/cub3D/cub3d)
==573572==    by 0x4062D6: close_game (close_events.c:64)
==573572==    by 0x405F1B: key_reaction (key_events.c:53)
==573572==    by 0x488E728: ??? (in /usr/lib/x86_64-linux-gnu/libglfw.so.3.3)
==573572==    by 0x408B4F: mlx_loop (in /home/anshuval/Documents/GIT/cub3D/cub3D/cub3d)
==573572==    by 0x40647D: start_game (frame.c:44)
==573572==    by 0x4025CA: main (main.c:40)
==573572==  Block was alloc'd at
==573572==    at 0x484DA83: calloc (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
==573572==    by 0x408221: mlx_init (in /home/anshuval/Documents/GIT/cub3D/cub3D/cub3d)
==573572==    by 0x402557: main (main.c:32)
==573572== 
==573572== Invalid read of size 8
==573572==    at 0x409088: mlx_lstremove (in /home/anshuval/Documents/GIT/cub3D/cub3D/cub3d)
==573572==    by 0x407F7A: mlx_delete_image (in /home/anshuval/Documents/GIT/cub3D/cub3D/cub3d)
==573572==    by 0x40616B: free_game (close_events.c:43)
==573572==    by 0x4062DF: close_game (close_events.c:65)
==573572==    by 0x405F1B: key_reaction (key_events.c:53)
==573572==    by 0x488E728: ??? (in /usr/lib/x86_64-linux-gnu/libglfw.so.3.3)
==573572==    by 0x408B4F: mlx_loop (in /home/anshuval/Documents/GIT/cub3D/cub3D/cub3d)
==573572==    by 0x40647D: start_game (frame.c:44)
==573572==    by 0x4025CA: main (main.c:40)
==573572==  Address 0x4f9ae10 is 32 bytes inside a block of size 288,216 free'd
==573572==    at 0x484B27F: free (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
==573572==    by 0x409459: mlx_freen (in /home/anshuval/Documents/GIT/cub3D/cub3D/cub3d)
==573572==    by 0x4062D6: close_game (close_events.c:64)
==573572==    by 0x405F1B: key_reaction (key_events.c:53)
==573572==    by 0x488E728: ??? (in /usr/lib/x86_64-linux-gnu/libglfw.so.3.3)
==573572==    by 0x408B4F: mlx_loop (in /home/anshuval/Documents/GIT/cub3D/cub3D/cub3d)
==573572==    by 0x40647D: start_game (frame.c:44)
==573572==    by 0x4025CA: main (main.c:40)
==573572==  Block was alloc'd at
==573572==    at 0x484DA83: calloc (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
==573572==    by 0x408221: mlx_init (in /home/anshuval/Documents/GIT/cub3D/cub3D/cub3d)
==573572==    by 0x402557: main (main.c:32)
==573572== 
==573572== Invalid read of size 8
==573572==    at 0x407F1B: mlx_delete_image (in /home/anshuval/Documents/GIT/cub3D/cub3D/cub3d)
==573572==    by 0x406194: free_game (close_events.c:45)
==573572==    by 0x4062DF: close_game (close_events.c:65)
==573572==    by 0x405F1B: key_reaction (key_events.c:53)
==573572==    by 0x488E728: ??? (in /usr/lib/x86_64-linux-gnu/libglfw.so.3.3)
==573572==    by 0x408B4F: mlx_loop (in /home/anshuval/Documents/GIT/cub3D/cub3D/cub3d)
==573572==    by 0x40647D: start_game (frame.c:44)
==573572==    by 0x4025CA: main (main.c:40)
==573572==  Address 0x4f9ad98 is 8 bytes inside a block of size 32 free'd
==573572==    at 0x484B27F: free (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
==573572==    by 0x409459: mlx_freen (in /home/anshuval/Documents/GIT/cub3D/cub3D/cub3d)
==573572==    by 0x4062D6: close_game (close_events.c:64)
==573572==    by 0x405F1B: key_reaction (key_events.c:53)
==573572==    by 0x488E728: ??? (in /usr/lib/x86_64-linux-gnu/libglfw.so.3.3)
==573572==    by 0x408B4F: mlx_loop (in /home/anshuval/Documents/GIT/cub3D/cub3D/cub3d)
==573572==    by 0x40647D: start_game (frame.c:44)
==573572==    by 0x4025CA: main (main.c:40)
==573572==  Block was alloc'd at
==573572==    at 0x484DA83: calloc (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
==573572==    by 0x408206: mlx_init (in /home/anshuval/Documents/GIT/cub3D/cub3D/cub3d)
==573572==    by 0x402557: main (main.c:32)
==573572== 
==573572== Invalid read of size 8
==573572==    at 0x409088: mlx_lstremove (in /home/anshuval/Documents/GIT/cub3D/cub3D/cub3d)
==573572==    by 0x407F31: mlx_delete_image (in /home/anshuval/Documents/GIT/cub3D/cub3D/cub3d)
==573572==    by 0x406194: free_game (close_events.c:45)
==573572==    by 0x4062DF: close_game (close_events.c:65)
==573572==    by 0x405F1B: key_reaction (key_events.c:53)
==573572==    by 0x488E728: ??? (in /usr/lib/x86_64-linux-gnu/libglfw.so.3.3)
==573572==    by 0x408B4F: mlx_loop (in /home/anshuval/Documents/GIT/cub3D/cub3D/cub3d)
==573572==    by 0x40647D: start_game (frame.c:44)
==573572==    by 0x4025CA: main (main.c:40)
==573572==  Address 0x4f9ae18 is 40 bytes inside a block of size 288,216 free'd
==573572==    at 0x484B27F: free (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
==573572==    by 0x409459: mlx_freen (in /home/anshuval/Documents/GIT/cub3D/cub3D/cub3d)
==573572==    by 0x4062D6: close_game (close_events.c:64)
==573572==    by 0x405F1B: key_reaction (key_events.c:53)
==573572==    by 0x488E728: ??? (in /usr/lib/x86_64-linux-gnu/libglfw.so.3.3)
==573572==    by 0x408B4F: mlx_loop (in /home/anshuval/Documents/GIT/cub3D/cub3D/cub3d)
==573572==    by 0x40647D: start_game (frame.c:44)
==573572==    by 0x4025CA: main (main.c:40)
==573572==  Block was alloc'd at
==573572==    at 0x484DA83: calloc (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
==573572==    by 0x408221: mlx_init (in /home/anshuval/Documents/GIT/cub3D/cub3D/cub3d)
==573572==    by 0x402557: main (main.c:32)
==573572== 
==573572== Invalid read of size 8
==573572==    at 0x409088: mlx_lstremove (in /home/anshuval/Documents/GIT/cub3D/cub3D/cub3d)
==573572==    by 0x407F7A: mlx_delete_image (in /home/anshuval/Documents/GIT/cub3D/cub3D/cub3d)
==573572==    by 0x406194: free_game (close_events.c:45)
==573572==    by 0x4062DF: close_game (close_events.c:65)
==573572==    by 0x405F1B: key_reaction (key_events.c:53)
==573572==    by 0x488E728: ??? (in /usr/lib/x86_64-linux-gnu/libglfw.so.3.3)
==573572==    by 0x408B4F: mlx_loop (in /home/anshuval/Documents/GIT/cub3D/cub3D/cub3d)
==573572==    by 0x40647D: start_game (frame.c:44)
==573572==    by 0x4025CA: main (main.c:40)
==573572==  Address 0x4f9ae10 is 32 bytes inside a block of size 288,216 free'd
==573572==    at 0x484B27F: free (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
==573572==    by 0x409459: mlx_freen (in /home/anshuval/Documents/GIT/cub3D/cub3D/cub3d)
==573572==    by 0x4062D6: close_game (close_events.c:64)
==573572==    by 0x405F1B: key_reaction (key_events.c:53)
==573572==    by 0x488E728: ??? (in /usr/lib/x86_64-linux-gnu/libglfw.so.3.3)
==573572==    by 0x408B4F: mlx_loop (in /home/anshuval/Documents/GIT/cub3D/cub3D/cub3d)
==573572==    by 0x40647D: start_game (frame.c:44)
==573572==    by 0x4025CA: main (main.c:40)
==573572==  Block was alloc'd at
==573572==    at 0x484DA83: calloc (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
==573572==    by 0x408221: mlx_init (in /home/anshuval/Documents/GIT/cub3D/cub3D/cub3d)
==573572==    by 0x402557: main (main.c:32)
==573572== 
==573572== 
==573572== HEAP SUMMARY:
==573572==     in use at exit: 318,250 bytes in 3,104 blocks
==573572==   total heap usage: 71,221 allocs, 68,121 frees, 69,345,501 bytes allocated
==573572== 
==573572== 0 bytes in 1 blocks are definitely lost in loss record 1 of 2,242
==573572==    at 0x4848899: malloc (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
==573572==    by 0x4005A22: malloc (rtld-malloc.h:56)
==573572==    by 0x4005A22: _dl_find_object_update (dl-find_object.c:791)
==573572==    by 0x400ECCF: dl_open_worker_begin (dl-open.c:735)
==573572==    by 0x4BBAB57: _dl_catch_exception (dl-error-skeleton.c:208)
==573572==    by 0x400DF99: dl_open_worker (dl-open.c:782)
==573572==    by 0x4BBAB57: _dl_catch_exception (dl-error-skeleton.c:208)
==573572==    by 0x400E34D: _dl_open (dl-open.c:883)
==573572==    by 0x4AD65FB: dlopen_doit (dlopen.c:56)
==573572==    by 0x4BBAB57: _dl_catch_exception (dl-error-skeleton.c:208)
==573572==    by 0x4BBAC22: _dl_catch_error (dl-error-skeleton.c:227)
==573572==    by 0x4AD60ED: _dlerror_run (dlerror.c:138)
==573572==    by 0x4AD6687: dlopen_implementation (dlopen.c:71)
==573572==    by 0x4AD6687: dlopen@@GLIBC_2.34 (dlopen.c:81)
==573572== 
==573572== 20 bytes in 1 blocks are definitely lost in loss record 20 of 2,242
==573572==    at 0x4848899: malloc (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
==573572==    by 0x406BD1: ft_strdup (in /home/anshuval/Documents/GIT/cub3D/cub3D/cub3d)
==573572==    by 0x4037DC: path_allocation (verification_path.c:22)
==573572==    by 0x4035B3: verify_path (verification_path.c:79)
==573572==    by 0x402A6E: populate_game (parser.c:51)
==573572==    by 0x4028BC: convert_map_to_list (parser.c:74)
==573572==    by 0x40273A: read_map (parser.c:90)
==573572==    by 0x402701: parser (parser.c:113)
==573572==    by 0x402527: main (main.c:30)
==573572== 
==573572== 20 bytes in 1 blocks are definitely lost in loss record 21 of 2,242
==573572==    at 0x4848899: malloc (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
==573572==    by 0x406BD1: ft_strdup (in /home/anshuval/Documents/GIT/cub3D/cub3D/cub3d)
==573572==    by 0x40381B: path_allocation (verification_path.c:24)
==573572==    by 0x4035B3: verify_path (verification_path.c:79)
==573572==    by 0x402A6E: populate_game (parser.c:51)
==573572==    by 0x4028BC: convert_map_to_list (parser.c:74)
==573572==    by 0x40273A: read_map (parser.c:90)
==573572==    by 0x402701: parser (parser.c:113)
==573572==    by 0x402527: main (main.c:30)
==573572== 
==573572== 21 bytes in 1 blocks are definitely lost in loss record 34 of 2,242
==573572==    at 0x4848899: malloc (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
==573572==    by 0x406BD1: ft_strdup (in /home/anshuval/Documents/GIT/cub3D/cub3D/cub3d)
==573572==    by 0x40375E: path_allocation (verification_path.c:18)
==573572==    by 0x4035B3: verify_path (verification_path.c:79)
==573572==    by 0x402A6E: populate_game (parser.c:51)
==573572==    by 0x4028BC: convert_map_to_list (parser.c:74)
==573572==    by 0x40273A: read_map (parser.c:90)
==573572==    by 0x402701: parser (parser.c:113)
==573572==    by 0x402527: main (main.c:30)
==573572== 
==573572== 21 bytes in 1 blocks are definitely lost in loss record 35 of 2,242
==573572==    at 0x4848899: malloc (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
==573572==    by 0x406BD1: ft_strdup (in /home/anshuval/Documents/GIT/cub3D/cub3D/cub3d)
==573572==    by 0x40379D: path_allocation (verification_path.c:20)
==573572==    by 0x4035B3: verify_path (verification_path.c:79)
==573572==    by 0x402A6E: populate_game (parser.c:51)
==573572==    by 0x4028BC: convert_map_to_list (parser.c:74)
==573572==    by 0x40273A: read_map (parser.c:90)
==573572==    by 0x402701: parser (parser.c:113)
==573572==    by 0x402527: main (main.c:30)
==573572== 
==573572== 112 (56 direct, 56 indirect) bytes in 1 blocks are definitely lost in loss record 2,203 of 2,242
==573572==    at 0x484DA83: calloc (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
==573572==    by 0x663486E: ???
==573572==    by 0x6106293: ???
==573572==    by 0x60EEDB8: ???
==573572==    by 0x60EEF6A: ???
==573572==    by 0x60A1109: ???
==573572==    by 0x60A3C24: ???
==573572==    by 0x609E9FC: ???
==573572==    by 0x604DAB7: ???
==573572==    by 0x608AEAD: ???
==573572==    by 0x608743C: ???
==573572==    by 0x601E61A: ???
==573572== 
==573572== LEAK SUMMARY:
==573572==    definitely lost: 138 bytes in 6 blocks
==573572==    indirectly lost: 56 bytes in 1 blocks
==573572==      possibly lost: 0 bytes in 0 blocks
==573572==    still reachable: 318,056 bytes in 3,097 blocks
==573572==         suppressed: 0 bytes in 0 blocks
==573572== Reachable blocks (those to which a pointer was found) are not shown.
==573572== To see them, rerun with: --leak-check=full --show-leak-kinds=all
==573572== 
==573572== For lists of detected and suppressed errors, rerun with: -s
==573572== ERROR SUMMARY: 22 errors from 22 contexts (suppressed: 0 from 0)

==641346== Memcheck, a memory error detector
==641346== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==641346== Using Valgrind-3.18.1 and LibVEX; rerun with -h for copyright info
==641346== Command: ./cub3d maps/valid/irregular_corridor_rooms.cub
==641346== 
==641346== Invalid read of size 8
==641346==    at 0x40286A8: strncmp (strcmp.S:172)
==641346==    by 0x400668D: is_dst (dl-load.c:216)
==641346==    by 0x400810E: _dl_dst_count (dl-load.c:253)
==641346==    by 0x400810E: expand_dynamic_string_token (dl-load.c:395)
==641346==    by 0x40082B7: fillin_rpath.isra.0 (dl-load.c:483)
==641346==    by 0x4008602: decompose_rpath (dl-load.c:654)
==641346==    by 0x400ABF5: cache_rpath (dl-load.c:696)
==641346==    by 0x400ABF5: cache_rpath (dl-load.c:677)
==641346==    by 0x400ABF5: _dl_map_object (dl-load.c:2165)
==641346==    by 0x4003494: openaux (dl-deps.c:64)
==641346==    by 0x4BBAB57: _dl_catch_exception (dl-error-skeleton.c:208)
==641346==    by 0x4003C7B: _dl_map_object_deps (dl-deps.c:248)
==641346==    by 0x400EA0E: dl_open_worker_begin (dl-open.c:592)
==641346==    by 0x4BBAB57: _dl_catch_exception (dl-error-skeleton.c:208)
==641346==    by 0x400DF99: dl_open_worker (dl-open.c:782)
==641346==  Address 0x50a0229 is 9 bytes inside a block of size 15 alloc'd
==641346==    at 0x4848899: malloc (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
==641346==    by 0x40271DF: malloc (rtld-malloc.h:56)
==641346==    by 0x40271DF: strdup (strdup.c:42)
==641346==    by 0x4008594: decompose_rpath (dl-load.c:629)
==641346==    by 0x400ABF5: cache_rpath (dl-load.c:696)
==641346==    by 0x400ABF5: cache_rpath (dl-load.c:677)
==641346==    by 0x400ABF5: _dl_map_object (dl-load.c:2165)
==641346==    by 0x4003494: openaux (dl-deps.c:64)
==641346==    by 0x4BBAB57: _dl_catch_exception (dl-error-skeleton.c:208)
==641346==    by 0x4003C7B: _dl_map_object_deps (dl-deps.c:248)
==641346==    by 0x400EA0E: dl_open_worker_begin (dl-open.c:592)
==641346==    by 0x4BBAB57: _dl_catch_exception (dl-error-skeleton.c:208)
==641346==    by 0x400DF99: dl_open_worker (dl-open.c:782)
==641346==    by 0x4BBAB57: _dl_catch_exception (dl-error-skeleton.c:208)
==641346==    by 0x400E34D: _dl_open (dl-open.c:883)
==641346== 
==641346== Invalid read of size 8
==641346==    at 0x40286A8: strncmp (strcmp.S:172)
==641346==    by 0x400668D: is_dst (dl-load.c:216)
==641346==    by 0x4007F79: _dl_dst_substitute (dl-load.c:295)
==641346==    by 0x40082B7: fillin_rpath.isra.0 (dl-load.c:483)
==641346==    by 0x4008602: decompose_rpath (dl-load.c:654)
==641346==    by 0x400ABF5: cache_rpath (dl-load.c:696)
==641346==    by 0x400ABF5: cache_rpath (dl-load.c:677)
==641346==    by 0x400ABF5: _dl_map_object (dl-load.c:2165)
==641346==    by 0x4003494: openaux (dl-deps.c:64)
==641346==    by 0x4BBAB57: _dl_catch_exception (dl-error-skeleton.c:208)
==641346==    by 0x4003C7B: _dl_map_object_deps (dl-deps.c:248)
==641346==    by 0x400EA0E: dl_open_worker_begin (dl-open.c:592)
==641346==    by 0x4BBAB57: _dl_catch_exception (dl-error-skeleton.c:208)
==641346==    by 0x400DF99: dl_open_worker (dl-open.c:782)
==641346==  Address 0x50a0229 is 9 bytes inside a block of size 15 alloc'd
==641346==    at 0x4848899: malloc (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
==641346==    by 0x40271DF: malloc (rtld-malloc.h:56)
==641346==    by 0x40271DF: strdup (strdup.c:42)
==641346==    by 0x4008594: decompose_rpath (dl-load.c:629)
==641346==    by 0x400ABF5: cache_rpath (dl-load.c:696)
==641346==    by 0x400ABF5: cache_rpath (dl-load.c:677)
==641346==    by 0x400ABF5: _dl_map_object (dl-load.c:2165)
==641346==    by 0x4003494: openaux (dl-deps.c:64)
==641346==    by 0x4BBAB57: _dl_catch_exception (dl-error-skeleton.c:208)
==641346==    by 0x4003C7B: _dl_map_object_deps (dl-deps.c:248)
==641346==    by 0x400EA0E: dl_open_worker_begin (dl-open.c:592)
==641346==    by 0x4BBAB57: _dl_catch_exception (dl-error-skeleton.c:208)
==641346==    by 0x400DF99: dl_open_worker (dl-open.c:782)
==641346==    by 0x4BBAB57: _dl_catch_exception (dl-error-skeleton.c:208)
==641346==    by 0x400E34D: _dl_open (dl-open.c:883)
==641346== 
==641346== 
==641346== HEAP SUMMARY:
==641346==     in use at exit: 318,168 bytes in 3,100 blocks
==641346==   total heap usage: 71,141 allocs, 68,041 frees, 68,551,758 bytes allocated
==641346== 
==641346== 0 bytes in 1 blocks are definitely lost in loss record 1 of 2,238
==641346==    at 0x4848899: malloc (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
==641346==    by 0x4005A22: malloc (rtld-malloc.h:56)
==641346==    by 0x4005A22: _dl_find_object_update (dl-find_object.c:791)
==641346==    by 0x400ECCF: dl_open_worker_begin (dl-open.c:735)
==641346==    by 0x4BBAB57: _dl_catch_exception (dl-error-skeleton.c:208)
==641346==    by 0x400DF99: dl_open_worker (dl-open.c:782)
==641346==    by 0x4BBAB57: _dl_catch_exception (dl-error-skeleton.c:208)
==641346==    by 0x400E34D: _dl_open (dl-open.c:883)
==641346==    by 0x4AD65FB: dlopen_doit (dlopen.c:56)
==641346==    by 0x4BBAB57: _dl_catch_exception (dl-error-skeleton.c:208)
==641346==    by 0x4BBAC22: _dl_catch_error (dl-error-skeleton.c:227)
==641346==    by 0x4AD60ED: _dlerror_run (dlerror.c:138)
==641346==    by 0x4AD6687: dlopen_implementation (dlopen.c:71)
==641346==    by 0x4AD6687: dlopen@@GLIBC_2.34 (dlopen.c:81)
==641346== 
==641346== 112 (56 direct, 56 indirect) bytes in 1 blocks are definitely lost in loss record 2,199 of 2,238
==641346==    at 0x484DA83: calloc (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
==641346==    by 0x663486E: ???
==641346==    by 0x6106293: ???
==641346==    by 0x60EEDB8: ???
==641346==    by 0x60EEF6A: ???
==641346==    by 0x60A1109: ???
==641346==    by 0x60A3C24: ???
==641346==    by 0x609E9FC: ???
==641346==    by 0x604DAB7: ???
==641346==    by 0x608AEAD: ???
==641346==    by 0x608743C: ???
==641346==    by 0x601E61A: ???
==641346== 
==641346== LEAK SUMMARY:
==641346==    definitely lost: 56 bytes in 2 blocks
==641346==    indirectly lost: 56 bytes in 1 blocks
==641346==      possibly lost: 0 bytes in 0 blocks
==641346==    still reachable: 318,056 bytes in 3,097 blocks
==641346==         suppressed: 0 bytes in 0 blocks
==641346== Reachable blocks (those to which a pointer was found) are not shown.
==641346== To see them, rerun with: --leak-check=full --show-leak-kinds=all
==641346== 
==641346== For lists of detected and suppressed errors, rerun with: -s
==641346== ERROR SUMMARY: 4 errors from 4 contexts (suppressed: 0 from 0)