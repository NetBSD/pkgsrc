# $NetBSD: Makefile,v 1.18 2026/02/24 08:45:41 bsiegert Exp $

DISTNAME=	anubis-src-vendor-npm-1.24.0
PKGNAME=	${DISTNAME:S/anubis-src-vendor-npm-/anubis-/}
PKGREVISION=	2
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_GITHUB:=TecharoHQ/}
GITHUB_RELEASE=	v${PKGVERSION_NOREV}

MAINTAINER=	bsiegert@NetBSD.org
HOMEPAGE=	https://anubis.techaro.lol/
COMMENT=	Proof-of-work check to stop AI bots
LICENSE=	mit

USE_LANGUAGES=		c # Go
GOFLAGS+=		-ldflags="-X github.com/TecharoHQ/anubis.Version=v${PKGVERSION_NOREV}"
GO_BUILD_PATTERN=	./cmd/anubis

EGDIR=			share/examples/anubis
INSTALLATION_DIRS=	${EGDIR}
PKG_SYSCONFSUBDIR=	anubis
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
	${INSTALL_DATA} ${WRKSRC}/run/default.env ${DESTDIR}${PREFIX}/share/examples/anubis


.include "go-modules.mk"

.include "../../lang/go/go-module.mk"
.include "../../mk/bsd.pkg.mk"
