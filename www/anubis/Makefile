# $NetBSD: Makefile,v 1.6 2025/06/06 14:01:41 bsiegert Exp $

DISTNAME=	anubis-1.18.0
PKGREVISION=	4
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_GITHUB:=TecharoHQ/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	bsiegert@NetBSD.org
HOMEPAGE=	https://anubis.techaro.lol/
COMMENT=	Proof-of-work check to stop AI bots
LICENSE=	mit

ASSETS=		anubis-1.18.0-assets.tar.bz2
DISTFILES=	${DEFAULT_DISTFILES} ${ASSETS}
SITES.${ASSETS}=	${MASTER_SITE_LOCAL}

EXTRACT_ONLY=	${DEFAULT_DISTFILES} ${ASSETS}

USE_LANGUAGES=		c # Go
GO_BUILD_PATTERN+=	-ldflags="-X github.com/TecharoHQ/anubis.Version=v${PKGVERSION_NOREV}"
GO_BUILD_PATTERN+=	./cmd/anubis

EGDIR=			share/examples/anubis
INSTALLATION_DIRS=	${EGDIR}
PKG_SYSCONFSUBDIR=	anubis
CONF_FILES+=		${EGDIR}/botPolicies.json ${PKG_SYSCONFDIR}/botPolicies.json
CONF_FILES+=		${EGDIR}/default.env ${PKG_SYSCONFDIR}/default.env

APACHE_USER?=		www
APACHE_GROUP?=		www
PKG_USERS_VARS+=	APACHE_USER
PKG_GROUPS_VARS+=	APACHE_GROUP
PKG_GROUPS=		${APACHE_GROUP}
PKG_USERS=		${APACHE_USER}:${APACHE_GROUP}

FILES_SUBST+=		APACHE_USER=${APACHE_USER}
FILES_SUBST+=		APACHE_GROUP=${APACHE_GROUP}

RCD_SCRIPTS+=		anubis

post-install:
	${INSTALL_DATA} ${WRKSRC}/data/botPolicies.json ${DESTDIR}${PREFIX}/share/examples/anubis
	${INSTALL_DATA} ${WRKSRC}/run/default.env ${DESTDIR}${PREFIX}/share/examples/anubis


.include "go-modules.mk"

.include "../../lang/go/go-module.mk"
.include "../../mk/bsd.pkg.mk"
