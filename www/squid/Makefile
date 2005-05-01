# $NetBSD: Makefile,v 1.149 2005/05/01 23:17:49 taca Exp $

DISTNAME=	squid-2.5.STABLE9
PKGNAME=	squid-2.5.9
PKGREVISION=	10
CATEGORIES=	www
MASTER_SITES=	http://www.squid-cache.org/Versions/v2/2.5/ \
		ftp://ftp.leo.org/pub/comp/general/infosys/www/daemons/squid/squid-2/STABLE/ \
		ftp://ftp1.au.squid-cache.org/pub/squid/squid-2/STABLE/
EXTRACT_SUFX=	.tar.bz2

PATCH_SITES=	http://www.squid-cache.org/Versions/v2/2.5/bugs/
PATCHFILES=	squid-2.5.STABLE9-setcookie.patch \
		squid-2.5.STABLE9-ftp_EPLF.patch \
		squid-2.5.STABLE9-ftp_base_href.patch \
		squid-2.5.STABLE9-acl_error.patch \
		squid-2.5.STABLE9-date.patch \
		squid-2.5.STABLE9-reload_into_ims.patch \
		squid-2.5.STABLE9-delay_access_doc.patch \
		squid-2.5.STABLE9-config_overflow.patch \
		squid-2.5.STABLE9-bzero.patch \
		squid-2.5.STABLE9-pid_t.patch \
		squid-2.5.STABLE9-ctype.patch \
		squid-2.5.STABLE9-defer_digest_fetch.patch \
		squid-2.5.STABLE9-dup_content_length.patch \
		squid-2.5.STABLE9-excess_data.patch \
		squid-2.5.STABLE9-aufs.patch \
		squid-2.5.STABLE9-long_basic_auth.patch \
		squid-2.5.STABLE9-CONNECT_truncated.patch \
		squid-2.5.STABLE9-LDAP_SUN_SDK.patch \
		squid-2.5.STABLE9-disable_hostname_checks.patch \
		squid-2.5.STABLE9-aufs_shutdown.patch \
		squid-2.5.STABLE9-2GB.patch \
		squid-2.5.STABLE9-rename_cleanup.patch \
		squid-2.5.STABLE9-cachemgr_objects.patch \
		squid-2.5.STABLE9-extaclauth.patch \
		squid-2.5.STABLE9-syslog.patch \
		squid-2.5.STABLE9-errpage_user.patch \
		squid-2.5.STABLE9-debug_newlines.patch \
		squid-2.5.STABLE9-squid_k_nohostname.patch \
		squid-2.5.STABLE9-config_CRLF.patch \
		squid-2.5.STABLE9-forwardcc.patch \
		squid-2.5.STABLE9-authinfo.patch \
		squid-2.5.STABLE9-chroot_pidfile.patch \
		squid-2.5.STABLE9-cachemgr_conf.patch
#		squid-2.5.STABLE9-transparent_port.patch
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
DIST_STAMP=	2005042600

DOCFILES=	ChangeLog RELEASENOTES.html doc/debug-sections.txt

# Configuration directory location which can be overwritten by the user.
PKG_SYSCONFSUBDIR?=	squid

.include "../../mk/bsd.prefs.mk"

USE_PERL5=		build
USE_PKGINSTALL=		yes
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR} \
			--localstatedir=${DATADIR} \
			${SQUID_CONFIGURE_ARGS}
#CONFIGURE_ENV+=		PERL=${PERL5}

BUILD_DEFS+=	SQUID_CONFIGURE_ARGS
MAKE_ENV+=	INSTALL_SCRIPT="${INSTALL_SCRIPT}"
MAKE_ENV+=	PKG_PREFIX="${PREFIX}" VARBASE="${VARBASE}"
PLIST_SRC=	${WRKDIR}/PLIST
RCD_SCRIPTS=	squid

SQUID_USER?=	squid
SQUID_GROUP?=	squid
BUILD_DEFS+=	SQUID_USER SQUID_GROUP

PKG_GROUPS=	${SQUID_GROUP}
PKG_USERS=	${SQUID_USER}:${SQUID_GROUP}::Squid\\ Web-Cache\\ pseudo-user
CONF_FILES+=	${EXAMPLESDIR}/mime.conf ${PKG_SYSCONFDIR}/mime.conf
CONF_FILES+=	${EXAMPLESDIR}/squid.conf ${PKG_SYSCONFDIR}/squid.conf
OWN_DIRS=	${DATADIR}
OWN_DIRS_PERMS+= ${DATADIR}/cache ${SQUID_USER} ${SQUID_GROUP} 0750 \
		 ${DATADIR}/logs ${SQUID_USER} ${SQUID_GROUP} 0750

.if ${OPSYS} == "FreeBSD" || ${OPSYS} == "Linux" || ${OPSYS} == "SunOS"
CONFIGURE_ARGS+=	--enable-arp-acl
.endif

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

.include "../../lang/perl5/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
