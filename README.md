# 42_Fractol

42_Fractol is my project from 42's curriculum where we are first introduced to graphical programming. In this project, we are asked to create at least 2 fractals by using the MLX42 Library (mlx folder here). 

My project contains 3 fractals namely the Mandelbrot set, the Julia set and the Multibrot set. I also added a few features to this project which I will resume in a table.

Commands | Description | Fractals |
|---|---|---|
C | change color scheme | ALL |
F | change the constant's value for the Julia set | Julia |
'+' | add iterations to the counter (only work for large keyboards) | ALL |
'-' | minus iterations to the counter (only work for large keyboards) | ALL |
Arrow key UP | move up the fractal image | ALL |
W | move up the fractal image | ALL |
Arrow key DOWN | move down the fractal image | ALL |
S | move down the fractal image | ALL |
Arrow key LEFT | move left the fractal image | ALL |
A | move left the fractal image | ALL |
Arrow key RIGHT | move right the fractal image | ALL |
D | move right the fractal image | ALL |
ZOOM In (mouse/trackpad) | zooms in the fractal image following the mouse | ALL | 
ZOOM Out (mouse/trackpad) | zooms out the fractal image following the mouse | ALL | 

## Installation

```bash
git clone git@github.com:PGCL1/42_Fractol.git
cd 42_Fractol/mlx && make
cd .. && make
./fractol [fractal-name] [iterations]
```

> [!NOTE]  
> The Julia set can have two more params (see below): <br />
./fractol [fractal-name] [iterations] [complex-real] [complex-imaginary]

## Usage

```C
# to compile the program
make

# returns 'Mandelbrot set'
./fractol Mandelbrot

# returns 'Mandelbrot set at 300 iterations'
./fractol Mandelbrot 30

# returns 'Julia set 0.285 0 at 30 iterations '
./fractol Julia 30 0.285 0
```
