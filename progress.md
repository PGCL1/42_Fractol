							**FRACTOL**


DONE:
	- created keyhooks for exiting the window
	- created function where mandelbrot Mandelbrot or 1 can be passed as parameters or even MandeLbrot and do so for all the next fractals
	- created keyhooks for move the image with keys A S D W and arrows and added incrementing proportionally during zooming
	- created the zoom functions
	- created the colors shading for the fractal depending on n iterations
	- create the Julia set
	- create julia set with increments in c (need to rethink structures)
	- create atof for char to double to be able to parse the numbers for the julia set
	- create the zoom to follow the mouse


STUFF FOR TODAY:
	- polish multibrot as the current function is not the desired shape
	- look for errors in the arguments check in main

for 1 arg:
	- need to return error
	./fractol  																			GOOD
	./fractol  ""
	./fractol  " "

for 2 arg:
	- need to print the fractal unless the fractal type is 0							GOOD

for 3 arg:
	- need to print the fractal unless the fractal type is 0

for 4 arg:
	- need to return error

for 5 arg:
	- need to print the julia set

./fractol name iterations param param
	0		1		2

IMPROVEMENTS:
	- need to rewrite Makefile in libft/


ERRORS:


DOUBTS:
	- var.fractal.height_y is the same as var.mlx.height_y		CHANGE IT /* Upd: we keepin it (take away var.fractal.width/height) //streches the image for some reason
	- var.fractal.width_x is the same as var.mlx.width_x		CHANGE IT /* Upd: we keepin it (take away var.fractal.width/height) ///streches the image for some reason