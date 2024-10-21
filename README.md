# Bilinear Interpolation

This is a simple project to create and display gradients using bilinear interpolation method

## Installation & Build

Copy git repository

```bash
git copy https://github.com/p4sttt/bilinear-interpolation.git
```

This project usage [Meson Build system](https://mesonbuild.com/). All files for build and executable files container in `/build` directory

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
# hex color must starts with \# symbol
./build/src/bilinear_interpolation <LEFT_HEX_COLOR> <RIGHT_HEX_COLOR>
```

## Explonation

Gradient Maker is a simple C++ program that generates and displays a color gradient in an SDL2 window. The start and end colors of the gradient are passed as command-line arguments in hex format (e.g., #FF5733). The program uses a linear interpolation algorithm to smoothly transition between the start and end colors for each pixel in the window.
