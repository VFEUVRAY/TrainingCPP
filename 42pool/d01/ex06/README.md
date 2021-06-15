As pointed by the example, HumanA requires a ctor with both a name and a weapon object.<br>
So the HumanA class is usable only if a weapon object already exists<br>
Since we know the object exists, we can just make a reference to it and not create a second object<br>

HumanB requrie a ctor with only a name<br>
This means that when a humanB object is created, and when calling for any function using the weapon, we have to make sure that there is in fact a weapon<br>
Thus using a pointer to a weapon object structure is ideal<br>
We can initialise this pointer to NULL on ctor, then check if setWeapon has been used by checking in attack() if the weapon pointer is pointing to an actual weapon object<br>