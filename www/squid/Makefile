# $NetBSD: Makefile,v 1.23 2000/02/27 23:11:12 tron Exp $

DISTNAME=	squid-2.3.STABLE1-src
PKGNAME=	squid-2.3s1
CATEGORIES=	www
MASTER_SITES=  \
	ftp://squid.nlanr.net/pub/squid-2/STABLE/ \
	ftp://ftp.gw.com/pub/unix/squid/squid-2/STABLE/ \
	ftp://www.unimelb.edu.au/pub/cwis/servers/unix/squid/squid-2/STABLE/ \
	ftp://sunsite.auc.dk/pub/infosystems/squid/squid-2/STABLE/ \
	ftp://ftp.net.lut.ac.uk/squid/squid-2/STABLE/

MAINTAINER=	tron@netbsd.org
HOMEPAGE=	http://squid.nlanr.net/Squid/

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
