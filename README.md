# Micromouse Project - Autonomous Maze Navigation Robot

[![License](https://img.shields.io/badge/License-MIT-blue.svg)](https://opensource.org/licenses/MIT)

## Table of Contents
- [Introduction](#introduction)
- [Features](#features)
- [Dependencies](#dependencies)

## Introduction

Welcome to the Micromouse Project! This Arduino-based project is designed to create an autonomous maze navigation robot, also known as a micromouse. The robot uses ultrasonic sensors and motor control to explore and navigate through a maze, finding the shortest path from the starting point to the center.

This repository contains the code and resources required to build and program the micromouse robot. The robot uses flood fill algorithm to map the maze and determines the optimal path to reach the center, all while avoiding obstacles and dead ends.

![Micromouse in Action](./images/micromouse_demo.gif)

## Features

- Autonomous maze navigation using flood fill algorithm
- Real-time maze mapping and obstacle detection with ultrasonic sensors
- Optimal path planning to reach the center of the maze
- Easy-to-understand code structure and modular design for customization
- Detailed maze visualization with the `printMaze()` function
- Encapsulated classes for Bot control and Maze management


Clone this repository to your local machine using the following command:

```git clone https://github.com/paras-roy/micro_mouse```


## Dependencies

This project relies on the following Arduino libraries:
- `cppQueue.h` for implementing the queue data structure

Install the required library using the Arduino Library Manager or manually include it in your Arduino IDE.
