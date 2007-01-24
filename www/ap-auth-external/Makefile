# $NetBSD: Makefile,v 1.2 2007/01/24 15:06:57 sborrill Exp $
#

DISTNAME=	mod_auth_external-${DISTVERS}
PKGREVISION=	1
PKGNAME=	${APACHE_PKG_PREFIX}-auth-external-${DISTVERS}
CATEGORIES=	www
MASTER_SITES=	http://unixpapa.com/software/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://unixpapa.com/mod_authnz_external/
COMMENT=	Apache module for external program authentication

PKG_APACHE_ACCEPTED=	apache13 apache2

.include "../../mk/apache.mk"

APACHE_MODULE_NAME=	mod_auth_external.so

.if ${PKG_APACHE} == "apache13"
DISTVERS=	2.1.19
.else
DISTVERS=	2.2.11
.endif

.include "../../www/apache/module.mk"
.include "../../mk/bsd.pkg.mk"
