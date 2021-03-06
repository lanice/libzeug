
# 
# External dependencies
# 

find_package(Qt5Core    5.1)
find_package(Qt5Gui     5.1)
find_package(Qt5Widgets 5.1)

# Enable automoc
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(AUTOMOC_MOC_OPTIONS PROPERTIES FOLDER CMakeAutomocTargets)
set_property(GLOBAL PROPERTY AUTOMOC_FOLDER CMakeAutomocTargets)

# ENABLE CMP0020: Automatically link Qt executables to qtmain target on Windows.
if (POLICY CMP0020)
    cmake_policy(SET CMP0020 NEW)
endif()


# 
# Library name and options
# 

# Target name
set(target propertyguizeug)

# Exit here if required dependencies are not met
if (NOT Qt5Core_FOUND)
    message(STATUS "Lib ${target} skipped: Qt5 not found")
    return()
else()
    message(STATUS "Lib ${target}")
endif()

# Set API export file and macro
string(TOUPPER ${target} target_upper)
set(feature_file "include/${target}/${target}_features.h")
set(export_file  "include/${target}/${target}_api.h")
set(export_macro "${target_upper}_API")


# 
# Sources
# 

set(include_path "${CMAKE_CURRENT_SOURCE_DIR}/include/${target}")
set(source_path  "${CMAKE_CURRENT_SOURCE_DIR}/source")

set(headers
    ${include_path}/BoolEditor.h
    ${include_path}/ColorButton.h
    ${include_path}/ColorEditor.h
    ${include_path}/ChoicesModel.h
    ${include_path}/dpi_util.h
    ${include_path}/EnumEditor.h
    ${include_path}/FilePathEditor.h
    ${include_path}/FloatingPointEditor.h
    ${include_path}/LongLongSpinBox.h
    ${include_path}/PropertyBrowser.h
    ${include_path}/PropertyBrowser.hpp
    ${include_path}/PropertyDelegate.h
    ${include_path}/PropertyEditor.h
    ${include_path}/PropertyEditorFactory.h
    ${include_path}/PropertyEditorPlugin.h
    ${include_path}/PropertyModel.h
    ${include_path}/PropertyPainter.h
    ${include_path}/PropertyPainterPlugin.h
    ${include_path}/SignedIntegralEditor.h
    ${include_path}/StringEditor.h
    ${include_path}/ULongLongSpinBox.h
    ${include_path}/UnsignedIntegralEditor.h
    ${include_path}/ValueEditor.h
    ${include_path}/VariantEditor.h
)

set(sources
    ${source_path}/BoolEditor.cpp
    ${source_path}/ColorButton.cpp
    ${source_path}/ColorEditor.cpp
    ${source_path}/ChoicesModel.cpp
    ${source_path}/dpi_util.cpp
    ${source_path}/EnumEditor.cpp
    ${source_path}/FilePathEditor.cpp
    ${source_path}/FloatingPointEditor.cpp
    ${source_path}/LongLongSpinBox.cpp
    ${source_path}/PropertyBrowser.cpp
    ${source_path}/PropertyDelegate.cpp
    ${source_path}/PropertyEditor.cpp
    ${source_path}/PropertyEditorFactory.cpp
    ${source_path}/PropertyItem.cpp
    ${source_path}/PropertyItem.h
    ${source_path}/PropertyModel.cpp
    ${source_path}/PropertyPainter.cpp
    ${source_path}/SignedIntegralEditor.cpp
    ${source_path}/StringEditor.cpp
    ${source_path}/TransparencyBackgroundBrush.hpp
    ${source_path}/ULongLongSpinBox.cpp
    ${source_path}/UnsignedIntegralEditor.cpp
    ${source_path}/util.cpp
    ${source_path}/util.h
    ${source_path}/ValueEditor.cpp
    ${source_path}/VariantEditor.cpp
)

# Group source files
set(header_group "Header Files (API)")
set(source_group "Source Files")
source_group_by_path(${include_path} "\\\\.h$|\\\\.hpp$" 
    ${header_group} ${headers})
source_group_by_path(${source_path}  "\\\\.cpp$|\\\\.c$|\\\\.h$|\\\\.hpp$" 
    ${source_group} ${sources})


