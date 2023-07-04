import express from "express"
import type { Request, Response } from "express"
import {body, validationResult} from "express-validator"
import bcrypt from "bcrypt"
import * as logService from "./logs.service"
import { request } from "http"

export const logRouter = express.Router()

//GET: list of all logs
logRouter.get("/", async(request: Request, response: Response) => {
    try{
        const logs = await logService.listLogs()
        return response.status(200).json(logs)
    }
    catch(error: any){
        return response.status(500).json(error.message)
    }
})

//GET: a single log by id 
logRouter.get("/:userId", async(request: Request, response: Response) => {
    const userId: number = parseInt(request.params.userId, 10)

    try{
        const log = await logService.getLog(userId)

        if(log){
            return response.status(200).json(log)
        }
        return response.status(404).json("Author could not ne found")
    }
    catch(error: any){
        return response.status(500).json(error.message)
    }
}) 

//POST: create an log
logRouter.post("/", body("userId").isInt(), body("vehicleId").isInt(), 
async(request: Request, response: Response) => {
    const errors = validationResult(request)

    if(!errors.isEmpty()){
        return response.status(400).json({errors: errors.array()})
    }

    try{
        const log = request.body

        const newlog = await logService.createLog(log)
        return response.status(201).json(newlog)
    }
    catch(error: any){
        return response.status(500).json(error.message)
    }
})

//POST: updating an log
logRouter.put("/:id", body("userId").isInt(), body("vehicleId").isInt(), 
async(request: Request, response: Response) => {
    const errors = validationResult(request)

    if(!errors.isEmpty()){
        return response.status(400).json({errors: errors.array()})
    }

    const id: number = parseInt(request.params.id, 10) 

    try{
        const log = request.body
        const updatedlog = await logService.updateLog(log, id)

        return response.status(200).json(updatedlog)
    }
    catch(error: any){
        return response.status(500).json(error.message)
    }
})


//DELETE: Delete an log based on the id
logRouter.delete("/:id", async(request: Request, response: Response) => {
    const id: number = parseInt(request.params.id, 10)

    try{
        await logService.deleteLog(id)
        return response.status(204).json("Log has been successfully deleted")
    }
    catch(error: any){
        return response.status(500).json(error.message)
    }
})