# Changelog

All notable changes to this project will be documented in this file.

The format is based on [Keep a Changelog](https://keepachangelog.com/en/1.0.0/).

## UNRELEASED

- [#6](https://github.com/Nelson-numerical-software/nelson-minimalist-core/issues/6): Windows build with cmake.

- [#24](https://github.com/Nelson-numerical-software/nelson-minimalist-core/issues/24): CI build with Cmake on Windows.

- plug `trigonometric_functions` module (currently only builtin)
  `cos`, `sin`, `tan`, `cosh`, `sinh`, `tanh`, `acos`, `asin`, `atan`, `cosm`, `sinm`, `tanm`, `atan2`, `atanh`

- plug `display_format` module (format, disp, display, echo)

- builtin loaded by gateway.

## 0.1.0

### Added

- [#16](https://github.com/Nelson-numerical-software/nelson-minimalist-core/issues/16): text_completion code imported.

- [#13](https://github.com/Nelson-numerical-software/nelson-minimalist-core/issues/13): cmake packaging (Thanks to JohanMabille).

- [#11](https://github.com/Nelson-numerical-software/nelson-minimalist-core/issues/11): plug 'addpath' builtin.

### Changed

- nelson.sln renamed to nelson-minimalist-core.sln

- synchronized with complete version Nelson 0.6.12

### Fixed

- [#23](https://github.com/Nelson-numerical-software/nelson-minimalist-core/issues/23): VariableCompleter was not filtered by prefix.

- [#8](https://github.com/Nelson-numerical-software/nelson-minimalist-core/issues/8): Install nelson-minimalist-core in local environment

Thanks to JohanMabille, Hind-M and [QuantStack](https://quantstack.net/) for their helps for this initial version of nelson-minimalist-core.
