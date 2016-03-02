# $NetBSD: Makefile,v 1.13 2016/03/02 23:03:59 ryoon Exp $

DISTNAME=	qtbase-opensource-src-${QTVERSION}
PKGNAME=	qt5-mysql-${QTVERSION}
PKGREVISION=	1
COMMENT=	Qt5 MySQL plugin

CFLAGS+=		-I${BUILDLINK_PREFIX.mysql-client}/include/mysql

BUILD_DIRS=		src/plugins/sqldrivers
MAKE_ENV+=		QTDIR=${QTDIR}
INSTALL_ENV+=		INSTALL_ROOT=${DESTDIR}

.include "../../x11/qt5-qtbase/Makefile.common"

do-configure:
	${RM} -f -r ${WRKSRC}/mkspecs
	cd ${WRKSRC}/${BUILD_DIRS} && \
	${QTDIR}/bin/qmake "sql-plugins=mysql" -o Makefile

.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../mk/mysql.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
