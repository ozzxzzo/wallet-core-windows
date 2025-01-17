// Copyright © 2017-2022 Trust Wallet.
//
// This file is part of Trust. The full Trust copyright notice, including
// terms governing use, modification, and redistribution, is contained in the
// file LICENSE at the root of the source code distribution tree.
#include <gtest/gtest.h>

#ifdef WIN32
// Copyright © 2017-2020 Trust Wallet.
//
// This file is part of Trust. The full Trust copyright notice, including
// terms governing use, modification, and redistribution, is contained in the
// file LICENSE at the root of the source code distribution tree.
#include <string>
std::string TESTS_ROOT;

int main(int argc, char **argv) {
    if (argc < 2) {
        std::cerr << "Please specify the tests root folder." << std::endl;
        exit(1);
    }

    TESTS_ROOT = argv[1];
    struct stat s;
    if (stat(TESTS_ROOT.c_str(), &s) != 0 || (s.st_mode & S_IFDIR) == 0) {
        std::cerr << "Please specify the tests root folder. '" << TESTS_ROOT << "' is not a valid directory." << std::endl;
        exit(1);
    }
    std::cout<<"TESTS_ROOT: "<<argv[0]<<std::endl;
    ::testing::InitGoogleTest(&argc, argv);
    int ret = RUN_ALL_TESTS();
    return ret;
}

#else


#include <filesystem>
#include <string>


std::string TESTS_ROOT;

int main(int argc, char** argv) {

    // current path
    auto path = std::filesystem::current_path();
    // executable path
    path.append(argv[0]);
    // normalize
    path = std::filesystem::canonical(path);
    std::cout<<"normaliz  path: "<<path<<std::endl;
    // root path
    path = path.parent_path().parent_path().parent_path();
    TESTS_ROOT = path.append("tests").string();
    std::cout<<"TESTS_ROOT: "<<path<<std::endl;
    ::testing::InitGoogleTest(&argc, argv);
    int ret = RUN_ALL_TESTS();
    return ret;
}
#endif
