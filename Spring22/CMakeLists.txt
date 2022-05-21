set(HEADER_FILES 
	Entity.h
	SpringApp.h
)

set(SOURCE_FILES
	Entity.cpp
	SpringApp.cpp
	main.cpp
)

add_executable(Spring22 ${HEADER_FILES} ${SOURCE_FILES})

include_directories(../Game)

target_link_libraries(Spring22 Game)

file(COPY Assets DESTINATION ${PROJECT_BINARY_DIR}/Spring22)
file(COPY Assets DESTINATION ${PROJECT_BINARY_DIR}/Debug)
file(COPY Assets DESTINATION ${PROJECT_BINARY_DIR}/Release)