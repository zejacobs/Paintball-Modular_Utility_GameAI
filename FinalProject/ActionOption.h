/*
* The ActionOption class represents a action that can be performed by an enemy
* The ActionOption can take in float functors to determine how desirable and action
* is to perfom and also contains the action's priority rating 
*/
#pragma once

class ActionOption {
	
public:

	virtual const float getEvaluation() const  { return m_Evaluation; }

	virtual const float getPriority() const { return m_Priority; }

protected:
	float m_Evaluation = 0.f;
	int m_Priority = 0;
};