# $NetBSD: Makefile,v 1.47 2020/11/05 09:07:22 ryoon Exp $

DISTNAME=	qtxmlpatterns-everywhere-src-${QTVERSION}
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
