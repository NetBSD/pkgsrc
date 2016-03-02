# $NetBSD: Makefile,v 1.21 2016/03/02 23:04:00 ryoon Exp $

DISTNAME=	qtquick1-opensource-src-${QTVERSION}
PKGNAME=	qt5-qtquick1-${QTVERSION}
PKGREVISION=	2
COMMENT=	Qt5 module for Quick1

BUILD_TARGET=		sub-tools
MAKE_ENV+=		QTDIR=${QTDIR}

INSTALL_ENV+=		INSTALL_ROOT=${DESTDIR}
INSTALLATION_DIRS+=	lib/pkgconfig

.include "../../x11/qt5-qtbase/Makefile.common"

post-install:
.for i in Qt5Declarative.pc
	cd ${DESTDIR}${PREFIX}/lib/pkgconfig && \
	ln -f -s ${QTPREFIX}/lib/pkgconfig/${i} ${i}
.endfor

.include "../../x11/qt5-qtscript/buildlink3.mk"
.include "../../x11/qt5-qttools/buildlink3.mk"
.include "../../x11/qt5-qtwebkit/buildlink3.mk"
.include "../../x11/qt5-qtxmlpatterns/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
