module;

export module RoguePhysicEngine;
export namespace RoguePhysicEngine
{
	void Init();

	void setStopCallback(void (*cb)(int));

	bool ShouldStop();

	void Terminate();
}