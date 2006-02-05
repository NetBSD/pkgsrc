# $NetBSD: Makefile,v 1.29 2006/02/05 23:11:17 joerg Exp $
#

.include "Makefile.common"

PKGNAME=	${DISTNAME:S/mod_/ap-/}
PKGREVISION=	2

APACHE_MODULE=	yes
APACHE_MODULE_NAME=	mod_fastcgi.so
APACHE_MANUAL=	htdocs/manual

.include "../../www/apache/module.mk"
.include "../../mk/bsd.pkg.mk"
