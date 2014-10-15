# $NetBSD: Makefile,v 1.2 2014/10/15 21:28:01 joerg Exp $
#

DISTNAME=	HTTP_Request2-2.2.1
CATEGORIES+=	www

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	PHP classes to provides an easy way to perform HTTP requests
LICENSE=	modified-bsd

DEPENDS+=	${PHP_PKG_PREFIX}-pear-Net_URL2>=2.0.0:../../net/pear-Net_URL2

USE_LANGUAGES=	# none

.include "../../lang/php/pear.mk"
.include "../../mk/bsd.pkg.mk"
