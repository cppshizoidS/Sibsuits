using System;
using System.Collections.Generic;
using System.Linq;

namespace RomanNumber.Models
{
    public class RomanNumber : ICloneable, IComparable
    {
        private static readonly Dictionary<char, int> RomanNumeralMap = new Dictionary<char, int>
        {
            {'I', 1},
            {'V', 5},
            {'X', 10},
            {'L', 50},
            {'C', 100},
            {'D', 500},
            {'M', 1000}
        };

        private ushort _value;
        //Конструктор получает число n, которое должен представлять объект класса
        public RomanNumber(ushort n)
        {
            if (n < 1 || n > 3999)
            {
                throw new RomanNumberException("Value must be in the range [1; 3999]");
            }

            _value = n;
        }
        //Сложение римских чисел
        public static RomanNumber Add(RomanNumber? n1, RomanNumber? n2)
        {
            if (n1 == null || n2 == null)
            {
                throw new RomanNumberException("Cannot perform addition with null operands");
            }

            return new RomanNumber((ushort)(n1._value + n2._value));
        }

        public static RomanNumber operator +(RomanNumber? n1, RomanNumber? n2)
        {
            return Add(n1, n2);
        }
        //Вычитание римских чисел
        public static RomanNumber Sub(RomanNumber? n1, RomanNumber? n2)
        {
            if (n1 == null || n2 == null)
            {
                throw new RomanNumberException("Cannot perform subtraction with null operands");
            }

            if (n1._value < n2._value)
            {
                throw new RomanNumberException("Result of subtraction cannot be negative");
            }

            return new RomanNumber((ushort)(n1._value - n2._value));
        }

        public static RomanNumber operator -(RomanNumber? n1, RomanNumber? n2)
        {
            return Sub(n1, n2);
        }
        //Умножение римских чисел
        public static RomanNumber Mul(RomanNumber? n1, RomanNumber? n2)
        {
            if (n1 == null || n2 == null)
            {
                throw new RomanNumberException("Cannot perform multiplication with null operands");
            }

            return new RomanNumber((ushort)(n1._value * n2._value));
        }

        public static RomanNumber operator *(RomanNumber? n1, RomanNumber? n2)
        {
            return Mul(n1, n2);
        }
        //Целочисленное деление римских чисел
        public static RomanNumber Div(RomanNumber? n1, RomanNumber? n2)
        {
            if (n1 == null || n2 == null)
            {
                throw new RomanNumberException("Cannot perform division with null operands");
            }

            if (n2._value == 0)
            {
                throw new RomanNumberException("Cannot divide by zero");
            }

            return new RomanNumber((ushort)(n1._value / n2._value));
        }

        public static RomanNumber operator /(RomanNumber? n1, RomanNumber? n2)
        {
            return Div(n1, n2);
        }
        //Возвращает строковое представление римского числа, например, "XX" для числа двадцать
        public override string ToString()
        {
            return ToRoman(_value);
        }
        //Реализация интерфейса IClonable
        public object Clone()
        {
            return new RomanNumber(_value);
        }
        //Реализация интерфейса IComparable
        public int CompareTo(object? obj)
        {
            if (obj == null)
            {
                throw new ArgumentNullException(nameof(obj));
            }

            if (!(obj is RomanNumber other))
            {
                throw new ArgumentException("Object is not a RomanNumber");
            }

            return _value.CompareTo(other._value);
        }

        private static string ToRoman(int number)
        {
            if (number < 1 || number > 3999)
            {
                throw new RomanNumberException("Value must be in the range [1; 3999]");
            }

            var result = "";
            foreach (var pair in RomanNumeralMap.OrderByDescending(x => x.Value))
            {
                while (number >= pair.Value)
                {
                    result += pair.Key;
                    number -= pair.Value;
                }
            }

            return result;
        }
    }
}
