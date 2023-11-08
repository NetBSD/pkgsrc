# $NetBSD: Makefile,v 1.56 2023/11/08 13:21:39 wiz Exp $

DISTNAME=	qtwebsockets-everywhere-opensource-src-${QTVERSION}
PKGNAME=	qt5-qtwebsockets-${QTVERSION}
PKGREVISION=	2
COMMENT=	Qt5 module for websockets

MAKE_ENV+=		QTDIR=${QTDIR}
INSTALL_ENV+=		INSTALL_ROOT=${DESTDIR}
INSTALLATION_DIRS+=	lib/pkgconfig

.include "../../x11/qt5-qtbase/Makefile.common"

post-install:
.for i in Qt5WebSockets.pc
	cd ${DESTDIR}${PREFIX}/lib/pkgconfig && \
	${LN} -f -s ${QTPREFIX}/lib/pkgconfig/${i} ${i}
.endfor

.include "../../x11/qt5-qtdeclarative/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
