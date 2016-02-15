# $NetBSD: Makefile,v 1.6 2016/02/15 15:11:09 mef Exp $

DISTNAME=	h2o-1.2.0
PKGREVISION=	1
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_GITHUB:=h2o/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

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
