# $NetBSD: Makefile,v 1.35 2024/05/25 14:21:19 adam Exp $

DISTNAME=	qtconnectivity-everywhere-opensource-src-${QTVERSION}
PKGNAME=	qt5-qtconnectivity-${QTVERSION}
COMMENT=	Qt5 module for connectivity framework

BUILD_TARGET=		sub-src
INSTALL_ENV+=		INSTALL_ROOT=${DESTDIR}
INSTALLATION_DIRS+=	lib/pkgconfig

.include "../../x11/qt5-qtbase/Makefile.common"

post-install:
.for i in Qt5Bluetooth.pc Qt5Nfc.pc
	cd ${DESTDIR}${PREFIX}/lib/pkgconfig && \
	${LN} -f -s ${QTPREFIX}/lib/pkgconfig/${i} ${i}
.endfor

.include "../../x11/qt5-qtdeclarative/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
