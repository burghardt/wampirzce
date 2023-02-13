Wampirzce
---------

Symulacja Wampirzców-Rozpustników (pol. The Libertine Vampire Simulation) - a
zero-player game inspired by Conway's Game of Life.

How to build it?
----------------

To compile it you will need:
 * SDL
 * freeglut
 * automake

Install `libsdl1.2-dev`, `freeglut3-dev` and `automake` on Debian/Ubuntu:

    # sudo apt update -qq
    # sudo apt install libsdl1.2-dev freeglut3-dev automake

Install `SDL-devel`, `freeglut-devel` and `automake` on Fedora:

    # sudo dnf install SDL-devel freeglut-devel automake

Compile `wampirzce` with:

    # sh autogen.sh
    # sh configure
    # make

Enjoy!
