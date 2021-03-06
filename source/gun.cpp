/*
Static
(c) 2016
Author: David Erbelding
Written under the supervision of David I. Schwartz, Ph.D., and
supported by a professional development seed grant from the B. Thomas
Golisano College of Computing & Information Sciences
(https://www.rit.edu/gccis) at the Rochester Institute of Technology.
This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or (at
your option) any later version.
This program is distributed in the hope that it will be useful, but
WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
General Public License for more details.
You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

// Includes
#include "..\header\gun.h"
#include <iostream>

// Magazine constructor:
Magazine::Magazine(int bulletsinitial, int bulletsCapacity) :
    bullets(bulletsinitial),    // Since capacity is const, it actually has to be set in the intializer list.
    capacity(bulletsCapacity)   // If it isn't the compiler will complain at you for not having a guarenteed value.
{
}

// This is the constructor definition for the gun class.
Gun::Gun(Magazine m) : mag(m)
{
    std::cout << "Gun Created: " << mag.bullets << "/" << mag.capacity << std::endl;
}

// Definition for the gun destructor.
Gun::~Gun()
{
    std::cout << "Gun Destructed" << std::endl;
}


// Function defintion for firing the gun:
void Gun::Fire(int numTimes)
{
    for (int i = 0; i < numTimes; i++)
    {
        if (IsLoaded())
        {
            // If there are bullets, fire the gun.
            mag.bullets--;
            std::cout << "BANG!" << std::endl;
            shotsFired++;                       // the static variable can be easily modified from within the class.
        }
        else
        {
            // If there are no bullets, click instead.
            std::cout << "click" << std::endl;
        }
    }
}

// Reloads the magazine.
void Gun::Reload()
{
    std::cout << "Reload" << std::endl;
    mag.bullets = mag.capacity;
}


// Returns true if the magazine has more than 0 bullets.
bool Gun::IsLoaded() const  // Has to be const just like in the header, or the compiler won't know they go together.
{
    return mag.bullets > 0;
}

int Gun::shotsFired = 0;


// Static members are defined just like regular member functions.
int Gun::ShotsFired()
{
    // You can't access the this pointer, because there is no associated object.
    // That means you can't access non-static members either.

    return shotsFired;  // What we can do, is access other static members, (or stuff involving objects passed into the parameters if there are any)
}

