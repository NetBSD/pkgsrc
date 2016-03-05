# $NetBSD: Makefile,v 1.24 2016/03/05 11:28:00 jperkin Exp $

DISTNAME=	qtmultimedia-opensource-src-${QTVERSION}
PKGNAME=	qt5-qtmultimedia-${QTVERSION}
PKGREVISION=	2
COMMENT=	Qt5 module for multimedia

BUILD_TARGET=		sub-src
MAKE_ENV+=		QTDIR=${QTDIR}
INSTALL_ENV+=		INSTALL_ROOT=${DESTDIR}
INSTALLATION_DIRS+=	lib/pkgconfig

.include "../../x11/qt5-qtbase/Makefile.common"

.if ${OPSYS} != "Darwin"
MAKE_ENV+=		LFLAGS=${COMPILER_RPATH_FLAG}${PREFIX}/lib/pulseaudio
.endif

post-install:
.for i in Qt5Multimedia.pc Qt5MultimediaQuick_p.pc Qt5MultimediaWidgets.pc
	cd ${DESTDIR}${PREFIX}/lib/pkgconfig && \
	ln -f -s ${QTPREFIX}/lib/pkgconfig/${i} ${i}
.endfor

PLIST_VARS+=		alsa
.if ${OPSYS} == "Linux"
.include "../../audio/alsa-lib/buildlink3.mk"
PLIST.alsa=		yes
.endif

.if ${OPSYS} != "Darwin"
.include "../../audio/openal/buildlink3.mk"
.include "../../audio/pulseaudio/buildlink3.mk"
.include "../../multimedia/gst-plugins1-base/buildlink3.mk"
.endif
.include "../../x11/qt5-qtdeclarative/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
