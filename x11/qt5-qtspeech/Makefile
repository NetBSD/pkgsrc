# $NetBSD: Makefile,v 1.61 2026/09/02 19:05:29 wiz Exp $

DISTNAME=	qtspeech-everywhere-opensource-src-${QTVERSION}
PKGNAME=	qt5-qtspeech-${QTVERSION}
PKGREVISION=	2

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
