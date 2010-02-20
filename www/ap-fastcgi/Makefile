# $NetBSD: Makefile,v 1.31 2010/02/20 14:58:45 joerg Exp $
#

PKG_DESTDIR_SUPPORT=	user-destdir

.include "Makefile.common"

PKGNAME=	${DISTNAME:S/mod_/ap13-/}

CONFLICTS=	ap-fastcgi-[0-9]*

APACHE_MODULE=	yes
APACHE_MODULE_NAME=	mod_fastcgi.so
APACHE_MANUAL=	htdocs/manual

.include "../../www/apache/module.mk"
.include "../../mk/bsd.pkg.mk"
