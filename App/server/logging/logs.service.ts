import { db, Role, User } from "../utils/db.server";
import { logRouter } from "./logs.router";
import type { Request, Response } from "express";
import { request } from "http";

import * as logService from "./logs.service";

type Log = {
  id: number
  userId: number | null
  vehicleId: number | null
};

export const listLogs = async (): Promise<Log[]> => {
  return db.log.findMany({
    select: {
      id: true,
      userId: true,
      vehicleId: true,
    },
  });
};

export const getLog = async (userId: number): Promise<Log[] | null> => {
  return db.log.findMany({
    where: {
      userId,
    },
    select: {
      id: true,
      userId: true,
      vehicleId: true,
    },
  });
};

export const createLog = async (log: Omit<Log, "id">): Promise<Log> => {
  const { userId, vehicleId } = log;
  return db.log.create({
    data: {
      userId,
      vehicleId,
    },
    select: {
      id: true,
      userId: true,
      vehicleId: true,
    },
  });
};

export const updateLog = async (log: Omit<Log, "id">, id: number): Promise<Log> => {
  const { userId, vehicleId } = log;
  return db.log.update({
    where: {
      id,
    },
    data: {
      userId,
      vehicleId,
    },
    select: {
      id: true,
      userId: true,
      vehicleId: true,
    },
  });
};

export const deleteLog = async (id: number): Promise<void> => {
  await db.log.delete({
    where: {
      id,
    },
  });
};
