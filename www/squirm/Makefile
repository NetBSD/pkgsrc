# $NetBSD: Makefile,v 1.7 2026/08/04 20:29:20 wiz Exp $

DISTNAME=		squirm-1.0betaB
CATEGORIES=		www
#MASTER_SITES=		http://squirm.foote.com.au/

MAINTAINER=		pkgsrc-users@NetBSD.org
#HOMEPAGE=		http://squirm.foote.com.au/
COMMENT=		Redirector for the Squid Internet Object Cache

USE_TOOLS+=		gmake
GNU_CONFIGURE=		yes
CONFIGURE_DIRS=		regex-0.12
BUILD_DIRS=		regex-0.12 .

.include "../../mk/bsd.prefs.mk"

SQUID_USER?=		squid
SQUID_GROUP?=		squid
PKG_USERS+=		${SQUID_USER}:${SQUID_GROUP}
PKG_GROUPS+=		${SQUID_GROUP}
PKG_USERS_VARS+=	SQUID_USER
PKG_GROUPS_VARS+=	SQUID_GROUP
BUILD_DEFS+=		VARBASE

PKG_SYSCONFSUBDIR=	squirm
EGDIR=			${PREFIX}/share/examples/squirm
INSTALLATION_DIRS=	bin ${EGDIR}
OWN_DIRS_PERMS=		${VARBASE}/log/squirm ${SQUID_USER} ${SQUID_GROUP} ${PKGDIRMODE}
CONF_FILES=		${EGDIR}/squirm.local.dist ${PKG_SYSCONFDIR}/squirm.local.dist
CONF_FILES+=		${EGDIR}/squirm.patterns.dist ${PKG_SYSCONFDIR}/squirm.patterns.dist

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/squirm ${DESTDIR}${PREFIX}/bin/
	cd ${WRKSRC} && ${INSTALL_DATA} squirm.local.dist squirm.patterns.dist ${DESTDIR}${EGDIR}/

# FIXME: replace by proper LDFLAGS handling
_WRAP_EXTRA_ARGS.CC+=	${_RELRO_LDFLAGS}
_WRAP_EXTRA_ARGS.CXX+=	${_RELRO_LDFLAGS}
CWRAPPERS_PREPEND.cc+=	${_RELRO_LDFLAGS}
CWRAPPERS_PREPEND.cxx+=	${_RELRO_LDFLAGS}

.include "../../mk/bsd.pkg.mk"
