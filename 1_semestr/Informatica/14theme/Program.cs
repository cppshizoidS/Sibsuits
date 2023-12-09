using CarProject;

var car = new Car();
if (car.EngineIsRunning)
{
    Console.WriteLine("Engine could not be running. Programm.cs: 3");
}
car.EngineStart();
if (car.EngineIsRunning == false)
{
    Console.WriteLine("Engine should be running. Programm.cs: 9");
}
car.EngineStop();
if (car.EngineIsRunning)
{
    Console.WriteLine("Engine could not be running. Programm.cs: 15");
}
car = new Car(1);
car.EngineStart();
Enumerable.Range(0, 3000).ToList().ForEach(s => car.RunningIdle());
if (Math.Abs(0.10 - car.fuelTankDisplay.FillLevel) > 0.001)
{
    Console.WriteLine("Wrong fuel tank fill level! Programm.cs: 21-23");
}
car = new Car(60);
if (car.fuelTankDisplay.IsComplete == false)
{
    Console.WriteLine("Fuel tank must be complete! Programm.cs: 29");
}
car = new Car(4);
if (car.fuelTankDisplay.IsOnReserve == false)
{
    Console.WriteLine("Fuel tank must be on reserve! Programm.cs: 35");
}
car = new Car(5);
car.Refuel(40);
if (Math.Abs(45 - car.fuelTankDisplay.FillLevel) > 0.001)
{
    Console.WriteLine("Wrong fuel tank fill level! Programm.cs: 41-42");
}
Console.WriteLine("Tests are done!");
