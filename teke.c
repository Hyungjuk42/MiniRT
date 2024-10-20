███╗   ███╗██╗███╗   ██╗██╗██████╗ ████████╗ bonus!
████╗ ████║██║████╗  ██║██║██╔══██╗╚══██╔══╝
██╔████╔██║██║██╔██╗ ██║██║██████╔╝   ██║   
██║╚██╔╝██║██║██║╚██╗██║██║██╔══██╗   ██║   
██║ ╚═╝ ██║██║██║ ╚████║██║██║  ██║   ██║   
╚═╝     ╚═╝╚═╝╚═╝  ╚═══╝╚═╝╚═╝  ╚═╝   ╚═╝   by hyungjuk and yeonwkan
➜  sobigRT git:(master) ✗ ./miniRT ./rt/B_two_light_parabolic_shadow.rt
=================================================================
==75541==ERROR: AddressSanitizer: unknown-crash on address 0x00010fd567f8 at pc 0x00010194c688 bp 0x70001e12f150 sp 0x70001e12f148
READ of size 4 at 0x00010fd567f8 thread T240029
    #0 0x10194c687 in get_normal mlx_texture_utils_bonus.c:27
    #1 0x10195c9e6 in normal_map texture_bonus.c:38
    #2 0x101952a8f in chk_hittable_sp hittable1_bonus.c:41
    #3 0x101958655 in itinerate_and_chk_hit check_hittable_bonus.c:23
    #4 0x101958525 in check_hittable_to_all_obj check_hittable_bonus.c:45
    #5 0x10195a544 in sum_all_light shoot_ray_bonus.c:37
    #6 0x101959d34 in ray_tracing_recur shoot_ray_bonus.c:56
    #7 0x10195952c in shoot_each_ray_to_pixel shoot_ray_bonus.c:69
    #8 0x101959031 in shoot_ray_by_thread shoot_ray_bonus.c:105
    #9 0x7fff6f2d0108 in _pthread_start+0x93 (libsystem_pthread.dylib:x86_64+0x6108)
    #10 0x7fff6f2cbb8a in thread_start+0xe (libsystem_pthread.dylib:x86_64+0x1b8a)

Address 0x00010fd567f8 is a wild pointer.
SUMMARY: AddressSanitizer: unknown-crash mlx_texture_utils_bonus.c:27 in get_normal
Shadow bytes around the buggy address:
  0x100021faaca0: fe fe fe fe fe fe fe fe fe fe fe fe fe fe fe fe
  0x100021faacb0: fe fe fe fe fe fe fe fe fe fe fe fe fe fe fe fe
  0x100021faacc0: fe fe fe fe fe fe fe fe fe fe fe fe fe fe fe fe
  0x100021faacd0: fe fe fe fe fe fe fe fe fe fe fe fe fe fe fe fe
  0x100021faace0: fe fe fe fe fe fe fe fe fe fe fe fe fe fe fe fe
=>0x100021faacf0: fe fe fe fe fe fe fe fe fe fe fe fe fe fe fe[fe]
  0x100021faad00: fe fe fe fe fe fe fe fe fe fe fe fe fe fe fe fe
  0x100021faad10: fe fe fe fe fe fe fe fe fe fe fe fe fe fe fe fe
  0x100021faad20: fe fe fe fe fe fe fe fe fe fe fe fe fe fe fe fe
  0x100021faad30: fe fe fe fe fe fe fe fe fe fe fe fe fe fe fe fe
  0x100021faad40: fe fe fe fe fe fe fe fe fe fe fe fe fe fe fe fe
Shadow byte legend (one shadow byte represents 8 application bytes):
  Addressable:           00
  Partially addressable: 01 02 03 04 05 06 07 
  Heap left redzone:       fa
  Freed heap region:       fd
  Stack left redzone:      f1
  Stack mid redzone:       f2
  Stack right redzone:     f3
  Stack after return:      f5
  Stack use after scope:   f8
  Global redzone:          f9
  Global init order:       f6
  Poisoned by user:        f7
  Container overflow:      fc
  Array cookie:            ac
  Intra object redzone:    bb
  ASan internal:           fe
  Left alloca redzone:     ca
  Right alloca redzone:    cb
  Shadow gap:              cc
Thread T240029 created by T0 here:
    #0 0x1019dd31a in wrap_pthread_create+0x5a (libclang_rt.asan_osx_dynamic.dylib:x86_64h+0x4331a)
    #1 0x101959a20 in shoot_ray_to_pixel shoot_ray_bonus.c:122
    #2 0x101948f6e in make_new_image mlx_utils1_bonus.c:23
    #3 0x101949203 in keyboard_handling mlx_utils1_bonus.c:81
    #4 0x7fff330ccd5c in -[NSWindow(NSEventRouting) _reallySendEvent:isDelayedEvent:]+0x196f (AppKit:x86_64+0x1e7d5c)
    #5 0x7fff330cb1c8 in -[NSWindow(NSEventRouting) sendEvent:]+0x15c (AppKit:x86_64+0x1e61c8)
    #6 0x7fff330c9efd in -[NSApplication(NSEvent) sendEvent:]+0xb09 (AppKit:x86_64+0x1e4efd)
    #7 0x7fff32f165be in -[NSApplication run]+0x2c2 (AppKit:x86_64+0x315be)
    #8 0x101962f28 in mlx_loop+0x88 (miniRT:x86_64+0x100026f28)
    #9 0x10194b12c in print_mlx_img mlx_utils2_bonus.c:61
    #10 0x10195ed1e in main main_bonus.c:67
    #11 0x7fff6f0cbcc8 in start+0x0 (libdyld.dylib:x86_64+0x1acc8)

