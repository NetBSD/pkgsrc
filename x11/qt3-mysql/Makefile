# $NetBSD: Makefile,v 1.7 2003/12/19 15:43:31 skrll Exp $
#

.include "../qt3-libs/Makefile.common"

PKGNAME=		qt3-mysql-${QTVERSION}
COMMENT=		QT mysql driver

CONFIGURE_ARGS+=	-I${QTDIR}/include \
			-L${QTDIR}/lib \
			-I${BUILDLINK_PREFIX.mysql-client}/include/mysql \
			-L${BUILDLINK_PREFIX.mysql-client}/lib/mysql

USE_BUILDLINK2=		yes
BUILD_QT3=		yes

do-build:
	(cd ${WRKSRC}/plugins/src/sqldrivers/mysql; \
		${SETENV} ${MAKE_ENV} ${GMAKE})

SQLDRVDIR=	${QTPREFIX}/plugins/sqldrivers

do-install:
	${INSTALL_DATA_DIR} ${SQLDRVDIR}
	${LIBTOOL} ${INSTALL_DATA} ${WRKSRC}/plugins/sqldrivers/libqsqlmysql.la \
		${SQLDRVDIR}

.include "../../x11/qt3-libs/buildlink2.mk"
.include "../../databases/mysql-client/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
