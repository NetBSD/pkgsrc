# $NetBSD: Makefile,v 1.76 2003/02/16 06:43:40 taca Exp $

DISTNAME=	squid-2.5.STABLE1
PKGNAME=	squid-2.5.1
PKGREVISION=	3
CATEGORIES=	www
MASTER_SITES=	http://www.squid-cache.org/Versions/v2/2.5/ \
		ftp://ftp.leo.org/pub/comp/general/infosys/www/daemons/squid/squid-2/STABLE/ \
		ftp://ftp1.au.squid-cache.org/pub/squid/squid-2/STABLE/
EXTRACT_SUFX=	.tar.bz2

PATCH_SITES=	http://www.squid-cache.org/Versions/v2/2.5/bugs/
PATCHFILES=	squid-2.5.STABLE1-disable-ident-lookups.patch \
		squid-2.5.STABLE1-disable-http-violations.patch \
		squid-2.5.STABLE1-proxy_auth.patch \
		squid-2.5.STABLE1-max_user_ip.patch \
		squid-2.5.STABLE1-cache_dir_docs.patch \
		squid-2.5.STABLE1-load_icons.patch \
		squid-2.5.STABLE1-referer_log.patch \
		squid-2.5.STABLE1-ldap_auth.patch \
		squid-2.5.STABLE1-addlang.patch \
		squid-2.5.STABLE1-pthreads.patch \
		squid-2.5.STABLE1-strwordtok.patch \
		squid-2.5.STABLE1-wccp.patch \
		squid-2.5.STABLE1-memstat.patch \
		squid-2.5.STABLE1-aufs.patch \
		squid-2.5.STABLE1-acl_leak.patch \
		squid-2.5.STABLE1-ext_acl_comma.patch \
		squid-2.5.STABLE1-request_entity.patch \
		squid-2.5.STABLE1-ext_acl_exit.patch \
		squid-2.5.STABLE1-uninstall.patch \
		squid-2.5.STABLE1-cachemgr.patch \
		squid-2.5.STABLE1-auth-proxy.patch \
		squid-2.5.STABLE1-dnsserver.patch \
		squid-2.5.STABLE1-spaces.patch \
		squid-2.5.STABLE1-flags_open.patch \
		squid-2.5.STABLE1-ldap_group-compile.patch \
		squid-2.5.STABLE1-aufs_performance.patch \
		squid-2.5.STABLE1-RunCache.patch \
		squid-2.5.STABLE1-rebuild_assert.patch \
		squid-2.5.STABLE1-offline_mode.patch \
		squid-2.5.STABLE1-S.patch \
		squid-2.5.STABLE1-chroot.patch \
		squid-2.5.STABLE1-aufs_reentrant.patch \
		squid-2.5.STABLE1-relnote11.patch \
		squid-2.5.STABLE1-ldap_group.patch \
		squid-2.5.STABLE1-offline_toggle.patch \
		squid-2.5.STABLE1-failure_ratio.patch \
		squid-2.5.STABLE1-hostnames.patch \
		squid-2.5.STABLE1-sbrk.patch \
		squid-2.5.STABLE1-log_mime_hdrs.patch \
		squid-2.5.STABLE1-peer_select_alg.patch \
		squid-2.5.STABLE1-mempoolstat.patch \
		squid-2.5.STABLE1-copy_offset.patch \
		squid-2.5.STABLE1-select_fds_hist.patch \
		squid-2.5.STABLE1-select_stat.patch \
		squid-2.5.STABLE1-pidfile.patch \
		squid-2.5.STABLE1-http_reply_max_size.patch \
		squid-2.5.STABLE1-cachemgr_non_get.patch \
		squid-2.5.STABLE1-authsheme_realloc.patch \
		squid-2.5.STABLE1-ftp_abort.patch \
		squid-2.5.STABLE1-helper_stats.patch \
		squid-2.5.STABLE1-delay_pools_docs.patch \
		squid-2.5.STABLE1-auth_connection.patch \
		squid-2.5.STABLE1-authenticate_program_docs.patch \
		squid-2.5.STABLE1-with_aufs_threads_trap.patch \
		squid-2.5.STABLE1-shutdown_assert.patch \
		squid-2.5.STABLE1-cachemgr_passwd.patch \
		squid-2.5.STABLE1-etc_hosts_fdleak.patch \
		squid-2.5.STABLE1-openssl097.patch \
		squid-2.5.STABLE1-HEAD_bad_headers.patch \
		squid-2.5.STABLE1-time_acl_list.patch \
		squid-2.5.STABLE1-CONNECT_pipeline.patch \
		squid-2.5.STABLE1-winbind.patch
