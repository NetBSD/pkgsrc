# $NetBSD: Makefile,v 1.9 2002/06/21 15:01:54 cjones Exp $
#

DISTNAME=		mod_aolserver-1.1
PKGNAME=		ap-aolserver-1.1
CATEGORIES=		www
MASTER_SITES=		${MASTER_SITE_LOCAL}

MAINTAINER=		cjones@netbsd.org
HOMEPAGE=		http://www.arsdigita.com/acs-repository/one-version?version_id=601
COMMENT=		Module that emulates AOLServer in Apache

DEPENDS+=		postgresql-lib>=7.0:../../databases/postgresql-lib
DEPENDS+=		libmm>=1.1.3:../../devel/libmm
DEPENDS+=		tcl>=8.3:../../lang/tcl
DEPENDS+=		apache{,6}-1.3.*:../../www/apache

HAS_CONFIGURE=	# yes
GNU_CONFIGURE=	# yes

CONFIGURE_ARGS+=	--with-database=postgres --with-mm=${PREFIX}
CONFIGURE_ENV+=		CPPFLAGS="-I${PREFIX}/include/pgsql -I${PREFIX}/include/httpd"

MESSAGE_SUBST+=		PREFIX=${PREFIX}

_FETCH_MESSAGE= \
	${ECHO} "===================================================================="; \
	${ECHO} "  Please fetch ${DISTFILES} into ${DISTDIR}" ; \
	${ECHO} "  from ${HOMEPAGE} ." ; \
	${ECHO} "===================================================================="

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/mod_aolserver
	${INSTALL_DATA} ${FILESDIR}/README ${FILESDIR}/nsd.tcl.sample \
		${WRKSRC}/tcl_modules/nsd.ini.sample \
		${PREFIX}/share/examples/mod_aolserver

.include "../../www/apache/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
