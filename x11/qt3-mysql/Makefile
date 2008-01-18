# $NetBSD: Makefile,v 1.22 2008/01/18 05:10:06 tnn Exp $

.include "../../x11/qt3-libs/Makefile.common"

PKGNAME=		qt3-mysql-${QTVERSION}
PKGREVISION=		1
COMMENT=		QT mysql driver

CONFIGURE_ARGS+=	-I${QTDIR}/include \
			-L${QTDIR}/lib \
			-I${BUILDLINK_PREFIX.mysql-client}/include/mysql \
			-L${BUILDLINK_PREFIX.mysql-client}/lib/mysql

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
.include "../../mk/mysql.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
