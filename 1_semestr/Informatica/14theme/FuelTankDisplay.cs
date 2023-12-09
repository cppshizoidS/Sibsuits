namespace CarProject
{
    public class FuelTankDisplay : IFuelTankDisplay
    {
        private IFuelTank _fuelTank;
        public double FillLevel {get => _fuelTank.FillLevel;}
        public bool IsOnReserve {get => _fuelTank.IsOnReserve;}
        public bool IsComplete {get => _fuelTank.IsComplete;}
        public FuelTankDisplay(IFuelTank fuelTank)
        {
            _fuelTank = fuelTank;
        }
    }
}