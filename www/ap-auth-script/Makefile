# $NetBSD: Makefile,v 1.2 2003/06/02 01:16:10 jschauma Exp $
#

DISTNAME=	mod_auth_script-alpha1.3
PKGNAME=	ap-auth-script-1.3
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=mod-auth-script/}

MAINTAINER=	tech-pkg@netbsd.org
HOMEPAGE=	http://mod-auth-script.sourceforge.net/
COMMENT=	Apache module for script-based authentication

USE_BUILDLINK2=	YES

APACHE_MODULE_NAME=	mod_auth_script.so

.include "../../www/apache/module.mk"
.include "../../mk/bsd.pkg.mk"
