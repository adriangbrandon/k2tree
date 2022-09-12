/***
BSD 2-Clause License

Copyright (c) 2018, Adrián
All rights reserved.

Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions are met:

* Redistributions of source code must retain the above copyright notice, this
  list of conditions and the following disclaimer.

* Redistributions in binary form must reproduce the above copyright notice,
  this list of conditions and the following disclaimer in the documentation
  and/or other materials provided with the distribution.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
**/


//
// Created by Adrián on 09/09/2019.
//

#include <stdint.h>
#include <vector>
#include <k2_tree_compression_leaves.hpp>


int main(int argc, char **argv) {


    std::vector<std::vector<int64_t>> adjacency_lists(32);
    adjacency_lists[0] = {0, 1, 4, 7};
    adjacency_lists[1] = {0, 1, 7};
    adjacency_lists[2] = {0, 8};
    adjacency_lists[3] = {1, 9};
    adjacency_lists[4] = {0, 11};
    adjacency_lists[10] = {0, 1, 4, 7, 24, 30};
    adjacency_lists[11] = {0, 1, 7, 15, 28};
    adjacency_lists[12] = {0, 8, 10, 12, 30};
    adjacency_lists[13] = {1, 9, 11, 22};
    adjacency_lists[14] = {0, 11, 22, 23, 24, 25};



    cds::k2_tree_compression_leaves<> m_k2_tree(adjacency_lists, 2);

    std::vector<std::vector<int64_t>> result;
    m_k2_tree.access_region(0, 0, 31, 31, result);
    for(uint64_t i = 0; i < 32; ++i){
        std::cout << i << "-th list: [";
        for(uint64_t j = 0; j < result[i].size(); ++j){
            std::cout << result[i][j] << " ";
        }
        std::cout << "]" << std::endl;
    }

    std::cout << "Size: " << sdsl::size_in_bytes(m_k2_tree) << " bytes." << std::endl;
}