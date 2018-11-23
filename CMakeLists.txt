cmake_minimum_required(VERSION 2.6)
project(TMSENGINE)

if (MSVC)
 include_directories(
    contrib/msvc-windows-x86/glew/include
    contrib/msvc-windows-x86/SDL2/include
    contrib/msvc-windows-X86/openal-soft/include
    contrib/msvc-windows-X86/ogg/include
    contrib/msvc-windows-X86/vorbis/include
    contrib
    src
 )

 link_directories(
    ${CMAKE_SOURCE_DIR}/contrib/msvc-windows-x86/SDL2/lib
    ${CMAKE_SOURCE_DIR}/contrib/msvc-windows-x86/glew/lib
    ${CMAKE_SOURCE_DIR}/contrib/msvc-windows-x86/openal-soft/lib
    ${CMAKE_SOURCE_DIR}/contrib/msvc-windows-x86/ogg/lib
    ${CMAKE_SOURCE_DIR}/contrib/msvc-windows-x86/vorbis/lib
  )
endif()

if(MSVC)
  add_definitions(-DSDL_MAIN_HANDLED)
endif()

add_executable(Game
src/Game/main.cpp
src/Game/Scene.cpp
src/Game/Scene.h
src/Game/Box.cpp
src/Game/Box.h
src/Game/Apple.cpp
src/Game/Apple.h

)

add_library(TMSEngine
src/TMSEngine/Core.cpp
src/TMSEngine/Core.h
src/TMSEngine/TMSEngine.h
src/TMSEngine/GameObject.cpp
src/TMSEngine/GameObject.h
src/TMSEngine/Component.h
src/TMSEngine/Component.cpp
src/TMSEngine/VertexBuffer.h
src/TMSEngine/VertexBuffer.cpp
src/TMSEngine/VertexArray.h
src/TMSEngine/VertexArray.cpp
src/TMSEngine/ShaderProgram.h
src/TMSEngine/ShaderProgram.cpp
src/TMSEngine/Keyboard.h
src/TMSEngine/Keyboard.cpp
src/TMSEngine/Screen.h
src/TMSEngine/Screen.cpp
src/TMSEngine/Enviroment.h
src/TMSEngine/Enviroment.cpp
src/TMSEngine/ResourceManager.h
src/TMSEngine/ResourceManager.cpp
src/TMSEngine/MeshRenderer.h
src/TMSEngine/MeshRenderer.cpp
src/TMSEngine/Transform.h
src/TMSEngine/Transform.cpp
src/TMSEngine/Material.h
src/TMSEngine/Material.cpp
src/TMSEngine/MaterialAttribute.h
src/TMSEngine/MaterialAttribute.cpp
src/TMSEngine/Sound.h
src/TMSEngine/Sound.cpp
src/TMSEngine/Camera.h
src/TMSEngine/Camera.cpp
src/TMSEngine/Exception.h
src/TMSEngine/Exception.cpp
src/TMSEngine/Collider.h
src/TMSEngine/Collider.cpp

src/TMSEngine/Resources/Resource.cpp
src/TMSEngine/Resources/Resource.h
src/TMSEngine/Resources/Mesh.cpp
src/TMSEngine/Resources/Mesh.h
src/TMSEngine/Resources/Texture.cpp
src/TMSEngine/Resources/Texture.h
src/TMSEngine/Resources/Shader.cpp
src/TMSEngine/Resources/Shader.h

contrib/stb_image/stb_image.cpp
contrib/stb_image/stb_image.h
)

target_link_libraries(Game TMSEngine)

if(MSVC)
  target_link_libraries(Game
    SDL2 glew32 opengl32 TMSEngine OpenAL32 ogg vorbis vorbisfile
  )
else()
  target_link_libraries(Game
    SDL2 GLU GLEW GL TMSEngine AL ogg vorbis vorbisfile
  )
endif()

if(MSVC)
  add_custom_command(TARGET Game POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_if_different
      "${CMAKE_SOURCE_DIR}/contrib/msvc-windows-x86/SDL2/bin/SDL2.dll"
      "$<TARGET_FILE_DIR:Game>"
  )

  add_custom_command(TARGET Game POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_if_different
      "${CMAKE_SOURCE_DIR}/contrib/msvc-windows-x86/glew/bin/glew32.dll"
      "$<TARGET_FILE_DIR:Game>"
  )

  add_custom_command(TARGET Game POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_if_different
      "${CMAKE_SOURCE_DIR}/contrib/msvc-windows-x86/openal-soft/bin/OpenAL32.dll"
      "$<TARGET_FILE_DIR:Game>"
  )
endif()