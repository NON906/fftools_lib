#ifdef _WIN32
#define DLL_EXPORT __declspec(dllexport)
#else
#define DLL_EXPORT 
#endif

#include "libavformat/unitybuf.h"

DLL_EXPORT UnitybufStates *unitybuf_get_handle_dll2(const char *uri) {
    return unitybuf_get_handle_dll(uri);
}
DLL_EXPORT int unitybuf_write_dll2(UnitybufStates *handle, const unsigned char *buf, int size) {
    return unitybuf_write_dll(handle, buf, size);
}
DLL_EXPORT int unitybuf_read_dll2(UnitybufStates *handle, unsigned char *buf, int size) {
    return unitybuf_read_dll(handle, buf, size);
}
DLL_EXPORT int unitybuf_clear_dll2(UnitybufStates *handle) {
    return unitybuf_clear_dll(handle);
}
DLL_EXPORT int unitybuf_count_dll2(UnitybufStates *handle) {
    return unitybuf_count_dll(handle);
}