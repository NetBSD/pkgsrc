# $NetBSD: Makefile,v 1.14 2012/03/07 14:50:57 taca Exp $

DISTNAME=	HTML_Select-1.3.1
CATEGORIES=	www

MAINTAINER=	jdolecek@NetBSD.org
COMMENT=	PHP class for generating HTML form select elements

PKG_DESTDIR_SUPPORT=	user-destdir

CONFLICTS=	php-pear-HTML_Select-[0-9]*

DEPENDS+=	${PHP_PKG_PREFIX}-pear-HTML_Common>=1.1:../../www/pear-HTML_Common

.include "../../lang/php/pear.mk"
.include "../../mk/bsd.pkg.mk"
