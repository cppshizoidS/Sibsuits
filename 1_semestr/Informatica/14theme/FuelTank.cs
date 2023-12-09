namespace CarProject
{
    public class FuelTank : IFuelTank
    {
        private double _fillLevel;
        public double FillLevel {get => _fillLevel;}
        public bool IsOnReserve {get => _fillLevel <= 5.0;}
        public bool IsComplete {get => _fillLevel == 60.0;}
        public void Consume(double liters)
        {
            if (_fillLevel < liters)
            {
                _fillLevel = 0.0;
            }
            else{
                _fillLevel -= liters;
            }
        }

        public void Refuel(double liters)
        {
            _fillLevel +=liters;
            if (_fillLevel > 60.0)
                _fillLevel = 60;
        }
        public FuelTank()
        {
            _fillLevel = 20.0;
        }
        public FuelTank(double liters)
        {
            _fillLevel = Math.Clamp(liters, 0.0,60.0);
        }
    }
}