#!/usr/bin/env bash
for COUNTER in {134000..150000..1000}
do
    printf "%s" "$COUNTER" >> Wynik.txt
    ./Generator.x $COUNTER 1000000 | ./BubbleSort.x >> Wynik.txt
    printf "%s" "$COUNTER" >> Wynik2.txt
    ./Generator.x $COUNTER 1000000 | ./SelectionSort.x >> Wynik2.txt
    printf "%s" "$COUNTER" >> Wynik3.txt
    ./Generator.x $COUNTER 1000000 | ./InsertionSort.x >> Wynik3.txt
done