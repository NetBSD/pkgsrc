# $NetBSD: Makefile,v 1.47 2001/07/29 16:41:18 tron Exp $

DISTNAME=	squid-2.4.STABLE1-src
PKGNAME=	squid-2.4.1nb1
CATEGORIES=	www
MASTER_SITES=	http://www.squid-cache.org/Versions/v2/2.4/ \
		ftp://ftp.leo.org/pub/comp/general/infosys/www/daemons/squid/squid-2/STABLE/ \
		ftp://ftp1.au.squid-cache.org/pub/squid/squid-2/STABLE/

PATCH_SITES=	http://www.squid-cache.org/Versions/v2/2.4/bugs/
PATCHFILES=	squid-2.4.stable1-diskd_fixed_path.patch \
		squid-2.4.stable1-force_valid_blksize.patch \
		squid-2.4.stable1-high_cpu_with_peers.patch \
		squid-2.4.stable1-htcp_assertion_fix.patch \
		squid-2.4.stable1-kill_parent_on_child_sigkill.patch \
		squid-2.4.stable1-wrong_sign_on_timestamp_check.patch

MAINTAINER=	tron@netbsd.org
HOMEPAGE=	http://www.squid-cache.org/
COMMENT=	Post-Harvest_cached WWW proxy cache and accelerator

BUILD_DEPENDS+=	perl>=${PERL5_REQD}:../../lang/perl5

GNU_CONFIGURE=	# defined
CONFIGURE_ARGS+= --sysconfdir=${PREFIX}/etc/squid \
		--localstatedir=/var/squid \
		${SQUID_CONFIGURE_ARGS}
CONFIGURE_ENV+=	PERL=${PERL5}

BUILD_DEFS+=	SQUID_CONFIGURE_ARGS
MAKEFILE=	makefile
MAKE_ENV+=	INSTALL_SCRIPT="${INSTALL_SCRIPT}" PKG_PREFIX="${PREFIX}"
PLIST_SRC=	${WRKDIR}/PLIST
WRKSRC=		${WRKDIR}/${DISTNAME:S/-src//}

.include "../../mk/bsd.prefs.mk"
# Configuration options which can be overwritten by the user.
SQUID_CONFIGURE_ARGS?=	--enable-cachemgr-hostname=localhost \
			--enable-delay-pools \
			--enable-icmp \
			--enable-ipf-transparent \
			--enable-kill-parent-hack \
			--enable-snmp \
			--enable-underscores

post-configure:
	@cd ${WRKSRC}/include && \
	${MV} autoconf.h autoconf.h.prepatch && \
	${SED} -e 's%#define fd_mask int%/* #undef fd_mask */%' <autoconf.h.prepatch \
	 >autoconf.h

post-build:
	${SED} s#@PREFIX@#${PREFIX}#g <${FILESDIR}/squid.sh >${WRKDIR}/squid.sh

pre-install:
	@${CP} ${PKGDIR}/PLIST ${PLIST_SRC}
	@${INSTALL_DATA_DIR} ${PREFIX}/share/squid
	@${INSTALL_DATA_DIR} ${PREFIX}/share/squid/errors
	@${INSTALL_DATA_DIR} ${PREFIX}/share/squid/icons
	@(							\
	cd ${WRKSRC}/errors/English;				\
	ls ERR_* | ${SED} -e 's@^@share/squid/errors/@';		\
	${ECHO} "@dirrm share/squid/errors";			\
	cd ${WRKSRC}/icons;					\
	ls anthony-*.gif | ${SED} -e 's@^@share/squid/icons/@';	\
	${ECHO} "@dirrm share/squid/icons";			\
	${ECHO} "share/squid/mib.txt";				\
	${ECHO} "@dirrm share/squid";				\
	) >>${PLIST_SRC}

post-install:
	${INSTALL_DATA_DIR} /var/squid
	${INSTALL} -d -o nobody /var/squid/logs
	cd ${WRKSRC}/src; ${MAKE} install-pinger
	${INSTALL_SCRIPT} ${WRKDIR}/squid.sh ${PREFIX}/etc/rc.d/squid
	@${SETENV} ${MAKE_ENV} ${SH} ${INSTALL_FILE} ${PKGNAME} POST-INSTALL

.include "../../mk/bsd.pkg.mk"
