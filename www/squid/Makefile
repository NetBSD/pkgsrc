# $NetBSD: Makefile,v 1.124 2005/01/13 16:19:10 taca Exp $

DISTNAME=	squid-2.5.STABLE7
PKGNAME=	squid-2.5.7
PKGREVISION=	5
CATEGORIES=	www
MASTER_SITES=	http://www.squid-cache.org/Versions/v2/2.5/ \
		ftp://ftp.leo.org/pub/comp/general/infosys/www/daemons/squid/squid-2/STABLE/ \
		ftp://ftp1.au.squid-cache.org/pub/squid/squid-2/STABLE/
EXTRACT_SUFX=	.tar.bz2

PATCH_SITES=	http://www.squid-cache.org/Versions/v2/2.5/bugs/
PATCHFILES=	squid-2.5.STABLE7-half_closed_POST.patch \
		squid-2.5.STABLE7-LDAP_version_documentation.patch \
		squid-2.5.STABLE7_req_resp_header.patch \
		squid-2.5.STABLE7-helper_shutdown.patch \
		squid-2.5.STABLE7-non_blocking_disk.patch \
		squid-2.5.STABLE7-blank_response.patch \
		squid-2.5.STABLE7-dothost.patch \
		squid-2.5.STABLE7-httpd_accel_vport.patch \
		squid-2.5.STABLE7-cachemgr_vmobjects.patch \
		squid-2.5.STABLE7-empty_acls.patch \
		squid-2.5.STABEL7-close_other.patch \
		squid-2.5.STABLE7-fakeauth_auth.patch \
		squid-2.5.STABLE7-gopher_html_parsing.patch \
		squid-2.5.STABLE7-wccp_denial_of_service.patch
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
DIST_STAMP=	2005010100

DOCFILES=	ChangeLog RELEASENOTES.html doc/debug-sections.txt

# Configuration directory location which can be overwritten by the user.
PKG_SYSCONFSUBDIR?=	squid

.include "../../mk/bsd.prefs.mk"

USE_BUILDLINK3=		yes
USE_PERL5=		build
USE_PKGINSTALL=		yes
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR} \
			--localstatedir=${DATADIR} \
			${SQUID_CONFIGURE_ARGS}
#CONFIGURE_ENV+=		PERL=${PERL5}

BUILD_DEFS+=	SQUID_CONFIGURE_ARGS
MAKE_ENV+=	INSTALL_SCRIPT="${INSTALL_SCRIPT}"
MAKE_ENV+=	PKG_PREFIX="${PREFIX}"
PLIST_SRC=	${WRKDIR}/PLIST
RCD_SCRIPTS=	squid

SQUID_USER?=	squid
SQUID_GROUP?=	squid

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
