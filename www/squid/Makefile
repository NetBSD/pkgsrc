# $NetBSD: Makefile,v 1.112 2004/06/19 22:05:48 taca Exp $

DISTNAME=	squid-2.5.STABLE5
PKGNAME=	squid-2.5.5
PKGREVISION=	6
CATEGORIES=	www
MASTER_SITES=	http://www.squid-cache.org/Versions/v2/2.5/ \
		ftp://ftp.leo.org/pub/comp/general/infosys/www/daemons/squid/squid-2/STABLE/ \
		ftp://ftp1.au.squid-cache.org/pub/squid/squid-2/STABLE/
EXTRACT_SUFX=	.tar.bz2

PATCH_SITES=	http://www.squid-cache.org/Versions/v2/2.5/bugs/
PATCHFILES=	squid-2.5.STABLE5-ntlm_assert.patch \
		squid-2.5.STABLE5-ldap.patch \
		squid-2.5.STABLE5-helper_warning.patch \
		squid-2.5.STABLE5-pkgconfig.patch \
		squid-2.5.STABLE5-vary.patch \
		squid-2.5.STABLE5-lin22_poll.patch \
		squid-2.5.STABLE5-version.patch \
		squid-2.5.STABLE5-deny_info.patch \
		squid-2.5.STABLE5-CONNECT_timeout.patch \
		squid-2.5.STABLE5-cache_swap_log.patch \
		squid-2.5.STABLE5-ntlm_warning.patch \
		squid-2.5.STABLE5-rfc1035NameUnpack.patch \
		squid-2.5.STABLE5-digest_blank.patch \
		squid-2.5.STABLE5-post_assert.patch \
		squid-2.5.STABLE5-spelling.patch \
		squid-2.5.STABLE5-digest_ERR.patch \
		squid-2.5.STABLE5-turkish_ERR_DNS_FAIL.patch \
		squid-2.5.STABLE5-vary_negatively.patch \
		squid-2.5.STABLE5-range_offset_limit.patch \
		squid-2.5.STABLE5-large_cache_mem.patch \
		squid-2.5.STABLE5-least-load.patch \
		squid-2.5.STABLE5-cacheCurrentUnlinkRequests.patch \
		squid-2.5.STABLE5-debug_client_ip.patch \
		squid-2.5.STABLE5-openbsd_m88k.patch \
		squid-2.5.STABLE5-ftp_html_doctype.patch \
		squid-2.5.STABLE5-dns_localhost.patch \
		squid-2.5.STABLE5-msnt_auth_doc.patch \
		squid-2.5.STABLE5-va_copy.patch \
		squid-2.5.STABLE5-CONNECT_log_size.patch \
		squid-2.5.STABLE5-proxy_abuse.patch \
		squid-2.5.STABLE5-sasl_auth_SASL2.patch \
		squid-2.5.STABLE5-ntlm_auth_overflow.patch
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
