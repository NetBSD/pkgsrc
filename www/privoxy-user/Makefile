# $NetBSD: Makefile,v 1.2 2003/07/17 22:56:00 grant Exp $

DISTNAME=	privoxy-user-3.0.2
CATEGORIES=	www
MASTER_SITES=   # empty
DISTFILES=      # empty

MAINTAINER=	jmc@NetBSD.org
HOMEPAGE=	# empty
COMMENT=	Pre-req package for privoxy to setup user needed for build/use

USE_PKGINSTALL=	yes

EXTRACT_ONLY=	# empty
NO_CHECKSUM=	yes
NO_CONFIGURE=	yes
NO_BUILD=	yes

PRIVOXY_USER?=          privoxy
PRIVOXY_GROUP?=         privoxy

USE_PKGINSTALL=         YES
PKG_GROUPS=             ${PRIVOXY_GROUP}
PKG_USERS=              ${PRIVOXY_USER}:${PRIVOXY_GROUP}::Privoxy\\ user

do-install:	# empty

.include "../../mk/bsd.pkg.mk"
