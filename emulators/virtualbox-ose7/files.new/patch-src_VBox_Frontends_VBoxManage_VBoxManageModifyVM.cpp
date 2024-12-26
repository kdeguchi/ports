--- src/VBox/Frontends/VBoxManage/VBoxManageModifyVM.cpp.orig	2024-10-10 18:30:44 UTC
+++ src/VBox/Frontends/VBoxManage/VBoxManageModifyVM.cpp
@@ -170,7 +170,7 @@ enum
     MODIFYVM_UARTMODE,
     MODIFYVM_UARTTYPE,
     MODIFYVM_UART,
-#if defined(RT_OS_LINUX) || defined(RT_OS_WINDOWS)
+#if defined(RT_OS_FREEBSD) || defined(RT_OS_LINUX) || defined(RT_OS_WINDOWS)
     MODIFYVM_LPTMODE,
     MODIFYVM_LPT,
 #endif
@@ -384,7 +384,7 @@ static const RTGETOPTDEF g_aModifyVMOptions[] =
     OPT2("--uart-mode",                     "--uartmode",               MODIFYVM_UARTMODE,                  RTGETOPT_REQ_STRING | RTGETOPT_FLAG_INDEX),
     OPT2("--uart-type",                     "--uarttype",               MODIFYVM_UARTTYPE,                  RTGETOPT_REQ_STRING | RTGETOPT_FLAG_INDEX),
     OPT1("--uart",                                                      MODIFYVM_UART,                      RTGETOPT_REQ_STRING | RTGETOPT_FLAG_INDEX),
-#if defined(RT_OS_LINUX) || defined(RT_OS_WINDOWS)
+#if defined(RT_OS_FREEBSD) || defined(RT_OS_LINUX) || defined(RT_OS_WINDOWS)
     OPT2("--lpt-mode",                      "--lptmode",                MODIFYVM_LPTMODE,                   RTGETOPT_REQ_STRING | RTGETOPT_FLAG_INDEX),
     OPT1("--lpt",                                                       MODIFYVM_LPT,                       RTGETOPT_REQ_STRING | RTGETOPT_FLAG_INDEX),
 #endif
@@ -2499,7 +2499,7 @@ RTEXITCODE handleModifyVM(HandlerArg *a)
                 break;
             }
 
-#if defined(RT_OS_LINUX) || defined(RT_OS_WINDOWS)
+#if defined(RT_OS_FREEBSD) || defined(RT_OS_LINUX) || defined(RT_OS_WINDOWS)
             case MODIFYVM_LPTMODE:
             {
                 ComPtr<IParallelPort> lpt;
