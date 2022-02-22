#include "ExampleMod.h"
#include "Utilities/MinHook.h"
#include "Logging.h"

//My own logging functions to make logging look nicer
Logging logging;

#pragma region Blueprint Functions

//Example of a function being exposed for use in a logicmod
// Explained here: https://youtu.be/i-hp3NS6heQ?t=371
BPFUNCTION(ExampleBPFunction)
{
  struct InputParams
  {
    UE4::FString message;
  };
  auto Inputs = stack->GetInputParams<InputParams>();
  logging.Info(Inputs->message.ToString());
}

#pragma endregion

// Only Called Once, if you need to hook shit, declare some global non changing values
void ExampleMod::InitializeMod()
{
  UE4::InitSDK();
  SetupHooks();
  logging.SetModName(ModName); //Setup our logging system to have our modname
  logging.Info("Core Initialized"); //Print that our coremod was initialized
  UseMenuButton = false;

  //We have to register our blueprint function for it to work
  REGISTER_FUNCTION(ExampleBPFunction);
}

void ExampleMod::InitGameState()
{
}

void ExampleMod::BeginPlay(UE4::AActor* Actor)
{
}

void ExampleMod::PostBeginPlay(std::wstring ModActorName, UE4::AActor* Actor)
{
  // Filters Out All Mod Actors Not Related To Your Mod
  std::wstring TmpModName(ModName.begin(), ModName.end());
  if(ModActorName == TmpModName)
  {
    //Sets ModActor Ref
    ModActor = Actor;
  }
}

void ExampleMod::DX11Present(ID3D11Device* pDevice, ID3D11DeviceContext* pContext, ID3D11RenderTargetView* pRenderTargetView)
{
}

void ExampleMod::OnModMenuButtonPressed()
{
}

void ExampleMod::DrawImGui()
{
}