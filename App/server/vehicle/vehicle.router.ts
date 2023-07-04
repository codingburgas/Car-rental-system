import express from "express"
import type { Request, Response } from "express"
import {body, validationResult} from "express-validator"
import bcrypt from "bcrypt"
import * as vehicleService from "./vehicle.service"
import { request } from "http"

export const vehicleRouter = express.Router()

//GET: list of all vehicles
vehicleRouter.get("/", async(request: Request, response: Response) => {
    try{
        const vehicles = await vehicleService.listVehicles()
        return response.status(200).json(vehicles)
    }
    catch(error: any){
        return response.status(500).json(error.message)
    }
})

//GET: a single vehicle by id 
vehicleRouter.get("/:userId", async(request: Request, response: Response) => {
    const userId: number = parseInt(request.params.userId, 10)

    try{
        const vehicle = await vehicleService.getVehicle(userId)

        if(vehicle){
            return response.status(200).json(vehicle)
        }
        return response.status(404).json("Author could not ne found")
    }
    catch(error: any){
        return response.status(500).json(error.message)
    }
}) 

//POST: create an vehicle
vehicleRouter.post("/", body("vehicleType").isString(), body("name").isString(), 
body("manufacturer").isString(),body("model").isString(),body("isReserved").isBoolean(),
body("reservationDate").isString(),body("location").isString(), 
body("price").isInt(), body("reservedById").isInt(),
async(request: Request, response: Response) => {
    const errors = validationResult(request)

    if(!errors.isEmpty()){
        return response.status(400).json({errors: errors.array()})
    }

    try{
        const vehicle = request.body

        const newvehicle = await vehicleService.createVehicle(vehicle)
        return response.status(201).json(newvehicle)
    }
    catch(error: any){
        return response.status(500).json(error.message)
    }
})

//POST: updating an vehicle
vehicleRouter.put("/:id", body("vehicleType").isString(), body("name").isString(), 
body("manufacturer").isString(),body("model").isString(),body("isReserved").isBoolean(),
body("reservationDate").isString(),body("location").isString(), 
body("price").isInt(), body("reservedById").isInt(),
async(request: Request, response: Response) => {
    const errors = validationResult(request)

    if(!errors.isEmpty()){
        return response.status(400).json({errors: errors.array()})
    }

    const id: number = parseInt(request.params.id, 10) 

    try{
        const vehicle = request.body
        const updatedvehicle = await vehicleService.updateVehicle(vehicle, id)

        return response.status(200).json(updatedvehicle)
    }
    catch(error: any){
        return response.status(500).json(error.message)
    }
})


//DELETE: Delete an vehicle based on the id
vehicleRouter.delete("/:id", async(request: Request, response: Response) => {
    const id: number = parseInt(request.params.id, 10)

    try{
        await vehicleService.deleteVehicle(id)
        return response.status(204).json("Vehicle has been successfully deleted")
    }
    catch(error: any){
        return response.status(500).json(error.message)
    }
})