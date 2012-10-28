# $NetBSD: Makefile,v 1.5 2012/10/28 06:31:05 asau Exp $
#

DISTNAME=		squirm-1.0betaB
CATEGORIES=		www
MASTER_SITES=		http://squirm.foote.com.au/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://squirm.foote.com.au/
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

.include "../../mk/bsd.pkg.mk"
