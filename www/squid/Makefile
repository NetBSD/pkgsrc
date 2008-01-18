# $NetBSD: Makefile,v 1.202 2008/01/18 05:09:53 tnn Exp $

DISTNAME=	squid-2.6.STABLE18
PKGNAME=	${DISTNAME:S/STABLE//}
PKGREVISION=	1
CATEGORIES=	www
MASTER_SITES=	http://www.squid-cache.org/Versions/v2/2.6/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	taca@NetBSD.org
HOMEPAGE=	http://www.squid-cache.org/
COMMENT=	Post-Harvest_cached WWW proxy cache and accelerator

WRKSRC=		${WRKDIR}/${DISTNAME:S/-src//}

DOCDIR=		${PREFIX}/share/doc/squid
EXAMPLESDIR=	${PREFIX}/share/examples/squid

DOCFILES=	ChangeLog RELEASENOTES.html doc/debug-sections.txt

USE_TOOLS+=		perl
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR:Q} \
			--localstatedir=${SQUID_DATADIR:Q}

MAKE_ENV+=	INSTALL_SCRIPT=${INSTALL_SCRIPT:Q}
MAKE_ENV+=	PKG_PREFIX=${PREFIX:Q} VARBASE=${VARBASE:Q}
PLIST_SRC=	${WRKDIR}/PLIST
RCD_SCRIPTS=	squid

CONF_FILES+=	${EXAMPLESDIR}/cachemgr.conf ${PKG_SYSCONFDIR}/cachemgr.conf
CONF_FILES+=	${EXAMPLESDIR}/mime.conf ${PKG_SYSCONFDIR}/mime.conf
CONF_FILES+=	${EXAMPLESDIR}/squid.conf ${PKG_SYSCONFDIR}/squid.conf
CONF_FILES+=	${EXAMPLESDIR}/msntauth.conf ${PKG_SYSCONFDIR}/msntauth.conf
OWN_DIRS=	${SQUID_DATADIR}
OWN_DIRS_PERMS+= ${SQUID_DATADIR}/cache ${SQUID_USER} ${SQUID_GROUP} 0750 \
		 ${SQUID_DATADIR}/logs ${SQUID_USER} ${SQUID_GROUP} 0750
EXAMPLES_FILES=	src/mime.conf.default src/squid.conf.default \
		helpers/basic_auth/MSNT/msntauth.conf.default \
		tools/cachemgr.conf

.include "../../mk/bsd.prefs.mk"
.include "Makefile.common"

BUILD_DEFS+=	VARBASE

CONFIGURE_ARGS+=	--enable-auth=basic,digest,ntlm \
			--enable-cachemgr-hostname=localhost \
			--enable-delay-pools \
			--enable-removal-policies=lru,heap \
			--enable-poll \
			--enable-underscores \
			--enable-storeio=${SQUID_BACKENDS:Q} \
			--with-aio

#
# generic helpers
#
OPTIONAL_FILES+= bin/cossdump libexec/diskd-daemon libexec/dnsserver
OPTIONAL_FILES+= libexec/pinger libexec/unlinkd
#
# basic auth helpers (except LDAP, multi-domain-NTLM and SASL)
#
OPTIONAL_FILES+= libexec/getpwname_auth libexec/msnt_auth libexec/ncsa_auth
OPTIONAL_FILES+= libexec/pam_auth man/man8/ncsa_auth.8 man/man8/pam_auth.8
OPTIONAL_FILES+= libexec/smb_auth libexec/yp_auth libexec/wb_auth
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

SUBST_CLASSES+=		confs
SUBST_STAGE.confs=	pre-configure
SUBST_FILES.confs=	src/cf.data.pre
SUBST_SED.confs=	-e "s/@USER@/${SQUID_USER}/"
SUBST_MESSAGE.confs=	Fixing configuration files.

CHECK_PORTABILITY_SKIP+=	icons/icons.shar

pre-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/squid
	${INSTALL_DATA_DIR} ${PREFIX}/share/squid/errors
	${INSTALL_DATA_DIR} ${PREFIX}/share/squid/icons

post-install:
	${INSTALL_DATA_DIR} ${EXAMPLESDIR}
.for f in ${EXAMPLES_FILES}
	${INSTALL_DATA}	${WRKSRC}/${f} ${EXAMPLESDIR}/`basename ${f} .default`
.endfor
	${CP} ${PKGDIR}/PLIST ${PLIST_SRC}
	${INSTALL_DATA_DIR} ${DOCDIR}
	cd ${WRKSRC};						\
	for i in ${DOCFILES}; do				\
		${INSTALL_DATA} $$i ${DOCDIR};			\
	done
	(							\
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
		${SED} -e 's@^@share/squid/icons/@';		\
	${ECHO} "@dirrm share/squid/icons";			\
	${ECHO} "share/squid/mib.txt";				\
	${ECHO} "@dirrm share/squid"				\
	) >>${PLIST_SRC}

.include "options.mk"
.include "../../mk/bsd.pkg.mk"
