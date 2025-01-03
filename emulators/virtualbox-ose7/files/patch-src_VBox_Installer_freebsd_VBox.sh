--- src/VBox/Installer/freebsd/VBox.sh.orig	2024-12-21 19:54:47 UTC
+++ src/VBox/Installer/freebsd/VBox.sh
@@ -0,0 +1,74 @@
+#!/bin/sh
+#
+# Oracle VM VirtualBox startup script, FreeBSD hosts.
+#
+# Copyright (C) 2006-2012 Oracle Corporation
+#
+# This file is part of VirtualBox Open Source Edition (OSE), as
+# available from http://www.virtualbox.org. This file is free software;
+# you can redistribute it and/or modify it under the terms of the GNU
+# General Public License (GPL) as published by the Free Software
+# Foundation, in version 2 as it comes in the "COPYING" file of the
+# VirtualBox OSE distribution. VirtualBox OSE is distributed in the
+# hope that it will be useful, but WITHOUT ANY WARRANTY of any kind.
+#
+
+PATH="/sbin:/bin:/usr/sbin:/usr/bin:/usr/local/sbin:/usr/local/bin"
+CONFIG="/usr/local/etc/vbox/vbox.cfg"
+
+test -r "${CONFIG}" &&
+    . "${CONFIG}"
+test -z "${INSTALL_DIR}" &&
+    if test -d /usr/local/lib/virtualbox &&
+        test -f /usr/local/lib/virtualbox/VBoxRT.so; then
+        INSTALL_DIR=/usr/local/lib/virtualbox
+    else
+        >&2 echo "Could not find VirtualBox installation. Please reinstall."
+        exit 1
+    fi
+
+if [ -d /etc/vbox ]; then
+    >&2 cat <<-EOH
+	WARNING: Directory /etc/vbox found, but ignored. VirtualBox
+	         configuration files are stored in /usr/local/etc/vbox/.
+	EOH
+fi
+
+# workaround for the KDE dialog problem
+KDE_FORK_SLAVES=1; export KDE_FORK_SLAVES
+
+APP=`basename $0`
+case "$APP" in
+    VirtualBox|virtualbox)
+        exec "$INSTALL_DIR/VirtualBox" "$@"
+        ;;
+    VirtualBoxVM|virtualboxvm)
+        exec "$INSTALL_DIR/VirtualBoxVM" "$@"
+        ;;
+    VBoxManage|vboxmanage)
+        exec "$INSTALL_DIR/VBoxManage" "$@"
+        ;;
+    VBoxSDL|vboxsdl)
+        exec "$INSTALL_DIR/VBoxSDL" "$@"
+        ;;
+    VBoxVRDP|VBoxHeadless|vboxheadless)
+        exec "$INSTALL_DIR/VBoxHeadless" "$@"
+        ;;
+    VBoxAutostart|vboxautostart)
+        exec "$INSTALL_DIR/VBoxAutostart" "$@"
+        ;;
+    VBoxBalloonCtrl|vboxballoonctrl)
+        exec "$INSTALL_DIR/VBoxBalloonCtrl" "$@"
+        ;;
+    VBoxBugReport|vboxbugreport)
+        exec "$INSTALL_DIR/VBoxBugReport" "$@"
+        ;;
+    vboxwebsrv)
+        exec "$INSTALL_DIR/vboxwebsrv" "$@"
+        ;;
+    *)
+        >&2 echo "Unknown application - $APP"
+        exit 1
+        ;;
+esac
+exit 0
