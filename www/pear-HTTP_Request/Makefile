# $NetBSD: Makefile,v 1.11 2010/02/06 16:08:48 taca Exp $

DISTNAME=	HTTP_Request-1.4.4
#CATEGORIES+=	www

MAINTAINER=	jdolecek@NetBSD.org
COMMENT=	PHP classes to provides an easy way to perform HTTP requests

PKG_DESTDIR_SUPPORT=	user-destdir

CONFLICTS=	php-pear-HTTP_Request-[0-9]*

DEPENDS+=	${PHP_PKG_PREFIX}-pear-Net_URL>=1.0.12:../../net/pear-Net_URL
DEPENDS+=	${PHP_PKG_PREFIX}-pear-Net_Socket>=1.0.7:../../net/pear-Net_Socket

.include "../../lang/php/pear.mk"
.include "../../mk/bsd.pkg.mk"
