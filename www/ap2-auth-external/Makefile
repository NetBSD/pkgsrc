# $NetBSD: Makefile,v 1.1.1.1 2007/12/20 14:59:14 sborrill Exp $
#

DISTNAME=	mod_auth_external-${DISTVERS}
PKGREVISION=	2
PKGNAME=	${APACHE_PKG_PREFIX}-auth-external-${DISTVERS}
CATEGORIES=	www
MASTER_SITES=	http://unixpapa.com/software/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://unixpapa.com/mod_authnz_external/
COMMENT=	Apache module for external program authentication

PKG_APACHE_ACCEPTED=	apache2 apache22

.include "../../mk/apache.mk"

APACHE_MODULE_NAME=	mod_auth_external.${MODULE_EXT}

DISTVERS=	2.2.11
MODULE_EXT=	la
MESSAGE_SUBST+=	MODULE_NAME=auth_external_module

.include "../../www/apache/module.mk"
.include "../../mk/bsd.pkg.mk"
