# $NetBSD: Makefile,v 1.2 2018/11/12 03:51:35 ryoon Exp $

DISTNAME=	qtnetworkauth-everywhere-src-${QTVERSION}
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
	ln -f -s ${QTPREFIX}/lib/pkgconfig/${i} ${i}
.endfor

.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
