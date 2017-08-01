# $NetBSD: Makefile,v 1.10 2017/08/01 17:40:17 wiz Exp $

DISTNAME=	mod_authn_otp-${DISTVERS}
PKGNAME=	${APACHE_PKG_PREFIX}-authn-otp-${DISTVERS}
PKGREVISION=	3
CATEGORIES=	www
#MASTER_SITES=	http://mod-authn-otp.googlecode.com/files/
LICENSE=	apache-2.0

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/archiecobbs/mod-authn-otp
COMMENT=	Apache module for one-time password authentication

PKG_APACHE_ACCEPTED=	apache22

APACHE_MODULE_NAME=	mod_authn_otp.${MODULE_EXT}

DISTVERS=	1.1.4
MODULE_EXT=	la
MESSAGE_SUBST+=	MODULE_NAME=authn_otp_module

.include "../../mk/apache.module.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
