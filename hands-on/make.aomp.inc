CXX=clang++
CXX_FLAGS=-g -O3 -fopenmp
CXX_OFFLOAD_FLAGS=-fopenmp-targets=amdgcn-amd-amdhsa -Xopenmp-target=amdgcn-amd-amdhsa -march=gfx906

FC=flang
FC_FLAGS=${CXX_FLAGS}
FC_OFFLOAD_FLAGS=${CXX_OFFLOAD_FLAGS}
