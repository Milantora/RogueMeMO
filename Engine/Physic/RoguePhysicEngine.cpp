module;

module RoguePhysicEngine;
import <iostream>;
import <list>;
namespace RoguePhysicEngine
{
	//private fields

	static bool shouldStop;
	void (*stopCallback)(int) = nullptr;
	std::list<Task*> tasks;

	//public classes defines

	class Task
	{
	private:
		static int counter;
	protected:
		std::string name;
	public:
		Task() { name = ("Task_" + std::to_string(++counter)); }
		Task(std::string name) : name(name) {}
		virtual void operator()() = 0;
	};
	int Task::counter;

	//private classes

	class TestTask : public Task
	{
	private:
		int t = 0, it = 0, mt = 0;
	protected:

	public:
		TestTask(int max) : Task(), mt(max) {}
		TestTask(std::string name, int max) : Task(name), mt(max) {}
		TestTask(const TestTask& other) : Task(other.name), mt(other.mt)
		{
			name = other.name + "_C";
		}
		TestTask& operator=(const TestTask& other)
		{
			name = other.name + "_D";
			t = other.t;
			it = other.it;
			mt = other.mt;
			return *this;
		}

		void operator()() override
		{
			++t;
			if (t == mt)
			{
				std::cout << ++it << " iteration of " << name << "\n";
				t /= mt;
			}
		}
	};
	
	//private methods declarations
	
	
	//public methods defines
	void AddTask(Task* task)
	{
		tasks.push_back(task);
	}

	void StartTests()
	{
		TestTask* tt0 = new TestTask(50'000'000);
		TestTask* tt1 = new TestTask("TestTask", 30'000'000);
		TestTask* tt2 = new TestTask(*tt1);
		TestTask* tt3 = new TestTask(1);
		*tt3 = *tt0;
		TestTask* tt4 = new TestTask(10'000'000);
		AddTask(tt0);
		AddTask(tt1);
		AddTask(tt2);
		AddTask(tt3);
		AddTask(tt4);
		std::cout << "Tasks succefully initializated!\n";
	}

	void Init() 
	{
		std::cout << "Physic Engine running!\n";
		while (!ShouldStop())
		{
			for (const auto& task : tasks)
			{
				(*task)();
			}
		}
		for (const auto& task : tasks)
		{
			delete task;
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