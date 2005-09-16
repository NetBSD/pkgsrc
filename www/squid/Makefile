# $NetBSD: Makefile,v 1.159 2005/09/16 14:19:00 taca Exp $

DISTNAME=	squid-2.5.STABLE10
PKGNAME=	squid-2.5.10
PKGREVISION=	4
CATEGORIES=	www
MASTER_SITES=	http://www.squid-cache.org/Versions/v2/2.5/ \
		ftp://ftp.leo.org/pub/comp/general/infosys/www/daemons/squid/squid-2/STABLE/ \
		ftp://ftp1.au.squid-cache.org/pub/squid/squid-2/STABLE/
EXTRACT_SUFX=	.tar.bz2

PATCH_SITES=	http://www.squid-cache.org/Versions/v2/2.5/bugs/
PATCHFILES=	squid-2.5.STABLE10-content_length.patch \
		squid-2.5.STABLE10-spanish.patch \
		squid-2.5.STABLE10-internal_date.patch \
		squid-2.5.STABLE10-chroot-2.patch \
		squid-2.5.STABLE10-transparent-2.patch \
		squid-2.5.STABLE10-redirect_flags.patch \
		squid-2.5.STABLE10-cache_dir_change.patch \
		squid-2.5.STABLE10-snmp_getnext.patch \
		squid-2.5.STABLE10-ftp_title-2.patch \
		squid-2.5.STABLE10-ftp_basehref.patch \
		squid-2.5.STABLE10-wbinfo_groups.patch \
		squid-2.5.STABLE10-64bit_cleanup.patch \
		squid-2.5.STABLE10-wb_ntlm_auth_silent.patch \
		squid-2.5.STABLE10-buildenv.patch \
		squid-2.5.STABLE10-mail_program.patch \
		squid-2.5.STABLE10-arp_ipfilter-2.patch \
		squid-2.5.STABLE10-sslConnectTimeout.patch \
		squid-2.5.STABLE10-statHistAssert.patch \
		squid-2.5.STABLE10-chroot_dir.patch \
		squid-2.5.STABLE10-errmsg.patch \
		squid-2.5.STABLE10-FORTIFY_SOURCE.patch \
		squid-2.5.STABLE10-ftp_250.patch \
		squid-2.5.STABLE10-Greek.patch \
		squid-2.5.STABLE10-STORE_PENDING.patch \
		squid-2.5.STABLE10-ldap_auth-U.patch \
		squid-2.5.STABLE10-cacheClientTable.patch \
		squid-2.5.STABLE10-Solaris_IPFilter-2.patch \
		squid-2.5.STABLE10-mail_from.patch \
		squid-2.5.STABLE10-LDAP_TLS.patch \
		squid-2.5.STABLE10-storedir_objsize_debug.patch \
		squid-2.5.STABLE10-header_id_enum.patch \
		squid-2.5.STABLE10-allow_coredump.patch \
		squid-2.5.STABLE10-delay_pools.patch \
		squid-2.5.STABLE10-NetBSD_IPFilter-4.patch \
		squid-2.5.STABLE10-pipeline-CONNECT.patch \
		squid-2.5.STABLE10-NTLM-scheme_assert-2.patch
PATCH_DIST_STRIP=       -p1

MAINTAINER=	taca@NetBSD.org
HOMEPAGE=	http://www.squid-cache.org/
COMMENT=	Post-Harvest_cached WWW proxy cache and accelerator

WRKSRC=		${WRKDIR}/${DISTNAME:S/-src//}
DIST_SUBDIR=	${PKGNAME_NOREV}-${DIST_STAMP}

DOCDIR=		${PREFIX}/share/doc/squid
EXAMPLESDIR=	${PREFIX}/share/examples/squid
DATADIR=	${VARBASE}/squid

# Update this time stamp pattern if any of official distfiles has changed.
#
DIST_STAMP=	2005060500

DOCFILES=	ChangeLog RELEASENOTES.html doc/debug-sections.txt

# Configuration directory location which can be overwritten by the user.
PKG_SYSCONFSUBDIR?=	squid

USE_PKGINSTALL=		yes
USE_TOOLS+=		perl:run
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR} \
			--localstatedir=${DATADIR}

MAKE_ENV+=	INSTALL_SCRIPT="${INSTALL_SCRIPT}"
MAKE_ENV+=	PKG_PREFIX="${PREFIX}" VARBASE="${VARBASE}"
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
	for FILE in ${OPTIONAL_FILES}; do			\
	  ${TEST} ! -r ${PREFIX}/$$FILE || ${ECHO} $$FILE;	\
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
	ls anthony-*.gif | ${SED} -e 's@^@share/squid/icons/@';	\
	${ECHO} "@dirrm share/squid/icons";			\
	${ECHO} "share/squid/mib.txt";				\
	${ECHO} "@dirrm share/squid"				\
	) >>${PLIST_SRC}

.include "options.mk"
.include "../../mk/bsd.pkg.mk"
