#include <iostream>
#include <fstream>

#define GLM_FORCE_RADIANS
#include <glm/glm.hpp>
#include <glm/gtx/string_cast.hpp>

#include "TextureMatrix.h"

using namespace std;
using namespace glm;

TextureMatrix::TextureMatrix()
{
	type = Type::NONE;
	T = mat3(1.0f);
}

TextureMatrix::~TextureMatrix()
{
	
}

void TextureMatrix::setType(const string &str)
{
	if(str.find("Body") != string::npos) {
		type = Type::BODY;
	} else if(str.find("Mouth") != string::npos) {
		type = Type::MOUTH;
	} else if(str.find("Eyes") != string::npos) {
		type = Type::EYES;
	} else if(str.find("Brows") != string::npos) {
		type = Type::BROWS;
	} else {
		type = Type::NONE;
	}
}

void TextureMatrix::update(unsigned int key)
{
	keyToggles[key]++;
	vec3 t = T[2];
	// Update T here
	if(type == Type::BODY) {
		// Do nothing
	} else if(type == Type::MOUTH) {
		// TODO
		if (key == 'm') {
			t.x = 0.1f * (keyToggles[key] % 3);
		}
		if (key == 'M') {
			t.y = -0.1f * (keyToggles[key] % 10);
		}
	} else if(type == Type::EYES) {
		// TODO
		if (key == 'e') {
			t.x = 0.2f * (keyToggles[key] % 3);
		}
		if (key == 'E') {
			t.y = -0.1f * (keyToggles[key] % 10);
		}
	} else if(type == Type::BROWS) {
		// TODO
		if (key == 'b') {
			t.y = -0.1f * (keyToggles[key] % 10);
		}
	}
	T[2] = t;
}
