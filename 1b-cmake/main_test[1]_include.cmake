if(EXISTS "/mnt/d/с++/1b-cmake/main_test[1]_tests.cmake")
  include("/mnt/d/с++/1b-cmake/main_test[1]_tests.cmake")
else()
  add_test(main_test_NOT_BUILT main_test_NOT_BUILT)
endif()
