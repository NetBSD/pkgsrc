# $NetBSD: Makefile,v 1.21 2017/09/18 09:53:09 maya Exp $

DISTNAME=	qtsensors-opensource-src-${QTVERSION}
PKGNAME=	qt5-qtsensors-${QTVERSION}
PKGREVISION=	8
COMMENT=	Qt5 module for Sensors

BUILD_TARGET=		sub-src
MAKE_ENV+=		QTDIR=${QTDIR}

INSTALL_ENV+=		INSTALL_ROOT=${DESTDIR}
INSTALLATION_DIRS+=	lib/pkgconfig

.include "../../x11/qt5-qtbase/Makefile.common"

post-install:
.for i in Qt5Sensors.pc
	cd ${DESTDIR}${PREFIX}/lib/pkgconfig && \
	ln -f -s ${QTPREFIX}/lib/pkgconfig/${i} ${i}
.endfor

.include "../../x11/qt5-qtdeclarative/buildlink3.mk"
.include "../../x11/qt5-qtsvg/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
