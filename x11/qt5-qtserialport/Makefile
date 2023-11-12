# $NetBSD: Makefile,v 1.63 2023/11/12 13:24:26 wiz Exp $

DISTNAME=	qtserialport-everywhere-opensource-src-${QTVERSION}
PKGNAME=	qt5-qtserialport-${QTVERSION}
PKGREVISION=	3
COMMENT=	Qt5 module for Serial Port

BUILD_TARGET=		sub-src
MAKE_ENV+=		QTDIR=${QTDIR}

INSTALL_ENV+=		INSTALL_ROOT=${DESTDIR}
INSTALLATION_DIRS+=	lib/pkgconfig

.include "../../x11/qt5-qtbase/Makefile.common"

post-install:
.for i in Qt5SerialPort.pc
	cd ${DESTDIR}${PREFIX}/lib/pkgconfig && \
	${LN} -f -s ${QTPREFIX}/lib/pkgconfig/${i} ${i}
.endfor

.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
