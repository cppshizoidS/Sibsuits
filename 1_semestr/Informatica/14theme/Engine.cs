namespace CarProject
{
    public class Engine : IEngine
    {
        private IFuelTank _fuelTank;
    
        private bool _isRunning = false;
        public bool IsRunning {get => _isRunning;}
        public void Consume(double liters)
        {
            _fuelTank.Consume(liters);
            if (_fuelTank.FillLevel == 0.0)
            {
                _isRunning = false;
            }
        }
        public void Start()
        {
            if (_fuelTank.FillLevel > 0)
                _isRunning = true;
        }

        public void Stop()
        {
            _isRunning = false;
        }
        public Engine(IFuelTank fuelTank)
        {
            _fuelTank = fuelTank;
        }
    }
}