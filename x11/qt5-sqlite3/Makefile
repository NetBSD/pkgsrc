# $NetBSD: Makefile,v 1.1 2013/12/13 14:38:36 ryoon Exp $

PKGNAME=	qt5-sqlite3-${QTVERSION}
COMMENT=	Qt5 SQLite3 plugin

.include "../../x11/qt5-qtbase/Makefile.common"

USE_LIBTOOL=		yes

CONFIGURE_ARGS+=	-I${QTDIR}/include -L${QTDIR}/lib

BUILD_DIRS+=		qtbase/src/plugins/sqldrivers
MAKE_ENV+=		QTDIR=${QTDIR}

INSTALL_ENV+=		INSTALL_ROOT=${DESTDIR}
INSTALLATION_DIRS+=	lib/pkgconfig qt5/plugins/sqldrivers

post-configure:
	cd ${WRKSRC}/${BUILD_DIRS} && \
		${QTDIR}/bin/qmake "sql-plugins=sqlite" -o Makefile

do-install:
	${LIBTOOL} --mode=install ${INSTALL_PROGRAM} \
		${WRKSRC}/qtbase/plugins/sqldrivers/libqsqlite.la \
		${DESTDIR}${QTPREFIX}/plugins/sqldrivers

.include "../../databases/sqlite3/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
