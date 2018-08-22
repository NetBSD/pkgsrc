# $NetBSD: Makefile,v 1.21 2018/08/22 09:48:04 wiz Exp $

DISTNAME=	qtmacextras-everywhere-src-${QTVERSION}
PKGNAME=	qt5-qtmacextras-${QTVERSION}
PKGREVISION=	2
COMMENT=	Qt5 module for Mac extras

BUILD_TARGET=		sub-src
INSTALL_ENV+=		INSTALL_ROOT=${DESTDIR}
INSTALLATION_DIRS+=	lib/pkgconfig

ONLY_FOR_PLATFORM=	Darwin-*-*

.include "../../x11/qt5-qtbase/Makefile.common"

post-install:
.for i in Qt5MacExtras.pc
	cd ${DESTDIR}${PREFIX}/lib/pkgconfig && \
	ln -f -s ${QTPREFIX}/lib/pkgconfig/${i} ${i}
.endfor

.include "../../x11/qt5-qtxmlpatterns/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
