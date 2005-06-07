# $NetBSD: Makefile,v 1.153 2005/06/07 14:19:10 taca Exp $

DISTNAME=	squid-2.5.STABLE10
PKGNAME=	squid-2.5.10
CATEGORIES=	www
MASTER_SITES=	http://www.squid-cache.org/Versions/v2/2.5/ \
		ftp://ftp.leo.org/pub/comp/general/infosys/www/daemons/squid/squid-2/STABLE/ \
		ftp://ftp1.au.squid-cache.org/pub/squid/squid-2/STABLE/
EXTRACT_SUFX=	.tar.bz2

PATCH_SITES=	http://www.squid-cache.org/Versions/v2/2.5/bugs/
PATCHFILES=	squid-2.5.STABLE10-content_length.patch
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
USE_TOOLS+=		perl
TOOLS_DEPMETHOD.perl?=	DEPENDS
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR} \
			--localstatedir=${DATADIR}

MAKE_ENV+=	INSTALL_SCRIPT="${INSTALL_SCRIPT}"
MAKE_ENV+=	PKG_PREFIX="${PREFIX}" VARBASE="${VARBASE}"
PLIST_SRC=	${WRKDIR}/PLIST
RCD_SCRIPTS=	squid

PKG_GROUPS=	${SQUID_GROUP}
PKG_USERS=	${SQUID_USER}:${SQUID_GROUP}::Squid\\ Web-Cache\\ pseudo-user
CONF_FILES+=	${EXAMPLESDIR}/mime.conf ${PKG_SYSCONFDIR}/mime.conf
CONF_FILES+=	${EXAMPLESDIR}/squid.conf ${PKG_SYSCONFDIR}/squid.conf
OWN_DIRS=	${DATADIR}
OWN_DIRS_PERMS+= ${DATADIR}/cache ${SQUID_USER} ${SQUID_GROUP} 0750 \
		 ${DATADIR}/logs ${SQUID_USER} ${SQUID_GROUP} 0750

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
			--enable-storeio=${SQUID_BACKEND:Q}

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
OPTIONAL_FILES+= libexec/wb_ntlmauth man/man8/squid_unix_group.8
#
# external acl helpers (except ldap_group, wbinfo_group and winbind_group)
#
OPTIONAL_FILES+= libexec/ip_user_check libexec/squid_unix_group

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

.include "options.mk"
.include "../../mk/bsd.pkg.mk"
