*this project has been created as part of the 42 curriculum by keblanch, lcohen*

# push_swap

## Description

Push swap is a project about creating a sorting algorithm in a specific context: two stacks are used with a specific set
of instructions: push (from one stack to another), swap (the firsst two elements of a stack) and rotate (shift up or
down all elements in a stack). The push_swap progam calculates an algorithm and outputs it as a series of instruction in
push_swap language:

- pa: push from B to A
- pb: push from A to B
- sa: swap A
- sb: swap B
- ss: swap A and B
- ra: rotate A up
- rb: rotate B up
- rr: rotate A and B up
- rra: rotate A down
- rrb: rotate B down
- rrr: rotate A and B down

The program includes 3 algorithms, one for simple (O(n²)) complexity, one for medium (O(n√n)) complexity and one for
complex (O(n log n)) complexity.

The program will also calculate the disorder of the given stack, as a value between 0 and 1; 0 meaning a sorted stack
and 1 being the most unordered stack.

A benchmark mode allows us to view metrics about the execution:
- disorder
- strategy
- nb of operations
- nb for each operation type

## Instructions

To create the executable program, run `make`.

You can then use the program using `./push_swap [OPTION] ...`

The program takes a list of integers representing stack A (the first argument is on the top of the stack)

The options are:
- Strategy selector
  - `--adaptive` *default*: selects the best algorithm depending of disorder
  - `--simple`: selects the simple algorithm, independant of disorder
  - `--medium`: selects the simple algorithm, independant of disorder
  - `--complex`: selects the simple algorithm, independant of disorder
- `--bench`: use the benchmark. Benchmark output is sent to the error output

## Resources:

- [Previous attempt at 42 by keblanch](https://github.com/42-kblanche/push_swap)

