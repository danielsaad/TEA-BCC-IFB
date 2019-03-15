bool sol = false;
int x, y, z;
for (x = -100; x <= 100; x++)
    for (y = -100; y <= 100; y++)
        for (z = -100; z <= 100; z++)
            // x,y e z devem ser distintos
            if (y != x && z != x && z != y &&
                x + y + z == A && x * y * z == B && 
                x * x + y * y + z * z == C) {
                    if (!sol) 
                        printf("%d %d %d\n", x, y, z);
                    sol = true; 
            }