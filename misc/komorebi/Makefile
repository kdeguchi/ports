# $FreeBSD$

PORTNAME=	komorebi
DISTVERSION=	1.1
CATEGORIES=	misc

MAINTAINER=	fjachuf@gmail.com
COMMENT=	Animated Wallpaper for your desktop

LICENSE=	BSD3CLAUSE

BUILD_DEPENDS=	${LOCALBASE}/bin/bash:shells/bash \
		${LOCALBASE}/bin/cmake:devel/cmake \
		${LOCALBASE}/bin/vala:lang/vala
LIB_DEPENDS=	libgee-0.8.so:devel/libgee \
		libgtk-3.so:x11-toolkits/gtk30 \
		libglib-2.0.so:devel/glib20 \
		libwebkit2gtk-4.0.so:www/webkit2-gtk3 \
		libclutter-gtk-1.0.so:graphics/clutter-gtk3 \
		libclutter-1.0.so:graphics/clutter \
		libclutter-gst-3.0.so:multimedia/clutter-gst3 \
		libsoup-2.4.so:devel/libsoup \
		libcogl-path.so:graphics/cogl \
		libcairo-gobject.so:graphics/cairo \
		libatk-1.0.so:accessibility/atk \
		libcogl-pango.so:graphics/cogl \
		libpangocairo-1.0.so:x11-toolkits/pango \
		libpango-1.0.so:x11-toolkits/pango \
		libjson-glib-1.0.so:devel/json-glib \
		libXi.so:x11/libXi \
		libcogl.so:graphics/cogl \
		libcairo.so:graphics/cairo \
		libgdk_pixbuf-2.0.so:graphics/gdk-pixbuf2 \
		libEGL.so:graphics/mesa-libs \
		libX11.so:x11/libX11 \
		libXext.so:x11/libXext \
		libXdamage.so:x11/libXdamage \
		libXfixes.so:x11/libXfixes \
		libXcomposite.so:x11/libXcomposite \
		libXrandr.so:x11/libXrandr \
		libintl.so:devel/gettext-runtime

USES=	cmake pkgconfig
USE_GSTREAMER1=libav

USE_GITHUB=	yes
GH_ACCOUNT=	SrWither
GH_PROJECT=	KomorebiBSD
GH_TAGNAME=	1.1

.include <bsd.port.mk>
