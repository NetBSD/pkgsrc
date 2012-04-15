# $NetBSD: Makefile,v 1.15 2012/04/15 22:01:04 wiz Exp $

DISTNAME=	HTML_Select-1.3.1
CATEGORIES=	www

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	PHP class for generating HTML form select elements

PKG_DESTDIR_SUPPORT=	user-destdir

CONFLICTS=	php-pear-HTML_Select-[0-9]*

DEPENDS+=	${PHP_PKG_PREFIX}-pear-HTML_Common>=1.1:../../www/pear-HTML_Common

.include "../../lang/php/pear.mk"
.include "../../mk/bsd.pkg.mk"
