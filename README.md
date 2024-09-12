# A Generic Microservice C++ Project Template 

Work In Progress...

## Introduction
This project will develop a standard microservice implementation in C++. We will use Docker to set up and deploy the applications and gRPC to implement communication between the containers. The main objective is to optimise development time for setting up this kind of environment.

### Why go for a microservice?
Implementing a microservice architecture with C++ and gRPC is a powerful way to build scalable and maintainable systems.
There are lots of benefits to choosing a microservice implementation. It basically means splitting a large application into smaller, independent services that can be developed, deployed and scaled independently. This modular approach makes things more flexible and scalable, meaning we can work on different parts of the system at the same time without affecting the other modules. 
It makes maintenance easier by keeping issues to one service, updates are much easier since docker provides a good and efficient way to replace a container. For non constraint environments enables you to use different programming languages and tools.
Additionaly, microservices work great with continuous integration and continuous deployment (CI/CD) practices, which makes developing software faster and more reliable.

## Documentation
This project documentation includes the design decisions, UML diagrams and drawings.
A guide on how to use the system will be provided.

### Requirements
WIP
#### Microservices
- **Data Ingestion Microservice**: collects data from sensor or other souces and ingests into the system
- **Data Processing Microservice**: process, analyze and perform transformation, filtering or aggregations to the data
- **Data Storage Microservice**: Manage data storagem proving persistent storage for the collected and processed data
- **Data Retrieval Microservice**: Handles requests for querying and retrieving data.
- **Hardware Management Microservice**: Manager metadata, configuration and status
  - sensor data
  - camera
  - audio
  - 3th party devices metadata

#### Technical
- SOLID Principles
- collect metrics such as latency, errors, resource usage, faults, etc...
- implement a logging mechanism with a level of persistancy
- use centralized configuration settings
- authentification and authorization?
- Use TLS/SSL for encrypting gRPC communications?
- exception should be threated if possible to not break the system
- keep code coverage up to 80%

### Tools, frameworks, technologies, principles and standards
- Software Architecture Design
  - SOLID Principles
  - Design Patterns (some)
  - UML Diagrams
- Programming Languages
  - Modern C++
  - Python and Shell for scripting
- Technologies and Frameworks
  - [Docker](https://www.docker.com/) to containerize the apps
  - [Docker-Compose](https://docs.docker.com/compose/) for multi-container managenment
  - [gRPC](https://grpc.io/) to implement RPC calls, streaming and error handling
  - [Protobuffers](https://protobuf.dev/) to define the RPC calls and data structures
  - [googletest](https://github.com/google/googletest) as the unit testing framework
  - [Conan](https://conan.io/) as the software package manager

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