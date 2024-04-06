# Geometry

Приложение для парсинга входных данных в формате WKT поиска их периметра,
площади и поиска пересечений между фигурами. Приложение обрабатывает не
корректный ввод и указывает место ошибки

```sh
❯ ./geometry test.txt

circle((0 0, 1.5)

       ^
Error at column 7: expected ')'
```

Грамматика EBFN

```
Object = 'circle' '(' Point ',' Number ')'
       | 'triangle' '(' '(' Point ',' Point ',' Point ',' Point ')' ')'
       | 'polygon' '(' '(' Point ',' Point ',' Point {',' Point } ')' ')'
Point = Number Number
Number = (* Floating-point number *)
```

# How to run

```sh
make
./bin/geometry exemple/test.txt
```