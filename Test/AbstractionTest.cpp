#include "pch.h"
#include "CppUnitTest.h"
#include "AbstractMoving.h"
#include "AbstractMoving.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace AbstractionTest
{
	TEST_CLASS(AbstractionTest)
	{
	public:

		TEST_METHOD(MovingObjEx)
		{
			std::map<std::string, std::any> spaceshipData;

			spaceshipData["position"] = Vector(1, 2);
			spaceshipData["velocity"] = 1;
			spaceshipData["direction"] = 0;
			spaceshipData["directionsNumber"] = 8;

			Spaceship* spaceship = new Spaceship(spaceshipData);

			MovableAdp moveAd(spaceship);
			moveAd.setPosition({ 1, 2 });

			MovingObj move(moveAd);

			move.execute();
			Vector returnValue = moveAd.getPosition();

			Assert::IsTrue(returnValue == Vector(2, 2));
		}

		TEST_METHOD(RotatingObjEx)
		{
			std::map<std::string, std::any> spaceshipData;

			spaceshipData["angularVelocity"] = 1;
			spaceshipData["direction"] = 0;

			Spaceship* spaceship = new Spaceship(spaceshipData);

			RotatableAdp rotateAd(spaceship);
			rotateAd.setDirection(0);

			RotatingObj rotate(rotateAd);

			rotate.execute();
			int returnValue = rotateAd.getDirection();

			Assert::IsTrue(returnValue == 1);
		}
	};
}
