# $NetBSD: Makefile,v 1.9 2010/02/10 19:34:08 joerg Exp $

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../x11/qt3-libs/Makefile.common"

PKGNAME=	qt3-psql-${QTVERSION}
PKGREVISION=	6
COMMENT=	QT postgresql driver

CONFIGURE_ARGS+=	-I${QTDIR}/include \
			-I${PGSQL_PREFIX}/include/postgresql/server \
			-L${QTDIR}/lib

BUILD_QT3=		yes

do-build:
	(cd ${WRKSRC}/plugins/src/sqldrivers/psql; \
		${SETENV} ${MAKE_ENV} ${GMAKE})

SQLDRVDIR=	${QTPREFIX}/plugins/sqldrivers
INSTALLATION_DIRS=	${SQLDRVDIR}

do-install:
	${LIBTOOL} --mode=install ${INSTALL_DATA} ${WRKSRC}/plugins/sqldrivers/libqsqlpsql.la \
		${DESTDIR}${SQLDRVDIR}

.include "../../x11/qt3-libs/buildlink3.mk"
.include "../../mk/pgsql.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
