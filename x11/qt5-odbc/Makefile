# $NetBSD: Makefile,v 1.8 2014/12/25 13:51:13 wiz Exp $

PKGNAME=	qt5-odbc-${QTVERSION}
PKGREVISION=	1
COMMENT=	Qt5 odbc plugin

USE_LIBTOOL=		yes
CONFIGURE_ARGS+=	-I${QTDIR}/include -L${QTDIR}/lib
CONFIGURE_ARGS+=	-no-dbus
CONFIGURE_ARGS+=	-no-sql-mysql
CONFIGURE_ARGS+=	-no-sql-psql
CONFIGURE_ARGS+=	-no-sql-sqlite

BUILD_DIRS=		qtbase/src/plugins/sqldrivers
MAKE_ENV+=		QTDIR=${QTDIR}

INSTALL_ENV+=		INSTALL_ROOT=${DESTDIR}

LIBS+=			-lltdl

.include "../../x11/qt5-qtbase/Makefile.common"

qmake-odbc-configure:
	cd ${WRKSRC}/${BUILD_DIRS} && \
		${QTDIR}/bin/qmake "sql-plugins=odbc" -o Makefile

post-configure: qmake-odbc-configure


.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/libltdl/buildlink3.mk"
.include "../../databases/unixodbc/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
