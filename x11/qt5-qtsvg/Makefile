# $NetBSD: Makefile,v 1.27 2018/08/22 09:48:04 wiz Exp $

DISTNAME=	qtsvg-everywhere-src-${QTVERSION}
PKGNAME=	qt5-qtsvg-${QTVERSION}
PKGREVISION=	2
COMMENT=	Qt5 module for SVG

BUILD_TARGET=		sub-src
MAKE_ENV+=		QTDIR=${QTDIR}

INSTALL_ENV+=		INSTALL_ROOT=${DESTDIR}
INSTALLATION_DIRS+=	lib/pkgconfig

.include "../../x11/qt5-qtbase/Makefile.common"

post-install:
.for i in Qt5Svg.pc
	cd ${DESTDIR}${PREFIX}/lib/pkgconfig && \
	ln -f -s ${QTPREFIX}/lib/pkgconfig/${i} ${i}
.endfor

.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
