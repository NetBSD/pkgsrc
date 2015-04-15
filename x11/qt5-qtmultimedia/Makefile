# $NetBSD: Makefile,v 1.15 2015/04/15 13:13:44 joerg Exp $

DISTNAME=	qtmultimedia-opensource-src-${QTVERSION}
PKGNAME=	qt5-qtmultimedia-${QTVERSION}
PKGREVISION=	4
COMMENT=	Qt5 module for multimedia

BUILD_TARGET=		sub-src
MAKE_ENV+=		QTDIR=${QTDIR}
INSTALL_ENV+=		INSTALL_ROOT=${DESTDIR}
INSTALLATION_DIRS+=	lib/pkgconfig

.include "../../x11/qt5-qtbase/Makefile.common"

_WRAP_EXTRA_ARGS.CXX+= -L${PREFIX}/lib/pulseaudio

post-install:
.for i in Qt5Multimedia.pc Qt5MultimediaQuick_p.pc Qt5MultimediaWidgets.pc
	cd ${DESTDIR}${PREFIX}/lib/pkgconfig && \
	ln -f -s ${QTPREFIX}/lib/pkgconfig/${i} ${i}
.endfor

.if ${OPSYS} != "Darwin"
.include "../../audio/openal/buildlink3.mk"
.include "../../audio/pulseaudio/buildlink3.mk"
.include "../../multimedia/gst-plugins0.10-base/buildlink3.mk"
.endif
.include "../../x11/qt5-qtdeclarative/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
