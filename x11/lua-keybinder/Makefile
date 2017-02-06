# $NetBSD: Makefile,v 1.3 2017/02/06 13:54:56 wiz Exp $

PKGREVISION= 2
.include "../../x11/keybinder/Makefile.common"

PKGNAME=	${LUA_PKGPREFIX}-${DISTNAME}
CATEGORIES=	x11

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Lua bindings for the keybinder library
LICENSE=	gnu-gpl-v2

# --enable-lua is broken
CONFIGURE_ARGS+=	--disable-python

INSTALL_DIRS=	lua-keybinder

LUA_VERSIONS_ACCEPTED=	51

.include "../../x11/keybinder/buildlink3.mk"
.include "../../lang/lua/luaversion.mk"
.include "../../lang/lua/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
