# $NetBSD: Makefile,v 1.6 2023/11/04 15:25:50 taca Exp $
#

DISTNAME=	HTTP_Request2-2.6.0
CATEGORIES+=	www

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	PHP classes to provides an easy way to perform HTTP requests
LICENSE=	modified-bsd

DEPENDS+=	${PHP_PKG_PREFIX}-pear-Net_URL2>=2.0.0:../../net/pear-Net_URL2

USE_LANGUAGES=	# none

.include "../../lang/php/pear.mk"
.include "../../mk/bsd.pkg.mk"
