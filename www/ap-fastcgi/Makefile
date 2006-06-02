# $NetBSD: Makefile,v 1.30 2006/06/02 18:27:59 joerg Exp $
#

.include "Makefile.common"

PKGNAME=	${DISTNAME:S/mod_/ap13-/}

CONFLICTS=	ap-fastcgi-[0-9]*

APACHE_MODULE=	yes
APACHE_MODULE_NAME=	mod_fastcgi.so
APACHE_MANUAL=	htdocs/manual

.include "../../www/apache/module.mk"
.include "../../mk/bsd.pkg.mk"
