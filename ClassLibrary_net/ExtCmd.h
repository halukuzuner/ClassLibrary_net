#pragma once
#include "Namespaces.h"
#include "WindowHandler.h"
#include "ModelessForm.h"
using namespace System;

namespace ClassLibrarynet {
   //	Bu bildirim IExternalCommand tan�m�ndan hemen �nce yap�lmal�.
   [Transaction(Autodesk::Revit::Attributes::TransactionMode::Manual)]
      [Regeneration(Autodesk::Revit::Attributes::RegenerationOption::Manual)]

      public ref class ExtCmd : IExternalCommand
   {
   private: const String^ _prompt = "Please select some elements.";
   public: static WindowHandle^ _hWndRevit = nullptr;
         //Public so can be set to false from Window closed event
   public: static bool isMainFormActive = false;

#pragma region Cached Variables

   public: static ExternalCommandData^ _cachedCmdData;

   public: static property UIApplication^ CachedUiApp
   {
      UIApplication^ get()
      {
         return _cachedCmdData->Application;
      }
   }

   public: static property UIDocument^ CachedUIDoc
   {
      UIDocument^ get()
      {
         return CachedUiApp->ActiveUIDocument;
      }
   }

   public:	static property RvtAppSrv::Application^ CachedApp
   {
      RvtAppSrv::Application^ get()
      {
         return CachedUiApp->Application;
      }
   }

   public: static property RvtDB::Document^ CachedDoc
   {
      RvtDB::Document^ get()
      {
         return CachedUiApp->ActiveUIDocument->Document;
      }
   }

   public: static ModelessForm^ MainForm;

#pragma endregion

#pragma region IExternalCommand Members        

   public: virtual Result Execute(ExternalCommandData^, String^%, ElementSet^);

#pragma endregion
   };
}
