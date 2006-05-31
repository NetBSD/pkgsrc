# $NetBSD: Makefile,v 1.1.1.1 2006/05/31 19:22:13 adam Exp $

.include "../../x11/qt4-libs/Makefile.common"

PKGNAME=	qt4-psql-${QTVERSION}
COMMENT=	QT postgresql driver

CONFIGURE_ARGS+=	-I${QTDIR}/include
CONFIGURE_ARGS+=	-I${PGSQL_PREFIX}/include/postgresql/server
CONFIGURE_ARGS+=	-L${QTDIR}/lib

BUILD_QT4=		yes

do-build:
	cd ${WRKSRC}/src/tools/moc && ${SETENV} ${MAKE_ENV} ${GMAKE}
	cd ${WRKSRC}/src/plugins/sqldrivers/psql && \
		${SETENV} ${MAKE_ENV} ${GMAKE}

SQLDRVDIR=	${QTPREFIX}/plugins/sqldrivers

do-install:
	${INSTALL_DATA_DIR} ${SQLDRVDIR}
	${LIBTOOL} ${INSTALL_DATA} ${WRKSRC}/plugins/sqldrivers/libqsqlpsql.la \
		${SQLDRVDIR}

.include "../../x11/qt4-libs/buildlink3.mk"
.include "../../x11/qt4-tools/buildlink3.mk"
.include "../../mk/pgsql.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
