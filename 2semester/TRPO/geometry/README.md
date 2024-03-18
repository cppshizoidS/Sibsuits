# Лабораторная работа № 3
Geometry
Приложение принимает на вход геометрические фигуры различных типов в WKT-подобном формате.

Для каждой фигуры приложение определяет:

Периметр.

Площадь.

С какими фигурами пересекается текущая.

Поддерживаемые фигуры в зависимости от уровня сложности:

Normal
Окружность, треугольник.

Грамматика (EBNF):
```wkt
Object = 'circle' '(' Point ',' Number ')'
       | 'triangle' '(' '(' Point ',' Point ',' Point ',' Point ')' ')'
    
Point = Number Number
Number = (* Floating-point number *)
```

Типы фигур нечувствительны к регистру (case insensitive).

Между токенами может быть произвольное количество пробельных символов.

Для простоты можно считать, что одна фигура занимает ровно одну строку. В строке не может быть нескольких фигур.

Пример входных данных:
```wkt
triangle((-3.0 -2, -1 0.0, -3.0 2.0, -3 -2))
circle(0 0, 1.5)
triangle((3 -2.0, 3.0 2, 1.0 0, 3.0 -2))
```

Вывод:
```wkt
1. triangle((-3 -2, -1 0, -3 2, -3 -2))
    perimeter =  9.657
    area = 4
    intersects:
      2. circle

2. circle(0 0, 1.5)
    perimeter = 9.4247
    area = 7.0686
    intersects:
      1. triangle
      3. triangle

3. triangle((3 -2, 3 2, 1 0, 3 -2))
    perimeter = 9.657
    area = 4
    intersects:
      2. circle
```
Приложение обрабатывает ошибки
```
circlee(1.0 2.0, 3)
^
Error at column 6: expected '(' or ' ' after figure name

circle(x1 2, 3.0)
       ^
Error at column 7: expected '<double>'


circle(1 2, 3.1(
               ^
Error at column 15: expected ')'


circle(1.0 2.1, 3) 123
                   ^
Error at column 19: unexpected token
```


```sh
cd geometry
./main ../geometry.txt
```
