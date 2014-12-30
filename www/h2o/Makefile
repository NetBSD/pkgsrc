# $NetBSD: Makefile,v 1.1 2014/12/30 12:50:11 wiz Exp $

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
.include "../../mk/bsd.pkg.mk"
