# $NetBSD: Makefile,v 1.34 2000/10/15 20:17:44 veego Exp $

DISTNAME=	squid-2.3.STABLE4-src
PKGNAME=	squid-2.3s4
CATEGORIES=	www
MASTER_SITES=	\
	http://www.squid-cache.org/Versions/v2/2.3/ \
	ftp://ftp.gw.com/pub/unix/squid/squid-2/STABLE/ \
	ftp://www.unimelb.edu.au/pub/cwis/servers/unix/squid/squid-2/STABLE/ \
	ftp://sunsite.auc.dk/pub/infosystems/squid/squid-2/STABLE/ \
	ftp://ftp.net.lut.ac.uk/squid/squid-2/STABLE/ \
	ftp://ftp.kpnqwest.de/pub/mirror.squid/squid-2/STABLE/

PATCH_SITES=	http://www.squid-cache.org/Versions/v2/2.3/bugs/
PATCHFILES=	squid-2.3.stable4-invalid_ip_acl_entry.patch \
		squid-2.3.stable4-ipfw_configure.patch \
		squid-2.3.stable4-internal_dns_rcode_table_formatting.patch \
		squid-2.3.stable4-ftp_icon_not_found.patch

MAINTAINER=	tron@netbsd.org
HOMEPAGE=	http://www.squid-cache.org/

BUILD_DEPENDS+=	${PERL5}:../../lang/perl5-base

GNU_CONFIGURE=	# defined
CONFIGURE_ARGS+= --sysconfdir=/etc \
		--localstatedir=/var/squid \
		${SQUID_CONFIGURE_ARGS}
CONFIGURE_ENV+=	CACHE_HTTP_PORT=${SQUID_HTTP_PORT} \
		CACHE_ICP_PORT=${SQUID_ICP_PORT} \
		PERL=${PERL5}

BUILD_DEFS+=	SQUID_CONFIGURE_ARGS SQUID_HTTP_PORT SQUID_ICP_PORT
MAKEFILE=	makefile
MAKE_ENV+=	INSTALL_SCRIPT="${INSTALL_SCRIPT}" PKG_PREFIX="${PREFIX}"
PLIST_SRC=	${PKGDIR}/PLIST ${WRKDIR}/PLIST.share
WRKSRC=		${WRKDIR}/${DISTNAME:S/-src//}

.include "../../mk/bsd.prefs.mk"
# Configuration options which can be overwritten by the user.
SQUID_CONFIGURE_ARGS?=	--enable-cachemgr-hostname=localhost \
			--enable-delay-pools \
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

post-configure:
	@cd ${WRKSRC}/include && \
	${MV} autoconf.h autoconf.h.prepatch && \
	${SED} -e 's%#define fd_mask int%/* #undef fd_mask */%' <autoconf.h.prepatch \
	 >autoconf.h

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
