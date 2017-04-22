# $NetBSD: Makefile,v 1.21 2017/04/22 21:03:21 adam Exp $

DISTNAME=	qtbase-opensource-src-${QTVERSION}
PKGNAME=	qt5-odbc-${QTVERSION}
PKGREVISION=	7
COMMENT=	Qt5 odbc plugin

BUILD_DIRS=		src/plugins/sqldrivers
MAKE_ENV+=		QTDIR=${QTDIR}
INSTALL_ENV+=		INSTALL_ROOT=${DESTDIR}

LIBS+=			-lltdl

.include "../../x11/qt5-qtbase/Makefile.common"

do-configure:
	${RM} -f -r ${WRKSRC}/mkspecs
	cd ${WRKSRC}/${BUILD_DIRS} && \
	${QTDIR}/bin/qmake "sql-plugins=odbc" -o Makefile

.include "../../devel/libltdl/buildlink3.mk"
.include "../../databases/unixodbc/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
