import { db, Role, User } from "../utils/db.server";
import { vehicleRouter } from "./vehicle.router";
import type { Request, Response } from "express"
import { request } from "http";

import * as vehicleService from "./vehicle.service"

type Vehicle = {
    id: number;
    vehicleType: string;
    name: string;
    manufacturer: string;
    model: string;
    isReserved: boolean;
    reservationDate: string;
    location: string;
    price: number | null;
    reservedById: number | null;
};

export const listVehicles = async (): Promise<Vehicle[]> => {
    return db.vehicle.findMany({
        select: {
            id: true,
            vehicleType: true,
            name: true,
            manufacturer: true,
            model: true,
            isReserved: true,
            reservationDate: true,
            location: true,
            price: true,
            reservedById: true
        }
    });
};


export const getVehicle = async(id: number): Promise<Vehicle[] | null> => {
    return db.vehicle.findMany({
        where: {
            id,
        },

        select: {
            id: true,
            vehicleType: true,
            name: true,
            manufacturer: true,
            model: true,
            isReserved: true,
            reservationDate: true,
            location: true,
            price: true,
            reservedById: true
        },
    })
}

export const createVehicle = async(Vehicle: Omit<Vehicle, "id">): Promise<Vehicle> => {
    const {vehicleType, name, manufacturer, model, isReserved, reservationDate, location, price, reservedById} = Vehicle
    return  db.vehicle.create({
        data: 
        {
            vehicleType,
            name,
            manufacturer,
            model,
            isReserved,
            reservationDate,
            location,
            price,
            reservedById
        },

        select: {
            id: true,
            vehicleType: true,
            name: true,
            manufacturer: true,
            model: true,
            isReserved: true,
            reservationDate: true,
            location: true,
            price: true,
            reservedById: true
        }
    })
}

export const updateVehicle = async(Vehicle: Omit<Vehicle, "id">, id: number): Promise<Vehicle> => {
    const {vehicleType, name, manufacturer, model, isReserved, reservationDate, location, price, reservedById} = Vehicle
    return db.vehicle.update({
        where: {
            id,
        },

        data: 
        {
            vehicleType,
            name,
            manufacturer,
            model,
            isReserved,
            reservationDate,
            location,
            price,
            reservedById
        },

        select: {
            id: true,
            vehicleType: true,
            name: true,
            manufacturer: true,
            model: true,
            isReserved: true,
            reservationDate: true,
            location: true,
            price: true,
            reservedById: true
        }
    })
}

export const deleteVehicle = async (id: number): Promise<void> => {
    await db.vehicle.delete({
        where: {
            id,
        },
    })
}