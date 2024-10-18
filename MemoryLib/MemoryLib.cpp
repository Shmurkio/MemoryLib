#include <Library/MemoryLib.hpp>

extern "C"
void*
__cdecl
calloc(
    _In_ const size_t _Count,
    _In_ const size_t _Size
)
{
    return AllocateZeroPool(_Count * _Size);
}

extern "C"
void*
__cdecl
malloc(
    _In_ const size_t _Size
)
{
    return AllocatePool(_Size);
}

extern "C"
void
__cdecl
free(
    _In_ _Pre_maybenull_ _Post_invalid_ void* _Block
)
{
    FreePool(_Block);
}

extern "C"
__declspec(deprecated("memcpy may be unsafe, consider using memcpy_s instead."))
void*
__cdecl
memcpy(
    _Out_ _Pre_maybenull_ void* _Dst,
    _In_ _Pre_maybenull_ const void* _Src,
    _In_ const size_t _Size
)
{
    return CopyMem(_Dst, _Src, _Size);
}

extern "C"
errno_t
__cdecl
memcpy_s(
    _Out_ void* _Dst,
    _In_ const rsize_t _DstSize,
    _In_ const void* _Src,
    _In_ const rsize_t _Size
)
{
    if (_Dst == nullptr || _Src == nullptr)
    {
        return EINVAL;
    }

    if (_Size > _DstSize)
    {
        return ERANGE;
    }

    NO_WARNING(memcpy(_Dst, _Src, _Size));

    return 0;
}

extern "C"
void*
__cdecl
realloc(
    _In_ _Pre_maybenull_ _Post_invalid_ void* _Block,
    _In_ const size_t _Size
)
{
    void* NewBlock = malloc(_Size);

    if (NewBlock && _Block)
    {

        NO_WARNING(memcpy(NewBlock, _Block, _Size));
        free(_Block);
    }

    return NewBlock;
}

void*
operator
new(
    _In_ const size_t _Size
) noexcept
{
    return malloc(_Size);
}

void*
operator
new[](
    _In_ const size_t _Size
) noexcept
{
    return malloc(_Size);
}

void
operator
delete(
    _In_ _Pre_maybenull_ _Post_invalid_ void* _Block
) noexcept
{
    free(_Block);
}

void
operator
delete[](
    _In_ _Pre_maybenull_ _Post_invalid_ void* _Block
) noexcept
{
    free(_Block);
}

void*
operator
new(
    _In_ const size_t _Size,
    _In_ _Pre_maybenull_ void* _Block
) noexcept
{
    return _Block;
}

void*
operator
new[](
    _In_ const size_t _Size,
    _In_ _Pre_maybenull_ void* _Block
) noexcept
{
    return _Block;
}

void
operator
delete(
    _In_ _Pre_maybenull_ _Post_invalid_ void* _Block,
    _In_ const size_t _Size
) noexcept
{
    free(_Block);
}

void
operator
delete[](
    _In_ _Pre_maybenull_ _Post_invalid_ void* _Block,
    _In_ const size_t _Size
) noexcept
{
    free(_Block);
}