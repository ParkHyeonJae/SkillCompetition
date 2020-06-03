#pragma once
class IGameObject
{
public:
	virtual ~IGameObject() {};

	virtual void FrameMove(DWORD elapsed) = 0;
	virtual void Render() = 0;
	virtual void Control(CInput* Input) = 0;	//07
};

