# $NetBSD: Makefile,v 1.116 2004/10/03 00:18:27 tv Exp $

DISTNAME=	squid-2.5.STABLE6
PKGNAME=	squid-2.5.6
PKGREVISION=	2
CATEGORIES=	www
MASTER_SITES=	http://www.squid-cache.org/Versions/v2/2.5/ \
		ftp://ftp.leo.org/pub/comp/general/infosys/www/daemons/squid/squid-2/STABLE/ \
		ftp://ftp1.au.squid-cache.org/pub/squid/squid-2/STABLE/
EXTRACT_SUFX=	.tar.bz2

PATCH_SITES=	http://www.squid-cache.org/Versions/v2/2.5/bugs/
PATCHFILES=	squid-2.5.STABLE6-ufs_no_valid_dir.patch \
		squid-2.5.STABLE6-ldap_helpers.patch \
		squid-2.5.STABLE6-concurrent_dns_lookups.patch \
		squid-2.5.STABLE6-request_header_max_size.patch \
		squid-2.5.STABLE6-partial_hit_is_miss.patch \
		squid-2.5.STABLE6-HEAD.patch \
		squid-2.5.STABLE6-ufs_create_error.patch \
		squid-2.5.STABLE6-basic_auth_caseinsensitive.patch \
		squid-2.5.STABLE6-active_requests_delaypool.patch \
		squid-2.5.STABLE6-client_db_gc.patch \
		squid-2.5.STABLE6-ntlmtruncated.patch \
		squid-2.5.STABLE6-grammar.patch \
		squid-2.5.STABLE6-errorpage_quote.patch \
		squid-2.5.STABLE6-heap_segfault.patch \
		squid-2.5.STABLE6-initgroups.patch \
		squid-2.5.STABLE6-external_acl_newlines.patch \
		squid-2.5.STABLE6-ntlm_fetch_string.patch \
		squid-2.5.STABLE6-ntlm_noreuse_leak.patch \
		squid-2.5.STABLE6-ntlm_challengereuse_leak.patch \
		squid-2.5.STABLE6-rotate_error.patch \
		squid-2.5.STABLE6-digest_crash.patch \
		squid-2.5.STABLE6-acl_times.patch \
		squid-2.5.STABLE6-http_header_range.patch \
		squid-2.5.STABLE6-Content-Disposition.patch
PATCH_DIST_STRIP=       -p1

MAINTAINER=	taca@NetBSD.org
HOMEPAGE=	http://www.squid-cache.org/
COMMENT=	Post-Harvest_cached WWW proxy cache and accelerator

WRKSRC=		${WRKDIR}/${DISTNAME:S/-src//}
USE_PERL5=	build
DIST_SUBDIR=	${PKGNAME}
DOCDIR=		${PREFIX}/share/doc/squid
EXAMPLESDIR=	${PREFIX}/share/examples/squid

DOCFILES=	ChangeLog RELEASENOTES.html doc/debug-sections.txt

# Configuration directory location which can be overwritten by the user.
PKG_SYSCONFSUBDIR?=	squid

.include "../../mk/bsd.prefs.mk"

USE_BUILDLINK3=		yes
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
SQUID_CONFIGURE_ARGS?=	--enable-auth=basic,digest,ntlm \
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

.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
