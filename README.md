# A Generic Microservice C++ Project Template 

Work In Progress...

## Introduction
This project will develop a standard microservice implementation in C++. We will use Docker to set up and deploy the applications and gRPC to implement communication between the containers. The main objective is to optimise development time for setting up this kind of environment.

## Documentation
This project documentation includes the design decisions, UML diagrams and drawings.
A guide on how to use the system will be provided.

### Repository organization
#### doc
Details about the software design, such as UML diagrams and explanatory README files.

#### scripts
Includes supplementary shell and python scripts to facilitate development, such as build, test, deploy, and format scripts. 

#### src
The source code, in a modular structure.

#### test
This folder contains files related to unit tests using gTest and gMock, as well as integration tests and functional tests.

### Standards
- Programming Language: C++20
- Style Guide: [CppCoreGuidelines](https://isocpp.github.io/CppCoreGuidelines/CppCoreGuidelines)
- Format Style: Modified version of [WebKit](https://webkit.org/code-style-guidelines/) with personal touches.
  - PS: I do not follow the guide, I only use some sets available on clang-format.
 
## How to build


## CI/CD
WIP