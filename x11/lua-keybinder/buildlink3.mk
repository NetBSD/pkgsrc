# $NetBSD: buildlink3.mk,v 1.10 2020/03/08 16:48:27 wiz Exp $

BUILDLINK_TREE+=	lua-keybinder

.if !defined(LUA_KEYBINDER_BUILDLINK3_MK)
LUA_KEYBINDER_BUILDLINK3_MK:=

.include "../../lang/lua/luaversion.mk"

BUILDLINK_API_DEPENDS.lua-keybinder+=	${LUA_PKGPREFIX}-keybinder>=0.3.0
BUILDLINK_ABI_DEPENDS.lua-keybinder?=	lua51-keybinder>=0.3.0nb9
BUILDLINK_PKGSRCDIR.lua-keybinder?=	../../x11/lua-keybinder

.include "../../x11/keybinder/buildlink3.mk"
.endif	# LUA_KEYBINDER_BUILDLINK3_MK

BUILDLINK_TREE+=	-lua-keybinder
