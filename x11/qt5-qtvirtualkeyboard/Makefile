# $NetBSD: Makefile,v 1.13 2020/11/21 11:22:34 adam Exp $

DISTNAME=	qtvirtualkeyboard-everywhere-src-${QTVERSION}
PKGNAME=	qt5-qtvirtualkeyboard-${QTVERSION}
COMMENT=	Qt5 module for virtualkeyboard framework

BUILD_TARGET=		sub-src
INSTALL_ENV+=		INSTALL_ROOT=${DESTDIR}
INSTALLATION_DIRS+=	lib/pkgconfig

.include "../../x11/qt5-qtbase/Makefile.common"

post-install:
.for i in Qt5VirtualKeyboard.pc
	cd ${DESTDIR}${PREFIX}/lib/pkgconfig && \
	${LN} -f -s ${QTPREFIX}/lib/pkgconfig/${i} ${i}
.endfor

.include "../../x11/qt5-qtdeclarative/buildlink3.mk"
.include "../../x11/qt5-qtsvg/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
