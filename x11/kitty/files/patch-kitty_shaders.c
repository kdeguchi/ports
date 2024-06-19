--- kitty/shaders.c.orig	1979-11-29 15:00:00 UTC
+++ kitty/shaders.c
@@ -601,7 +601,7 @@ draw_scroll_indicator(bool premult, Screen *screen, co
     if (premult) { BLEND_PREMULT } else { BLEND_ONTO_OPAQUE }
     bind_program(TINT_PROGRAM);
     const color_type bar_color = colorprofile_to_color(screen->color_profile, screen->color_profile->overridden.highlight_bg, screen->color_profile->configured.highlight_bg).rgb;
-    GLfloat alpha = 0.8f;
+    GLfloat alpha = OPT(scrollback_indicator_opacity);
     float frac = (float)screen->scrolled_by / (float)screen->historybuf->count;
     const GLfloat bar_height = crd->gl.dy;
     GLfloat bottom = (crd->gl.ystart - crd->gl.height);
