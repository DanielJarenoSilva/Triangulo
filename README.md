_This project has been created as part of the 42 curriculum by djareno | lvargas-_

# Description

**Cub3d** is a simple 3D graphic engine inspired by the game Wolfenstein 3D.
It uses a raycasting technique to render a pseudo-3D environment from a 2D map, allowing the player to navigate through a maze-like world.

The project is built in C and leverages in the MLX42 library to handle window creation, rendering, and user input.

The goal is to simulate a first-person perspective by calculating the distance between the player and walls and projecting them onto the screen.

Key features include:

- Real-time rendering using raycasting
- Player movement (forward, backward, left, right, rotation)
- Wall textures and colors
- Map parsing from a **.cub** file
- Basic event handling (keyboard input, window closing)

## Instructions

#### 1. Clone the repository
git clone https://github.com/your-username/cub3d.git

cd cub3d

---

#### 2. Install MLX42

This project uses the MLX42 graphics library.
You need to clone it into the root of the project:

git clone https://github.com/codam-coding-college/MLX42.git

---

#### 4. Compile the project

make

---

#### 5. Run the program

./cub3D maps/example.cub

# Resources

We used [this page](https://lodev.org/cgtutor/raycasting.html) as a guide.

And we used ChatGPT to find errors