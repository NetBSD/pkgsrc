# $NetBSD: Makefile,v 1.67 2002/09/15 14:39:51 grant Exp $

DISTNAME=	squid-2.4.STABLE7-src
PKGNAME=	squid-2.4.7
CATEGORIES=	www
MASTER_SITES=	http://www.squid-cache.org/Versions/v2/2.4/ \
		ftp://ftp.leo.org/pub/comp/general/infosys/www/daemons/squid/squid-2/STABLE/ \
		ftp://ftp1.au.squid-cache.org/pub/squid/squid-2/STABLE/

MAINTAINER=	tron@netbsd.org
HOMEPAGE=	http://www.squid-cache.org/
COMMENT=	Post-Harvest_cached WWW proxy cache and accelerator

USE_PERL5=	build

# Configuration directory location which can be overwritten by the user.
PKG_SYSCONFSUBDIR?=	squid

.include "../../mk/bsd.prefs.mk"

GNU_CONFIGURE=	YES
CONFIGURE_ARGS+= --sysconfdir=${PKG_SYSCONFDIR} \
		--localstatedir=/var/squid \
		${SQUID_CONFIGURE_ARGS}
CONFIGURE_ENV+=	PERL=${PERL5}

BUILD_DEFS+=	SQUID_CONFIGURE_ARGS
MAKEFILE=	makefile
MAKE_ENV+=	INSTALL_SCRIPT="${INSTALL_SCRIPT}" PKG_PREFIX="${PREFIX}"
PLIST_SRC=	${WRKDIR}/PLIST
WRKSRC=		${WRKDIR}/${DISTNAME:S/-src//}
RCD_SCRIPTS=	squid

CONF_FILES+=	${PREFIX}/share/examples/squid/mime.conf \
			${PKG_SYSCONFDIR}/mime.conf
CONF_FILES+=	${PREFIX}/share/examples/squid/squid.conf \
			${PKG_SYSCONFDIR}/squid.conf

# Configuration options which can be overwritten by the user.
SQUID_CONFIGURE_ARGS?=	--disable-internal-dns \
			--enable-cachemgr-hostname=localhost \
			--enable-delay-pools \
			--enable-icmp \
			--enable-ipf-transparent \
			--enable-snmp \
			--enable-underscores \
			--enable-storeio=ufs,diskd

OPTIONAL_FILES=	libexec/diskd libexec/dnsserver libexec/pinger libexec/unlinkd

post-build:
	@${SED} ${FILES_SUBST_SED} ${FILESDIR}/squid.sh > ${WRKDIR}/squid

pre-install:
	@${INSTALL_DATA_DIR} ${PREFIX}/share/examples/squid
	@${INSTALL_DATA_DIR} ${PREFIX}/share/squid
	@${INSTALL_DATA_DIR} ${PREFIX}/share/squid/errors
	@${INSTALL_DATA_DIR} ${PREFIX}/share/squid/icons

post-install:
	cd ${WRKSRC}/src; ${TEST} ! -x pinger || ${MAKE} install-pinger
	${INSTALL_SCRIPT} ${WRKDIR}/squid ${RCD_SCRIPTS_EXAMPLEDIR}/squid
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

.include "../../mk/bsd.pkg.install.mk"
.include "../../mk/bsd.pkg.mk"
