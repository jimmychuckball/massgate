// Massgate
// Copyright (C) 2017 Ubisoft Entertainment
// 
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 2 of the License, or
// (at your option) any later version.
// 
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
// 
// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <https://www.gnu.org/licenses/>.
#include "stdafx.h"

#include "MC_Base.h"
#if IS_PC_BUILD

#include "MT_ThreadingTools.h"

// #include "MC_Logger.h"

#include "MSB_WorkerThread.h"

MSB_WorkerThread::MSB_WorkerThread(
	MSB_IoCore&			aIocp)
	: MT_Thread()
	, iocp(aIocp)
{

}

MSB_WorkerThread::~MSB_WorkerThread()
{

}

void
MSB_WorkerThread::Run()
{
	MT_ThreadingTools::SetCurrentThreadName("ServerBox - WorkerThread");
	while(!StopRequested())
		iocp.WaitCompletion(100);
}

#endif // IS_PC_BUILD
