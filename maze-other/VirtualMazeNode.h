class VirtualMazeNode {
	public:
		VirtualMazeNode(bool northIsObstructed, bool eastIsObstructed,
										bool southIsObstructed, bool westIsObstructed,
										bool isStart, bool isFinish);
		getIsObstructed(Direction dir);
		getIsStart();
		getIsFinish();

		static VirtualMazeNode textfileToNodes(string path); // FIXME: Might be an
																												 // error here

	private:
		bool northIsObstructed;
		bool eastIsObstructed;
		bool southIsObstructed;
		bool westIsObstructed;

		bool isStart;
		bool isFinish;
}