# $NetBSD: Makefile,v 1.41 2020/04/02 22:05:59 adam Exp $

DISTNAME=	qtserialport-everywhere-src-${QTVERSION}
PKGNAME=	qt5-qtserialport-${QTVERSION}
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
