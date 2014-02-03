# $NetBSD: Makefile,v 1.4 2014/02/03 16:17:12 ryoon Exp $

PKGNAME=	qt5-odbc-${QTVERSION}
PKGREVISION=	2
COMMENT=	Qt5 odbc plugin

.include "../../x11/qt5-qtbase/Makefile.common"

USE_LIBTOOL=		yes

CONFIGURE_ARGS+=	-I${QTDIR}/include -L${QTDIR}/lib
CONFIGURE_ARGS+=	-no-dbus
CONFIGURE_ARGS+=	-no-sql-mysql
CONFIGURE_ARGS+=	-no-sql-psql
CONFIGURE_ARGS+=	-no-sql-sqlite

BUILD_DIRS+=		qtbase/src/plugins/sqldrivers
MAKE_ENV+=		QTDIR=${QTDIR}

INSTALL_ENV+=		INSTALL_ROOT=${DESTDIR}
INSTALLATION_DIRS+=	qt5/plugins/sqldrivers

LIBS+=			-lltdl

qmake-odbc-configure:
	cd ${WRKSRC}/${BUILD_DIRS} && \
		${QTDIR}/bin/qmake "sql-plugins=odbc" -o Makefile

post-configure: qmake-odbc-configure

do-install:
	${LIBTOOL} --mode=install ${INSTALL_PROGRAM} \
		${WRKSRC}/qtbase/plugins/sqldrivers/libqsqlodbc.la \
		${DESTDIR}${QTPREFIX}/plugins/sqldrivers

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/libltdl/buildlink3.mk"
.include "../../databases/unixodbc/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
