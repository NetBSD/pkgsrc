# $NetBSD: Makefile,v 1.13 2004/07/06 16:59:55 wiz Exp $
#

.include "../qt3-libs/Makefile.common"

PKGNAME=		qt3-psql-${QTVERSION}
COMMENT=		QT postgresql driver

CONFIGURE_ARGS+=	-I${QTDIR}/include \
			-I${BUILDLINK_PREFIX.postgresql-lib}/include/postgresql/server \
			-L${QTDIR}/lib

USE_BUILDLINK3=		yes
BUILD_QT3=		yes

do-build:
	(cd ${WRKSRC}/plugins/src/sqldrivers/psql; \
		${SETENV} ${MAKE_ENV} ${GMAKE})

SQLDRVDIR=	${QTPREFIX}/plugins/sqldrivers

do-install:
	${INSTALL_DATA_DIR} ${SQLDRVDIR}
	${LIBTOOL} ${INSTALL_DATA} ${WRKSRC}/plugins/sqldrivers/libqsqlpsql.la \
		${SQLDRVDIR}

.include "../../x11/qt3-libs/buildlink3.mk"
.include "../../databases/postgresql-lib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
