# $NetBSD: Makefile,v 1.1.1.1 2003/02/18 00:23:00 grant Exp $
#

DISTNAME=	mod_auth_script-alpha1.3
PKGNAME=	ap-auth-script-1.3
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=mod-auth-script/}

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://mod-auth-script.sourceforge.net/
COMMENT=	Apache module for script-based authentication

USE_BUILDLINK2=	YES

APACHE_MODULE_NAME=	mod_auth_script.so

.include "../../www/apache/module.mk"
.include "../../mk/bsd.pkg.mk"
