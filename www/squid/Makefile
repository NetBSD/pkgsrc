# $NetBSD: Makefile,v 1.93 2003/09/17 05:33:46 taca Exp $

DISTNAME=	squid-2.5.STABLE4
PKGNAME=	squid-2.5.4
WRKSRC=		${WRKDIR}/${DISTNAME:S/-src//}
CATEGORIES=	www
MASTER_SITES=	http://www.squid-cache.org/Versions/v2/2.5/ \
		ftp://ftp.leo.org/pub/comp/general/infosys/www/daemons/squid/squid-2/STABLE/ \
		ftp://ftp1.au.squid-cache.org/pub/squid/squid-2/STABLE/
EXTRACT_SUFX=	.tar.bz2

#PATCH_SITES=	http://www.squid-cache.org/Versions/v2/2.5/bugs/
#PATCHFILES=
PATCH_DIST_STRIP=       -p1

MAINTAINER=	taca@NetBSD.org
HOMEPAGE=	http://www.squid-cache.org/
COMMENT=	Post-Harvest_cached WWW proxy cache and accelerator

USE_PERL5=	build
DIST_SUBDIR=	squid-2.5.4
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
