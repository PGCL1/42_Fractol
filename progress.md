							**FRACTOL**


DONE:
	- create keyhooks for exiting the window
	- create function where mandelbrot Mandelbrot or 1 can be passed as parameters or even MandeLbrot and do so for all the next fractals


STUFF FOR TODAY:
	- follow instructions from step by step in  http://warp.povusers.org/Mandelbrot/
	- create keyhooks for move the image with keys A S D W and arrows
	- print the background first and then print the mandelbrot set



IMPROVEMENTS:
	- need to rewrite Makefile in libft/


ERRORS:

LEARNING:
	make use of function mlx_loop_hook() to generate fractal and constantly re-render
	To initialize the Minilib Library, we need to invoce the mlx_init function; this will enable us to connect our operating software with the minilib API.
	Then, we need to create a window in which our project will be hosted. To ensure our program stays optimized it is recommended to create an image in which the pixels will first be rendered and then that same image will be pushed to the original window we created.

	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	The 0, 0 is the position at which the image will be drawn within the window

All keyhooks events for the minilib are

KeyPress:			Event code: 2	 MLX_KEY_PRESS
KeyRelease:			Event code: 3	 MLX_KEY_RELEASE
ButtonPress:		Event code: 4	 MLX_BUTTON_PRESS
ButtonRelease:		Event code: 5	 MLX_BUTTON_RELEASE
MotionNotify:		Event code: 6	 MLX_MOTION_NOTIFY
Expose:				Event code: 12	 MLX_EXPOSE
DestroyNotify:		Event code: 17	 MLX_DESTROY_NOTIFY
EnterNotify:		Event code: 7	 MLX_ENTER_NOTIFY
LeaveNotify:		Event code: 8	 MLX_LEAVE_NOTIFY
FocusIn:			Event code: 9	 MLX_FOCUS_IN
FocusOut:			Event code: 10	 MLX_FOCUS_OUT
ConfigureNotify:	Event code: 22	 MLX_CONFIGURE_NOTIFY
MapNotify:			Event code: 19	 MLX_MAP_NOTIFY
UnmapNotify:		Event code: 18	 MLX_UNMAP_NOTIFY
ClientMessage:		Event code: 33	 MLX_CLIENT_MESSAGE



INSTRUCTIONS:
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


ZOOM IN		is 4
ZOOM OUT	is 5

