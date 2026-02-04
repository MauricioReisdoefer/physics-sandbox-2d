# Physics Sandbox (C)

A small 2D physics sandbox written in C.

This project is a physics and math experimentation environment, focused on Vector2-based simulation, forces, and movement.

Not a game engine. Just math and physics.

GCC Build

```bash
gcc main.c src/core/entity.c src/math/vector.c src/module/rigidbody.c src/module/transform.c -I./include -I./include/core -I./include/math -I./include/module -I C:/libs/SDL3/include -L C:/libs/SDL3/lib -lSDL3 -o main.exe
```
