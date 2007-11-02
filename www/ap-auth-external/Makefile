# $NetBSD: Makefile,v 1.5 2007/11/02 15:06:26 sborrill Exp $
#

DISTNAME=	mod_auth_external-${DISTVERS}
PKGREVISION=	2
PKGNAME=	${APACHE_PKG_PREFIX}-auth-external-${DISTVERS}
CATEGORIES=	www
MASTER_SITES=	http://unixpapa.com/software/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://unixpapa.com/mod_authnz_external/
COMMENT=	Apache module for external program authentication

PKG_APACHE_ACCEPTED=	apache13 apache2

.include "../../mk/apache.mk"

APACHE_MODULE_NAME=	mod_auth_external.${MODULE_EXT}

.if ${PKG_APACHE} == "apache13"
DISTVERS=	2.1.19
MODULE_EXT=	so
MESSAGE_SUBST+=	MODULE_NAME=external_auth_module
.else
DISTVERS=	2.2.11
MODULE_EXT=	la
MESSAGE_SUBST+=	MODULE_NAME=auth_external_module
.endif

.include "../../www/apache/module.mk"
.include "../../mk/bsd.pkg.mk"
