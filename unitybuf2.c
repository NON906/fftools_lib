#include "libavformat/unitybuf.h"

UnitybufStates *unitybuf_get_handle_dll2(const char *uri) {
    return unitybuf_get_handle_dll(uri);
}
int unitybuf_write_dll2(UnitybufStates *handle, const unsigned char *buf, int size) {
    return unitybuf_write_dll(handle, buf, size);
}
int unitybuf_read_dll2(UnitybufStates *handle, unsigned char *buf, int size) {
    return unitybuf_read_dll(handle, buf, size);
}
int unitybuf_clear_dll2(UnitybufStates *handle) {
    return unitybuf_clear_dll(handle);
}
int unitybuf_count_dll2(UnitybufStates *handle) {
    return unitybuf_count_dll(handle);
}