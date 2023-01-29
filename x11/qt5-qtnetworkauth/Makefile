# $NetBSD: Makefile,v 1.28 2023/01/29 21:15:16 ryoon Exp $

DISTNAME=	qtnetworkauth-everywhere-opensource-src-${QTVERSION}
PKGNAME=	qt5-qtnetworkauth-${QTVERSION}
PKGREVISION=	1
COMMENT=	Qt5 module for networkauth framework

BUILD_TARGET=		sub-src
INSTALL_ENV+=		INSTALL_ROOT=${DESTDIR}
INSTALLATION_DIRS+=	lib/pkgconfig

.include "../../x11/qt5-qtbase/Makefile.common"

post-install:
.for i in Qt5NetworkAuth.pc
	cd ${DESTDIR}${PREFIX}/lib/pkgconfig && \
	${LN} -f -s ${QTPREFIX}/lib/pkgconfig/${i} ${i}
.endfor

.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
