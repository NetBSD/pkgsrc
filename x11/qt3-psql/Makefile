# $NetBSD: Makefile,v 1.10 2003/12/19 15:43:31 skrll Exp $
#

.include "../qt3-libs/Makefile.common"

PKGNAME=		qt3-psql-${QTVERSION}
COMMENT=		QT postgresql driver

CONFIGURE_ARGS+=	-I${QTDIR}/include \
			-I${BUILDLINK_PREFIX.postgresql-lib}/include/postgresql/server \
			-L${QTDIR}/lib

USE_BUILDLINK2=		yes
BUILD_QT3=		yes

do-build:
	(cd ${WRKSRC}/plugins/src/sqldrivers/psql; \
		${SETENV} ${MAKE_ENV} ${GMAKE})

SQLDRVDIR=	${QTPREFIX}/plugins/sqldrivers

do-install:
	${INSTALL_DATA_DIR} ${SQLDRVDIR}
	${LIBTOOL} ${INSTALL_DATA} ${WRKSRC}/plugins/sqldrivers/libqsqlpsql.la \
		${SQLDRVDIR}

.include "../../x11/qt3-libs/buildlink2.mk"
.include "../../databases/postgresql-lib/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
