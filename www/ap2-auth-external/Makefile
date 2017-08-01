# $NetBSD: Makefile,v 1.8 2017/08/01 16:49:18 wiz Exp $

DISTNAME=	mod_auth_external-${DISTVERS}
PKGREVISION=	2
PKGNAME=	${APACHE_PKG_PREFIX}-auth-external-${DISTVERS}
CATEGORIES=	www
MASTER_SITES=	http://mod-auth-external.googlecode.com/files/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/phokz/mod-auth-external
COMMENT=	Apache module for external program authentication

PKG_APACHE_ACCEPTED=	apache22

APACHE_MODULE_NAME=	mod_auth_external.${MODULE_EXT}

DISTVERS=	2.2.11
MODULE_EXT=	la
MESSAGE_SUBST+=	MODULE_NAME=auth_external_module

.include "../../mk/apache.module.mk"
.include "../../mk/bsd.pkg.mk"
