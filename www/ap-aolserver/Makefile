# $NetBSD: Makefile,v 1.21 2004/10/03 00:18:23 tv Exp $
#

DISTNAME=		mod_aolserver-1.1
PKGNAME=		ap-aolserver-1.1
PKGREVISION=		5
CATEGORIES=		www
MASTER_SITES=		${MASTER_SITE_LOCAL}

MAINTAINER=		cjones@NetBSD.org
HOMEPAGE=		http://www.arsdigita.com/acs-repository/one-version?version_id=601
COMMENT=		Module that emulates AOLServer in Apache

GNU_CONFIGURE=	YES
USE_BUILDLINK3=	YES

CONFIGURE_ARGS+=	--with-database=postgres
CONFIGURE_ARGS+=	--with-mm=${BUILDLINK_PREFIX.libmm}

CPPFLAGS+=	-I${PGSQL_PREFIX}/include/postgresql
CFLAGS+=	`${APXS} -q CFLAGS CFLAGS_SHLIB`

MESSAGE_SUBST+=		PREFIX=${PREFIX}

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/mod_aolserver
	${INSTALL_DATA} ${FILESDIR}/README ${FILESDIR}/nsd.tcl.sample \
		${WRKSRC}/tcl_modules/nsd.ini.sample \
		${PREFIX}/share/examples/mod_aolserver

.include "../../devel/libmm/buildlink3.mk"
.include "../../lang/tcl83/buildlink3.mk"
.include "../../www/apache/buildlink3.mk"
.include "../../mk/pgsql.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