# 
# Create library
# 

# Build library
add_library(${target}
    ${sources}
    ${headers}
)

# Create namespaced alias
add_library(${META_PROJECT_NAME}::${target} ALIAS ${target})

# Export library for downstream projects
export(TARGETS ${target} NAMESPACE ${META_PROJECT_NAME}:: FILE ${PROJECT_BINARY_DIR}/cmake/${target}/${target}-export.cmake)

# Create feature detection header
# Compilers: https://cmake.org/cmake/help/v3.1/variable/CMAKE_LANG_COMPILER_ID.html#variable:CMAKE_%3CLANG%3E_COMPILER_ID
# Feature: https://cmake.org/cmake/help/v3.1/prop_gbl/CMAKE_CXX_KNOWN_FEATURES.html
write_compiler_detection_header(
    FILE ${feature_file}
    PREFIX ${target_upper}
    COMPILERS AppleClang Clang GNU MSVC
    FEATURES cxx_alignas cxx_alignof cxx_constexpr cxx_final cxx_noexcept cxx_nullptr cxx_sizeof_member cxx_thread_local
)

# Create API export header
generate_export_header(${target}
    EXPORT_FILE_NAME  ${export_file}
    EXPORT_MACRO_NAME ${export_macro}
)


# 
# Project options
# 

set_target_properties(${target}
    PROPERTIES
    ${DEFAULT_PROJECT_OPTIONS}
    FOLDER "${IDE_FOLDER}"
)


# 
# Include directories
# 

target_include_directories(${target}
    PRIVATE
    ${PROJECT_BINARY_DIR}/source/include
    ${CMAKE_CURRENT_SOURCE_DIR}/include
    ${CMAKE_CURRENT_BINARY_DIR}/include
    ${CMAKE_CURRENT_BINARY_DIR}

    PUBLIC
    ${DEFAULT_INCLUDE_DIRECTORIES}

    INTERFACE
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    $<BUILD_INTERFACE:${CMAKE_CURRENT_BINARY_DIR}/include>
    $<INSTALL_INTERFACE:include>
)


# 
# Libraries
# 

target_link_libraries(${target}
    PRIVATE
    
    PUBLIC
    ${DEFAULT_LIBRARIES}
    Qt5::Core
    Qt5::Gui
    Qt5::Widgets
    ${META_PROJECT_NAME}::reflectionzeug
    ${META_PROJECT_NAME}::signalzeug
	${META_PROJECT_NAME}::stringzeug

    INTERFACE
)


# 
# Compile definitions
# 

target_compile_definitions(${target}
    PRIVATE

    PUBLIC
    $<$<NOT:$<BOOL:${BUILD_SHARED_LIBS}>>:${target_upper}_STATIC_DEFINE>
    ${DEFAULT_COMPILE_DEFINITIONS}

    INTERFACE
)


# 
# Compile options
# 

target_compile_options(${target}
    PRIVATE

    PUBLIC
    ${DEFAULT_COMPILE_OPTIONS}

    INTERFACE
)


# 
# Linker options
# 

target_link_libraries(${target}
    PRIVATE

    PUBLIC
    ${DEFAULT_LINKER_OPTIONS}

    INTERFACE
)


# 
# Deployment
# 

# Library
install(TARGETS ${target}
    EXPORT  "${target}-export"            COMPONENT dev
    RUNTIME DESTINATION ${INSTALL_BIN}    COMPONENT runtime
    LIBRARY DESTINATION ${INSTALL_SHARED} COMPONENT runtime
    ARCHIVE DESTINATION ${INSTALL_LIB}    COMPONENT dev
)

# Header files
install(DIRECTORY
    ${CMAKE_CURRENT_SOURCE_DIR}/include/${target} DESTINATION ${INSTALL_INCLUDE}
    COMPONENT dev
)

# Generated header files
install(DIRECTORY
    ${CMAKE_CURRENT_BINARY_DIR}/include/${target} DESTINATION ${INSTALL_INCLUDE}
    COMPONENT dev
)

# CMake config
install(EXPORT ${target}-export
    NAMESPACE   ${META_PROJECT_NAME}::
    DESTINATION ${INSTALL_CMAKE}/${target}
    COMPONENT   dev
)
