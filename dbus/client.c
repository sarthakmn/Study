#include <dbus/dbus.h>
#include <stdio.h>

int main() {
    DBusError err;
    DBusConnection* conn;
    DBusMessage* msg;
    DBusMessage* reply;

    dbus_error_init(&err);

    conn = dbus_bus_get(DBUS_BUS_SESSION, &err);

    msg = dbus_message_new_method_call(
        "com.example.Service",
        "/com/example/service",
        "com.example.Service",
        "Hello"
    );

    const char* text = "Hello Server";

    dbus_message_append_args(msg,
                             DBUS_TYPE_STRING, &text,
                             DBUS_TYPE_INVALID);

    reply = dbus_connection_send_with_reply_and_block(conn,
                                                      msg,
                                                      -1,
                                                      &err);

    char* response;

    dbus_message_get_args(reply,
                          &err,
                          DBUS_TYPE_STRING,
                          &response,
                          DBUS_TYPE_INVALID);

    printf("Reply: %s\n", response);

    dbus_message_unref(msg);
    dbus_message_unref(reply);

    return 0;
}
