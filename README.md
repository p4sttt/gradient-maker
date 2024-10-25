# Gradient Maker

This is a simple project to create and display gradients using bilinear/linear interpolation algorithm. The project is written in C++ and uses the SDL2 library to create a window and display the gradient. The start and end colors of the gradient are passed as command-line arguments in hex format. The program uses a bilinear interpolation algorithm to smoothly transition between the start and end colors for each pixel in the window.

## Installation & Build

Copy git repository

```bash
git copy https://github.com/p4sttt/gradient-maker.git
```

This project usage [Meson Build system](https://mesonbuild.com/) and [Simple DirectMedia Layer](https://www.libsdl.org/) library for graphic interface. All files for build and executable files container in `/build` directory.

Create build directory

```bash
meson setup build
```

Compile project

```bash
meson compile -C build
```

Run executable file

```bash
./build/src/bilinear_interpolation [interpolation-type] [colors...]
```

Where `[colors...]` is a list of colors in hex format (e.g., FF5733 DON'T START WITH A HASH!!). The program will generate a gradient using the colors provided. And `[interpolation-type]` is a type of interpolation. It can be `bilinear` or `linear` using flags `-bi` and `-li` represently.

## Explonation

Gradient Maker is a simple C++ program that generates and displays a color gradient in an SDL2 window. The start and end colors of the gradient are passed as command-line arguments in hex format (e.g., FF5733). The program uses a linear interpolation algorithm to smoothly transition between the start and end colors for each pixel in the window.
