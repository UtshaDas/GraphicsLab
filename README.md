# Graphics Lab (OpenGL / GLUT)

Lab work from a university **Computer Graphics** course, written in C/C++ with **OpenGL** and **GLUT**. The programs start with drawing simple 2D shapes and go on to animation, keyboard-driven transformations, reflection, and 3D viewing with perspective projection.

Most projects are **Code::Blocks** projects (`.cbp`) built with MinGW on Windows. A few are **Visual Studio 2012** projects.

---

## Labs at a glance

| # | Topic | Where | What it shows |
|---|-------|-------|---------------|
| 0 | Environment setup | `00/` | Setting up GLUT on Windows, plus a first triangle program (`00/Manual/Source.txt`) |
| 1 | Simple shapes | `01/OpenGL Programming Guide/PolygonShapes.c` | A leaf-like figure drawn from a triangle and polygons, with per-vertex colors |
| 2 | Rotating object | `GraphicsLab/main.cpp` | Five copies of the shape rotated by 72° to form a star or flower, which spins continuously |
| 3 | Keyboard interaction | `project2/main.cpp` | Translate, rotate and scale a shape with the keyboard |
| 4 | Reflection | `Reflection/main.cpp` | Reflection about the x-axis and about an arbitrary line |
| 5 | 3D object and viewing | `3Dtesting/main.cpp` | A colored cube viewed with `gluPerspective` and `gluLookAt`, with keys to change the camera |
| 6 | Pyramid | `Piramid.cpp` | A square-based pyramid with the same camera controls |
| 7 | Animated 3D viewing | `3DViewlooping/` (source in `143034.zip`) | Same as Lab 5, but one key press runs a sequence of random camera changes |
| – | Lit 3D cube | `3DProjection/`, `3DVIEWING/` | A red cube lit by a single light with depth testing (based on Mark J. Kilgard's GLUT example) |

---

## Repository layout

```
GraphicsLab/
├── 00/                      Lab 0: environment setup
│   ├── Manual/              GLUT files (GLUT.H, glut32.lib, GLUT32.DLL), setup guide PDF, first program
│   ├── OpenGL Overview.pdf
│   └── Report00.docx
├── 01/OpenGL Programming Guide/
│   ├── PolygonShapes.c      Lab 1 source
│   ├── LAB_TASK.txt         Lab task: shapes as separate functions + rotation
│   ├── Leaf*.JPG            Reference output images
│   └── Chapter 1–14 *.pdf   OpenGL Programming Guide reading material
├── GraphicsLab/             Lab 2: rotating star (Code::Blocks)
├── project2/                Lab 3: keyboard transformations (Code::Blocks)
├── Reflection/              Lab 4: reflection (Code::Blocks)
├── 3Dtesting/               Lab 5: 3D cube + camera controls (Code::Blocks)
├── 3DViewlooping/           Lab 7: project files only (source is in 143034.zip)
├── 3DProjection/            Lit red cube (Code::Blocks)
├── 3DVIEWING/               Lit red cube (Code::Blocks)
├── PraceticeLab/            Practice version of the rotating star
├── Lab_project/             Visual Studio 2012 solutions (Project1: five-fold rotated figure)
├── Piramid.cpp              Lab 6: pyramid with camera controls
├── Circle draw.cpp          Rectangle drawing; circle code kept in comments
├── Untitled2.cpp            Copy of GraphicsLab/main.cpp
├── 143034.zip               Submission archive: 3Dtesting + 3DViewlooping
└── Notice.txt               Index of which folder covers which lab
```

---

## Requirements

- A C/C++ compiler: **MinGW** (via [Code::Blocks](https://www.codeblocks.org/)) or **Visual Studio**
- **OpenGL** (included with the graphics driver)
- **GLUT**: the original GLUT files are in `00/Manual/`, or use [freeglut](https://freeglut.sourceforge.net/)

The Code::Blocks projects link against `opengl32`, `glu32`, `glut32`, `gdi32` and `winmm`.

---

## Building and running

### Windows: Code::Blocks (recommended)

1. Install Code::Blocks with MinGW.
2. Set up GLUT by following `00/Manual/make-ready-envirnmnt.pdf`. In short:
   - copy `GLUT.H` to your compiler's `include/GL/` folder as `glut.h`
   - copy `glut32.lib` to the compiler's `lib/` folder
   - copy `GLUT32.DLL` to `C:\Windows\System32` (on 64-bit Windows, `C:\Windows\SysWOW64`) or next to the `.exe`
3. Open a project's `.cbp` file (e.g. `GraphicsLab/GraphicsLab.cbp`) and press **F9** (Build and run).

To run a single `.cpp` file such as `Piramid.cpp`, create a new **GLUT project** in Code::Blocks and paste the code into its `main.cpp`.

### Windows: Visual Studio

Open `Lab_project/Project1/Project1.sln`. Its source uses `#include <glut.h>`, so put `glut.h` somewhere on the include path and add `glut32.lib` to the linker inputs.

### Linux (freeglut)

The sources include `<windows.h>`, which doesn't exist on Linux. Remove that line, change any `#include <glut.h>` to `#include <GL/glut.h>`, and then:

```bash
sudo apt install freeglut3-dev
g++ GraphicsLab/main.cpp -o rotate -lglut -lGLU -lGL
./rotate
```

`3DViewlooping` also calls the Windows-only `Sleep(1)`. Replace it with `usleep(1000)` from `<unistd.h>`.

---

## Keyboard controls

### Lab 3: Keyboard interaction (`project2`)

| Key | Action |
|-----|--------|
| `t` | Translate |
| `r` | Rotate (15° on the figure, 30° on the square) |
| `s` | Scale down (×0.5) |
| `e` | Enlarge (×1.5) |
| `q` | Switch to the square only |
| `o` | Switch back to the full figure (from the square view) |
| `x` | Exit |

Transformations add up, because the matrix isn't reset between key presses.

### Lab 4: Reflection (`Reflection`)

The square is drawn reflected about the x-axis (`glScalef(1, -1, 1)`) when the program starts.

| Key | Action |
|-----|--------|
| `p` | Reflect about the line through (0, 0.2) at 60°: translate → rotate → reflect → rotate back → translate back |

### Labs 5–6: 3D viewing (`3Dtesting`, `Piramid.cpp`)

Keys are case-insensitive.

| Key | Increase | Key | Decrease | Parameter |
|-----|----------|-----|----------|-----------|
| `A` | +5° | `B` | −5° | Field of view (`fovy`) |
| `C` | ×2 | `D` | ÷2 | Aspect ratio |
| `E` | +2 | `F` | −2 | Near plane |
| `G` | +2 | `H` | −2 | Far plane |
| `I` | +0.1 | `J` | −0.1 | Eye position (x, y, z) |
| `K` | +0.1 | `L` | −0.1 | Look-at center (x, y, z) |
| `M` | +0.1 | `N` | −0.1 | Up vector (x, y, z) |

In **3DViewlooping**, pressing any key runs about 900 random steps from the table above, which animates the camera.

---

## Known issues

- **Near and far planes are swapped.** `3Dtesting` and `Piramid.cpp` start with `nearr = 20` and `farr = 5`, so the object may not appear until you press `E`/`F`/`G`/`H`. Swapping the starting values (`nearr = 1`, `farr = 20`) shows the object right away.
- **Pyramid sides are drawn as quads.** The four triangular sides of `Piramid.cpp` have three vertices each but are drawn inside a `GL_QUADS` block, so they render incorrectly. Draw the base with `GL_QUADS` and the sides with `GL_TRIANGLES`.
- **No depth test in 3D labs.** `3Dtesting` and `Piramid.cpp` don't enable `GL_DEPTH_TEST`, so faces can overlap in the wrong order.
- **Missing source.** `3DViewlooping/` has no `main.cpp` in the repository. Its source is only in `143034.zip`.
- **Build output committed.** `.exe`, `.o`, Visual Studio `Debug/` folders and the Word lock file `~$port00.docx` are build or temporary files and can be removed (see the `.gitignore` below).

Suggested `.gitignore`:

```gitignore
bin/
obj/
Debug/
*.o
*.exe
*.ilk
*.pdb
*.sdf
*.suo
*.depend
*.layout
~$*
```

---

## Credits

- `3DVIEWING/main.cpp` and `3DProjection/main.cpp` are based on the GLUT "red 3D lighted cube" example, © Mark J. Kilgard, 1997.
- Reading material: *OpenGL Programming Guide* (the "Red Book").

## Author

**Utsha Das**, Department of CSE, RUET
