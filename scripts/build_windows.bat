call "C:\Program Files\Microsoft Visual Studio\2022\Community\VC\Auxiliary\Build\vcvars64.bat"
cmake -S third_party -B deps-build -DCMAKE_INSTALL_PREFIX=%cd%/deps-install -G Ninja
cmake --build deps-build --config Release
cmake -S . -B build -DCMAKE_PREFIX_PATH=%cd%/deps-install -G Ninja
cmake --build build

REM the plugins/ dir needs to be copied over
