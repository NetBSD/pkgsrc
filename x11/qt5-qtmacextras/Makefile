# $NetBSD: Makefile,v 1.61 2024/05/29 16:35:11 adam Exp $

DISTNAME=	qtmacextras-everywhere-opensource-src-${QTVERSION}
PKGNAME=	qt5-qtmacextras-${QTVERSION}
PKGREVISION=	1
COMMENT=	Qt5 module for Mac extras

BUILD_TARGET=		sub-src
INSTALL_ENV+=		INSTALL_ROOT=${DESTDIR}
INSTALLATION_DIRS+=	lib/pkgconfig

ONLY_FOR_PLATFORM=	Darwin-*-*

.include "../../x11/qt5-qtbase/Makefile.common"

post-install:
.for i in Qt5MacExtras.pc
	cd ${DESTDIR}${PREFIX}/lib/pkgconfig && \
	${LN} -f -s ${QTPREFIX}/lib/pkgconfig/${i} ${i}
.endfor

.include "../../x11/qt5-qtxmlpatterns/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
