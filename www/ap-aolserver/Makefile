# $NetBSD: Makefile,v 1.14 2003/11/26 15:58:08 jlam Exp $
#

DISTNAME=		mod_aolserver-1.1
PKGNAME=		ap-aolserver-1.1
PKGREVISION=		2
CATEGORIES=		www
MASTER_SITES=		${MASTER_SITE_LOCAL}

MAINTAINER=		cjones@NetBSD.org
HOMEPAGE=		http://www.arsdigita.com/acs-repository/one-version?version_id=601
COMMENT=		Module that emulates AOLServer in Apache

GNU_CONFIGURE=	YES
USE_BUILDLINK2=	YES

CONFIGURE_ARGS+=	--with-database=postgres --with-mm=${BUILDLINK_PREFIX.libmm}
CPPFLAGS+=	-I${BUILDLINK_PREFIX.postgresql-lib}/include/postgresql
CFLAGS+=	`${APXS} -q CFLAGS CFLAGS_SHLIB`

MESSAGE_SUBST+=		PREFIX=${PREFIX}

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/mod_aolserver
	${INSTALL_DATA} ${FILESDIR}/README ${FILESDIR}/nsd.tcl.sample \
		${WRKSRC}/tcl_modules/nsd.ini.sample \
		${PREFIX}/share/examples/mod_aolserver

.include "../../databases/postgresql-lib/buildlink2.mk"
.include "../../devel/libmm/buildlink2.mk"
.include "../../lang/tcl/buildlink2.mk"
.include "../../www/apache/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
