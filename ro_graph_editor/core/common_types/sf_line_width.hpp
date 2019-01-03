#pragma once
#include <SFML/Graphics.hpp>
#include <cmath>
#include <utility>
#include <memory>
#include <algorithm>


namespace sf{

	class LineShape: public Drawable{
	public:

		int PHISIC_EPSILON = 1;
		int id;

		LineShape(int _id, float _width = 1, Vector2f init_A = {0,0}, Vector2f init_B = {1,1}, Color _color = {0,255,0}, float add_offset = 0):
			id(_id),
			width(_width),
			A(init_A),
			B(init_B)
			{
				setColor(_color);
				setAdditionalOffset(add_offset);
			}

		void setA(Vector2f vec){
			A = vec;
		}

		void setB(Vector2f vec){
			B = vec;
		}

		void setColor(Color col){
			for(int i = 0; i < 4; i++)
               line[i].color = col;
		}

		void setAdditionalOffset(float offset){
			aditional_offset = offset;
		}

		void update(){
			sf::Vector2f direction = A - B;
            sf::Vector2f unitDirection = direction/std::sqrt(direction.x*direction.x+direction.y*direction.y);
            sf::Vector2f unitPerpendicular(-unitDirection.y,unitDirection.x);

            sf::Vector2f offset = (width/2.f)*unitPerpendicular;

            line[0].position = A + offset;
            line[1].position = B + offset;
            line[2].position = B - offset;
            line[3].position = A - offset;

            for(int i = 0; i < 4; i++){
                line[i].position += offset * aditional_offset;
            }

            A = line[0].position;
            B = line[1].position;

		}


		bool phisic_isInLine(sf::Vector2f point) const{
			return ( magnitude(A-point) + magnitude(B-point) - magnitude(A-B) ) <= PHISIC_EPSILON;
		}

	private:

		double magnitude(const sf::Vector2f& vec) const{
            return sqrt(vec.x * vec.x + vec.y * vec.y);
        }

		float width;
		float aditional_offset = 0;

		Vector2f A;
		Vector2f B;


		
		Vertex line[4];

		void draw(sf::RenderTarget& target,sf::RenderStates states)const override{
			target.draw(line, 4, sf::Quads);
		}

	};



};