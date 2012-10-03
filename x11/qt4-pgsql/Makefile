# $NetBSD: Makefile,v 1.33.2.1 2012/10/03 12:10:02 spz Exp $

.include "../../x11/qt4-libs/Makefile.common"

PKGNAME=	qt4-pgsql-${QTVERSION}
PKGREVISION=	1
COMMENT=	QT postgresql driver

CONFIGURE_ARGS+=	-I${QTDIR}/include
CONFIGURE_ARGS+=	-I${PGSQL_PREFIX}/include/postgresql/server
CONFIGURE_ARGS+=	-L${QTDIR}/lib

BUILD_QT4=		yes

do-build:
	cd ${WRKSRC}/src/tools/bootstrap && env ${MAKE_ENV} ${GMAKE}
	cd ${WRKSRC}/src/tools/moc && env ${MAKE_ENV} ${GMAKE}
	cd ${WRKSRC}/src/plugins/sqldrivers/psql && env ${MAKE_ENV} ${GMAKE}

SQLDRVDIR=	${QTPREFIX}/plugins/sqldrivers
INSTALLATION_DIRS=	${SQLDRVDIR}

do-install:
	${LIBTOOL} --mode=install ${INSTALL_LIB} ${WRKSRC}/plugins/sqldrivers/libqsqlpsql.la \
		${DESTDIR}${SQLDRVDIR}

.include "../../x11/qt4-libs/buildlink3.mk"
.include "../../x11/qt4-tools/buildlink3.mk"
.include "../../mk/pgsql.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
