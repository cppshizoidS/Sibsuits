namespace CarProject
{
    public class Car : ICar
    {
        public IFuelTankDisplay fuelTankDisplay;
        private IEngine _engine;
        private IFuelTank _fuelTank;
        public bool EngineIsRunning { get => _engine.IsRunning;}

        public void EngineStart()
        {
            _engine.Start();
        }

        public void EngineStop()
        {
            _engine.Stop();
        }

        public void Refuel(double liters)
        {
            _fuelTank.Refuel(liters);
        }
        public void RunningIdle(){
            _engine.Consume(0.0003);
        }
        public Car()
        {
            _fuelTank = new FuelTank();
            _engine = new Engine(_fuelTank);
            fuelTankDisplay = new FuelTankDisplay(_fuelTank);
        }
        public Car(double liters)
        {
            _fuelTank = new FuelTank(liters);
            _engine = new Engine(_fuelTank);
            fuelTankDisplay = new FuelTankDisplay(_fuelTank);
        }
    }
    
}