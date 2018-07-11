cmake_minimum_required(VERSION 2.8)

project(LAStools)

SET(CMAKE_MODULE_PATH "${PROJECT_SOURCE_DIR}/CMake")

function(prepend_path var prefix)
   set(listVar "")
   foreach(f ${ARGN})
      list(APPEND listVar "${prefix}/${f}")
   endforeach(f)
   set(${var} "${listVar}" PARENT_SCOPE)
endfunction(prepend_path)

set(LASZIP_SRCS arithmeticdecoder.cpp  lasquadtree.cpp               lasunzipper.cpp                laszip.cpp
                arithmeticencoder.cpp  lasreaditemcompressed_v1.cpp  laswriteitemcompressed_v1.cpp
                arithmeticmodel.cpp    lasreaditemcompressed_v2.cpp  laswriteitemcompressed_v2.cpp  laszipper.cpp
                integercompressor.cpp  lasreaditemcompressed_v3.cpp  laswriteitemcompressed_v3.cpp
                lasindex.cpp           lasreaditemcompressed_v4.cpp  laswriteitemcompressed_v4.cpp
                lasinterval.cpp        lasreadpoint.cpp              laswritepoint.cpp)# laszip_dll.cpp)
set(LASZIP_INCLUDE_DIR "${PROJECT_SOURCE_DIR}/LASzip/src/" CACHE PATH "laszip include dir")
set(LASZIP_DLL_INCLUDE_DIR "${PROJECT_SOURCE_DIR}/LASzip/dll/" CACHE PATH "laszip dllinclude dir")
set(LASZIP_INCLUDE_DIRS ${LASZIP_INCLUDE_DIR} ${LASZIP_DLL_INCLUDE_DIR})
include_directories(${LASZIP_INCLUDE_DIRS})
prepend_path(LASZIP_SRCS "${PROJECT_SOURCE_DIR}/LASzip/src/" ${LASZIP_SRCS})
message(STATUS "laszip srcs ${LASZIP_SRCS}")

set(LASLIB_SRCS lasreader_bin.cpp     lasreaderbuffered.cpp  laswaveform13reader.cpp  laswriter_txt.cpp
                fopen_compressed.cpp  lasreader_dtm.cpp   lasreadermerged.cpp    laswaveform13writer.cpp  laswriter_wrl.cpp
                lasfilter.cpp         lasreader_las.cpp   lasreaderpipeon.cpp    laswriter.cpp            laswritercompatible.cpp
                lasreader.cpp         lasreader_qfit.cpp  lasreaderstored.cpp    laswriter_bin.cpp
                lasreader_asc.cpp     lasreader_shp.cpp   lastransform.cpp       laswriter_las.cpp
                lasreader_bil.cpp     lasreader_txt.cpp   lasutility.cpp         laswriter_qfit.cpp)
set(LASLIB_INCLUDE_DIRS "${PROJECT_SOURCE_DIR}/LASlib/inc/" CACHE PATH "laslib include dir")
include_directories(${LASLIB_INCLUDE_DIRS})
prepend_path(LASLIB_SRCS "${PROJECT_SOURCE_DIR}/LASlib/src/" ${LASLIB_SRCS})
message(STATUS "laslib srcs ${LASLIB_SRCS}")

add_library(laslib STATIC ${LASZIP_SRCS} ${LASLIB_SRCS})

set(LASZIP_HEADERS arithmeticdecoder.hpp     bytestreamout_file.hpp     lasreaditemcompressed_v1.hpp   laswriteitemcompressed_v4.hpp
                   arithmeticencoder.hpp     bytestreamout_nil.hpp      lasreaditemcompressed_v2.hpp   laswriteitemraw.hpp
                   arithmeticmodel.hpp       bytestreamout_ostream.hpp  lasreaditemcompressed_v3.hpp   laswritepoint.hpp
                   bytestreamin.hpp          integercompressor.hpp      lasreaditemcompressed_v4.hpp   laszip.hpp
                   bytestreamin_array.hpp    lasattributer.hpp          lasreaditemraw.hpp             laszip_common_v1.hpp
                   bytestreamin_file.hpp     lasindex.hpp               lasreadpoint.hpp               laszip_common_v2.hpp
                   bytestreamin_istream.hpp  lasinterval.hpp            lasunzipper.hpp                laszip_common_v3.hpp
                   bytestreaminout.hpp       laspoint.hpp               laswriteitem.hpp               laszip_decompress_selective_v3.hpp
                   bytestreaminout_file.hpp  lasquadtree.hpp            laswriteitemcompressed_v1.hpp  laszipper.hpp
                   bytestreamout.hpp         lasquantizer.hpp           laswriteitemcompressed_v2.hpp  mydefs.hpp
                   bytestreamout_array.hpp   lasreaditem.hpp            laswriteitemcompressed_v3.hpp)
prepend_path(LASZIP_HEADERS "${PROJECT_SOURCE_DIR}/LASzip/src/" ${LASZIP_HEADERS})

set(LASLIB_HEADERS lasdefinitions.hpp  lasreader_dtm.hpp      lasreadermerged.hpp      laswaveform13writer.hpp  laswriter_wrl.hpp
                   lasfilter.hpp       lasreader_las.hpp      lasreaderpipeon.hpp      laswriter.hpp            laswritercompatible.hpp
                   lasreader.hpp       lasreader_qfit.hpp     lasreaderstored.hpp      laswriter_bin.hpp
                   lasreader_asc.hpp   lasreader_shp.hpp      lastransform.hpp         laswriter_las.hpp
                   lasreader_bil.hpp   lasreader_txt.hpp      lasutility.hpp           laswriter_qfit.hpp
                   lasreader_bin.hpp   lasreaderbuffered.hpp  laswaveform13reader.hpp  laswriter_txt.hpp)
prepend_path(LASLIB_HEADERS "${PROJECT_SOURCE_DIR}/LASlib/inc/" ${LASLIB_HEADERS})

INSTALL(TARGETS laslib
        DESTINATION "${CMAKE_BINARY_DIR}/lib"
        )
INSTALL(FILES ${LASZIP_HEADERS}
        DESTINATION "${CMAKE_BINARY_DIR}/laszip/include"
        )
INSTALL(FILES ${LASLIB_HEADERS}
        DESTINATION "${CMAKE_BINARY_DIR}/laslib/include"
        )
