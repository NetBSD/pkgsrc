# $NetBSD: Makefile,v 1.4 2014/02/12 23:18:55 tron Exp $

PKGNAME=	qt5-mysql-${QTVERSION}
PKGREVISION=	3
COMMENT=	Qt5 MySQL plugin

.include "../../x11/qt5-qtbase/Makefile.common"

USE_LIBTOOL=		yes

CONFIGURE_ARGS+=	-I${QTDIR}/include -L${QTDIR}/lib

CFLAGS+=		-I${BUILDLINK_PREFIX.mysql-client}/include/mysql

BUILD_DIRS+=		qtbase/src/plugins/sqldrivers
MAKE_ENV+=		QTDIR=${QTDIR}

INSTALL_ENV+=		INSTALL_ROOT=${DESTDIR}
INSTALLATION_DIRS+=	qt5/plugins/sqldrivers

post-configure:
	cd ${WRKSRC}/${BUILD_DIRS} && \
		${QTDIR}/bin/qmake "sql-plugins=mysql" -o Makefile

do-install:
	${LIBTOOL} --mode=install ${INSTALL_PROGRAM} \
		${WRKSRC}/qtbase/plugins/sqldrivers/libqsqlmysql.la \
		${DESTDIR}${QTPREFIX}/plugins/sqldrivers

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../mk/mysql.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
