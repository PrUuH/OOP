add_test([=[TimeTest.DefaultConstructor]=]  [==[D:/с++/lesson3/build/Debug/time_test.exe]==] [==[--gtest_filter=TimeTest.DefaultConstructor]==] --gtest_also_run_disabled_tests)
set_tests_properties([=[TimeTest.DefaultConstructor]=]  PROPERTIES WORKING_DIRECTORY [==[D:/с++/lesson3/build]==] SKIP_REGULAR_EXPRESSION [==[\[  SKIPPED \]]==])
add_test([=[TimeTest.ParametricConstructor]=]  [==[D:/с++/lesson3/build/Debug/time_test.exe]==] [==[--gtest_filter=TimeTest.ParametricConstructor]==] --gtest_also_run_disabled_tests)
set_tests_properties([=[TimeTest.ParametricConstructor]=]  PROPERTIES WORKING_DIRECTORY [==[D:/с++/lesson3/build]==] SKIP_REGULAR_EXPRESSION [==[\[  SKIPPED \]]==])
add_test([=[TimeTest.CopyConstructor]=]  [==[D:/с++/lesson3/build/Debug/time_test.exe]==] [==[--gtest_filter=TimeTest.CopyConstructor]==] --gtest_also_run_disabled_tests)
set_tests_properties([=[TimeTest.CopyConstructor]=]  PROPERTIES WORKING_DIRECTORY [==[D:/с++/lesson3/build]==] SKIP_REGULAR_EXPRESSION [==[\[  SKIPPED \]]==])
add_test([=[TimeTest.AssignmentOperator]=]  [==[D:/с++/lesson3/build/Debug/time_test.exe]==] [==[--gtest_filter=TimeTest.AssignmentOperator]==] --gtest_also_run_disabled_tests)
set_tests_properties([=[TimeTest.AssignmentOperator]=]  PROPERTIES WORKING_DIRECTORY [==[D:/с++/lesson3/build]==] SKIP_REGULAR_EXPRESSION [==[\[  SKIPPED \]]==])
add_test([=[TimeTest.ToSeconds]=]  [==[D:/с++/lesson3/build/Debug/time_test.exe]==] [==[--gtest_filter=TimeTest.ToSeconds]==] --gtest_also_run_disabled_tests)
set_tests_properties([=[TimeTest.ToSeconds]=]  PROPERTIES WORKING_DIRECTORY [==[D:/с++/lesson3/build]==] SKIP_REGULAR_EXPRESSION [==[\[  SKIPPED \]]==])
add_test([=[TimeTest.SubtractionOperator]=]  [==[D:/с++/lesson3/build/Debug/time_test.exe]==] [==[--gtest_filter=TimeTest.SubtractionOperator]==] --gtest_also_run_disabled_tests)
set_tests_properties([=[TimeTest.SubtractionOperator]=]  PROPERTIES WORKING_DIRECTORY [==[D:/с++/lesson3/build]==] SKIP_REGULAR_EXPRESSION [==[\[  SKIPPED \]]==])
add_test([=[TimeTest.SubtractionAssignmentOperator]=]  [==[D:/с++/lesson3/build/Debug/time_test.exe]==] [==[--gtest_filter=TimeTest.SubtractionAssignmentOperator]==] --gtest_also_run_disabled_tests)
set_tests_properties([=[TimeTest.SubtractionAssignmentOperator]=]  PROPERTIES WORKING_DIRECTORY [==[D:/с++/lesson3/build]==] SKIP_REGULAR_EXPRESSION [==[\[  SKIPPED \]]==])
add_test([=[TimeTest.EqualityOperator]=]  [==[D:/с++/lesson3/build/Debug/time_test.exe]==] [==[--gtest_filter=TimeTest.EqualityOperator]==] --gtest_also_run_disabled_tests)
set_tests_properties([=[TimeTest.EqualityOperator]=]  PROPERTIES WORKING_DIRECTORY [==[D:/с++/lesson3/build]==] SKIP_REGULAR_EXPRESSION [==[\[  SKIPPED \]]==])
add_test([=[TimeTest.InequalityOperator]=]  [==[D:/с++/lesson3/build/Debug/time_test.exe]==] [==[--gtest_filter=TimeTest.InequalityOperator]==] --gtest_also_run_disabled_tests)
set_tests_properties([=[TimeTest.InequalityOperator]=]  PROPERTIES WORKING_DIRECTORY [==[D:/с++/lesson3/build]==] SKIP_REGULAR_EXPRESSION [==[\[  SKIPPED \]]==])
set(  time_test_TESTS TimeTest.DefaultConstructor TimeTest.ParametricConstructor TimeTest.CopyConstructor TimeTest.AssignmentOperator TimeTest.ToSeconds TimeTest.SubtractionOperator TimeTest.SubtractionAssignmentOperator TimeTest.EqualityOperator TimeTest.InequalityOperator)