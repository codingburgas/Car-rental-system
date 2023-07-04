import { db, Role, User } from "../utils/db.server";

type Vehicle = {
  vehicleType: string;
  name: string;
  manufacturer: string;
  model: string;
  isReserved: boolean;
  reservationDate: string;
  location: string;
  price: number;
  reservedById: number | null;
};

const seedData = async () => {
  try {
    const vehicles: Vehicle[] = [
      // Cars
      {
        vehicleType: 'Car',
        name: 'Toyota Camry',
        manufacturer: 'Toyota',
        model: 'Camry',
        isReserved: false,
        reservationDate: '',
        location: '',
        price: 25000,
        reservedById: null
      },
      {
        vehicleType: 'Car',
        name: 'Honda Civic',
        manufacturer: 'Honda',
        model: 'Civic',
        isReserved: false,
        reservationDate: '',
        location: '',
        price: 22000,
        reservedById: null
      },
      {
        vehicleType: 'Car',
        name: 'Ford Mustang',
        manufacturer: 'Ford',
        model: 'Mustang',
        isReserved: false,
        reservationDate: '',
        location: '',
        price: 40000,
        reservedById: null
      },
      {
        vehicleType: 'Car',
        name: 'Chevrolet Camaro',
        manufacturer: 'Chevrolet',
        model: 'Camaro',
        isReserved: false,
        reservationDate: '',
        location: '',
        price: 38000,
        reservedById: null
      },
      
      // Motorcycles
      {
        vehicleType: 'Motorcycle',
        name: 'Honda CB500F',
        manufacturer: 'Honda',
        model: 'CB500F',
        isReserved: false,
        reservationDate: '',
        location: '',
        price: 8000,
        reservedById: null
      },
      {
        vehicleType: 'Motorcycle',
        name: 'Kawasaki Ninja 400',
        manufacturer: 'Kawasaki',
        model: 'Ninja 400',
        isReserved: false,
        reservationDate: '',
        location: '',
        price: 9000,
        reservedById: null
      },
      {
        vehicleType: 'Motorcycle',
        name: 'Yamaha YZF-R6',
        manufacturer: 'Yamaha',
        model: 'YZF-R6',
        isReserved: false,
        reservationDate: '',
        location: '',
        price: 12000,
        reservedById: null
      },
      {
        vehicleType: 'Motorcycle',
        name: 'Suzuki GSX-R750',
        manufacturer: 'Suzuki',
        model: 'GSX-R750',
        isReserved: false,
        reservationDate: '',
        location: '',
        price: 11000,
        reservedById: null
      },
      
      // Trucks
      {
        vehicleType: 'Truck',
        name: 'Ford F-150',
        manufacturer: 'Ford',
        model: 'F-150',
        isReserved: false,
        reservationDate: '',
        location: '',
        price: 35000,
        reservedById: null
      },
      {
        vehicleType: 'Truck',
        name: 'Chevrolet Silverado',
        manufacturer: 'Chevrolet',
        model: 'Silverado',
        isReserved: false,
        reservationDate: '',
        location: '',
        price: 38000,
        reservedById: null
      },
      {
        vehicleType: 'Truck',
        name: 'Toyota Tacoma',
        manufacturer: 'Toyota',
        model: 'Tacoma',
        isReserved: false,
        reservationDate: '',
        location: '',
        price: 32000,
        reservedById: null
      },
      {
        vehicleType: 'Truck',
        name: 'GMC Sierra',
        manufacturer: 'GMC',
        model: 'Sierra',
        isReserved: false,
        reservationDate: '',
        location: '',
        price: 37000,
        reservedById: null
      },
    
      // SUVs
      {
        vehicleType: 'SUV',
        name: 'Jeep Wrangler',
        manufacturer: 'Jeep',
        model: 'Wrangler',
        isReserved: false,
        reservationDate: '',
        location: '',
        price: 30000,
        reservedById: null
      },
      {
        vehicleType: 'SUV',
        name: 'Toyota RAV4',
        manufacturer: 'Toyota',
        model: 'RAV4',
        isReserved: false,
        reservationDate: '',
        location: '',
        price: 28000,
        reservedById: null
      },
      {
        vehicleType: 'SUV',
        name: 'Honda CR-V',
        manufacturer: 'Honda',
        model: 'CR-V',
        isReserved: false,
        reservationDate: '',
        location: '',
        price: 26000,
        reservedById: null
      },
      {
        vehicleType: 'SUV',
        name: 'Ford Explorer',
        manufacturer: 'Ford',
        model: 'Explorer',
        isReserved: false,
        reservationDate: '',
        location: '',
        price: 35000,
        reservedById: null
      },
    
      // Vans
      {
        vehicleType: 'Van',
        name: 'Mercedes-Benz Sprinter',
        manufacturer: 'Mercedes-Benz',
        model: 'Sprinter',
        isReserved: false,
        reservationDate: '',
        location: '',
        price: 45000,
        reservedById: null
      },
      {
        vehicleType: 'Van',
        name: 'Ford Transit',
        manufacturer: 'Ford',
        model: 'Transit',
        isReserved: false,
        reservationDate: '',
        location: '',
        price: 40000,
        reservedById: null
      },
      {
        vehicleType: 'Van',
        name: 'Chevrolet Express',
        manufacturer: 'Chevrolet',
        model: 'Express',
        isReserved: false,
        reservationDate: '',
        location: '',
        price: 42000,
        reservedById: null
      },
      {
        vehicleType: 'Van',
        name: 'Dodge Grand Caravan',
        manufacturer: 'Dodge',
        model: 'Grand Caravan',
        isReserved: false,
        reservationDate: '',
        location: '',
        price: 28000,
        reservedById: null
      }
    ];

    const createdVehicles = await Promise.all(
      vehicles.map((vehicle) => db.vehicle.create({ data: vehicle }))
    );

  } catch (error) {
    console.error('Error inserting seed data:', error);
  } finally {
    // Close the database connection after seeding
    await db.$disconnect();
  }
};

seedData();