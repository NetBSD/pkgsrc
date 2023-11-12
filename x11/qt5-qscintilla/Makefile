# $NetBSD: Makefile,v 1.24 2023/11/12 13:24:24 wiz Exp $

PKGREVISION= 3
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
	install_name_tool -id ${QTDIR}/lib/libqscintilla2_qt5.15.2.0.dylib \
	${DESTDIR}${QTDIR}/lib/libqscintilla2_qt5.15.2.0.dylib
.endif

.include "../../mk/bsd.pkg.mk"