==75541==ABORTING
[1]    75541 abort      ./miniRT ./rt/B_two_light_parabolic_shadow.rt

# 두 개의 구체를 {0, 0, 0}에 위치시키세요
A   0.2         255,255,255
C   5,0,15      0,0,-1      100
L   0,10,10      0.4     255,255,255
sp  0,0,0       3           0,0,255
# sp  0,0,0       5           0,255,0
sp  10,0,0       5           0,255,0

# 원기둥 하나를 y 축에 걸치도록 위치시키고 카메라는 원기둥을 향하도록 합니다
# A	0.4						255,255,255
# C	10,0,10		-1,0,-1		100
# L   0,0,0			0.6 	255,255,255
# cy	0,0,0			0,1,0	2   4       150,30,20
# cy	0,0,0			0,0,1	2   4       230,100,255

A	0.1						255,255,255
C	0,0,15		0,0,-1		80
L   0,0,0			0.6 	255,255,255
L	0,20,-5					0.4				255,255,255

pl	0,-3,0			0,1,0	255,255,255
sp	3,0,-5					3			255,130,0
cy	10,0,-5			-0.2,1,-1	2   4       150,30,20

# 장면을 무작위로 구성하고 카메라를 X 축에 걸치도록 하여 좌표 {0, 0, 0}을 향하도록 하세요
A	0.2						255,255,255
C	5,0,0		-1,0,0	100
L   10,0,10			0.6 	255,255,255
sp	0,0,0		1			0,200,0

# 장면을 무작위로 구성하고 카메라를 Y 축에 걸치도록 하여 좌표 {0, 0, 0}을 향하도록 하세요
# A	0.2						255,255,255
# C	0,5,0		0,-1,0		100
# L   10,0,10			0.6 	255,255,255
# sp	0,0,0		1			0,200,0

# 장면을 무작위로 구성하고 카메라를 Z 축에 걸치도록 하여 좌표 {0, 0, 0}을 향하도록 하세요
# A	0.2						255,255,255
# C	0,0,5	 0,0,-1		100
# L   10,0,10			0.6 	255,255,255
# sp	0,0,0		1			0,200,0

# 장면을 무작위로 구상하고 카메라를 각 축이나 각 축에 대한 대각선 방향에 위치하지 않도록 무작위 위치에 둔 뒤 좌표 {0, 0, 0}을 향하도록 하세요. 렌더링 된 이미지를 확인하고 장면은 잘 보여야 하며 깨짐이 없어야 합니다.
# A	0.2						255,255,255
# C	5,0,5		-1,0,-1		100
# L   10,0,10			0.6 	255,255,255
# sp	0,0,0		3			0,200,0

# 설정 파일에서 세 개의 카메라를 위치시키고, 어떤 키로 카메라를 전환할 수 있는지를 피평가자에게 물어보세요. 프로그램 종료 없이 카메라간 전환이 잘 되어야 합니다. 장면은 잘 보여야 하며 새로운 시점에서도 깨짐이 없어야 합니다.
# A	0.1						255,255,255
# C	0,0,15		0,0,-1		80
# C	0,0,5		0,0,-1		80
# C   20,0,10  	-1,0,-1	    80
# L   0,0,0			0.6 	255,255,255
# L	0,20,-5					0.4				255,255,255
# pl	0,-3,0			0,1,0	255,255,255
# sp	3,0,-5					3			255,130,0
# cy	10,0,-5			-0.2,1,-1	2   4       150,30,20

# 좌표 {0, 0, 0}에 구체를 위치시키세요.
A   0.2         255,255,255
C   0,0,15      0,0,-1      100
L   0,10,10      0.4     255,255,255
sp  0,0,0       3           0,255,255

# z 값 없이 평면을 위치시키세요
# A   0.2                                  255,255,255
# C   0,0,15      0,0,-1      80
# L   -2,10,10      0.4     255,255,255
# pl  0,-3,0      0,1,0           0,255,0

# 좌표 {0, 0, 0} 의 중앙에 정사각형을 위치키세요
# A   0.2                                  255,255,255
# C   0,0,15      0,0,-1      80
# L   0,5,10      0.5     255,255,255

# # 다음의 세 꼭지점을 가진 삼각형을 위치시키세요.
# A 0.4 255,255,255
# C   30,0,0  	-1,0,0	    100
# L   0,0,0			0.6 	255,255,255

# y 축에 걸쳐져 있도록 원기둥을 위치시키세요
# A	0.4						255,255,255
# C	10,0,15		0,0,-1		80
# L   0,0,0			0.6 	255,255,255
# cy	10,0,-5			0,1,0	2   4       150,30,20