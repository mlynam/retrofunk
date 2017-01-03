project(test-core)

add_executable(main_test
        TestComponent.cpp
        TestComponent.h
        TestSerializer.cpp
        TestSerializer.h
        TestEntity.cpp
        TestEntity.h
        component.spec.cpp
        entity.spec.cpp TestComponent2.cpp TestComponent2.h)

target_link_libraries(main_test gtest gtest_main)
target_link_libraries(main_test retrofunk_core)
