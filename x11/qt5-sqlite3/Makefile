# $NetBSD: Makefile,v 1.10 2015/04/06 08:17:20 adam Exp $

DISTNAME=	qtbase-opensource-src-${QTVERSION}
PKGNAME=	qt5-sqlite3-${QTVERSION}
PKGREVISION=	1
COMMENT=	Qt5 SQLite3 plugin

BUILD_DIRS=		src/plugins/sqldrivers
MAKE_ENV+=		QTDIR=${QTDIR}

INSTALL_ENV+=		INSTALL_ROOT=${DESTDIR}

CFLAGS.SunOS+=	-D__EXTENSIONS__	# posix_fallocate()

.include "../../x11/qt5-qtbase/Makefile.common"

do-configure:
	${RM} -f -r ${WRKSRC}/mkspecs
	cd ${WRKSRC}/${BUILD_DIRS} && \
	${QTDIR}/bin/qmake "sql-plugins=sqlite" -o Makefile

.include "../../databases/sqlite3/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
