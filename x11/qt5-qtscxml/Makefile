# $NetBSD: Makefile,v 1.27 2023/11/08 13:21:38 wiz Exp $

DISTNAME=	qtscxml-everywhere-opensource-src-${QTVERSION}
PKGNAME=	qt5-qtscxml-${QTVERSION}
PKGREVISION=	2
COMMENT=	Qt5 module for scxml framework

BUILD_TARGET=		sub-src
INSTALL_ENV+=		INSTALL_ROOT=${DESTDIR}
INSTALLATION_DIRS+=	lib/pkgconfig

.include "../../x11/qt5-qtbase/Makefile.common"

post-install:
.for i in Qt5Scxml.pc
	cd ${DESTDIR}${PREFIX}/lib/pkgconfig && \
	${LN} -f -s ${QTPREFIX}/lib/pkgconfig/${i} ${i}
.endfor

.include "../../x11/qt5-qtdeclarative/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
