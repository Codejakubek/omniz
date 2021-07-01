
set (HEADERS
    ${HEADERS}
    ${CMAKE_CURRENT_SOURCE_DIR}/include/Other_LuaTesting.h
    ${CMAKE_CURRENT_SOURCE_DIR}/include/OZ_Application.h
    ${CMAKE_CURRENT_SOURCE_DIR}/include/OZ_Class.h
    ${CMAKE_CURRENT_SOURCE_DIR}/include/OZ_Commons.h
    ${CMAKE_CURRENT_SOURCE_DIR}/include/OZ_Core.h
    ${CMAKE_CURRENT_SOURCE_DIR}/include/OZ_CoreData.h
    ${CMAKE_CURRENT_SOURCE_DIR}/include/OZ_CoreImpls.h
    ${CMAKE_CURRENT_SOURCE_DIR}/include/OZ_CoreResult.h
    ${CMAKE_CURRENT_SOURCE_DIR}/include/OZ_Result.h
    ${CMAKE_CURRENT_SOURCE_DIR}/include/OZ_Testing.h
    ${CMAKE_CURRENT_SOURCE_DIR}/include/OZ_Tmp_Movement_Test.h
    #Implementation
    PARENT_SCOPE
)

set (SOURCE
    ${SOURCE}
    ${CMAKE_CURRENT_SOURCE_DIR}/src/main.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/Other_LuaTesting.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/OZ_Application.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/OZ_Class.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/OZ_Commons.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/OZ_Core.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/OZ_CoreData.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/OZ_CoreImpls.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/OZ_CoreResult.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/OZ_Result.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/OZ_Testing.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/OZ_Tmp_Movement_Test.cpp
    #Implementation
    PARENT_SCOPE
)
