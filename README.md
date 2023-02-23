# 2223-10: On the job training (OTJ) project

# The Car Rental System
This document describes the OTJ project for 10th graders. **It will be updated frequently**.

# 1. Assignment Goals
A car rental system is an application that manages the renting of automobiles for a short period of time—a few hours to a few weeks. 
A car rental system has a number of offices in different locations within each city. 
It allows the users to reserve and return a vehicle from different locations and is primarily located near airports or city areas.T
he car rental system keeps a list of all its clients in a database. The database includes the name, address, and contact number of each new customer.
A member can reserve a car for a certain number of days, hire a car, or return the car that was rented. 
A member makes a reservation by supplying the pickup and drop-off locations, the kind of vehicle, and the day and time of the reservation.

# 2. Expectations from the interviewee
The car rental system consists of multiple components. Each component has its own functionality and constraints. 
This section provides an overview of some of the main expectations that the interviewer will want to hear you discuss in more detail during the interview.

## 2.1. Vehicle types
An interviewer would expect you to discuss the different vehicle types, and ask the following questions:
* What types of vehicles will that system support?
* How can we identify the specific vehicle?

## 2.2. Search interface
Members will use the application and add location and the reservation date. They will receive several options to select the vehicle. 
Therefore, an interviewer would expect you to ask questions listed below:
* Is it possible to search a vehicle using its name or type?
* Can we search for a vehicle by its model number?

## 2.3. Services
An interviewer would also expect you to discuss the services of the car rental system and may ask the following questions:
* Does a car rental system assign a driver to its customer?
* Does a car rental system provide roadside assistance to its customer?

## 2.4. Reservation cancelation
There will be many duplicate instances in our system. The interviewer expects you to ask questions listed below:

* Can the member be able to cancel a reservation?
* Which member is allowed to request a vehicle reservation cancelation and when?

## 2.5. Payment flexibility
One of the car rental system’s most significant attributes is its customer payment structure. The payment depends on the vehicle type and time stamp. Therefore, an interviewer would expect you to ask questions listed below:

* How can customers pay at different branch locations and by different methods (cash, credit, or cheque)?
* If there are multiple branches of the car rental system, how will the system keep track of the customer having already paid at a particular branch?

# 3. Requirements for the Car Rental System
The set of requirements for the car rental system are listed below:

 ## Authentication
* R1: There can be two types of users in the car rental system, i.e., customers and receptionists.

* R2: The system should handle multiple types of vehicles. Initially, the system should cater to the following vehicles: cars, trucks, vans, and motorcycles.

## Users Management
* R3: There can be multiple subtypes for vehicles. The car type can be economy, luxury, standard, and compact. The van type can be passenger or cargo. Moreover, the motorcycle type can be cruiser, touring, or sports.The truck type can be light, medium, or high-duty.

* R4: The system should be able to keep a record of who reserved a particular vehicle and on which date the vehicle was issued.

* R5: The system should be able to find out how many vehicles have been rented out by the specific customer.

* R6: The customers should be able to cancel their reservations.

* R7: To keep track of all events related to the vehicle, the system should maintain a vehicle log.

* R8: The system should allow the users to add equipment to the reservations like a ski rack, child seat, and navigation.

* R9: The system should allow the users to add services to the reservations like a driver, Wi-Fi, and roadside assistance.

## Projects Management
* R10: The system should send a notification to the customer and generate a fine if the vehicle is not returned within the due date.

* R11: The system should allow the user to search the vehicles by type or model.

* R12: A system should be able to manage the multiple branches of the car rental system.

* R13: Every branch of the car rental system should have parking stalls to park the vehicles.

# Base requirements

* Programming language: C++
* Visual Studio 2022 (latest release)
* Git for Windows (latest release)
* Skill for working with Git from command line (CLI) & Git extension in Visual Studio
* Following the best practices for C++ / Git / GitHub is a mandatory requirement

Additional requirements will be added later.
