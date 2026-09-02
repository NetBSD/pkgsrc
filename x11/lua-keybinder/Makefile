# $NetBSD: Makefile,v 1.31 2026/09/02 19:05:17 wiz Exp $

PKGREVISION= 28
.include "../../x11/keybinder/Makefile.common"

PKGNAME=	${LUA_PKGPREFIX}-${DISTNAME}
CATEGORIES=	x11 lua

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Lua bindings for the keybinder library
LICENSE=	gnu-gpl-v2

TOOL_DEPENDS+=	glib2-introspection-[0-9]*:../../devel/glib2-introspection

# --enable-lua is broken
CONFIGURE_ARGS+=	--disable-python

INSTALL_DIRS=	lua-keybinder

LUA_VERSIONS_ACCEPTED=	51

BUILDLINK_DEPMETHOD.gobject-introspection=	build
.include "../../devel/gobject-introspection/buildlink3.mk"
.include "../../x11/keybinder/buildlink3.mk"
.include "../../lang/lua/luaversion.mk"
.include "../../lang/lua/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
