# $NetBSD: Makefile,v 1.3 2001/12/09 00:33:25 jmc Exp $
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

# Requires a manual fetch
IS_INTERACTIVE=		yes
HAS_CONFIGURE=	# yes
GNU_CONFIGURE=	# yes

CONFIGURE_ARGS+=	--with-database=postgres
CONFIGURE_ENV+=		CPPFLAGS="-I${PREFIX}/include/pgsql"

MESSAGE_SUBST+=		PREFIX=${PREFIX}

do-fetch:
	@if [ ! -f ${DISTDIR}/${DISTFILES} ] ; then \
		${ECHO} "Please fetch ${DISTFILES} into ${DISTDIR}" ; \
		${ECHO} "from ${HOMEPAGE} ." ; \
		exit 1 ; \
	fi

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/mod_aolserver
	${INSTALL_DATA} ${FILESDIR}/README ${FILESDIR}/nsd.tcl.sample \
		${WRKSRC}/tcl_modules/nsd.ini.sample \
		${PREFIX}/share/examples/mod_aolserver

.include "../../mk/bsd.pkg.mk"
