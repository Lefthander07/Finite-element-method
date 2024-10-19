# Метод конечных элементов
### Как использовать программу?
Реализация метода конечных элементов для решения неоднордных дифференциальных уравнений вида $$A\frac{d^2u}{dx^2}+b\frac{du}{dx} + cu + d = 0$$.
Количество конечных элементов задаются переменными `numberOfElements_1` и `numberOfElements_2`. По умолчанию в задании требуется 20 и 40 элементов, но их количество можно поменять.


Переменные `x_start` и `x_end` задает промежуток на оси _X_. Переменные берутся из ГУ, причем `x_start < x_end`.



