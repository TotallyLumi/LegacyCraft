#pragma once

#ifdef _WINDOWS64
typedef unsigned __int64 __uint64;

#define WIN32_LEAN_AND_MEAN

#include <windows.h>
#include <malloc.h>
#include <tchar.h>
#include <d3d11.h>
#endif

#include <unordered_map>
#include <unordered_set>
#include <sal.h>
#include <vector>

#include <memory>

#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <algorithm>
#include <math.h>
#include <limits>
#include <string>
#include <sstream>
#include <iostream>
#include <exception>

#include "..\Minecraft.Client\Xbox\Network\extra.h"

#include "Definitions.h"
#include "Class.h"
#include "Exceptions.h"
#include "Mth.h"
#include "StringHelpers.h"
#include "ArrayWithLength.h"
#include "Random.h"
#include "TilePos.h"
#include "ChunkPos.h"
#include "compression.h"
#include "PerformanceTimer.h"

void MemSect( int sect );

#ifdef _WINDOWS64
#include "..\Minecraft.Client\Windows64\4JLibs\inc\4J_Profile.h"
#include "..\Minecraft.Client\Windows64\4JLibs\inc\4J_Render.h"
#include "..\Minecraft.Client\Windows64\4JLibs\inc\4J_Storage.h"
#include "..\Minecraft.Client\Windows64\4JLibs\inc\4J_Input.h"
#endif

#include "..\Minecraft.Common\Network\GameNetworkManager.h"

#include "..\Minecraft.Common\UI\UIEnums.h"
#include "..\Minecraft.Common\App_defines.h"
#include "..\Minecraft.Common\App_enums.h"
#include "..\Minecraft.Common\Tutorial\TutorialEnum.h"
#include "..\Minecraft.Common\App_structs.h"

#include "..\Minecraft.Common\BuildVer.h"

#ifdef _WINDOWS64
#include "..\Minecraft.Client\Windows64\Windows64_App.h"
#include "..\Minecraft.Client\Windows64Media\strings.h"
#include "..\Minecraft.Client\Windows64\Sentient\SentientTelemetryCommon.h"
#include "..\Minecraft.Client\Windows64\Sentient\MinecraftTelemetry.h"
#endif

#include "..\Minecraft.Common\DLC\DLCSkinFile.h"
#include "..\Minecraft.Common\Console_Awards_enum.h"
#include "..\Minecraft.Common\Potion_Macros.h"
#include "..\Minecraft.Common\Console_Debug_enum.h"
#include "..\Minecraft.Common\GameRules\ConsoleGameRulesConstants.h"
#include "..\Minecraft.Common\GameRules\ConsoleGameRules.h"
#include "..\Minecraft.Common\Telemetry\TelemetryManager.h"