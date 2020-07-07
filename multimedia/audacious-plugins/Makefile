# Created by: Zastupov Stepan [RedChrom] <redchrom@mail.ru>
# $FreeBSD: multimedia/audacious-plugins/Makefile 2545 2020-06-08 03:39:43Z  $

PORTNAME=	audacious-plugins
PORTVERSION=	3.10.1
PORTREVISION=	6
CATEGORIES=	multimedia audio
MASTER_SITES=	http://distfiles.audacious-media-player.org/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Plugins needed for audacious

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	audacious:multimedia/audacious
LIB_DEPENDS=	libdbus-glib-1.so:devel/dbus-glib \
		libdbus-1.so:devel/dbus \
		libfontconfig.so:x11-fonts/fontconfig \
		libfreetype.so:print/freetype2
RUN_DEPENDS=	audacious:multimedia/audacious

USES=		compiler:c++11-lib gettext-tools gmake gnome iconv \
		localbase pkgconfig tar:bzip2 xorg
USE_GNOME=	gtk20 glib20 libxml2 cairo gdkpixbuf2
USE_XORG=	x11

CONFLICTS_INSTALL=	audacious-plugins-gtk3-3.*

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-console \
		--enable-gtk --enable-hotkey

#OPTIONS_DEFINE=	AAC ADPLUG AMIDI AMPACHE AOSD BS2B \

OPTIONS_DEFINE=	AAC ADPLUG AMIDI AOSD BS2B \
		CDDA CUE FFMPEG FLAC LAME LIRC MMS MODPLUG MP3 \
		MPRIS NEON NLS NOTIFY OPENGL QT5 QT5AUDIO QT5GLSPECTRUM \
		SAMPLERATE SCROBBLER SID SNDFILE SOXR SPEEDPITCH VORBIS WAVPACK
OPTIONS_MULTI=		OUTPUT
OPTIONS_MULTI_OUTPUT=	ALSA FILEWRITER JACK OSS PULSEAUDIO SDL SNDIO
OPTIONS_DEFAULT=AAC AOSD CDDA CUE FFMPEG FILEWRITER FLAC MP3 \
		MMS MPRIS NEON NLS NOTIFY OSS SCROBBLER VORBIS WAVPACK
OPTIONS_SUB=	yes

ADPLUG_DESC=	AdLib emulator
AMIDI_DESC=	Amidi decoder
AMPACHE_DESC=	Ampache browser (require Qt)
AOSD_DESC=	Audacious OSD
BS2B_DESC=	BS2B effect
FILEWRITER_DESC=File writer
MPRIS_DESC=	NPRIS plugin
NEON_DESC=	Neon plugin
QT5AUDIO_DESC=	Qt multimedia output
QT5GLSPECTRUM_DESC=	Qt opengl spectrum analyzer
SCROBBLER_DESC=	Scrobbler decoder
SID_DESC=	Sound chip emulator of Commodore
SPEEDPITCH_DESC=Speed and Pitch plugin

AAC_LIB_DEPENDS=	libfaad.so:audio/faad
AAC_CONFIGURE_ENABLE=	aac
ADPLUG_CONFIGURE_ENABLE=	adplug
ADPLUG_LIB_DEPENDS=	libadplug.so:audio/libadplug
ALSA_LIB_DEPENDS=	libasound.so:audio/alsa-lib
ALSA_CONFIGURE_ENABLE=	alsa
AMIDI_LIB_DEPENDS=	libfluidsynth.so:audio/fluidsynth
AMIDI_CONFIGURE_ENABLE=	amidiplug
AMPACHE_CONFIGURE_ENABLE=	ampache
AMPACHE_IMPLIES=	QT5
AOSD_USES=		xorg
AOSD_USE=		gnome=pango xorg=xrender,xcomposite
AOSD_CONFIGURE_ENABLE=	aosd
BS2B_LIB_DEPENDS=	libbs2b.so:audio/libbs2b
BS2B_CONFIGURE_ENABLE=	bs2b
CDDA_LIB_DEPENDS=	libcdio_cdda.so:sysutils/libcdio-paranoia \
			libcddb.so:audio/libcddb \
			libcdio.so:sysutils/libcdio
CDDA_CONFIGURE_ENABLE=	cdaudio
CUE_LIB_DEPENDS=	libcue.so:textproc/libcue
CUE_CONFIGURE_ENABLE=	cue
FFMPEG_LIB_DEPENDS=	libavcodec.so:multimedia/ffmpeg
FFMPEG_CONFIGURE_WITH=	ffmpeg=ffmpeg
FILEWRITER_CONFIGURE_ENABLE=	filewriter
FLAC_LIB_DEPENDS=	libFLAC.so:audio/flac
FLAC_CONFIGURE_ENABLE=	flac
JACK_LIB_DEPENDS=	libjack.so:audio/jack \
			libsamplerate.so:audio/libsamplerate
