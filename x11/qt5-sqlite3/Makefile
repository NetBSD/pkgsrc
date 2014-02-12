# $NetBSD: Makefile,v 1.4 2014/02/12 23:18:56 tron Exp $

PKGNAME=	qt5-sqlite3-${QTVERSION}
PKGREVISION=	3
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
