#include <protocols/rest/FastBuffer.h>

#include <malloc.h>

#define BUFFER_START_LENGTH 200

using namespace eprosima::rpc;
using namespace protocol::rest;

FastBuffer::FastBuffer() : m_buffer(NULL),
    m_bufferSize(0), m_internalBuffer(true){}

    FastBuffer::FastBuffer(char* const buffer, const size_t bufferSize) : m_buffer(buffer),
    m_bufferSize(bufferSize), m_internalBuffer(false){}

bool FastBuffer::resize(size_t minSizeInc)
{
    size_t incBufferSize = BUFFER_START_LENGTH;

    if(m_internalBuffer)
    {
        if(minSizeInc > BUFFER_START_LENGTH)
        {
            incBufferSize = minSizeInc;
        }

        if(m_buffer == NULL)
        {
            m_bufferSize = incBufferSize;

            m_buffer = (char*)malloc(m_bufferSize);

            if(m_buffer != NULL)
            {
                return true;
            }
        }
        else
        {
            m_bufferSize += incBufferSize;

            m_buffer = (char*)realloc(m_buffer, m_bufferSize);

            if(m_buffer != NULL)
            {
                return true;
            }
        }
    }

    return false;
}
