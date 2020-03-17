# $NetBSD: Makefile,v 1.62 2020/03/17 15:42:06 nia Exp $

DISTNAME=	qtmultimedia-everywhere-src-${QTVERSION}
PKGNAME=	qt5-qtmultimedia-${QTVERSION}
PKGREVISION=	3
COMMENT=	Qt5 module for multimedia

BUILD_TARGET=		sub-src
MAKE_ENV+=		QTDIR=${QTDIR}
INSTALL_ENV+=		INSTALL_ROOT=${DESTDIR}
INSTALLATION_DIRS+=	lib/pkgconfig

.include "../../x11/qt5-qtbase/Makefile.common"

# Needs gnu+11 for alloca.
BUILDLINK_TRANSFORM+=	rm:-std=c++1z

post-install:
.for i in Qt5Multimedia.pc Qt5MultimediaWidgets.pc
	cd ${DESTDIR}${PREFIX}/lib/pkgconfig && \
	${LN} -f -s ${QTPREFIX}/lib/pkgconfig/${i} ${i}
.endfor

.include "options.mk"
.include "../../x11/qt5-qtdeclarative/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
