# $NetBSD: Makefile,v 1.8 2004/05/14 01:51:07 snj Exp $
#

.include "../qt3-libs/Makefile.common"

PKGNAME=		qt3-mysql-${QTVERSION}
COMMENT=		QT mysql driver

CONFIGURE_ARGS+=	-I${QTDIR}/include \
			-L${QTDIR}/lib \
			-I${BUILDLINK_PREFIX.mysql-client}/include/mysql \
			-L${BUILDLINK_PREFIX.mysql-client}/lib/mysql

USE_BUILDLINK3=		yes
BUILD_QT3=		yes

do-build:
	(cd ${WRKSRC}/plugins/src/sqldrivers/mysql; \
		${SETENV} ${MAKE_ENV} ${GMAKE})

SQLDRVDIR=	${QTPREFIX}/plugins/sqldrivers

do-install:
	${INSTALL_DATA_DIR} ${SQLDRVDIR}
	${LIBTOOL} ${INSTALL_DATA} ${WRKSRC}/plugins/sqldrivers/libqsqlmysql.la \
		${SQLDRVDIR}

.include "../../x11/qt3-libs/buildlink3.mk"
.include "../../databases/mysql-client/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
