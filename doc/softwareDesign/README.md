# Software Design Documentation

## High-level Block Diagram
This section completes the issue [#3](https://github.com/brunogriep/generic_microservice_cpp/issues/3).
![alt text](../drawio/blockDiagram.png "Block Diagram")

## Microservices
This section completes the issues [#1](https://github.com/brunogriep/generic_microservice_cpp/issues/1) and [#4](https://github.com/brunogriep/generic_microservice_cpp/issues/4) by describing the system microservices with initial details of their objectives and responsabilities.

### Why Choose a Microservice?
Implementing a [Microservice Software Architecture] (https://medium.com/hashmapinc/the-what-why-and-how-of-a-microservices-architecture-4179579423a9) with C++ and gRPC is a powerful way to build scalable and maintainable systems.
There are many advantages to choosing a microservice implementation. Essentially, it means breaking a large application into smaller, independent services that can be developed, deployed, and scaled independently. This modular approach makes things more flexible and scalable, meaning we can work on different parts of the system at the same time without affecting the other modules. 
It makes maintenance easier by keeping problems to one service, updates are much easier since Docker provides a good and efficient way to replace a container. For unconstrained environments, it allows you to use different programming languages and tools.
In addition, microservices work well with continuous integration and continuous deployment (CI/CD) practices, making software development faster and more reliable.

### The containerized services
- Manager
    - controls the data flow and the sytem itself, by being a proxy to the other services (docker containers)
- System Monitor
    - responsible to track and collect the system metrics
    - collects the following info:
        - cpu usage
        - memory usage
        - disk usage
- Database
    - manage data storage and retrieval
    - features a backup system
    - store; remove; retrieve; clean data
    - cleaning method to remove old data
- Cloud Service
    - responsible to push data to a cloud service, e.g., google cloud or AWS services
    - responsible to encrypt the retrieve data from the data base using TLS/SSL before pushing the data
    - check internet connection and availability
    - accepts:
        - eth
        - wifi
        - modem (future implementation for embedded applications)
- Generic Fake Application
    - implement a fake or dummy data ingestor to be able to emulate some data collection from different devices, e.g., sensor data, USB device data collection, etc...

## Requirements
This is not definitive
### Microservices
- **Data Ingestion Microservice**: collects data from sensor or other souces and ingests into the system
- **Data Processing Microservice**: process, analyze and perform transformation, filtering or aggregations to the data
- **Data Storage Microservice**: Manage data storagem proving persistent storage for the collected and processed data
- **Data Retrieval Microservice**: Handles requests for querying and retrieving data.
- **Hardware Management Microservice**: Manager metadata, configuration and status
  - sensor data
  - camera
  - audio
  - 3th party devices metadata

### Technical
- SOLID Principles
- collect metrics such as latency, errors, resource usage, faults, etc...
- implement a logging mechanism with a level of persistancy
- use centralized configuration settings
- authentification and authorization?
- Use TLS/SSL for encrypting gRPC communications?
- exception should be threated if possible to not break the system
- keep code coverage up to 80%

## Tools, frameworks, technologies, principles and standards
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
