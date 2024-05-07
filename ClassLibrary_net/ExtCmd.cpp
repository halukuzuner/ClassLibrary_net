#include "pch.h"
#include "ExtCmd.h"
#include "stdafx.h"
#include "Namespaces.h"
#include "WindowHandler.h"
#include "ModelessForm.h"
#include "Resource.h"

namespace ClassLibrarynet
{
#pragma region IExternalCommand Members        
   Result ExtCmd::Execute(ExternalCommandData^ cmdData, String^% msg, ElementSet^ elemSet)
   {
      ExtCmd::_cachedCmdData = cmdData;


      //	From Building coder. To handle main Revit window.
      if (nullptr == ExtCmd::_hWndRevit)
      {
         Process^ process = Process::GetCurrentProcess();

         IntPtr h = process->MainWindowHandle;
         ExtCmd::_hWndRevit = gcnew WindowHandle(h);
      }
      //	From Building coder
      try
      {
         // If we do not have a dialog yet, create and show it
         if (ExtCmd::MainForm == nullptr || ExtCmd::MainForm->IsDisposed)
         {
            // We give the objects to the new dialog;
            // The dialog becomes the owner responsible fore disposing them, eventually.

            ExtCmd::MainForm = gcnew ModelessForm();

            if (isMainFormActive == false)
            {
               ExtCmd::MainForm->Show(ExtCmd::_hWndRevit);
               isMainFormActive = true;
            }
         }
         return Result::Succeeded;
      }
      catch (System::Exception^ ex)
      {
         msg = ex->ToString();
         return Result::Failed;
      }

      return Result::Succeeded;
   }
}