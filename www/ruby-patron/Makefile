# $NetBSD: Makefile,v 1.46 2021/12/08 16:07:00 adam Exp $

DISTNAME=	patron-0.13.3
PKGREVISION=	5
CATEGORIES=	www

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://toland.github.com/patron/
COMMENT=	Ruby HTTP client library based on libcurl
LICENSE=	mit

USE_GCC_RUNTIME=	yes

.include "../../lang/ruby/gem.mk"
.include "../../www/curl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
