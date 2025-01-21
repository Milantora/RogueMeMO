module;
import <string>;

export module RogueGraphicEngine;
export namespace RogueGraphicEngine
{
	void Init(std::string name, int w, int h);

	void setStopCallback(void (*cb)(int));
	
	bool ShouldStop();

	void Terminate();
}