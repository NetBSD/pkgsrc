# $NetBSD: Makefile,v 1.25 2023/06/10 18:23:05 adam Exp $

DISTNAME=	qtscxml-everywhere-opensource-src-${QTVERSION}
PKGNAME=	qt5-qtscxml-${QTVERSION}
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
