# $NetBSD: Makefile,v 1.7 2002/02/26 21:28:49 fredb Exp $
#

DISTNAME=		mod_aolserver-1.1
PKGNAME=		ap-aolserver-1.1
CATEGORIES=		www
MASTER_SITES=		# none

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

do-fetch:
	@if [ ! -f ${DISTDIR}/${DISTFILES} ] ; then \
		${_FETCH_MESSAGE}; \
		exit 1 ; \
	fi

fetch-list-one-pkg:
	@${ECHO} ${_FETCH_MESSAGE:Q}

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/mod_aolserver
	${INSTALL_DATA} ${FILESDIR}/README ${FILESDIR}/nsd.tcl.sample \
		${WRKSRC}/tcl_modules/nsd.ini.sample \
		${PREFIX}/share/examples/mod_aolserver

.include "../../www/apache/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
