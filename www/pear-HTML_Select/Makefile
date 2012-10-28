# $NetBSD: Makefile,v 1.16 2012/10/28 06:30:56 asau Exp $

DISTNAME=	HTML_Select-1.3.1
CATEGORIES=	www

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	PHP class for generating HTML form select elements

CONFLICTS=	php-pear-HTML_Select-[0-9]*

DEPENDS+=	${PHP_PKG_PREFIX}-pear-HTML_Common>=1.1:../../www/pear-HTML_Common

.include "../../lang/php/pear.mk"
.include "../../mk/bsd.pkg.mk"
