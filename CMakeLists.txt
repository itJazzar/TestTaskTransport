﻿# CMakeList.txt: файл проекта CMake верхнего уровня; проведите глобальную конфигурацию
# и включите сюда подпроекты.

cmake_minimum_required (VERSION 3.10)

# Включение горячей перезагрузки для компиляторов MSVC, если поддерживается.
if (POLICY CMP0141)
  cmake_policy(SET CMP0141 NEW)
  set(CMAKE_MSVC_DEBUG_INFORMATION_FORMAT "$<IF:$<AND:$<C_COMPILER_ID:MSVC>,$<CXX_COMPILER_ID:MSVC>>,$<$<CONFIG:Debug,RelWithDebInfo>:EditAndContinue>,$<$<CONFIG:Debug,RelWithDebInfo>:ProgramDatabase>>")
endif()

# Установка стандарта C++ на версию 11
set(CMAKE_CXX_STANDARD 11) 
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Определение проекта
project ("TestTaskTransport")

# Включите подпроекты.
add_subdirectory ("TestTaskTransport")

# Добавление исполняемого файла
#add_executable(TestTaskTransport TestTaskTransport.cpp TestTaskTransportFactory.cpp TestTaskTransport.h)

# Линковка с подпроектом TestTaskTransport
#target_link_libraries(TestTaskTransport PRIVATE TestTaskTransport)