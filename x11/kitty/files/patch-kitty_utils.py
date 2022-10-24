--- kitty/utils.py.orig	2022-10-24 00:16:35 UTC
+++ kitty/utils.py
@@ -32,6 +32,10 @@ if TYPE_CHECKING:
 else:
     Options = object
 
+import ctypes
+libutempter = ctypes.CDLL('libutempter.so')
+libutempter.utempter_add_record.argtypes = [ctypes.c_int, ctypes.c_char_p]
+libutempter.utempter_remove_record.argtypes = [ctypes.c_int]
 
 class Flag:
 
@@ -526,10 +530,16 @@ class TTYIO:
 
     def __enter__(self) -> 'TTYIO':
         self.tty_fd, self.original_termios = open_tty(self.read_with_timeout)
+        print('self.tty_fd =', self.tty_fd, file=sys.stderr)
+        ret = libutempter.utempter_add_record(self.tty_fd, None)
+        print('libutempter ret = ', ret, file=sys.stderr)
         return self
 
     def __exit__(self, *a: Any) -> None:
         from .fast_data_types import close_tty
+        print('self.tty_fd =', self.tty_fd, file=sys.stderr)
+        ret = libutempter.utempter_remove_record(self.tty_fd)
+        print('libutempter ret = ', ret, file=sys.stderr)
         close_tty(self.tty_fd, self.original_termios)
 
     def wait_till_read_available(self) -> bool:
