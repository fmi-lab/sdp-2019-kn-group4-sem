### Свързан списък

Задача: Моном е израз от вида `a * x^n`, където коефициентът `а` е реално число, а степента `n` е цяло неотрицателно число. Полином наричаме сума от такива мономи.

1. Дефинирайте подходяща структура, която да описва моном.
1. Дефинирайте подходящ клас Полином, представен като едносвързан списък от мономи.
1. Реализирайте член-функции, които намират:
     * стойността на полином в точка
     * сумата на полином с друг полином
     * произведението на полином с моном
     * произведението на два полинома
     * резултатът от деленето на два полинома с частно и остатък (с предефиниране съответно на оператор / и оператор %)
     * еквивалентен полином в нормален вид (т.е. за всяка степен да има точно по един моном в представянето - например `2*x^3 + 3*x + x^3 + x + 4` да се приведе до `3*x^3 + 4*x + 4`)
     * производна на полином

Да се напишат подходящи тестове за всяка от горните точки.

### std::list
Задача: Да се имплементират следните функции върху списъци:
  * `list<list<T>> chunk(list<T>& l, int size)` - по зададен списък разделя елементите му в нови списъци, всеки от които с големина size
  * `void drop(list<T>& l, int numElements)` - премахва първите `numElements` от списъка
  * `void differenceBy(list<T>& l1, list<T>& l2, bool (*comparator)(const T& el1, const T& el2)` - премахва от първия списък елементите, които се срещат във втория, като елементите се сравняват не с ==, а със зададения компаратор
  * `list<T> flatten(list<list<T>>& l)` - по зададен списък от списъци връща списък, съдържащ всички елементи на списъците
  * `list<T> union(list<list<T>>& l)` - по зададен списък от списъци връща списък, съдържащ всички елементи на списъците с премахнати дубликати

### Итератори

Задача: За класа LinkedList, имплементиран на лекции, да се дефинират итератори, които обхождат:
  * Само елементите на четни индекси
  * Само елементите, изпълняващи даден предикат (зададен при създаването на итератора)

Бонус Задача: Да се имплементира функция `<подходящ тип> range(int start, int end, int step)`, която да може да се използва по следния начин:

```
for (int number : range(10, 20, 3))
{
   cout << number << " ";
}
```
и очакваният изход е `10 13 16 19`, т.е. генерира редица от числа през step, започваща от start и приключваща преди end.
