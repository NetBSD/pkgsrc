# $NetBSD: Makefile,v 1.10 2014/05/03 13:01:25 alnsn Exp $
#

DISTNAME=	lua-curl-0.2
PKGNAME=	${LUA_PKGPREFIX}-curl-0.2
PKGREVISION=	7
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
.include "../../lang/lua/tool.mk"
.include "../../mk/bsd.pkg.mk"
