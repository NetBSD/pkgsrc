# $NetBSD: Makefile,v 1.3 2004/11/27 14:23:55 jdolecek Exp $

DISTNAME=	HTTP_Request-1.2.3
#CATEGORIES+=	www

MAINTAINER=	jdolecek@NetBSD.org
COMMENT=	PHP classes to provides an easy way to perform HTTP requests

DEPENDS+=	pear-Net_URL>=1.0.12:../../net/pear-Net_URL

# need Net_Socket 1.0.2 or later
PEAR_NETSOCKET_VERSION_REQD=	1.0.2

.include "../../net/pear-Net_Socket/buildlink3.mk"
.include "../../lang/php/pear.mk"
.include "../../mk/bsd.pkg.mk"
