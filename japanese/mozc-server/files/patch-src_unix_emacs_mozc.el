--- src/unix/emacs/mozc.el.orig	2022-07-23 14:02:59 UTC
+++ src/unix/emacs/mozc.el
@@ -1540,7 +1540,7 @@ Return the new value of `mozc-session-seq'."
 
 ;;;; Communication with Mozc server through the helper process
 
-(defvar mozc-helper-program-name "mozc_emacs_helper"
+(defvar mozc-helper-program-name "%%PREFIX%%/libexec/mozc_emacs_helper"
   "Helper program's name or path to the helper program.
 The helper program helps Emacs communicate with Mozc server,
 which doesn't understand S-expression.")
@@ -1961,12 +1961,12 @@ CONDITIONS is a list of error conditions and shouldn't
 
 ;;;###autoload
 (progn  ; Put the program code into the autoload file.
-  (defcustom mozc-leim-title "[Mozc]"
-    "Mode line string shown when function `mozc-mode' is enabled.
-This indicator is not shown when you don't use LEIM."
-    :type '(choice (const :tag "No indicator" nil)
-                   (string :tag "Show an indicator"))
-    :group 'mozc)
+;;  (defcustom mozc-leim-title "[Mozc]"
+;;    "Mode line string shown when function `mozc-mode' is enabled.
+;;This indicator is not shown when you don't use LEIM."
+;;    :type '(choice (const :tag "No indicator" nil)
+;;                   (string :tag "Show an indicator"))
+;;    :group 'mozc)
 
   (defun mozc-leim-register-input-method ()
     "Register function `mozc-mode' as an input method of LEIM.
@@ -1989,10 +1989,10 @@ Do nothing if LEIM is not available."
   ;; Register mozc-mode as an input method after the init file has been read
   ;; so the user has a chance to specify `mozc-leim-title' in the init file
   ;; after loading this file.
-  (add-hook 'emacs-startup-hook #'mozc-leim-register-input-method)
+  ;;(add-hook 'emacs-startup-hook #'mozc-leim-register-input-method)
   ;; In the case that `emacs-startup-hook' has already been run, especially
   ;; when the user loads this file interactively, register immediately.
-  (mozc-leim-register-input-method)
+  ;;(mozc-leim-register-input-method)
   )
 
 
