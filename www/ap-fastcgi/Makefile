# $NetBSD: Makefile,v 1.27 2004/10/28 21:01:50 cube Exp $
#

.include "Makefile.common"

PKGNAME=	${DISTNAME:S/mod_/ap-/}

APACHE_MODULE=	yes
APACHE_MODULE_NAME=	mod_fastcgi.so
APACHE_MANUAL=	htdocs/manual

.include "../../www/apache/module.mk"
.include "../../mk/bsd.pkg.mk"
