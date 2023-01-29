# $NetBSD: Makefile,v 1.55 2023/01/29 21:15:18 ryoon Exp $

DISTNAME=	qtxmlpatterns-everywhere-opensource-src-${QTVERSION}
PKGNAME=	qt5-qtxmlpatterns-${QTVERSION}
PKGREVISION=	1
COMMENT=	Qt5 module for XML Patterns

BUILD_TARGET=		sub-tools

INSTALL_ENV+=		INSTALL_ROOT=${DESTDIR}
INSTALLATION_DIRS+=	lib/pkgconfig

.include "../../x11/qt5-qtbase/Makefile.common"

post-install:
.for i in Qt5XmlPatterns.pc
	cd ${DESTDIR}${PREFIX}/lib/pkgconfig && \
	${LN} -f -s ${QTPREFIX}/lib/pkgconfig/${i} ${i}
.endfor

.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
