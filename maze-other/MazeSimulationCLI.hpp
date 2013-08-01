class MazeSimulationCLI {
	public:
		MazeSimulationCLI(MazeSimulation& simulation);
		void show();

	private:
		MazeSimulation* simulation;
}