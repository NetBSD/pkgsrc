# $NetBSD: Makefile,v 1.4 2024/12/11 15:25:04 ryoon Exp $

DISTNAME=	fcgiwrap-1.1.0
PKGREVISION=	2
CATEGORIES=	www

COMMENT=	FastCGI wrapper for plain CGI scripts
LICENSE=	mit

GITHUB_TAG=	${PKGVERSION_NOREV}
MASTER_SITES=	${MASTER_SITE_GITHUB:=gnosek/}

MAINTAINER=	pkgsrc-users@NetBSD.org
#HOMEPAGE=	http://nginx.localdomain.pl/wiki/FcgiWrap


GNU_CONFIGURE=	yes
USE_TOOLS+=	automake autoreconf pkg-config

LDFLAGS.SunOS+=	-lsocket -lnsl

FCGIWRAP_USER?=		nginx
FCGIWRAP_GROUP?=	nginx
PKG_USERS_VARS+=	FCGIWRAP_USER
PKG_GROUPS_VARS+=	FCGIWRAP_GROUP
PKG_GROUPS=		${FCGIWRAP_GROUP}
PKG_USERS=		${FCGIWRAP_USER}:${FCGIWRAP_GROUP}

FILES_SUBST+=		FCGIWRAP_USER=${FCGIWRAP_USER}
FILES_SUBST+=		FCGIWRAP_GROUP=${FCGIWRAP_GROUP}

RCD_SCRIPTS+=		fcgiwrap

pre-configure:
	cd ${WRKSRC} && autoreconf -i

.include "../../www/fcgi/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
