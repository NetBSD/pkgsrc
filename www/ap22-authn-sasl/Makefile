# $NetBSD: Makefile,v 1.4 2012/12/16 01:52:37 obache Exp $

DISTNAME=	mod_authn_sasl-${DISTVERS}
#PKGREVISION=	1
PKGNAME=	${APACHE_PKG_PREFIX}-authn-sasl-${DISTVERS}
PKGREVISION=	1
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=mod-authn-sasl/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://mod-authn-sasl.sourceforge.net/
COMMENT=	Apache module for SASL authentication

PKG_APACHE_ACCEPTED=	apache22

.include "../../mk/apache.mk"

APACHE_MODULE_NAME=	mod_authn_sasl.${MODULE_EXT}

DISTVERS=	1.0.2
MODULE_EXT=	la
MESSAGE_SUBST+=	MODULE_NAME=authn_sasl_module

.include "../../security/cyrus-sasl/buildlink3.mk"
.include "../../www/apache/module.mk"
.include "../../mk/bsd.pkg.mk"
