/*
The MIT License (MIT)
Copyright (c) 2016 Alexey Yegorov

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in
all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY,
WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS
IN THE SOFTWARE.
*/

#include "asset_operations_stream.h"
#include <sys/stat.h>

namespace eps {

asset_read_operation_stream::asset_read_operation_stream(const char * name)
    : stream_(fopen(name, "rb"))
    , size_(0)
{
    if(stream_)
    {
        struct stat st;
        stat(name, &st);
        size_ = st.st_size;
    }
}

asset_read_operation_stream::~asset_read_operation_stream()
{
    if(stream_)
        fclose(stream_);
}

size_t asset_read_operation_stream::read(void * output, size_t size)
{
    return stream_ ? fread(output, 1, size, stream_) : 0;
}

size_t asset_read_operation_stream::size() const
{
    return size_;
}

} /* namespace eps */
