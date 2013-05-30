SET(SOURCE
   Main.cpp
)

SET(LIBRARIES
  sogre
)

ADD_EXECUTABLE(unit-tests ${SOURCE})
TARGET_LINK_LIBRARIES(unit-tests ${LIBRARIES})

ADD_DEPENDENCIES(unit-tests sogre)

ADD_CUSTOM_TARGET(run-tests COMMAND ${PROJECT_BINARY_DIR}/bin/unit-tests DEPENDS unit-tests)
ADD_CUSTOM_COMMAND(TARGET unit-tests POST_BUILD
                   COMMAND unit-tests)