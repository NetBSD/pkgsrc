# $NetBSD: Makefile,v 1.2 2015/01/18 15:56:07 wiedi Exp $

DISTNAME=	h2o-0.9.0
CATEGORIES=	www
MASTER_SITES=	-https://github.com/h2o/h2o/archive/v0.9.0${EXTRACT_SUFX}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://github.com/h2o/h2o
COMMENT=	Optimized HTTP server with support for HTTP/1.x and HTTP/2
LICENSE=	mit

USE_CMAKE=	yes
USE_LANGUAGES=	c c++

.include "../../textproc/libyaml/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
