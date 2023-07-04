import { db, Role, User } from "../utils/db.server";
import { userRouter } from "./user.router";
import type { Request, Response } from "express";
import * as userService from "./user.service";

enum RoleTypo {
  CUSTOMER = "CUSTOMER",
  RECEPTIONIST = "RECEPTIONIST",
}

export const listUsers = async (): Promise<User[]> => {
  return db.user.findMany({
    select: {
      id: true,
      name: true,
      contactNumber: true,
      email: true,
      password: true,
      role: true,
    },
  });
}

export const getUser = async (id: number): Promise<User | null> => {
  return db.user.findUnique({
    where: {
      id,
    },
    select: {
      id: true,
      name: true,
      contactNumber: true,
      email: true,
      password: true,
      role: true,
    },
  });
}

export const createUser = async (user: Omit<User, "id">): Promise<User> => {
  const { name, contactNumber, email, password, role } = user;
  return db.user.create({
    data: {
      name,
      contactNumber,
      email,
      password,
      role,
    },
    select: {
      id: true,
      name: true,
      contactNumber: true,
      email: true,
      password: true,
      role: true,
    },
  });
}

export const updateUser = async (user: Omit<User, "id">, id: number): Promise<User> => {
  const { name, contactNumber, email, password, role } = user;
  return db.user.update({
    where: {
      id,
    },
    data: {
      name,
      contactNumber,
      email,
      password,
      role,
    },
    select: {
      id: true,
      name: true,
      contactNumber: true,
      email: true,
      password: true,
      role: true,
    },
  });
}

export const deleteUser = async (id: number): Promise<void> => {
  await db.user.delete({
    where: {
      id,
    },
  });
}
