# $NetBSD: Makefile,v 1.89 2003/08/18 16:03:01 taca Exp $

DISTNAME=	squid-2.5.STABLE3
PKGNAME=	squid-2.5.3
PKGREVISION=	3
WRKSRC=		${WRKDIR}/${DISTNAME:S/-src//}
CATEGORIES=	www
MASTER_SITES=	http://www.squid-cache.org/Versions/v2/2.5/ \
		ftp://ftp.leo.org/pub/comp/general/infosys/www/daemons/squid/squid-2/STABLE/ \
		ftp://ftp1.au.squid-cache.org/pub/squid/squid-2/STABLE/
EXTRACT_SUFX=	.tar.bz2

PATCH_SITES=	http://www.squid-cache.org/Versions/v2/2.5/bugs/
PATCHFILES=	squid-2.5.STABLE3-Lithuanian.patch \
		squid-2.5.STABLE3-HttpHeaderTools.patch \
		squid-2.5.STABLE3-deny_info.patch \
		squid-2.5.STABLE3-cache_dir_doc.patch \
		squid-2.5.STABLE3-devnull.patch \
		squid-2.5.STABLE3-log_quote.patch \
		squid-2.5.STABLE3-rfc_reference.patch \
		squid-2.5.STABLE3-icmpRecv.patch \
		squid-2.5.STABLE3-external_acl_ident.patch \
		squid-2.5.STABLE3-aufs-openingfds.patch \
		squid-2.5.STABLE3-gcc-3_3.patch \
		squid-2.5.STABLE3-carpfactor.patch \
		squid-2.5.STABLE3-neighbor_type_domain.patch \
		squid-2.5.STABLE3-header_access_peer.patch \
		squid-2.5.STABLE3-memwarnsbrk.patch \
		squid-2.5.STABLE3-hostscomments.patch \
		squid-2.5.STABLE3-store_check_cachable_stats.patch \
		squid-2.5.STABLE3-cachePeerPingsSentsnmp.patch \
		squid-2.5.STABLE3-minimum_retry_timeout.patch \
		squid-2.5.STABLE3-ERR_TOO_BIG_Spanish.patch \
		squid-2.5.STABLE3-tcp_reset_leak.patch \
		squid-2.5.STABLE3-hostheader.patch \
		squid-2.5.STABLE3-reply_body_max_size.patch \
		squid-2.5.STABLE3-ie_refresh.patch \
		squid-2.5.STABLE3-http_reply_access-denied.patch \
		squid-2.5.STABLE3-SENT_PASV.patch \
		squid-2.5.STABLE3-peer_digest_not_found_assertion.patch \
		squid-2.5.STABLE3-round_robin_max_size.patch \
		squid-2.5.STABLE3-syscalls.disk-counters.patch \
		squid-2.5.STABLE3-coss-improvements.patch \
		squid-2.5.STABLE3-blank-username-log.patch \
		squid-2.5.STABLE3-mem_cfd.patch \
		squid-2.5.STABLE3-aufs_open_fail.patch \
		squid-2.5.STABLE3-aufs_threads.patch \
		squid-2.5.STABLE3-digest_compile.patch \
		squid-2.5.STABLE3-407_user_name.patch \
		squid-2.5.STABLE3-multicast-ICP-timeout.patch
# This patch is broken now.  It should be applied after
# squid-2.5.STABLE3-coss-improvements.patch
#		squid-2.5.STABLE3-coss-improvements-2.patch \
PATCH_DIST_STRIP=       -p1

MAINTAINER=	taca@NetBSD.org
HOMEPAGE=	http://www.squid-cache.org/
COMMENT=	Post-Harvest_cached WWW proxy cache and accelerator

USE_PERL5=	build
DIST_SUBDIR=	squid-2.5.3
DOCDIR=		${PREFIX}/share/doc/squid
EXAMPLESDIR=	${PREFIX}/share/examples/squid

DOCFILES=	ChangeLog RELEASENOTES.html doc/debug-sections.txt

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
RCD_SCRIPTS=		squid

CONF_FILES+=		${EXAMPLESDIR}/mime.conf ${PKG_SYSCONFDIR}/mime.conf
CONF_FILES+=		${EXAMPLESDIR}/squid.conf ${PKG_SYSCONFDIR}/squid.conf

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
	@${INSTALL_DATA_DIR} ${EXAMPLESDIR}
	@${INSTALL_DATA_DIR} ${PREFIX}/share/squid
	@${INSTALL_DATA_DIR} ${PREFIX}/share/squid/errors
	@${INSTALL_DATA_DIR} ${PREFIX}/share/squid/icons

post-install:
	@${CP} ${PKGDIR}/PLIST ${PLIST_SRC}
	${INSTALL_DATA_DIR} ${DOCDIR}
	@cd ${WRKSRC};						\
	for i in ${DOCFILES}; do				\
		${INSTALL_DATA} $$i ${DOCDIR};			\
	done
	@(							\
	for FILE in ${OPTIONAL_FILES}; do			\
	  ${TEST} ! -e ${PREFIX}/$$FILE || ${ECHO} $$FILE;	\
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

.include "../../security/openssl/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
