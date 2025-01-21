module;
import RogueGraphicEngine;
import RoguePhysicEngine;
import <iostream>;
import <string>;
import <thread>;

namespace RGE = RogueGraphicEngine;
namespace RPE = RoguePhysicEngine;

module RogueEngine;
namespace RogueEngine
{
	bool shouldStop = false;
	/// <summary>
	/// 
	/// </summary>
	/// <param name="x">RGE 0 RPE 1</param>
	void Stop(int x)
	{
		if (!shouldStop)
		{
			switch (x)
			{
			case 0:
				shouldStop = true;
				RPE::Terminate();
				break;
			case 1:
				shouldStop = true;
				RGE::Terminate();
				break;
			}
		}
	}

	void Start()
	{
		RGE::setStopCallback(&Stop);
		RPE::setStopCallback(&Stop);
		std::string name;
		std::cout << "Please enter name of window: ";
		std::getline(std::cin, name);
		name = name.empty() ? "Unnamed" : name;
		std::thread Graphic(RGE::Init, name, 800, 600);
		std::thread Physic(RPE::Init);
		while (!RPE::ShouldStop() || !RGE::ShouldStop())
		{

		}
		Graphic.join();
		Physic.join();
	}
}