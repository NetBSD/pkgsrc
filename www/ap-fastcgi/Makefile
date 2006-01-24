# $NetBSD: Makefile,v 1.28 2006/01/24 07:32:42 wiz Exp $
#

.include "Makefile.common"

PKGNAME=	${DISTNAME:S/mod_/ap-/}
PKGREVISION=	1

APACHE_MODULE=	yes
APACHE_MODULE_NAME=	mod_fastcgi.so
APACHE_MANUAL=	htdocs/manual

.include "../../www/apache/module.mk"
.include "../../mk/bsd.pkg.mk"
