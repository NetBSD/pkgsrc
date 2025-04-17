# $NetBSD: Makefile,v 1.31 2025/04/17 21:53:06 wiz Exp $

PKGREVISION= 6
.include "../../x11/qt5-qscintilla/Makefile.common"

PKGNAME=	qt5-${DISTNAME:S/_src//:tl}
COMMENT=	Scintilla C++ editor class for Qt5

BUILD_DIRS=	src

USE_TOOLS+=	gmake

MAKE_ENV+=	QTPREFIX=${QTDIR}
INSTALL_ENV+=	INSTALL_ROOT=${DESTDIR}

do-configure:
	cd ${WRKSRC}/src && ${QTDIR}/bin/qmake -o Makefile qscintilla.pro

.include "../../mk/bsd.prefs.mk"
.if ${OPSYS} == "Darwin"
post-install:
	install_name_tool -id ${QTDIR}/lib/libqscintilla2_qt5.15.2.1.dylib \
	${DESTDIR}${QTDIR}/lib/libqscintilla2_qt5.15.2.1.dylib
.endif

.include "../../mk/bsd.pkg.mk"
