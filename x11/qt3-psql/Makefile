# $NetBSD: Makefile,v 1.1.1.1 2002/10/28 11:18:36 drochner Exp $
#

.include "../qt3-libs/Makefile.common"

PKGNAME=		qt3-psql-${QTVERSION}
COMMENT=		QT postgresql driver

CONFIGURE_ARGS+=	-I${QTDIR}/include \
			-L${QTDIR}/lib

MAKE_ENV+=              LIBQT="-lqt-mt"

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
