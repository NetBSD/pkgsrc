# $NetBSD: buildlink3.mk,v 1.28 2023/11/12 13:24:19 wiz Exp $

BUILDLINK_TREE+=	modular-xorg-server

.if !defined(MODULAR_XORG_SERVER_BUILDLINK3_MK)
MODULAR_XORG_SERVER_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.modular-xorg-server+=	modular-xorg-server>=21.1.4nb1
BUILDLINK_ABI_DEPENDS.modular-xorg-server?=	modular-xorg-server>=21.1.9nb1
BUILDLINK_PKGSRCDIR.modular-xorg-server?=	../../x11/modular-xorg-server
BUILDLINK_INCDIRS.modular-xorg-server+=		include/xorg

.include "../../mk/bsd.fast.prefs.mk"

pkgbase := modular-xorg-server
.include "../../mk/pkg-build-options.mk"

.include "../../sysutils/libpciaccess/buildlink3.mk"
.include "../../x11/pixman/buildlink3.mk"

.include "../../x11/xorgproto/buildlink3.mk"
.include "../../x11/libxcvt/buildlink3.mk"
.include "../../x11/libXfont2/buildlink3.mk"
.if ${PKG_BUILD_OPTIONS.modular-xorg-server:Mdri}
.include "../../graphics/MesaLib/buildlink3.mk"
.endif
.endif # MODULAR_XORG_SERVER_BUILDLINK3_MK

BUILDLINK_TREE+=	-modular-xorg-server
