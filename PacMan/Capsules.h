#pragma once
#include <SFML/Graphics.hpp>

//sfml already has a class circleShape
//and capsules are circleShapes (dots) which Pacman eats

sf::CircleShape createDot();
sf::CircleShape createBigDot();