# $NetBSD: Makefile,v 1.2 2004/11/27 10:02:52 jdolecek Exp $

DISTNAME=	HTTP_Request-1.2
#CATEGORIES+=	www

MAINTAINER=	jdolecek@NetBSD.org
COMMENT=	PHP classes to provides an easy way to perform HTTP requests

DEPENDS+=	pear-Net_URL>=1.0:../../net/pear-Net_URL

.include "../../net/pear-Net_Socket/buildlink3.mk"
.include "../../lang/php/pear.mk"
.include "../../mk/bsd.pkg.mk"
