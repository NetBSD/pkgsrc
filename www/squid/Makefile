# $NetBSD: Makefile,v 1.28 2000/05/03 15:14:53 rh Exp $

DISTNAME=	squid-2.3.STABLE2-src
PKGNAME=	squid-2.3s2
CATEGORIES=	www
MASTER_SITES=	\
	http://www.squid-cache.org/Versions/v2/2.3/ \
	ftp://ftp.gw.com/pub/unix/squid/squid-2/STABLE/ \
	ftp://www.unimelb.edu.au/pub/cwis/servers/unix/squid/squid-2/STABLE/ \
	ftp://sunsite.auc.dk/pub/infosystems/squid/squid-2/STABLE/ \
	ftp://ftp.net.lut.ac.uk/squid/squid-2/STABLE/ \
	ftp://ftp.xlink.net/pub/mirror.squid/squid-2/STABLE/

PATCH_SITES=	http://www.squid-cache.org/Versions/v2/2.3/bugs/
PATCHFILES=	squid-2.3.stable2-EOF_in_cf.data.pre.patch \
		squid-2.3.stable2-USE_DNSSERVER.patch \
		squid-2.3.stable2-USE_DNSSERVER_part2.patch \
		squid-2.3.stable2-getMyHostname.patch \
		squid-2.3.stable2-hostname_whitespace.patch \
		squid-2.3.stable2-netdb_exchange_loop.patch \
		squid-2.3.stable2-redirected_username_logging.patch

MAINTAINER=	tron@netbsd.org
HOMEPAGE=	http://www.squid-cache.org/

BUILD_DEPENDS+=	${LOCALBASE}/bin/perl:../../lang/perl5

GNU_CONFIGURE=	yes
CONFIGURE_ARGS+= --sysconfdir=/etc \
		--localstatedir=/var/squid \
		${SQUID_CONFIGURE_ARGS}
CONFIGURE_ENV+=	CACHE_HTTP_PORT=${SQUID_HTTP_PORT} \
		CACHE_ICP_PORT=${SQUID_ICP_PORT} \
		PERL=${LOCALBASE}/bin/perl

BUILD_DEFS+=	SQUID_CONFIGURE_ARGS SQUID_HTTP_PORT SQUID_ICP_PORT
MAKEFILE=	makefile
MAKE_ENV+=	INSTALL_SCRIPT="${INSTALL_SCRIPT}" PKG_PREFIX="${PREFIX}"
PLIST_SRC=	${PKGDIR}/PLIST ${WRKDIR}/PLIST.share
WRKSRC=		${WRKDIR}/${DISTNAME:S/-src//}

.include "../../mk/bsd.prefs.mk"
# Configuration options which can be overwritten by the user.
SQUID_CONFIGURE_ARGS?=	--enable-cachemgr-hostname=localhost \
			--enable-delay-pool \
			--enable-icmp \
			--enable-ipf-transparent \
			--enable-snmp \
			--enable-underscores
SQUID_HTTP_PORT?=	3128
SQUID_ICP_PORT?=	3130

.if ${OPSYS} == "SunOS"
DEPENDS+=	egcs-1.1.2:../../lang/egcs
MAKE_ENV+=	CPPFLAGS= CFLAGS=
.endif

pre-patch:
	@cd ${WRKSRC}/src && \
	${MV} client_side.c client_side.c.prepatch && \
	${SED} -e 's#1\.459\.2\.36#1\.459\.2\.37#' <client_side.c.prepatch \
	  >client_side.c

post-build:
	${SED} s#@PREFIX@#${PREFIX}#g <${FILESDIR}/squid.sh >${WRKDIR}/squid.sh

pre-install:
	@-rm -f ${WRKDIR}/PLIST.share
	@${MKDIR} ${PREFIX}/share/squid
	@${MKDIR} ${PREFIX}/share/squid/errors
	@${MKDIR} ${PREFIX}/share/squid/icons
	@(							\
	cd ${WRKSRC}/errors/English;				\
	ls ERR_* | ${SED} -e 's@^@share/squid/errors/@';		\
	${ECHO} "@dirrm share/squid/errors";			\
	cd ${WRKSRC}/icons;					\
	ls anthony-*.gif | ${SED} -e 's@^@share/squid/icons/@';	\
	${ECHO} "@dirrm share/squid/icons";			\
	${ECHO} "share/squid/mib.txt";				\
	${ECHO} "share/squid/mime.conf";				\
	${ECHO} "share/squid/mime.conf.default";			\
	${ECHO} "share/squid/squid.conf.default";			\
	${ECHO} "@dirrm share/squid";				\
	) > ${WRKDIR}/PLIST.share

post-install:
	cd ${WRKSRC}/src; ${MAKE} install-pinger
	${INSTALL_SCRIPT} ${WRKDIR}/squid.sh ${PREFIX}/etc/rc.d/squid.sh
	@${SETENV} ${MAKE_ENV} ${SH} ${INSTALL_FILE} ${PKGNAME} POST-INSTALL

.include "../../mk/bsd.pkg.mk"
