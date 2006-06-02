# $NetBSD: Makefile,v 1.9 2006/06/02 18:27:59 joerg Exp $
#

DISTNAME=	mod_auth_script-alpha1.3
PKGNAME=	ap13-auth-script-1.3
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=mod-auth-script/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://mod-auth-script.sourceforge.net/
COMMENT=	Apache module for script-based authentication

CONFLICTS=	ap-auth-script-[0-9]*

APACHE_MODULE_NAME=	mod_auth_script.so

.include "../../www/apache/module.mk"
.include "../../mk/bsd.pkg.mk"
