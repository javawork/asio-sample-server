#pragma once

class CircularBuffer
{
public:
    CircularBuffer() : _offset(0)
    {
        _buffer = new char[MaxBufferSize];
        memset(_buffer, 0, MaxBufferSize);
    }

    ~CircularBuffer()
    {
        delete[] _buffer;
        _buffer = nullptr;
    }

    char* Allocate(size_t size)
    {
        if (_offset + size >= MaxBufferSize)
            _offset = 0;
        char* ptr = _buffer + _offset;
        _offset += size;
        return ptr;
    }

private:
    static constexpr int MaxBufferSize = 1024;
    char* _buffer;
    size_t _offset;
};