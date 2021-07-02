
# ToDos for SigmaDev Library

- [ToDos for SigmaDev Library](#todos-for-sigmadev-library)
  - [MISC: <-----](#misc------)
  - [GUI:](#gui)
  - [Graphics:](#graphics)
  - [Application:](#application)
  - [Lua:](#lua)
  - [Other:](#other)
  - [Resources:](#resources)
  - [Networking:](#networking)

## MISC: <-----
- SD_GenericVariable, SD_GenericValue
    - Loading via LUA
    - Loading via JSON
- SD_LoadingRule
- SD_SavingRule
- SD_ID
  - Multilevel id
  - like SD_StringPath
  
## GUI:
- SD_GUIObject
     - Integration with Lua & JSON (Loading, behavior)
     - Default properties:
     - Position
     - Size
     - Origin
     - Graphics
     - Events
- SD_GUIObjectData (contai- SD_LoadingRule

     - Loading to JSON
- SD_GUIObjectImpl (implementation specialization class)
     - Init();
     - Cleanup()
     - Tick();
     - RenderTick()
     - ActivityTick();
     - (definable by LUA Tick methods)
     - Definable by LUA
     - SD_GUIObjectImpl:: Init; Cleanup; Tick; RenderTick; ActivityTick; std::set<SD_Tick>
- SD_GUIObjectType (contains information about SD_GUIObject
     - Definable by LUA as well
- SD_GUIObjectEvents
     - Definable by LUA as well
- SD_GUIObjectEventListener(s)
    - Definable by LUA as well
- SD_GUI
    - Definable/Loadable/Savable by LUA & JSON
- SD_GUIEditor

## Graphics:
 - SD_Graphic
     - Integration with lua & JSON (loading, behavior)
     - Default propertioes:
          - Position
          - Size
          - Origin
          - Rotation
          - RenderStates Reference
          - RenderMethod();
          - Init();
          - Cleanup();
- SD_RenderStates
     - Integration with lua & JSON (loading, behavior)
 - SD_Texture
     - Integration with lua & JSON (loading, behavior)
- SD_TexturePack
- SD_TexturePack::SD_Variant
- SD_Shader 
     - Integration with lua & JSON & GLSL
     - Create Gaussian Blur (GLSL - Done)

## Application:
- SD_Application
     - Integration with lua & JSON (loading, behavior)
- Redefine all SD_Application modules
    - SD_ApplicationImpl
    - SD_ApplicationResources
    - SD_AudioModule
    - SD_JSONModule
    - SD_LuaModule
    - SD_GraphicsModule
    - SD_SFMLModule
    - SD_Box2DModule
    - SD_GUIModule
    - SD_NetworkingModule
    - SD_TestingModule
    - SD_RaportingModule

## Lua:
 - SD_LuaModule
 - SD_LuaState (only one!)
 - SD_LuaScript
   - SD_LuaScript::SD_Load
   - SD_LuaScript::SD_Execution
 - SD_LuaEditor
 - SD_LuaEditor
   - SD_LuaEditor::SD_Modify

## Other: 
- Create own tutorials and examples for SigmaDev Library.

## Resources:
 - SD_Resources redefine
   - Loadable by lua and JSON

## Networking:
 ...