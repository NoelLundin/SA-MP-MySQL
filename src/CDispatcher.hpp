#pragma once

#include "CSingleton.hpp"

#include <queue>
#include <boost/thread/mutex.hpp>

#include "types.hpp"


class DLL_API CDispatcher : public CSingleton < CDispatcher >
{
	friend class CSingleton < CDispatcher > ;
public: //type definitions

private: //constructor / destructor
	CDispatcher() = default;
	~CDispatcher() = default;

private: //variables
	std::queue<DispatchFunction_t> m_Queue;
	boost::mutex m_QueueMtx;

public: //functions
	void Dispatch(DispatchFunction_t &&func);
	void Process();

};
