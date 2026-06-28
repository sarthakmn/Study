#include <dbus/dbus.h>
#include <stdio.h>
#include <stdlib.h>

int main() {
    DBusError err;
    DBusConnection* conn;
    DBusMessage* msg;

    dbus_error_init(&err);

    conn = dbus_bus_get(DBUS_BUS_SESSION, &err);

    dbus_bus_request_name(conn,
                          "com.example.Service",
                          DBUS_NAME_FLAG_REPLACE_EXISTING,
                          &err);

    printf("Server waiting for messages...\n");

    while (1) {
        dbus_connection_read_write(conn, 0);
        msg = dbus_connection_pop_message(conn);

        if (msg == NULL)
            continue;

        if (dbus_message_is_method_call(msg,
            "com.example.Service",
            "Hello")) {

            char* name;
            dbus_message_get_args(msg, &err,
                                  DBUS_TYPE_STRING, &name,
                                  DBUS_TYPE_INVALID);

            printf("Received: %s\n", name);

            DBusMessage* reply;
            reply = dbus_message_new_method_return(msg);

            const char* response = "Hello from server";

            dbus_message_append_args(reply,
                                     DBUS_TYPE_STRING, &response,
                                     DBUS_TYPE_INVALID);

            dbus_connection_send(conn, reply, NULL);
            dbus_connection_flush(conn);

            dbus_message_unref(reply);
        }

        dbus_message_unref(msg);
    }
}
