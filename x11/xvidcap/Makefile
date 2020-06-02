# $NetBSD: Makefile,v 1.35 2020/06/02 08:25:05 adam Exp $

DISTNAME=	xvidcap-1.1.7
PKGREVISION=	1
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=xvidcap/}

MAINTAINER=	reed@reedmedia.net
HOMEPAGE=	http://xvidcap.sourceforge.net/
COMMENT=	Capture X display to individual frames or MPEG video
LICENSE=	gnu-gpl-v3

SUPERSEDES=	xvidcap-gtk2-[0-9]*

GNU_CONFIGURE=	yes

USE_TOOLS+=	gmake perl pkg-config
USE_TOOLS+=	intltool msgfmt msgmerge xgettext

REPLACE_SH+=	ppm2mpeg.sh

# Don't require gnome-doc-utils
CONFIGURE_ENV+=	ac_cv_path_XML2PO=no

# Breaks recording in current X servers
# https://sourceforge.net/p/xvidcap/bugs/77/
CONFIGURE_ENV+=	ac_cv_func_shmat=no

.include "../../mk/oss.buildlink3.mk"
.if ${OSS_TYPE} != "none"
LDFLAGS+=		-lossaudio
SUBST_CLASSES+=		oss
SUBST_STAGE.oss=	pre-configure
SUBST_MESSAGE.oss=	Correcting the path to the OSS device.
SUBST_FILES.oss+=	src/app_data.c
SUBST_SED.oss+=		-e "s,/dev/dsp,${DEVOSSAUDIO},g"
.  if ${OPSYS} == "NetBSD" || ${OPSYS} == "SunOS"
SUBST_CLASSES+=		sr
SUBST_STAGE.sr=		pre-configure
SUBST_MESSAGE.sr=	Setting a nicer default audio sample rate.
SUBST_FILES.sr+=	src/app_data.c
SUBST_SED.sr+=		-e "s|sndrate = 44100|sndrate = 48000|g"
.  endif
.endif

CONFIGURE_ARGS+=	--with-forced-embedded-ffmpeg

.include "options.mk"
.include "../../devel/libglade/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../x11/libXdamage/buildlink3.mk"
.include "../../x11/libXfixes/buildlink3.mk"
.include "../../x11/libXmu/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
.include "../../mk/omf-scrollkeeper.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/jpeg.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
