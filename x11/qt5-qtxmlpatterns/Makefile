# $NetBSD: Makefile,v 1.25 2018/06/19 07:21:25 adam Exp $

DISTNAME=	qtxmlpatterns-everywhere-src-${QTVERSION}
PKGNAME=	qt5-qtxmlpatterns-${QTVERSION}
COMMENT=	Qt5 module for XML Patterns

BUILD_TARGET=		sub-tools

INSTALL_ENV+=		INSTALL_ROOT=${DESTDIR}
INSTALLATION_DIRS+=	lib/pkgconfig

.include "../../x11/qt5-qtbase/Makefile.common"

post-install:
.for i in Qt5XmlPatterns.pc
	cd ${DESTDIR}${PREFIX}/lib/pkgconfig && \
	ln -f -s ${QTPREFIX}/lib/pkgconfig/${i} ${i}
.endfor

.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
