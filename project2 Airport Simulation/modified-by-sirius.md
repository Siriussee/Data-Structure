# some mod by sirius

## static mod

- user can load a preset data from preset-data.txt
- preset-data.txt can be modify in text editor
- preset-data.txt can be reset by using the `commented` code
- only modify `main.cpp` in this mod

```c++
//some preset data
end_time = 1000;
queue_limit = 5;
arrival_rate = departure_rate = 0.48;

//output of default preset
Total number of planes processed 917
Total number of planes asking to land 437
Total number of planes asking to take off 480
Total number of planes accepted to landing 437
Total number of planes accepted to take off 442
Total number of planes refused for landing 0
Total number of planes refused for takeoff 38
Total number of planes that landed 437
Total number of planes that took off 438
Total number of planes that left in landing queue 0
Total number of planes left in takeoff queue 4
Percentage of time runway idle 12.5%
Average wait in landing queue 3.71854 time units
Average wait in takeoff queue 3.71005 time units
Average observed rate of planes wanting to land0.437 per time unit
Average observed rate of planes wanting to take off 0.48 per time unit
```

## debug mod

- user can enable debug mod 
- only modify `main.cpp` in this mod

```c++
Enable debug mode? (y/n)y
---        debug toolkits help     ---
--- [n] - next time unit           ---
--- [b] - set beark point          ---
--- [c] - continue until end or bp ---
```

- enter n (or whatever char youl ike) to next time unit
- enter b and an int to set a breakpoint (invaild bp will pause the program)
- enter c to contine to the end or the next breakpoint
 