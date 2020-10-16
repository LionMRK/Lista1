#include "test.h"
#include <time.h>

float restitution2 = 0.0;
float friction2 = 0.0;
bool Ex4 = false;
bool Ex5 = false;


class Lista1 : public Test //você cria a sua classe derivada da classe base Test
{
public:
	Lista1() {

		
	}

	void Step(Settings& settings) override
	{
		//Chama o passo da simulação e o algoritmo de rendering
		Test::Step(settings);

		//show some text in the main screen
		g_debugDraw.DrawString(5, m_textLine, "Exercicios, utilize as teclas dos respectivos exercicios: '1', '2' + G,  3 - 'B' 'C' 'L' , '4' + 'B' , '5' , etc...");
		m_textLine += 15;

	}

	static Test* Create()  //a classe Test que instancia um objeto da sua nova classe
						   //o autor da Box2D usa um padrão de projeto chamado Factory
						   //para sua arquitetura de classes
	{
		
		return new Lista1;
	}

	//Para interagir com o teclado
	void Keyboard(int key) override //esse cabeçalho nao mudam
	{
		
		switch (key)
		{
			
			//Exercicio 1
		case GLFW_KEY_1:

			CreateBox(b2Vec2(rand() % 80 - 40, rand() % 45), b2Vec2(rand() % 7 + 1, rand() % 7 + 1), 0.5, 0.5, 0.5);

			CreateCircle(b2Vec2(rand() % 80 - 40, rand() % 45), rand() % 5 + 1, 0.5, 0.5, 0.5);

			CreateLine(b2Vec2(rand() % 60 - 40, rand() % 45), b2Vec2(rand() % 7 + 1, rand() % 7 + 1), b2Vec2(rand() % 7 + 1, rand() % 7 + 1), 0.5, 0.5, 0.5);

			break;

			//Exercicio 2
		case GLFW_KEY_2:

			CreateBox(b2Vec2(0.0, -3.8), b2Vec2(46.0, 1.0), 1.0, 0.5, 0.5, b2_staticBody); //bottom wall

			CreateBox(b2Vec2(0.0, 45.0), b2Vec2(46.0, 1.0), 1.0, 0.5, 0.5, b2_staticBody); // top wall

			CreateBox(b2Vec2(45.0, 20.5), b2Vec2(1.0, 25.5), 1.0, 0.5, 0.5, b2_staticBody); // right wall

			CreateBox(b2Vec2(-45.0, 20.5), b2Vec2(1.0, 25.5), 1.0, 0.5, 0.5, b2_staticBody); //left wall

			CreateBox(b2Vec2(0.0, 20.0), b2Vec2(4.0, 4.0), 1.0, 0.5, 0.5); // Press "G" to change gravity

			break;

			//Inicio Exercicio 3
		case GLFW_KEY_B:
			

			//CreateBox(b2Vec2(rand() % 80 - 40, rand() % 45), b2Vec2(rand() % 7 + 1, rand() % 7 + 1), 0.5, 0.5, 0.5);

			if (Ex5 == true)
			{
				CreateBox(b2Vec2(-40, 32), b2Vec2(1.0, 1.0), 0.5, friction2, 0.5);
				friction2 += 0.1;
				
			}
			else if(Ex4 == true)
			{
				CreateBox(b2Vec2(rand() % 80 - 40, rand() % 25 + 20), b2Vec2(rand() % 3 + 1, rand() % 3 + 1), 0.5, 0.5, restitution2);
				restitution2 += 0.1;
			}
			else
			{
				CreateBox(b2Vec2(rand() % 80 - 40, rand() % 25 + 20), b2Vec2(rand() % 3 + 1, rand() % 3 + 1), 0.5, 0.5, 0.5);
			}

				break;

		case GLFW_KEY_C:

			CreateCircle(b2Vec2(rand() % 80 - 40, rand() % 45), rand() % 5 + 1, 0.5, 0.5, 0.5);

			break;

		case GLFW_KEY_L: 

			CreateLine(b2Vec2(rand() % 60 - 40, rand() % 45), b2Vec2(rand() % 7 + 1, rand() % 7 + 1), b2Vec2(rand() % 7 + 1, rand() % 7 + 1), 0.5, 0.5, 0.5);
			
			
			break;
			//Exercicio 3 fim
			
			//Exercicio 4
		case GLFW_KEY_4:

			if (Ex4 == false)
			{
				Ex4 = true;
				Ex5 = false;
			}
			else
			{
				Ex4 = false;
			}

			/*for (float i = 0; i <= 1.0; i+=0.1)
			{
				CreateBox(b2Vec2(0.0, 20.0), b2Vec2(1.0, 1.0), 1.0, 0.5, i);
			}*/
			
			break;

			//Exercicio 5
		case GLFW_KEY_5:

			if (Ex5 == false)
			{
				Ex5 = true;
				CreateLine(b2Vec2(-42, 30), b2Vec2(0, 0), b2Vec2(40, -30), 0.5, 0.5, 0.5);
				Ex4 = false;
			}
			else
			{
				Ex5 = false;
			}

			

			break;

			//Exercicio 6
		case GLFW_KEY_6:

			for (float i = 0, l = 5.0; i < 6; i++, l+=5.0)
			{
				CreateBox(b2Vec2(0.0, l), b2Vec2(1.0, 1.0), 1.0, 0.5, 0.1);

				CreateCircle(b2Vec2(20.0, l), 3.0, 1.0, 0.5, 0.1);
			}

			break;

			//Exercicio 7
		case GLFW_KEY_7:

			for (float i = 0, c = 0.0; i < 10; i++, c+= 2.3)
			{
				for (float m = 0, l = 0.0; m < 10; m++, l+=2.1)
				{
					CreateBox(b2Vec2(l, c), b2Vec2(1.0, 1.0), 1.0, 0.5, 0.1);
				}
			}

			break;

		case GLFW_KEY_8:


			break;

		case GLFW_KEY_G:

			if (m_world->GetGravity().y < 0)
			{
				m_world->SetGravity(b2Vec2(0.0, 50.0));
			}
			else
			{
				m_world->SetGravity(b2Vec2(0.0, -50.0));
			}

			
			break;

		}
	}


