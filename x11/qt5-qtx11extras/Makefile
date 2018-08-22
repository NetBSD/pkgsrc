# $NetBSD: Makefile,v 1.27 2018/08/22 09:48:05 wiz Exp $

DISTNAME=	qtx11extras-everywhere-src-${QTVERSION}
PKGNAME=	qt5-qtx11extras-${QTVERSION}
PKGREVISION=	2
COMMENT=	Qt5 module for X11 extras

BUILD_TARGET=		sub-src
INSTALL_ENV+=		INSTALL_ROOT=${DESTDIR}
INSTALLATION_DIRS+=	lib/pkgconfig

.include "../../x11/qt5-qtbase/Makefile.common"

post-install:
.for i in Qt5X11Extras.pc
	cd ${DESTDIR}${PREFIX}/lib/pkgconfig && \
	ln -f -s ${QTPREFIX}/lib/pkgconfig/${i} ${i}
.endfor

.include "../../x11/qt5-qtxmlpatterns/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
