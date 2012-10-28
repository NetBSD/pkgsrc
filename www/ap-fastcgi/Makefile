# $NetBSD: Makefile,v 1.32 2012/10/28 06:30:04 asau Exp $
#

.include "Makefile.common"

PKGNAME=	${DISTNAME:S/mod_/ap13-/}

CONFLICTS=	ap-fastcgi-[0-9]*

APACHE_MODULE=	yes
APACHE_MODULE_NAME=	mod_fastcgi.so
APACHE_MANUAL=	htdocs/manual

.include "../../www/apache/module.mk"
.include "../../mk/bsd.pkg.mk"
