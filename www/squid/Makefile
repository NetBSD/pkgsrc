# $NetBSD: Makefile,v 1.57 2001/12/12 17:06:18 taca Exp $

DISTNAME=	squid-2.4.STABLE3-src
PKGNAME=	squid-2.4.3
CATEGORIES=	www
MASTER_SITES=	http://www.squid-cache.org/Versions/v2/2.4/ \
		ftp://ftp.leo.org/pub/comp/general/infosys/www/daemons/squid/squid-2/STABLE/ \
		ftp://ftp1.au.squid-cache.org/pub/squid/squid-2/STABLE/

MAINTAINER=	tron@netbsd.org
HOMEPAGE=	http://www.squid-cache.org/
COMMENT=	Post-Harvest_cached WWW proxy cache and accelerator

BUILD_DEPENDS+=	perl>=${PERL5_REQD}:../../lang/perl5

.include "../../mk/bsd.prefs.mk"
GNU_CONFIGURE=	YES
CONFIGURE_ARGS+= --sysconfdir=${SQUID_SYSCONFDIR} \
		--localstatedir=/var/squid \
		${SQUID_CONFIGURE_ARGS}
CONFIGURE_ENV+=	PERL=${PERL5}

BUILD_DEFS+=	SQUID_CONFIGURE_ARGS SQUID_SYSCONFDIR
MAKEFILE=	makefile
MAKE_ENV+=	INSTALL_SCRIPT="${INSTALL_SCRIPT}" PKG_PREFIX="${PREFIX}"
INSTALL_FILE=	${WRKDIR}/INSTALL
PLIST_SRC=	${WRKDIR}/PLIST
WRKSRC=		${WRKDIR}/${DISTNAME:S/-src//}

# Configuration options which can be overwritten by the user.
SQUID_CONFIGURE_ARGS?=	--disable-internal-dns \
			--enable-cachemgr-hostname=localhost \
			--enable-delay-pools \
			--enable-icmp \
			--enable-ipf-transparent \
			--enable-snmp \
			--enable-underscores \
			--enable-storeio=ufs,diskd

# Configuration directory location which can be overwritten by the user.
PKG_SYSCONFSUBDIR?=	squid
SQUID_SYSCONFDIR?=	${PKG_SYSCONFDIR}

OPTIONAL_FILES=	libexec/diskd libexec/dnsserver libexec/pinger libexec/unlinkd

post-configure:
	@cd ${WRKSRC}/include && \
	${MV} autoconf.h autoconf.h.prepatch && \
	${SED} -e 's%#define fd_mask int%/* #undef fd_mask */%' <autoconf.h.prepatch \
	 >autoconf.h

post-build:
	${SED} s#@PREFIX@#${PREFIX}#g <${FILESDIR}/squid.sh >${WRKDIR}/squid.sh
	${SED} s#@SYSCONFDIR@#${SQUID_SYSCONFDIR}#g <${PKGDIR}/INSTALL \
	  >${WRKDIR}/INSTALL

pre-install:
	@${INSTALL_DATA_DIR} ${PREFIX}/share/squid
	@${INSTALL_DATA_DIR} ${PREFIX}/share/squid/errors
	@${INSTALL_DATA_DIR} ${PREFIX}/share/squid/icons

post-install:
	cd ${WRKSRC}/src; ${TEST} ! -x pinger || ${MAKE} install-pinger
	${INSTALL_SCRIPT} ${WRKDIR}/squid.sh ${PREFIX}/etc/rc.d/squid
	@${SETENV} ${MAKE_ENV} ${SH} ${INSTALL_FILE} ${PKGNAME} POST-INSTALL
	@${CP} ${PKGDIR}/PLIST ${PLIST_SRC}
	@(							\
	for FILE in ${OPTIONAL_FILES}; do			\
	  ${TEST} ! -e ${PREFIX}/$$FILE || ${ECHO} $$FILE;	\
	done;							\
	cd ${WRKSRC}/errors/English;				\
	ls ERR_* | ${SED} -e 's@^@share/squid/errors/@';	\
	${ECHO} "@dirrm share/squid/errors";			\
	cd ${WRKSRC}/icons;					\
	ls anthony-*.gif | ${SED} -e 's@^@share/squid/icons/@';	\
	${ECHO} "@dirrm share/squid/icons";			\
	${ECHO} "share/squid/mib.txt";				\
	${ECHO} "@dirrm share/squid"				\
	) >>${PLIST_SRC}

.include "../../mk/bsd.pkg.mk"
