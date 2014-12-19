# define the install directory for miscellaneous files
if(WINDOWS)
    set(INSTALL_MISC_DIR . )
else()
    set(INSTALL_MISC_DIR "share/${GAME}")
endif()

# Install game
if (LINUX OR WINDOWS)
	install(DIRECTORY include
			DESTINATION .)

	install(TARGETS ${GAME}
        RUNTIME DESTINATION bin COMPONENT binaries
        LIBRARY DESTINATION lib${LIB_SUFFIX} COMPONENT binaries
        ARCHIVE DESTINATION lib${LIB_SUFFIX} COMPONENT libraries)
else()
	set_target_properties(${GAME} PROPERTIES MACOSX_BUNDLE TRUE)
        install(TARGETS ${GAME} BUNDLE DESTINATION ${INSTALL_MISC_DIR}/${target} COMPONENT game)
endif()

install(FILES "${CMAKE_SOURCE_DIR}/License.txt" "${CMAKE_SOURCE_DIR}/ReadMe.txt" "${CMAKE_SOURCE_DIR}/Authors.txt"
        DESTINATION ${INSTALL_MISC_DIR}
        COMPONENT resources)
