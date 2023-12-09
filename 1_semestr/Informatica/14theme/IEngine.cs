namespace CarProject
{
    public interface IEngine
    {
        bool IsRunning { get; }
        void Consume(double liters);
        void Start();
        void Stop();
    }
}