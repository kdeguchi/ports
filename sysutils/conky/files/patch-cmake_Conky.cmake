--- cmake/Conky.cmake.orig	2021-04-26 14:48:46 UTC
+++ cmake/Conky.cmake
@@ -18,7 +18,7 @@
 # along with this program.  If not, see <http://www.gnu.org/licenses/>.
 #
 
-# set(RELEASE true)
+set(RELEASE true)
 
 # Set system vars
 if(CMAKE_SYSTEM_NAME MATCHES "Linux")
