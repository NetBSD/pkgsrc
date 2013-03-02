# $NetBSD: Makefile,v 1.36 2013/03/02 20:33:34 wiz Exp $

.include "../../x11/qt3-libs/Makefile.common"

PKGNAME=		qt3-mysql-${QTVERSION}
PKGREVISION=		11
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
INSTALLATION_DIRS=	${SQLDRVDIR}

do-install:
	${LIBTOOL} --mode=install ${INSTALL_DATA} ${WRKSRC}/plugins/sqldrivers/libqsqlmysql.la \
		${DESTDIR}${SQLDRVDIR}

.include "../../x11/qt3-libs/buildlink3.mk"
.include "../../mk/mysql.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
