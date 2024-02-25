cmake_minimum_required(VERSION 3.21)
project(tomris-lab2 CXX)

set(CMAKE_C_STANDARD 11)

add_executable(${PROJECT_NAME}
    Node.h
    main.h
    main.cpp
    LinkedList.h
)

include(GNUInstallDirs)
install(TARGETS ${PROJECT_NAME}
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

include(InstallRequiredSystemLibraries)

set(CPACK_OUTPUT_CONFIG_FILE "${CMAKE_BINARY_DIR}/CPackDefaultConfig.cmake")

include(CPack)

add_custom_target(package
    COMMAND ${CMAKE_COMMAND} -E echo Run zip target...
    COMMAND ${CMAKE_CPACK_COMMAND}
            -G 7Z
            --config "${CMAKE_BINARY_DIR}/CPackDefaultConfig.cmake"
    VERBATIM
    USES_TERMINAL
)
