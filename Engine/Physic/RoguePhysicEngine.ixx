module;

export module RoguePhysicEngine;
import <string>;
export namespace RoguePhysicEngine
{
	void Init();

	void setStopCallback(void (*cb)(int));

	bool ShouldStop();

	void Terminate();

	class Task;

	void AddTask(Task);//TODO:refactor
	void StartTests();
}