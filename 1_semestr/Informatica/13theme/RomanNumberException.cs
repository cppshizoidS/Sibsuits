using System;

namespace RomanNumber.Models
{
    public class RomanNumberException : Exception
    {
        public RomanNumberException(string message) : base(message)
        {
        }
    }
}
