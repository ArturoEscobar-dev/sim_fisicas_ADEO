# Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
# file Copyright.txt or https://cmake.org/licensing for details.

cmake_minimum_required(VERSION 3.5)

file(MAKE_DIRECTORY
  "D:/veloc/UNIAT/Semestre 5, Sept23-Ene24/Simuladores de Físicas/github/sim_fisicas_ADEO/Proyeto_Hola_Goldberg/cmake-build-debug-visual-studio/_deps/sfml-src"
  "D:/veloc/UNIAT/Semestre 5, Sept23-Ene24/Simuladores de Físicas/github/sim_fisicas_ADEO/Proyeto_Hola_Goldberg/cmake-build-debug-visual-studio/_deps/sfml-build"
  "D:/veloc/UNIAT/Semestre 5, Sept23-Ene24/Simuladores de Físicas/github/sim_fisicas_ADEO/Proyeto_Hola_Goldberg/cmake-build-debug-visual-studio/_deps/sfml-subbuild/sfml-populate-prefix"
  "D:/veloc/UNIAT/Semestre 5, Sept23-Ene24/Simuladores de Físicas/github/sim_fisicas_ADEO/Proyeto_Hola_Goldberg/cmake-build-debug-visual-studio/_deps/sfml-subbuild/sfml-populate-prefix/tmp"
  "D:/veloc/UNIAT/Semestre 5, Sept23-Ene24/Simuladores de Físicas/github/sim_fisicas_ADEO/Proyeto_Hola_Goldberg/cmake-build-debug-visual-studio/_deps/sfml-subbuild/sfml-populate-prefix/src/sfml-populate-stamp"
  "D:/veloc/UNIAT/Semestre 5, Sept23-Ene24/Simuladores de Físicas/github/sim_fisicas_ADEO/Proyeto_Hola_Goldberg/cmake-build-debug-visual-studio/_deps/sfml-subbuild/sfml-populate-prefix/src"
  "D:/veloc/UNIAT/Semestre 5, Sept23-Ene24/Simuladores de Físicas/github/sim_fisicas_ADEO/Proyeto_Hola_Goldberg/cmake-build-debug-visual-studio/_deps/sfml-subbuild/sfml-populate-prefix/src/sfml-populate-stamp"
)

set(configSubDirs )
foreach(subDir IN LISTS configSubDirs)
    file(MAKE_DIRECTORY "D:/veloc/UNIAT/Semestre 5, Sept23-Ene24/Simuladores de Físicas/github/sim_fisicas_ADEO/Proyeto_Hola_Goldberg/cmake-build-debug-visual-studio/_deps/sfml-subbuild/sfml-populate-prefix/src/sfml-populate-stamp/${subDir}")
endforeach()
if(cfgdir)
  file(MAKE_DIRECTORY "D:/veloc/UNIAT/Semestre 5, Sept23-Ene24/Simuladores de Físicas/github/sim_fisicas_ADEO/Proyeto_Hola_Goldberg/cmake-build-debug-visual-studio/_deps/sfml-subbuild/sfml-populate-prefix/src/sfml-populate-stamp${cfgdir}") # cfgdir has leading slash
endif()
