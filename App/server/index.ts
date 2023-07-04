import * as dotenv from "dotenv"
import express from "express"
import cors from "cors"

import { userRouter } from "./user/user.router";
import { logRouter } from "./logging/logs.router";
import { vehicleRouter } from "./vehicle/vehicle.router";
dotenv.config();

if(!process.env.PORT)
{
    process.exit(1)
}

const PORT: number = parseInt(process.env.PORT as string, 10)

const app = express()

app.use(cors())
app.use(express.json())

app.use("/api/users", userRouter);
app.use("/api/vehicles", vehicleRouter);
app.use("/api/logs", logRouter);

app.listen(PORT, () => {
    console.log(`Listening on port ${PORT}`)
})