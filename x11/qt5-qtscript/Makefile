# $NetBSD: Makefile,v 1.63 2020/11/05 09:07:21 ryoon Exp $

DISTNAME=	qtscript-everywhere-src-${QTVERSION}
PKGNAME=	qt5-qtscript-${QTVERSION}
PKGREVISION=	1
COMMENT=	Qt5 module for script

BUILD_TARGET=		sub-src
MAKE_ENV+=		QTDIR=${QTDIR}

INSTALL_ENV+=		INSTALL_ROOT=${DESTDIR}
INSTALLATION_DIRS+=	lib/pkgconfig

.include "../../x11/qt5-qtbase/Makefile.common"

post-install:
.for i in Qt5Script.pc Qt5ScriptTools.pc
	cd ${DESTDIR}${PREFIX}/lib/pkgconfig && \
	${LN} -f -s ${QTPREFIX}/lib/pkgconfig/${i} ${i}
.endfor

.include "../../x11/qt5-qttools/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
