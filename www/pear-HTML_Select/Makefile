# $NetBSD: Makefile,v 1.12 2010/02/04 16:36:05 joerg Exp $

DISTNAME=	HTML_Select-1.2.1
PKGREVISION=	1
CATEGORIES=	www

MAINTAINER=	jdolecek@NetBSD.org
COMMENT=	PHP class for generating HTML form select elements

PKG_DESTDIR_SUPPORT=	user-destdir

CONFLICTS=	php-pear-HTML_Select-[0-9]*

DEPENDS+=	${PHP_PKG_PREFIX}-pear-HTML_Common>=1.1:../../www/pear-HTML_Common

.include "../../lang/php/pear.mk"
.include "../../mk/bsd.pkg.mk"
