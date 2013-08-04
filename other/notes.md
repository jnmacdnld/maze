# Notes #

These are things which I should revisit later but I left as they were at some
point becase they were not terribly important issues.

SHOULD BE MERGED INTO FILES WITH FIXMEs

*	MazeRobot has accessor methods for MazeRobot.algorithm so that subclasses can 
	access it; is this necessary?
*	VirtualMazeNode consturctor paramaters are ambigious when called (you're 
	supplying a long list of boolean values)
*	It would probably be cleaner to use a map to store VirtalMazeNode info
* The switch statement in VirtualMazeNode::getIsObstructed should throw an exception if a valid Direction is not supplied

find more by running
grep -r "FIXME" .