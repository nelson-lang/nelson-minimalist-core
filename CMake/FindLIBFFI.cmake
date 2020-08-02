FIND_PACKAGE(PkgConfig)
PKG_CHECK_MODULES(PC_LIBFFI QUIET libffi)

FIND_PATH(LIBFFI_INCLUDE_DIR ffi.h
  HINTS ${PC_LIBFFI_INCLUDEDIR})

IF (LIBFFI_INCLUDE_DIR)
  FIND_LIBRARY(LIBFFI_LIBRARY NAMES ffi
    HINTS ${PC_LIBFFI_LIBDIR} ${PC_LIBFFI_LIBRARY_DIRS})
ENDIF()

INCLUDE(FindPackageHandleStandardArgs)
FIND_PACKAGE_HANDLE_STANDARD_ARGS(LibFFI DEFAULT_MSG
                                  LIBFFI_LIBRARY LIBFFI_INCLUDE_DIR)

IF (NOT LIBFFI_INCLUDE_DIR)
  IF(EXISTS "/usr/include/ffi/ffi.h")
    set(LIBFFI_INCLUDE_DIR /usr/include/ffi)
  ENDIF()
ENDIF() 
IF (NOT LIBFFI_INCLUDE_DIR)
  IF(EXISTS "/usr/local/opt/libffi/include/ffi.h")
    set(LIBFFI_INCLUDE_DIR /usr/local/opt/libffi/include)
  ENDIF()
ENDIF()
IF (NOT LIBFFI_INCLUDE_DIR)
  IF(EXISTS "usr/lib/libffi-3.2.1/include/ffi.h")
      set(LIBFFI_INCLUDE_DIR "usr/lib/libffi-3.2.1/include")
  ENDIF()
ENDIF()
IF (NOT LIBFFI_INCLUDE_DIR)
  IF(EXISTS "/usr/include/x86_64-linux-gnu/ffi.h")
      set(LIBFFI_INCLUDE_DIR "/usr/include/x86_64-linux-gnu")
  ENDIF()
ENDIF()

MARK_AS_ADVANCED(LIBFFI_INCLUDE_DIR LIBFFI_LIBRARY)
