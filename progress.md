							**FRACTOL**

IMPROVEMENTS:
	- need to rewrite Makefile in libft/


ERRORS:


This project’s goal is to create a small fractal exploration program. Start by seeing what a fractal is.

*The constraints are as follows:*
	• Your software should offer the Julia set and the Mandelbrot set.
	• The mouse wheel zooms in and out, almost infinitely (within the limits of the
	computer). This is the very principle of fractals.
	• You must use at least a few colors to show the depth of each fractal. It’s even better if you hack away on psychedelic effects.
	• A parameter is passed on the command line to define what type of fractal will be viewed. If no parameter is provided, or if the parameter is invalid, the program
	displays a list of available parameters and exits properly.
	• More parameters must be used for fractal parameters or ignored.
	• You must be able to create different Julia set with the parameters of the program.
	As for the graphic representation:
	• ESC will exit the program.
	• The use of images of the minilibX is strongly recommended.

Commands allowed:
• open, close, read, write,
printf, malloc, free, perror,
strerror, exit
• All functions of the math
library (-lm man man 3 math)

• All functions of the MinilibX

       First of all, you need to initialize the connection between  your  software  and
       the  display.   Once this connection is established, you'll be able to use other
       MiniLibX functions to send the graphical orders, like "I want to draw  a  yellow
       pixel in this window" or "did the user hit a key?".

       The mlx_init function will create this connection. No parameters are needed, ant
       it will return a void * identifier, used for further calls to the  library  rou-
       tines.

       All other MiniLibX functions are described in the following man pages:


       mlx_new_window      : manage windows

       mlx_pixel_put       : draw inside window

       mlx_new_image       : manipulate images

       mlx_loop            : handle keyboard or mouse events