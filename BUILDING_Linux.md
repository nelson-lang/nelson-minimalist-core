### Linux

- You can also see [ccpp.yml](https://github.com/Nelson-numerical-software/nelson/blob/master/.github/workflows/ccpp.yml) file to help you to see dependencies. This file is up-to-date about how to build Nelson on each platform.

CMake options:

```bash
cmake -LAH

```

Standard build:

```bash
cd nelson
cmake -DCMAKE_BUILD_TYPE=Release -G "Unix Makefiles" .
cmake --build . -- -j $(nproc)
```

Some tips:

- Build Nelson with clang-tidy fix

```bash
  cd nelson
  cmake -DENABLE_CLANG_TIDY_FIX=ON -G "Unix Makefiles" .
```

- launch Nelson:

```bash
cd nelson
./bin/linux/nelson.sh
```

or

```bash
cd nelson
./bin/macOs/nelson.sh
```

[Previous (Building)](BUILDING.md)