JACK_CONFIGURE_ENABLE=	jack
LAME_LIB_DEPENDS=	libmp3lame.so:audio/lame
LAME_CONFIGURE_ENABLE=	filewriter_mp3
LIRC_LIB_DEPENDS=	liblirc_client.so:comms/lirc
LIRC_CONFIGURE_ENABLE=	lirc
MP3_LIB_DEPENDS=	libmpg123.so:audio/mpg123
MP3_CONFIGURE_ENABLE=	mpg123
MMS_LIB_DEPENDS=	libmms.so:net/libmms
MMS_CONFIGURE_ENABLE=	mms
MODPLUG_LIB_DEPENDS=	libmodplug.so:audio/libmodplug
MODPLUG_CONFIGURE_ENABLE=	modplug
MPRIS_CONFIGURE_ENABLE=	mpris2
NEON_LIB_DEPENDS=	libneon.so:www/neon
NEON_CONFIGURE_ENABLE=	neon
NLS_USES=		gettext-runtime
NLS_CONFIGURE_ENABLE=	nls
NOTIFY_LIB_DEPENDS=	libnotify.so:devel/libnotify
NOTIFY_CONFIGURE_ENABLE=notify
OPENGL_USES=		gl xorg
OPENGL_USE=		xorg=x11 gl=gl
OPENGL_CONFIGURE_ENABLE=glspectrum
OSS_CONFIGURE_ENABLE=	oss4
PULSEAUDIO_LIB_DEPENDS=	libpulse-mainloop-glib.so:audio/pulseaudio
PULSEAUDIO_CONFIGURE_ENABLE=	pulse
QT5_CONFIGURE_ENABLE=	qt
QT5_USES=	qt:5
QT5_USE=	qt=qmake_build,buildtools_build,core,gui,widgets
QT5AUDIO_CONFIGURE_ENABLE=	qtaudio
QT5AUDIO_USE=	qt=multimedia
QT5AUDIO_IMPLIES=	QT5
QT5GLSPECTRUM_CONFIGURE_ENABLE=	qtglspectrum
QT5GLSPECTRUM_AUDIO_USE=	qt=opengl
QT5GLSPECTRUM_IMPLIES=	QT5
SAMPLERATE_LIB_DEPENDS=	libsamplerate.so:audio/libsamplerate
SAMPLERATE_CONFIGURE_ENABLE=	resample
SCROBBLER_LIB_DEPENDS=	libcurl.so:ftp/curl
SCROBBLER_CONFIGURE_ENABLE=	scrobbler2
SDL_CONFIGURE_ON=	--enable-sdlout --with-libsdl=2
SDL_CONFIGURE_OFF=	--disable-sdlout
SDL_USES=		sdl
SDL_USE=		SDL=sdl2
SID_LIB_DEPENDS=	libsidplayfp.so:audio/libsidplayfp
SID_CONFIGURE_ENABLE=	sid
SNDFILE_LIB_DEPENDS=	libsndfile.so:audio/libsndfile
SNDFILE_CONFIGURE_ENABLE=	sndfile
SNDIO_LIB_DEPENDS=	libsndio.so:audio/sndio
SNDIO_CONFIGURE_ENABLE=	sndio
SOXR_CONFIGURE_ENABLE=	soxr
SOXR_LIB_DEPENDS=	libsoxr.so:audio/libsoxr
SPEEDPITCH_CONFIGURE_ENABLE=	speedpitch
SPEEDPITCH_IMPLIES=	SAMPLERATE
VORBIS_LIB_DEPENDS=	libvorbis.so:audio/libvorbis \
			libogg.so:audio/libogg
VORBIS_CONFIGURE_ENABLE=vorbis
WAVPACK_LIB_DEPENDS=	libwavpack.so:audio/wavpack
WAVPACK_CONFIGURE_ENABLE=	wavpack

post-patch:
	@${REINPLACE_CMD} -e 's| $${MFLAGS}||g' \
		${WRKSRC}/buildsys.mk.in
	@${FIND} ${WRKSRC} -type f -name 'Makefile' \
		| ${XARGS} ${REINPLACE_CMD} -e 's| -Wno-bool-operation||'

post-patch-NLS-off:
	${REINPLACE_CMD} -e 's,po,,' ${WRKSRC}/Makefile

post-install:
	@${FIND} ${STAGEDIR}${PREFIX}/lib/audacious/ -name "*.so" \
		-exec ${STRIP_CMD} {} \;

.include <bsd.port.mk>
