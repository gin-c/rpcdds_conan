#ifndef _RPC_CONFIG_H_
#define _RPC_CONFIG_H_

#ifndef RPC_VERSION_MAJOR
#define RPC_VERSION_MAJOR 1
#endif
#ifndef RPC_VERSION_MINOR
#define RPC_VERSION_MINOR 1
#endif
#ifndef RPC_VERSION_PATCH
#define RPC_VERSION_PATCH 1
#endif
#ifndef RPC_VERSION_STR
#define RPC_VERSION_STR "1.1.1"
#endif

#ifndef EPROSIMA_RPC_LIB_NAME
#define EPROSIMA_RPC_LIB_NAME rpcdds
#endif

// C++11 support defines
#ifndef HAVE_CXX11
#define HAVE_CXX11 1
#endif

// C++0x support defines
#ifndef HAVE_CXX0X
#define HAVE_CXX0X 1
#endif

// Endianness defines
#ifndef __BIG_ENDIAN__
#define __BIG_ENDIAN__ 0
#endif

#ifndef RPC_WITH_FASTRTPS
#define RPC_WITH_FASTRTPS 1
#endif

#ifndef RPC_WITH_RTIDDS
#define RPC_WITH_RTIDDS 0
#endif

#endif // _RPC_CONFIG_H_
