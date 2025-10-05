--- aq_hw.c.orig	2022-01-25 07:53:28 UTC
+++ aq_hw.c
@@ -32,7 +32,6 @@
  * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
  */
 
-#include <unistd.h>
 #include <sys/endian.h>
 #include <sys/param.h>
 #include <sys/systm.h>
@@ -40,10 +39,9 @@
 #include <sys/socket.h>
 #include <net/if.h>
 
-#include "aq_hw.h"
+#include "aq.h"
 #include "aq_dbg.h"
 #include "aq_hw_llh.h"
-#include "aq_fw.h"
 
 #define AQ_HW_FW_SM_RAM        0x2U
 #define AQ_CFG_FW_MIN_VER_EXPECTED 0x01050006U
