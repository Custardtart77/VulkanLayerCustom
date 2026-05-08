:: Build release binary for arm64-v8a

:: set ANDROID_NDK_HOME=/path/Android/sdk/ndk/29.0.14206865

cmake -S . -B build -D CMAKE_TOOLCHAIN_FILE=%ANDROID_NDK_HOME%/build/cmake/android.toolchain.cmake -D ANDROID_PLATFORM=34 -D CMAKE_ANDROID_ARCH_ABI=arm64-v8a -D CMAKE_ANDROID_STL_TYPE=c++_static -D ANDROID_USE_LEGACY_TOOLCHAIN_FILE=NO -D CMAKE_BUILD_TYPE=Release -D UPDATE_DEPS=ON -G Ninja

cmake --build build

cmake --install build --prefix build/install