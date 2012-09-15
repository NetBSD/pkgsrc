# $NetBSD: Makefile,v 1.32 2012/09/15 15:03:26 obache Exp $

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../x11/qt3-libs/Makefile.common"

PKGNAME=		qt3-mysql-${QTVERSION}
PKGREVISION=		8
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
