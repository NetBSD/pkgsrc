# $NetBSD: Makefile,v 1.8 2014/12/25 13:51:15 wiz Exp $

PKGNAME=	qt5-sqlite3-${QTVERSION}
PKGREVISION=	1
COMMENT=	Qt5 SQLite3 plugin

USE_LIBTOOL=		yes
CONFIGURE_ARGS+=	-I${QTDIR}/include -L${QTDIR}/lib

BUILD_DIRS=		qtbase/src/plugins/sqldrivers
MAKE_ENV+=		QTDIR=${QTDIR}

INSTALL_ENV+=		INSTALL_ROOT=${DESTDIR}

CFLAGS.SunOS+=	-D__EXTENSIONS__	# posix_fallocate()

.include "../../x11/qt5-qtbase/Makefile.common"

post-configure:
	cd ${WRKSRC}/${BUILD_DIRS} && \
		${QTDIR}/bin/qmake "sql-plugins=sqlite" -o Makefile


.include "../../databases/sqlite3/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