#	currently it is broken, so patch with patches/patch-cd
#		squid-2.5.STABLE1-mib.patch
PATCH_DIST_STRIP=       -p1

MAINTAINER=	taca@netbsd.org
HOMEPAGE=	http://www.squid-cache.org/
COMMENT=	Post-Harvest_cached WWW proxy cache and accelerator

USE_PERL5=	build
DIST_SUBDIR=	squid-2.5.1

# Configuration directory location which can be overwritten by the user.
PKG_SYSCONFSUBDIR?=	squid

.include "../../mk/bsd.prefs.mk"

USE_BUILDLINK2=		yes
USE_PKGINSTALL=		yes
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR} \
			--localstatedir=/var/squid \
			${SQUID_CONFIGURE_ARGS}
CONFIGURE_ENV+=		PERL=${PERL5}

BUILD_DEFS+=		SQUID_CONFIGURE_ARGS
MAKE_ENV+=		INSTALL_SCRIPT="${INSTALL_SCRIPT}"
MAKE_ENV+=		PKG_PREFIX="${PREFIX}"
PLIST_SRC=		${WRKDIR}/PLIST
WRKSRC=			${WRKDIR}/${DISTNAME:S/-src//}
RCD_SCRIPTS=		squid

CONF_FILES+=		${PREFIX}/share/examples/squid/mime.conf \
				${PKG_SYSCONFDIR}/mime.conf
CONF_FILES+=		${PREFIX}/share/examples/squid/squid.conf \
				${PKG_SYSCONFDIR}/squid.conf

# Configuration options which can be overwritten by the user.
SQUID_CONFIGURE_ARGS?=	--disable-internal-dns \
			--enable-auth=basic,digest,ntlm \
			--enable-cachemgr-hostname=localhost \
			--enable-delay-pools \
			--enable-removal-policies=lru,heap \
			--enable-icmp \
			--enable-ipf-transparent \
			--enable-poll \
			--enable-snmp \
			--enable-ssl \
			--with-openssl=${SSLBASE} \
			--enable-underscores \
			--enable-storeio=ufs,diskd,null \
			--enable-basic-auth-helpers=getpwnam,winbind,SMB \
			--enable-digest-auth-helpers=password \
			--enable-external-acl-helpers=unix_group,ip_user,winbind_group \
			--enable-ntlm-auth-helpers=winbind

OPTIONAL_FILES+= libexec/diskd libexec/dnsserver libexec/pinger libexec/unlinkd
OPTIONAL_FILES+= libexec/digest_pw_auth libexec/getpwname_auth
OPTIONAL_FILES+= libexec/ip_user_check libexec/smb_auth libexec/smb_auth.sh
OPTIONAL_FILES+= libexec/squid_unix_group libexec/wb_auth libexec/wb_group
OPTIONAL_FILES+= libexec/wb_ntlmauth man/man8/squid_unix_group.8

pre-install:
	@${INSTALL_DATA_DIR} ${PREFIX}/share/examples/squid
	@${INSTALL_DATA_DIR} ${PREFIX}/share/squid
	@${INSTALL_DATA_DIR} ${PREFIX}/share/squid/errors
	@${INSTALL_DATA_DIR} ${PREFIX}/share/squid/icons

post-install:
	@${CP} ${PKGDIR}/PLIST ${PLIST_SRC}
	@(							\
	for FILE in ${OPTIONAL_FILES}; do			\
	  ${TEST} ! -e ${PREFIX}/$$FILE || ${ECHO} $$FILE;	\
	done;							\
	cd ${WRKSRC}/errors;					\
	for i in *; do \
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

.include "../../security/openssl/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
