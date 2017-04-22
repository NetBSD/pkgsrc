# $NetBSD: Makefile,v 1.21 2017/04/22 21:03:23 adam Exp $

DISTNAME=	qtbase-opensource-src-${QTVERSION}
PKGNAME=	qt5-sqlite3-${QTVERSION}
PKGREVISION=	7
COMMENT=	Qt5 SQLite3 plugin

BUILD_DIRS=		src/plugins/sqldrivers
MAKE_ENV+=		QTDIR=${QTDIR}

INSTALL_ENV+=		INSTALL_ROOT=${DESTDIR}

OPSYSVARS+=    USE_LANGUAGES
USE_LANGUAGES.SunOS+=	c99
CFLAGS.SunOS+= -D__EXTENSIONS__        # posix_fallocate()

.include "../../x11/qt5-qtbase/Makefile.common"

do-configure:
	${RM} -f -r ${WRKSRC}/mkspecs
	cd ${WRKSRC}/${BUILD_DIRS} && \
	${QTDIR}/bin/qmake "sql-plugins=sqlite" -o Makefile

.include "../../databases/sqlite3/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
