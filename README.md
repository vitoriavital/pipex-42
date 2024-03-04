# Pipex

<p align="center">
  <img src="https://game.42sp.org.br/static/assets/achievements/pipexm.png" alt="Pipex Achievement" width="200" height="200">
  <img src="https://res.cloudinary.com/dfjub9qt4/image/upload/v1708631992/pipex_42.png" alt="Pipex Square" width="200" height="200">
</p>

## Introduction
Fract-ol is a project aimed at creating graphically beautiful fractals using computer graphics techniques. This project offers an opportunity to explore the mlx42 library, utilize mathematical concepts such as complex numbers, delve into optimization in computer graphics, and practice event handling. 

MLX42 is a performant, easy to use, cross-platform windowing library to create graphical applications without having to work directly with the native Windowing Framework of the given operating system.
```bash
https://github.com/codam-coding-college/MLX42
```

## Features

Fract-ol includes the following features:

- **Mandelbrot Set**: The classic Mandelbrot set is generated.
- **Julia Set**: Allows the user to explore the Julia set by specifying real and imaginary numbers.
- **Burning Ship Fractal**: The burning ship fractal is generated.
- **Interactive Zoom**: Zoom in and out using the scroll wheel, following the mouse position.
- **Continuous Zoom**: Hold down the mouse button to continuously zoom in or out.
- **Color Change**: Press the Enter key to change the color palette of the fractal.
- **Exit**: Press the Esc key to exit the program.

## How to Use

To run Fract-ol, follow these steps:

1. Clone the repository:
```bash
git clone https://github.com/vitoriavital/fractal-42.git fract-ol
```
3. Navigate to the project directory: `cd fract-ol`
4. Compile the program: `make` or `make bonus`
5. Run the executable: `./fractol [fractal_type]`
   - Replace `[fractal_type]` with `mandelbrot`, `julia`, or `burning` to generate the respective fractal.
```bash
./fractol mandelbrot
```
```bash
./fractol julia -0.7 0.27015 
```
```bash
./fractol burning
```

## Controls

- **Zoom In**: Right-click or Scroll-In
- **Zoom Out**: Left-click or Scroll-Out
- **Continuous Zoom**: Hold down the mouse button while zooming.
- **Change Color Palette**: Press Enter
- **Exit Program**: Press Esc

## Dependencies

Fract-ol relies on the following dependencies:

- **Codam mlx42 Library**: The internal mlx42 library is used for graphics rendering and event handling. There are instructions to Download and Build MLX42, as well as installing its dependencies.
```bash
https://github.com/codam-coding-college/MLX42
```
