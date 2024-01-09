message(STATUS "Start configuration for example_moules.")

file(GLOB ELEMENTS "*") # Import the entire item

foreach(ELEMENT ${ELEMENTS}) # or ELEMENT IN LISTS ${ELEMENTS}
  if(IS_DIRECTORY ${ELEMENT} AND EXISTS ${ELEMENT}/CMakeLists.txt) # 디렉토리이고 디렉토리 내부에 CMAKE 파일이 존재한다면
    message("Start configuration for ${ELEMENT}.")
    add_subdirectory(${ELEMENT}) # 폴더 내부를 엮어줘라.
    message("Finish configuration for ${ELEMENT}.")
  endif()
endforeach()

message(STATUS "Finish configuration for example_moules.\n")
