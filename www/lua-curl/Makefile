# $NetBSD: Makefile,v 1.5 2013/02/06 23:24:02 jperkin Exp $
#

DISTNAME=	lua-curl-0.2
PKGREVISION=	3
CATEGORIES=	www
MASTER_SITES=	http://luaforge.net/frs/download.php/2634/

MAINTAINER=	agc@NetBSD.org
HOMEPAGE=	http://lua-curl.luaforge.net/
COMMENT=	Full lua bindings for libcurl
LICENSE=	mit

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_LANGUAGES+=	c c++
USE_TOOLS+=	pkg-config

AUTO_MKDIRS=	yes

.include "../../www/curl/buildlink3.mk"
.include "../../lang/lua/module.mk"

.include "../../mk/bsd.pkg.mk"
