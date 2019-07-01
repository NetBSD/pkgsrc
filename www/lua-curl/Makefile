# $NetBSD: Makefile,v 1.23 2019/07/01 04:08:52 ryoon Exp $

DISTNAME=	lua-curl-0.2
PKGNAME=	${LUA_PKGPREFIX}-curl-0.2
PKGREVISION=	18
CATEGORIES=	www
MASTER_SITES=	http://luaforge.net/frs/download.php/2634/

MAINTAINER=	agc@NetBSD.org
#HOMEPAGE=	http://lua-curl.luaforge.net/
COMMENT=	Full lua bindings for libcurl
LICENSE=	mit

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_LANGUAGES+=	c c++
USE_TOOLS+=	pkg-config

AUTO_MKDIRS=	yes

.include "../../www/curl/buildlink3.mk"
.include "../../lang/lua/buildlink3.mk"
.include "../../lang/lua/module.mk"
.include "../../lang/lua/tool.mk"
.include "../../mk/bsd.pkg.mk"
