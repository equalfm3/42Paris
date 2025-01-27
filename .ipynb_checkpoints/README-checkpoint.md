# 42 School Projects Portfolio

This repository contains all my projects completed at 42 School. Each project represents different challenges and learning objectives that contributed to my development as a software engineer.

## Table of Contents
- [DoomNukem](#doomnukem)
- [FdF](#fdf)
- [Fillit](#fillit)
- [Fractol](#fractol)
- [Inception-of-Things](#inception-of-things)
- [Libft](#libft)
- [cloud-1](#cloud-1)
- [computorv1](#computorv1)
- [docker-1](#docker-1)
- [dslr](#dslr)
- [ft_linear_regression](#ft_linear_regression)
- [get_next_line](#get_next_line)
- [multilayer-perceptron](#multilayer-perceptron)

-----
# DoomNukem 3D

### Purpose
The main purpose of the DoomNukem 3D project is to create a first-person shooter game that combines elements of Doom and Duke Nukem 3D using raycasting techniques. 

### Key Skills and Concepts
- 3D graphics programming using raycasting 
- Game engine development
- Texture mapping
- Lighting and shading
- Player controls and physics
- Level design and editing
- Sound effects and music integration

### Technologies
- C language
- Custom game engine and raycasting renderer
- MinilibX graphics library

### Challenges  
- Implementing smooth 3D graphics and textures using 2D raycasting
- Allowing free player movement in all directions
- Developing advanced gameplay features like jumping, flying, swimming
- Creating engaging levels with puzzles, secrets, and progression
- Building a level editor for custom content creation
- Ensuring performant real-time rendering and gameplay

Overall, the project focuses on learning core 3D graphics concepts and game development skills by building a retro-style first person shooter from scratch.

-----
# FdF

### Purpose
The purpose of this project is to create a simplified 3D wireframe graphical representation of a landscape by connecting points (x, y, z coordinates) loaded from a file.

### Key Concepts  
- Computer graphics programming basics like placing points in space, connecting them with lines, and viewing the scene from different angles
- Event-driven programming by handling keyboard and mouse events
- Using a graphics library (miniLibX)

### Technologies
- C programming language
- miniLibX graphics library

### Challenges  
- Loading and parsing map data from a file
- Transforming the 2D coordinate data into a 3D graphical representation
- Allowing the user to manipulate the viewpoint and projection  
- Managing graphics events and input
- Optimizing rendering performance

The project focuses on core computer graphics concepts like coordinate spaces, projections, and event handling. Overall it provides an introduction to building a simple interactive 3D application.

-----
# Fillit

The main purpose of the Fillit project is to assemble a set of Tetriminos pieces into the smallest possible square. Students learn algorithms and optimization by finding an efficient way to arrange the pieces.

### Key technical skills and concepts:
- Algorithm design and analysis 
- Optimization techniques like backtracking and recursion
- Bit manipulation
- Dynamic memory allocation

### Technologies
- C language
- Makefiles

### Core challenges and learning objectives:  
- Implement an algorithm to find the optimal arrangement of Tetriminos in a square.
- Optimize the solution to run efficiently for large input sets.  
- Gain experience with C concepts like pointers, memory management, Makefiles.
- Learn how to analyze time and space complexity tradeoffs.

-----
# Fractol
### Purpose
The purpose of this project is to create a fractal visualization program to explore different mathematical fractal shapes. Fractals are infinitely complex patterns that repeat at every scale.

### Key Skills
- Computer graphics programming using miniLibX
- Visualizing mathematical fractals like Julia and Mandelbrot sets
- Zooming, panning, and coloring fractal visualizations 
- Handling mouse and keyboard input

### Technologies
- C programming language
- miniLibX graphics library
- Mathematical concepts like complex numbers

### Challenges  
- Generating fractal images efficiently
- Implementing smooth zooming and panning 
- Creating psychedelic color schemes
- Managing program state based on user input

-----
# Inception-of-Things

### Purpose
The main purpose of this project is to gain hands-on experience with Kubernetes (K8s) by deploying clusters using K3s and K3d. Students will learn core K8s concepts like pods, deployments, ingress, and namespaces.

### Key Skills and Concepts
- Deploying K8s clusters with K3s and K3d
- Creating and managing pods, deployments, services 
- Using ingress for routing
- Automating deployments with Git, Docker, and Argo CD

### Main Technologies
- Kubernetes (K3s, K3d)
- Vagrant
- Docker 
- Git/GitHub
- Argo CD

### Core Challenges  
- Install, configure and connect K3s servers and agents with Vagrant
- Deploy sample web apps and configure routing with ingress
- Automate deployments using Git, Docker, and Argo CD
- Gain practical experience with core K8s concepts like pods, deployments, namespaces, and ingress

The main goal is to learn Kubernetes basics by deploying clusters, sample apps, and setting up CI/CD pipelines. Students will gain hands-on experience with K8s core concepts using real tools like K3s, Git, and Argo CD.

-----
# Libft


### Purpose
The purpose of the Libft project is to code a C library regrouping useful functions that can be reused in future C projects. It serves as an introduction to C programming and developing reusable code.

### Key Concepts
- Implementing standard C library functions
- Memory allocation and management
- String manipulation
- Linked lists
- Modular code design

### Technologies
- C programming language
- Makefile for compilation

### Challenges and Learning Objectives
- Gain proficiency in C language syntax and features
- Understand memory management and pointers
- Implement standard library functions from scratch
- Modularize code into reusable components
- Learn basics of data structures like linked lists
- Write robust code that handles errors gracefully
- Learn to create and use Makefiles for compilation
- Gain experience developing a reusable code library

-----
# cloud-1


### Purpose
The main purpose of this project is to deploy a WordPress site and associated Docker infrastructure onto a cloud server instance in an automated way using tools like Ansible.

### Key Concepts  
- Automating deployment of a multi-container Docker application on a cloud server 
- Using configuration management tools like Ansible for automated deployments
- Securing services and limiting public access 
- Persisting data across server restarts
- Horizontal scaling by deploying to multiple servers

### Technologies
- Docker containers 
- Docker Compose 
- Ansible
- WordPress
- MySQL
- Nginx

### Challenges
- Automating all deployment steps without manual intervention
- Ensuring WordPress site data persists across server restarts
- Securing services like MySQL so they are not publicly accessible
- Making site scalable and deployable to multiple servers
- Using containers to isolate services

-----
# computorv1

### Purpose
The purpose of this project is to create a program that can solve polynomial equations up to degree 2. It aims to develop skills in math and programming.

### Key Concepts  
- Polynomial equations
- Equation solving and analysis
- Programming skills

### Technologies
- Python
- Jupyter Notebook for testing
- Makefile for compilation 

### Challenges  
- Parsing and analyzing polynomial equations
- Implementing equation solving algorithms
- Managing edge cases and exceptions
- Presenting solutions in a readable format

### Learning Objectives
- Refresh math skills like working with polynomials
- Practice core programming concepts like I/O, control flow, data structures
- Gain experience with compilation and Makefiles
- Develop skills in analyzing requirements and designing solutions

-----
# docker-1


### Purpose
The docker-1 project is an introductory project to learn the basics of Docker and containerization. Students learn how to use Docker and docker-machine to run containers and build images.

### Key Concepts  
- Containerization and benefits (portability, reproducibility, isolation)
- Docker components and architecture
- Basic Docker commands like docker run, docker ps, docker build
- Dockerfiles for building custom images 
- Docker networking and volumes
- Docker Swarm for clustering 

### Technologies
- Docker Engine
- Dockerfile
- docker-machine
- Docker Hub

### Learning Objectives
- Install Docker and run simple containers
- Build custom images with Dockerfiles
- Network containers and manage data with volumes
- Deploy containerized services across multiple machines with Swarm

### Challenges
- Understanding containerization and how Docker implements it
- Learning Docker's architecture and ecosystem of tools
- Building efficient Dockerfiles following best practices
- Networking containers and managing service discovery
- Coordinating containers across multiple machines

-----
### dslr

### Purpose
The purpose of this project is to build a logistic regression classifier to categorize students into Hogwarts houses. This solves the problem of the Sorting Hat not working.

### Key Skills
- Data analysis and visualization with Python
- Implementing logistic regression from scratch using gradient descent 
- Multi-class classification using one-vs-all logistic regression

### Technologies
- Python
- NumPy, Pandas, Matplotlib for data analysis and visualization
- Logistic regression model trained using gradient descent optimization 

### Challenges  
- Cleaning and wrangling the dataset
- Implementing logistic regression mathematically
- Achieving high accuracy on test data
- Explaining how the model works

The key learning objectives were to gain hands-on experience with data analysis, visualization, and implementing a complete machine learning pipeline. This project provided practical experience in working through a classification problem end-to-end.

-----
# ft_linear_regression


### Purpose
Implement a simple linear regression algorithm to predict car prices based on mileage data. Introduces core machine learning concepts.

### Key Skills/Concepts  
- Linear regression
- Gradient descent 
- Model training and prediction
- Basic machine learning techniques

### Technologies/Languages
- Any language that allows data visualization (Python recommended)

### Challenges/Objectives
- Implement linear regression from scratch without using libraries 
- Develop programs for model training and price prediction
- Visualize data and model fit
- Gain hands-on experience with a fundamental machine learning algorithm

-----
# get_next_line

### Purpose
The main purpose of this project is to code a function that returns a line read from a file descriptor in C. This teaches how to handle file descriptors and memory allocation.

### Key Concepts
- File descriptor manipulation
- Managing static variables
- Memory allocation on stack and heap
- Buffer management 

### Technologies
- C
- make

### Challenges  
- Handling errors and memory leaks
- Understanding file descriptors
- Managing unknown buffer sizes
- Restricted to only 5 functions of max 25 lines

### Takeaways
The project focuses on gaining deeper understanding of:
- Static variables and their state
- Memory allocation differences between stack and heap
- Unexpected complexity when using static variables
- Rigorous programming and adherence to Norm standards

-----
# multilayer-perceptron

### Purpose
This project focuses on implementing a multilayer perceptron neural network from scratch in order to classify breast cancer tumors as malignant or benign. The goal is to gain an understanding of artificial neural networks and the algorithms involved in training them.

### Key Concepts  
- Artificial neural networks
- Multilayer perceptrons
- Backpropagation
- Gradient descent optimization
- Data preprocessing

### Technologies
- Python 
- Linear algebra libraries
- Data visualization libraries 

### Challenges  
- Implementing the multilayer perceptron architecture
- Training the network using backpropagation and gradient descent
- Optimizing the network's performance on training and validation data
- Gaining an understanding of the underlying mathematical concepts
- Preprocessing the breast cancer dataset
- Saving and loading trained models

The project provides an introduction to neural networks and implementing machine learning models from scratch. Key challenges involve both programming skills and conceptual understanding of the algorithms and math involved.

-----
## About 42 School
42 is a globally recognized computer science school that uses a peer-to-peer learning methodology and project-based approach. The curriculum is designed to develop both technical skills and soft skills essential for a career in software development.
