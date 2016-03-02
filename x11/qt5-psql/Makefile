# $NetBSD: Makefile,v 1.15 2016/03/02 23:04:00 ryoon Exp $

DISTNAME=	qtbase-opensource-src-${QTVERSION}
PKGNAME=	qt5-psql-${QTVERSION}
PKGREVISION=	1
COMMENT=	Qt5 PostgreSQL plugin

BUILD_QT5=		yes

BUILD_DIRS=		src/plugins/sqldrivers
MAKE_ENV+=		QTDIR=${QTDIR}
INSTALL_ENV+=		INSTALL_ROOT=${DESTDIR}

.include "../../x11/qt5-qtbase/Makefile.common"

do-configure:
	${RM} -f -r ${WRKSRC}/mkspecs
	cd ${WRKSRC}/${BUILD_DIRS} && \
	${QTDIR}/bin/qmake "sql-plugins=psql" -o Makefile

.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../mk/pgsql.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
