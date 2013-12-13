# $NetBSD: Makefile,v 1.1 2013/12/13 14:38:35 ryoon Exp $

PKGNAME=	qt5-psql-${QTVERSION}
COMMENT=	Qt5 PostgreSQL plugin

.include "../../x11/qt5-qtbase/Makefile.common"

USE_LIBTOOL=		yes

CONFIGURE_ARGS+=	-I${QTDIR}/include -L${QTDIR}/lib
CONFIGURE_ARGS+=	-no-dbus
CONFIGURE_ARGS+=	-no-sql-mysql
CONFIGURE_ARGS+=	-no-sql-psql
CONFIGURE_ARGS+=	-no-sql-sqlite

BUILD_QT5=		yes

BUILD_DIRS+=		qtbase/src/plugins/sqldrivers
MAKE_ENV+=		QTDIR=${QTDIR}

INSTALL_ENV+=		INSTALL_ROOT=${DESTDIR}
INSTALLATION_DIRS+=	qt5/plugins/sqldrivers

post-configure:
	cd ${WRKSRC}/${BUILD_DIRS} && \
		${QTDIR}/bin/qmake "sql-plugins=psql" -o Makefile

do-install:
	${LIBTOOL} --mode=install ${INSTALL_PROGRAM} \
		${WRKSRC}/qtbase/plugins/sqldrivers/libqsqlpsql.la \
		${DESTDIR}${QTPREFIX}/plugins/sqldrivers

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../mk/pgsql.buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
