/*==============================================================================

  Program: 3D Slicer

  Copyright (c) 2010 Kitware Inc.

  See Doc/copyright/copyright.txt
  or http://www.slicer.org/copyright/copyright.txt for details.

  Unless required by applicable law or agreed to in writing, software
  distributed under the License is distributed on an "AS IS" BASIS,
  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
  See the License for the specific language governing permissions and
  limitations under the License.

  This file was originally developed by Jean-Christophe Fillion-Robin, Kitware Inc.
  and was partially funded by NIH grant 3P41RR013218-12S1

==============================================================================*/

// MRMLDisplayableManager includes
#include "vtkMRMLTestSliceViewDisplayableManager.h"
#include "vtkThreeDViewInteractorStyle.h"
#include "vtkMRMLDisplayableManagerGroup.h"

// MRML includes
#include <vtkMRMLCameraNode.h>

// VTK includes
#include <vtkSmartPointer.h>
#include <vtkRenderer.h>
#include <vtkRenderWindowInteractor.h>
#include <vtkRenderWindow.h>

// STD includes
#include <cassert>

// Convenient macro
#define VTK_CREATE(type, name) \
  vtkSmartPointer<type> name = vtkSmartPointer<type>::New()

//---------------------------------------------------------------------------
vtkStandardNewMacro(vtkMRMLTestSliceViewDisplayableManager );
vtkCxxRevisionMacro(vtkMRMLTestSliceViewDisplayableManager, "$Revision: 13525 $");

//---------------------------------------------------------------------------
int vtkMRMLTestSliceViewDisplayableManager::NodeAddedCount = 0;

//---------------------------------------------------------------------------
class vtkMRMLTestSliceViewDisplayableManager::vtkInternal
{
public:
  vtkInternal(vtkMRMLTestSliceViewDisplayableManager * external);
  ~vtkInternal();

  vtkMRMLTestSliceViewDisplayableManager*             External;
};

//---------------------------------------------------------------------------
// vtkInternal methods

//---------------------------------------------------------------------------
vtkMRMLTestSliceViewDisplayableManager::vtkInternal::vtkInternal(vtkMRMLTestSliceViewDisplayableManager * external)
{
  this->External = external;
}

//---------------------------------------------------------------------------
vtkMRMLTestSliceViewDisplayableManager::vtkInternal::~vtkInternal()
{
}

//---------------------------------------------------------------------------
// vtkMRMLTestSliceViewDisplayableManager methods

//---------------------------------------------------------------------------
vtkMRMLTestSliceViewDisplayableManager::vtkMRMLTestSliceViewDisplayableManager()
{
  this->Internal = new vtkInternal(this);
}

//---------------------------------------------------------------------------
vtkMRMLTestSliceViewDisplayableManager::~vtkMRMLTestSliceViewDisplayableManager()
{
  delete this->Internal;
}

//---------------------------------------------------------------------------
void vtkMRMLTestSliceViewDisplayableManager::PrintSelf(ostream& os, vtkIndent indent)
{
  this->Superclass::PrintSelf(os, indent);
}

//---------------------------------------------------------------------------
void vtkMRMLTestSliceViewDisplayableManager::AdditionnalInitializeStep()
{
}

//---------------------------------------------------------------------------
void vtkMRMLTestSliceViewDisplayableManager::Create()
{
  assert(this->GetRenderer());
  assert(this->GetMRMLSliceNode());
}

//---------------------------------------------------------------------------
void vtkMRMLTestSliceViewDisplayableManager::OnMRMLSceneNodeAddedEvent(vtkMRMLNode* node)
{
  vtkMRMLCameraNode * cameraNode = vtkMRMLCameraNode::SafeDownCast(node);
  if (!cameraNode)
    {
    return;
    }
  vtkMRMLTestSliceViewDisplayableManager::NodeAddedCount++;
  //std::cout << "vtkMRMLTestSliceViewDisplayableManager - NodeAdded - "
  //          << (node ? node->GetName() : "None")<< std::endl;
}

//---------------------------------------------------------------------------
void vtkMRMLTestSliceViewDisplayableManager::ProcessMRMLEvents(vtkObject * caller,
                                                      unsigned long event,
                                                      void *callData)
{
  //if (vtkMRMLCameraDisplayableManager::SafeDownCast(caller))
  //  {
  //  
  //  }
  //else
  //  {
    this->Superclass::ProcessMRMLEvents(caller, event, callData);
  //  }
}

