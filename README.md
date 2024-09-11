# A Generic Microservice C++ Project Template 

Work In Progress...

## Introduction
This project will develop a standard microservice implementation in C++. We will use Docker to set up and deploy the applications and gRPC to implement communication between the containers. The main objective is to optimise development time for setting up this kind of environment.

### Why go for a microservice?
Implementing a microservice architecture with C++ and gRPC is a powerful way to build scalable and maintainable systems.
There are lots of benefits to choosing a microservice implementation. It basically means splitting a large application into smaller, independent services that can be developed, deployed and scaled independently. This modular approach makes things more flexible and scalable, meaning we can work on different parts of the system at the same time without affecting the other modules. 
It makes maintenance easier by keeping issues to one service, updates are much easier since docker provides a good and efficient way to replace a container. For non constraint environments enables you to use different programming languages and tools.
Additionaly, microservices work great with continuous integration and continuous deployment (CI/CD) practices, which makes developing software faster and more reliable.

### 
  

## Documentation
This project documentation includes the design decisions, UML diagrams and drawings.
A guide on how to use the system will be provided.

### Tools, frameworks, technologies, principles and standards
- Software Architecture Design
  - SOLID Principles
  - Design Patterns (some)
  - UML Diagrams
- Programming Languages
  - Modern C++
  - Python and Shell for scripting
  - others for specific purposes (to be defined)
- Technologies and Frameworks
  - Docker to containerize the apps
  - Docker-Compose for multi-container managenment
  - gRPC to implement RPC calls, streaming and error handling
  - Protobuffers to define the RPC calls and data structures
  - gTest/gmock for unit testing
## CI/CD
