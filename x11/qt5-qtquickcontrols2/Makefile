# $NetBSD: Makefile,v 1.22 2020/04/02 22:05:58 adam Exp $

DISTNAME=	qtquickcontrols2-everywhere-src-${QTVERSION}
PKGNAME=	qt5-qtquickcontrols2-${QTVERSION}
COMMENT=	Next generation user interface controls based on Qt Quick

BUILD_TARGET=		sub-src
MAKE_ENV+=		QTDIR=${QTDIR}

INSTALL_ENV+=		INSTALL_ROOT=${DESTDIR}
INSTALLATION_DIRS+=	lib/pkgconfig

.include "../../x11/qt5-qtbase/Makefile.common"

post-install:
.for i in Qt5QuickControls2.pc
	cd ${DESTDIR}${PREFIX}/lib/pkgconfig && \
	${LN} -f -s ${QTPREFIX}/lib/pkgconfig/${i} ${i}
.endfor

.include "../../x11/qt5-qtdeclarative/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
