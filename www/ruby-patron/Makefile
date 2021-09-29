# $NetBSD: Makefile,v 1.45 2021/09/29 19:01:29 adam Exp $

DISTNAME=	patron-0.13.3
PKGREVISION=	4
CATEGORIES=	www

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://toland.github.com/patron/
COMMENT=	Ruby HTTP client library based on libcurl
LICENSE=	mit

USE_GCC_RUNTIME=	yes

.include "../../lang/ruby/gem.mk"
.include "../../www/curl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
