# $NetBSD: Makefile,v 1.8 2006/10/23 20:13:38 jdolecek Exp $

DISTNAME=	HTTP_Request-1.3.0
#CATEGORIES+=	www

MAINTAINER=	jdolecek@NetBSD.org
COMMENT=	PHP classes to provides an easy way to perform HTTP requests

CONFLICTS=	php-pear-HTTP_Request-[0-9]*

DEPENDS+=	${PHP_PKG_PREFIX}-pear-Net_URL>=1.0.12:../../net/pear-Net_URL
DEPENDS+=	${PHP_PKG_PREFIX}-pear-Net_Socket>=1.0.2:../../net/pear-Net_Socket

.include "../../lang/php/pear.mk"
.include "../../mk/bsd.pkg.mk"
