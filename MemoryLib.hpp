extern "C"
{
    #include <Base.h>
    #include <Uefi.h>
    #include <Library/UefiLib.h>
    #include <Library/BaseMemoryLib.h>
    #include <Library/MemoryAllocationLib.h>
    #include <sal.h>
}

#define EINVAL 22
#define ERANGE 34

#define NO_WARNING(Function) \
    do \
    { \
        __pragma(warning(push, 1)) \
        Function; \
        __pragma(warning(pop)) \
    } \
    while (0)

typedef int errno_t;
typedef size_t rsize_t;

extern "C"
void*
__cdecl
calloc(
    _In_ const size_t _Count,
    _In_ const size_t _Size
);

extern "C"
void*
__cdecl
malloc(
    _In_ const size_t _Size
);

extern "C"
void
__cdecl
free(
    _In_ _Pre_maybenull_ _Post_invalid_ void* _Block
);

extern "C"
__declspec(deprecated("memcpy may be unsafe, consider using memcpy_s instead."))
void*
__cdecl
memcpy(
    _Out_ _Pre_maybenull_ void* _Dst,
    _In_ _Pre_maybenull_ const void* _Src,
    _In_ const size_t _Size
);

extern "C"
errno_t
__cdecl
memcpy_s(
    _Out_ void* _Dst,
    _In_ const rsize_t _DstSize,
    _In_ const void* _Src,
    _In_ const rsize_t _Size
);

extern "C"
void*
__cdecl
realloc(
    _In_ _Pre_maybenull_ _Post_invalid_ void* _Block,
    _In_ const size_t _Size
);

void*
operator
new(
    _In_ const size_t _Size
) noexcept;

void*
operator
new[](
    _In_ const size_t _Size
) noexcept;

void
operator
delete(
    _In_ _Pre_maybenull_ _Post_invalid_ void* _Block
) noexcept;

void
operator
delete[](
    _In_ _Pre_maybenull_ _Post_invalid_ void* _Block
) noexcept;

void*
operator
new(
    _In_ const size_t _Size,
    _In_ _Pre_maybenull_ void* _Block
) noexcept;

void*
operator
new[](
    _In_ const size_t _Size,
    _In_ _Pre_maybenull_ void* _Block
) noexcept;

void
operator
delete(
    _In_ _Pre_maybenull_ _Post_invalid_ void* _Block,
    _In_ const size_t _Size
) noexcept;

void
operator
delete[](
    _In_ _Pre_maybenull_ _Post_invalid_ void* _Block,
    _In_ const size_t _Size
) noexcept;