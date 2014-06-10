# $NetBSD: Makefile,v 1.6 2014/06/10 15:22:16 joerg Exp $
#

DISTNAME=	mod_auth_external-${DISTVERS}
PKGREVISION=	2
PKGNAME=	${APACHE_PKG_PREFIX}-auth-external-${DISTVERS}
CATEGORIES=	www
MASTER_SITES=	http://mod-auth-external.googlecode.com/files/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://code.google.com/p/mod-auth-external/
COMMENT=	Apache module for external program authentication

PKG_APACHE_ACCEPTED=	apache22

.include "../../mk/apache.mk"

APACHE_MODULE_NAME=	mod_auth_external.${MODULE_EXT}

DISTVERS=	2.2.11
MODULE_EXT=	la
MESSAGE_SUBST+=	MODULE_NAME=auth_external_module

.include "../../www/apache/module.mk"
.include "../../mk/bsd.pkg.mk"
