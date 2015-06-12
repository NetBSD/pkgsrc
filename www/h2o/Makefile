# $NetBSD: Makefile,v 1.5 2015/06/12 10:51:49 wiz Exp $

DISTNAME=	h2o-1.2.0
PKGREVISION=	1
CATEGORIES=	www
MASTER_SITES=	-https://github.com/h2o/h2o/archive/v1.2.0${EXTRACT_SUFX}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://github.com/h2o/h2o
COMMENT=	Optimized HTTP server with support for HTTP/1.x and HTTP/2
LICENSE=	mit

USE_CMAKE=	yes
USE_LANGUAGES=	c c++

USE_TOOLS+=	perl:run

EXTRACT_USING=	gtar
REPLACE_PERL=	share/h2o/start_server

.include "../../textproc/libyaml/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
