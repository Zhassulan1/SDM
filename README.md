# Shutdown manager/SDM

I am not sure that someone will need this, just reinventing the wheel

This program was written in first semester (2022 fall, first course)

---

# Motivation

The reason I wrote this program was written because original `shutdown` command line utility does not support hybernation with time delay. I decided to fix it.

Why did I remember about this program now? I needed to learn how [`Inno setup script`](https://jrsoftware.org/isinfo.php) works (Also I neded some practice on writing README files).

---

# Installation

1. You can download [`Setup Wizzard`](https://github.com/Zhassulan1/SDM/blob/main/installer/SDM%20setup.exe) (If you trust stranger from internet)

2. You can build installer using [`Inno Setup`](https://jrsoftware.org/isinfo.php), script source codes are in "installer" folder

3. You can copy "ShutdownM.cpp" and qsd_modes.hpp", and compile `g++ ShutdownM.cpp -o SDM.exe` 

    (Make sure that it is added to `Path` in order to launch it by command line or by Run)