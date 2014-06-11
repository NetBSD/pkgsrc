# $NetBSD: Makefile,v 1.7 2014/06/11 12:57:23 joerg Exp $

DISTNAME=	mod_authn_otp-${DISTVERS}
PKGNAME=	${APACHE_PKG_PREFIX}-authn-otp-${DISTVERS}
PKGREVISION=	2
CATEGORIES=	www
MASTER_SITES=	http://mod-authn-otp.googlecode.com/files/
LICENSE=	apache-2.0

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://mod-authn-otp.googlecode.com/
COMMENT=	Apache module for one-time password authentication

PKG_APACHE_ACCEPTED=	apache22

APACHE_MODULE_NAME=	mod_authn_otp.${MODULE_EXT}

DISTVERS=	1.1.4
MODULE_EXT=	la
MESSAGE_SUBST+=	MODULE_NAME=authn_otp_module

.include "../../mk/apache.module.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
