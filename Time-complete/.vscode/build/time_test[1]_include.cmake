if(EXISTS "D:/с++/lesson3/build/time_test[1]_tests.cmake")
  include("D:/с++/lesson3/build/time_test[1]_tests.cmake")
else()
  add_test(time_test_NOT_BUILT time_test_NOT_BUILT)
endif()