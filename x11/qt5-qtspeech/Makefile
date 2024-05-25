# $NetBSD: Makefile,v 1.45 2024/05/25 14:21:21 adam Exp $

DISTNAME=	qtspeech-everywhere-opensource-src-${QTVERSION}
PKGNAME=	qt5-qtspeech-${QTVERSION}
COMMENT=	Qt5 module to make text to speech and speech recognition easy

MAKE_ENV+=		QTDIR=${QTDIR}
INSTALL_ENV+=		INSTALL_ROOT=${DESTDIR}
INSTALLATION_DIRS+=	lib/pkgconfig

.include "../../x11/qt5-qtbase/Makefile.common"

post-install:
.for i in Qt5TextToSpeech.pc
	cd ${DESTDIR}${PREFIX}/lib/pkgconfig && \
	${LN} -f -s ${QTPREFIX}/lib/pkgconfig/${i} ${i}
.endfor

.include "../../x11/qt5-qtmultimedia/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
