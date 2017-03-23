///////////////////////////////////////////////////////////////////////////
//
// Copyright (c) 2017, Arthur N. Klassen
// All rights reserved.
//
// Redistribution and use in source and binary forms, with or without
// modification, are permitted provided that the following conditions are met:
//
// 1. Redistributions of source code must retain the above copyright notice,
//    this list of conditions and the following disclaimer.
//
// 2. Redistributions in binary form must reproduce the above copyright notice,
//    this list of conditions and the following disclaimer in the documentation
//    and/or other materials provided with the distribution.
//
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
// AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
// IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
// ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
// LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
// CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
// SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
// INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
// CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
// ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
// POSSIBILITY OF SUCH DAMAGE.
//
///////////////////////////////////////////////////////////////////////////
//
// 2017.03.24 - First Version
//
//    May you do good and not evil.
//    May you find forgiveness for yourself and forgive others.
//    May you share freely, never taking more than you give.
//
///////////////////////////////////////////////////////////////////////////
//
// file_handle_test.cxx -- Tests for FileHandle in file_handle.cxx
//
///////////////////////////////////////////////////////////////////////////

#include <file_handle.hxx>
#include <mock_file_system.hxx>

#include <gmock/gmock.h>

using namespace ansak;
using namespace std;
using namespace testing;

namespace ansak
{

extern FileSystemMock* theMock;

}

namespace
{

#if defined(WIN32)

const char* homeDirP = "C:\\Users\\theUser";
// const char* foreignPathP = "/usr/sbin";

#else

const char* homeDirP = "/home/theUser";
// const char* foreignPathP = "C:\\Windows\\System32";

#endif

}

class FileHandleFixture : public Test {
public:
    FileHandleFixture()
    {
        theMock = &m_fileMock;
        EXPECT_CALL(m_fileMock, mockGetCwd()).WillRepeatedly(Return(FilePath(homeDirP)));
    }
    ~FileHandleFixture()
    {
        theMock = nullptr;
    }
    FileSystemMock& FileMock() { return m_fileMock; }

private:
    NiceMock<FileSystemMock>    m_fileMock;
};

TEST_F(FileHandleFixture, defaultConstruct)
{
}
