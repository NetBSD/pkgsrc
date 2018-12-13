# $NetBSD: Makefile,v 1.34 2018/12/13 19:52:26 adam Exp $

DISTNAME=	patron-0.13.1
PKGREVISION=	2
CATEGORIES=	www

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://toland.github.com/patron/
COMMENT=	Ruby HTTP client library based on libcurl
LICENSE=	mit

USE_GCC_RUNTIME=	yes

.include "../../lang/ruby/gem.mk"
.include "../../www/curl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
