# $NetBSD: Makefile,v 1.20 2020/11/05 09:07:20 ryoon Exp $

DISTNAME=	qtcharts-everywhere-src-${QTVERSION}
PKGNAME=	qt5-qtcharts-${QTVERSION}
PKGREVISION=	1
COMMENT=	Qt5 module for charts framework

BUILD_TARGET=		sub-src
INSTALL_ENV+=		INSTALL_ROOT=${DESTDIR}
INSTALLATION_DIRS+=	lib/pkgconfig

.include "../../x11/qt5-qtbase/Makefile.common"

post-install:
.for i in Qt5Charts.pc
	cd ${DESTDIR}${PREFIX}/lib/pkgconfig && \
	${LN} -f -s ${QTPREFIX}/lib/pkgconfig/${i} ${i}
.endfor

.include "../../x11/qt5-qtdeclarative/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
