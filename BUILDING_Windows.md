### Windows

- You can also see [ccpp.yml](https://github.com/nelson-lang/nelson/blob/master/.github/workflows/ccpp.yml) file to help you to see dependencies. This file is up-to-date about how to build Nelson on each platform.

- Prerequirements:
  Git for Windows
  Visual studio 2022 (C++)

- Creates Nelson main directory
  ```bash
  mkdir Nelson
  cd  Nelson
  ```
- Get thirdparty:
  - on Windows 32 bit architecture:
    ```bash
    git clone https://github.com/nelson-lang/nelson-thirdparty-win32.git
    ```
  - on Windows 64 bit architecture:
    ```bash
    git clone https://github.com/nelson-lang/nelson-thirdparty-x64.git
    ```
- Get sources:
  ```bash
  git clone https://github.com/nelson-lang/nelson.git
  ```
- Start the build:
  Goto Nelson directory
  launch nelson-minimalist-core.sln
  start build with VS 2022

[Previous (Building)](BUILDING.md)
