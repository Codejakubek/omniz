////////////////////////////////////////
//
// SigmaDev - Game Development and Multimedia Library
// Copyright (C) 2020-2021 Dawid Jakubowski (jakubowski.dawid@gmail.com)
//
// SigmaDev Library is licensed under MIT License (You can find it in the LICENSE file)
// Most recent version of the library is found on github repository: 
// https://github.com/Codedemens/SigmaDev/
// 
// 
// File: /impl/src/SigmaDev/Misc/Optional.cpp
// Description:
// Additional Notes:

#include <SigmaDev/Misc/Optional.h>

#include <SigmaDev/Testing/Testing.h>

SD_DEFINE_UNIT_TEST(sd_optional)
    SD_Optional<int> optional_int(10);
    SD_Optional<int> optional_int_2;

    SD_CHECK_TRUE("check1", optional_int.Initialized());
    SD_CHECK_TRUE("check2", optional_int_2.Initialized() == false);
    SD_CHECK_TRUE("check3", optional_int.Get() == 10);

    SD_OptionalShared<int> optionalshared_int(new int(10));
    SD_OptionalShared<int> optionalshared_int_2;

    SD_CHECK_TRUE("check4", optionalshared_int.Initialized());
    SD_CHECK_TRUE("check5", *optionalshared_int.Get().get() == 10);
    SD_CHECK_TRUE("check6", optionalshared_int_2.Initialized() == false);

    SD_OptionalUnique<int> optionalunique_int(new int(10));
    SD_OptionalUnique<int> optionalunique_int_2;

    SD_CHECK_TRUE("check7", optionalunique_int.Initialized());
    SD_CHECK_TRUE("check8", *optionalunique_int.Get().get() == 10);
    SD_CHECK_TRUE("check9", optionalunique_int_2.Initialized() == false);

    SD_OptionalRawptr<int> optionalptr_int(new int(10));
    SD_OptionalRawptr<int> optionalptr_int_2;

    SD_CHECK_TRUE("check10", optionalptr_int.Initialized());
    SD_CHECK_TRUE("check11", optionalptr_int.Ref() == 10);
    SD_CHECK_TRUE("check12", optionalptr_int_2.Initialized() == false);
SD_DEFINE_UNIT_TEST_END()
SD_INSERT_UNIT_TEST(sd_optional)