	b2Body* CreateBox(b2Vec2 pos, b2Vec2 dim, float density, float friction, float restitution, b2BodyType = b2_dynamicBody);
	b2Body* CreateCircle(b2Vec2 pos, float radius, float density, float friction, float restitution, b2BodyType = b2_dynamicBody);
	b2Body* CreateLine(b2Vec2 pos, b2Vec2 inicio, b2Vec2 fim, float density, float friction, float restitution, b2BodyType = b2_dynamicBody);
};

//Aqui fazemos o registro do novo teste 
static int testIndex = RegisterTest("Examples", "Lista1", Lista1::Create);

b2Body* Lista1::CreateBox(b2Vec2 pos, b2Vec2 dim, float density, float friction, float restitution, b2BodyType type)
{
	b2Body* newBox;

	//Definição dos atributos gerais do corpo rígido
	b2BodyDef boxDef;

	boxDef.position = pos;
	boxDef.type = type;

	//Criação da forma do corpo*
	b2PolygonShape boxShape;

	boxShape.SetAsBox(dim.x, dim.y);

	//Definição da fixture
	b2FixtureDef boxFix;

	boxFix.shape = &boxShape;
	boxFix.density = density;
	boxFix.friction = friction;
	boxFix.restitution = restitution;

	//Criação do corpo rígido pelo mundo e da fixture pelo corpo rígido;
	newBox = m_world->CreateBody(&boxDef);
	newBox->CreateFixture(&boxFix);


	return newBox;
}

b2Body* Lista1::CreateCircle(b2Vec2 pos, float radius, float density, float friction, float restitution, b2BodyType type)
{
	b2Body* newCircle;

	//Definição dos atributos gerais do corpo rígido
	b2BodyDef circleDef;

	circleDef.position = pos;
	circleDef.type = type;


	//Criação da forma do corpo*
	b2CircleShape circleShape;

	circleShape.m_radius = radius;


	//Definição da fixture
	b2FixtureDef circleFix;

	circleFix.shape = &circleShape;
	circleFix.density = density;
	circleFix.friction = friction;
	circleFix.restitution = restitution;

	//Criação do corpo rígido pelo mundo e da fixture pelo corpo rígido;
	newCircle = m_world->CreateBody(&circleDef);
	newCircle->CreateFixture(&circleFix);

	return newCircle;
}

b2Body* Lista1::CreateLine(b2Vec2 pos, b2Vec2 inicio,  b2Vec2 fim, float density, float friction, float restitution, b2BodyType type)
{
	b2Body* newLine;

	b2BodyDef lineDef;

	lineDef.position = pos;
	lineDef.type = type;

	b2EdgeShape lineShape;

	lineShape.SetTwoSided(inicio, fim);

	b2FixtureDef lineFix; 

	lineFix.shape = &lineShape;
	lineFix.density = density;
	lineFix.friction = friction;
	lineFix.restitution = restitution;

	newLine = m_world->CreateBody(&lineDef);
	newLine->CreateFixture(&lineFix);

	return newLine;

}

