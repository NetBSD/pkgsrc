# $NetBSD: Makefile,v 1.60 2023/06/10 18:23:07 adam Exp $

DISTNAME=	qtxmlpatterns-everywhere-opensource-src-${QTVERSION}
PKGNAME=	qt5-qtxmlpatterns-${QTVERSION}
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
