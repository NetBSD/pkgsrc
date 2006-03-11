# $NetBSD: Makefile,v 1.172 2006/03/11 10:41:03 taca Exp $

DISTNAME=	squid-2.5.STABLE12
PKGNAME=	squid-2.5.12
PKGREVISION=	6
CATEGORIES=	www
MASTER_SITES=	http://www.squid-cache.org/Versions/v2/2.5/ \
		ftp://ftp.leo.org/pub/comp/general/infosys/www/daemons/squid/squid-2/STABLE/ \
		ftp://ftp1.au.squid-cache.org/pub/squid/squid-2/STABLE/
EXTRACT_SUFX=	.tar.bz2

PATCH_SITES=	http://www.squid-cache.org/Versions/v2/2.5/bugs/
PATCHFILES=	squid-2.5.STABLE12-setenv.patch \
		squid-2.5.STABLE12-REPORT.patch \
		squid-2.5.STABLE12-SMB_BadFetch.patch \
		squid-2.5.STABLE12-wbinfo_group.patch \
		squid-2.5.STABLE12-asyncio_counters.patch \
		squid-2.5.STABLE12-prctl_args.patch \
		squid-2.5.STABLE12-irix_timezone.patch \
		squid-2.5.STABLE12-log_206-4.patch \
		squid-2.5.STABLE12-range2GB-2.patch \
		squid-2.5.STABLE12-empty_proxy_auth_acl.patch \
		squid-2.5.STABLE12-ident_acl.patch \
		squid-2.5.STABLE12-ntlm_nonpersistent.patch \
		squid-2.5.STABLE12-ftp_upload.patch \
		squid-2.5.STABLE12-delay_pool_reconfigure.patch \
		squid-2.5.STABLE12-persistent_connection_after_error.patch \
		squid-2.5.STABLE12-devnull.patch \
		squid-2.5.STABLE12-fc5.patch \
		squid-2.5.STABLE12-ftpdates.patch \
		squid-2.5.STABLE12-ftpsymlink.patch
PATCH_DIST_STRIP= -p1

MAINTAINER=	taca@NetBSD.org
HOMEPAGE=	http://www.squid-cache.org/
COMMENT=	Post-Harvest_cached WWW proxy cache and accelerator

WRKSRC=		${WRKDIR}/${DISTNAME:S/-src//}
DIST_SUBDIR=	${PKGNAME_NOREV}

DOCDIR=		${PREFIX}/share/doc/squid
EXAMPLESDIR=	${PREFIX}/share/examples/squid
DATADIR=	${VARBASE}/squid

DOCFILES=	ChangeLog RELEASENOTES.html doc/debug-sections.txt

USE_TOOLS+=		perl
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR:Q} \
			--localstatedir=${DATADIR:Q}

MAKE_ENV+=	INSTALL_SCRIPT=${INSTALL_SCRIPT:Q}
MAKE_ENV+=	PKG_PREFIX=${PREFIX:Q} VARBASE=${VARBASE:Q}
PLIST_SRC=	${WRKDIR}/PLIST
RCD_SCRIPTS=	squid

PKG_GROUPS=	${SQUID_GROUP}
PKG_USERS=	${SQUID_USER}:${SQUID_GROUP}::Squid\ Web-Cache\ pseudo-user
CONF_FILES+=	${EXAMPLESDIR}/mime.conf ${PKG_SYSCONFDIR}/mime.conf
CONF_FILES+=	${EXAMPLESDIR}/squid.conf ${PKG_SYSCONFDIR}/squid.conf
CONF_FILES+=	${EXAMPLESDIR}/msntauth.conf ${PKG_SYSCONFDIR}/msntauth.conf
OWN_DIRS=	${DATADIR}
OWN_DIRS_PERMS+= ${DATADIR}/cache ${SQUID_USER} ${SQUID_GROUP} 0750 \
		 ${DATADIR}/logs ${SQUID_USER} ${SQUID_GROUP} 0750
EXAMPLES_FILES=	src/mime.conf.default src/squid.conf.default \
		helpers/basic_auth/MSNT/msntauth.conf.default

.include "../../mk/bsd.prefs.mk"

PKG_SYSCONFSUBDIR?=	squid

SQUID_USER?=	squid
SQUID_GROUP?=	squid
BUILD_DEFS+=	SQUID_USER SQUID_GROUP

CONFIGURE_ARGS+=	--enable-auth=basic,digest,ntlm \
			--enable-cachemgr-hostname=localhost \
			--enable-delay-pools \
			--enable-removal-policies=lru,heap \
			--enable-poll \
			--enable-underscores \
			--enable-storeio=${SQUID_BACKENDS:Q}

#
# generic helpers
#
OPTIONAL_FILES+= libexec/diskd libexec/dnsserver libexec/pinger libexec/unlinkd
#
# basic auth helpers (except LDAP, multi-domain-NTLM and SASL)
#
OPTIONAL_FILES+= libexec/getpwname_auth libexec/msnt_auth libexec/ncsa_auth
OPTIONAL_FILES+= libexec/pam_auth man/man8/pam_auth.8 libexec/smb_auth
OPTIONAL_FILES+= libexec/yp_auth libexec/wb_auth
#
# digest auth helpers
#
OPTIONAL_FILES+= libexec/digest_pw_auth
#
# ntlm auth helpers (except no_check and winbind)
#
OPTIONAL_FILES+= libexec/fakeauth_auth libexec/ntlm_auth
OPTIONAL_FILES+= libexec/wb_ntlmauth man/man8/squid_unix_group.8
#
# external acl helpers (except ldap_group, wbinfo_group and winbind_group)
#
OPTIONAL_FILES+= libexec/ip_user_check libexec/squid_unix_group

pre-install:
	@${INSTALL_DATA_DIR} ${PREFIX}/share/squid
	@${INSTALL_DATA_DIR} ${PREFIX}/share/squid/errors
	@${INSTALL_DATA_DIR} ${PREFIX}/share/squid/icons

post-install:
	@${INSTALL_DATA_DIR} ${EXAMPLESDIR}
.for f in ${EXAMPLES_FILES}
	cd ${WRKSRC} && \
	${INSTALL_DATA}	${f} ${EXAMPLESDIR}/`basename ${f} .default`
.endfor
	@${CP} ${PKGDIR}/PLIST ${PLIST_SRC}
	${INSTALL_DATA_DIR} ${DOCDIR}
	@cd ${WRKSRC};						\
	for i in ${DOCFILES}; do				\
		${INSTALL_DATA} $$i ${DOCDIR};			\
	done
	@(							\
	for i in ${OPTIONAL_FILES}; do				\
	  ${TEST} ! -r ${PREFIX}/$$i || ${ECHO} $$i;		\
	done;							\
	cd ${WRKSRC}/errors;					\
	for i in *; do						\
		${TEST} -d $$i &&				\
		(${LS} $$i/ERR_* |				\
		${SED} -e 's@^@share/squid/errors/@';		\
		${ECHO} "@dirrm share/squid/errors/$$i");	\
	done; 							\
	${ECHO} "@dirrm share/squid/errors";			\
	cd ${WRKSRC}/icons;					\
	${LS} anthony-*.gif |					\
			${SED} -e 's@^@share/squid/icons/@';	\
	${ECHO} "@dirrm share/squid/icons";			\
	${ECHO} "share/squid/mib.txt";				\
	${ECHO} "@dirrm share/squid"				\
	) >>${PLIST_SRC}

.include "options.mk"
.include "../../mk/bsd.pkg.mk"
