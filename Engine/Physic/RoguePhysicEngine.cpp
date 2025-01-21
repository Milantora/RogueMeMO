module;

module RoguePhysicEngine;
import <iostream>;
namespace RoguePhysicEngine
{
	//private fields

	static bool shouldStop;
	void (*stopCallback)(int) = nullptr;

	//public fields


	//private methods


	//public methods defines

	void Init() 
	{
		std::cout << "Physic Engine running!\n";
		while (!ShouldStop())
		{

		}
	}

	void setStopCallback(void (*cb)(int))
	{
		stopCallback = cb;
	}
	
	bool ShouldStop()
	{
		return shouldStop;
	}
	
	void Terminate() 
	{
		shouldStop = true;
		std::cout << "Physic Engine ded :<\n";
		stopCallback(1);
	}

	//private methods defines


}