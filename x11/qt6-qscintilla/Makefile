# $NetBSD: Makefile,v 1.3 2024/05/29 16:35:14 adam Exp $

PKGREVISION= 2
.include "../../x11/qt6-qscintilla/Makefile.common"

PKGNAME=	qt6-${DISTNAME:S/_src//:tl}
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
	install_name_tool -id ${QTDIR}/lib/libqscintilla2_qt6.15.2.1.dylib \
	${DESTDIR}${QTDIR}/lib/libqscintilla2_qt6.15.2.1.dylib
.endif

.include "../../mk/bsd.pkg.mk"
