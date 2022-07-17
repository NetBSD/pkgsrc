# $NetBSD: buildlink3.mk,v 1.25 2022/07/17 02:29:41 tnn Exp $

BUILDLINK_TREE+=	modular-xorg-server

.if !defined(MODULAR_XORG_SERVER_BUILDLINK3_MK)
MODULAR_XORG_SERVER_BUILDLINK3_MK:=

.include "../../mk/bsd.fast.prefs.mk"

BUILDLINK_API_DEPENDS.modular-xorg-server+=	modular-xorg-server>=21.1.4nb1
BUILDLINK_PKGSRCDIR.modular-xorg-server?=	../../x11/modular-xorg-server
BUILDLINK_INCDIRS.modular-xorg-server+=		include/xorg

BUILDLINK_DEPMETHOD.libpciaccess=	full
.include "../../sysutils/libpciaccess/buildlink3.mk"
.include "../../x11/pixman/buildlink3.mk"

.include "../../x11/xorgproto/buildlink3.mk"
.include "../../x11/libxcvt/buildlink3.mk"
.include "../../x11/libXfont2/buildlink3.mk"
.include "../../graphics/MesaLib/buildlink3.mk" # XXX should not be needed for non-dri build
.endif # MODULAR_XORG_SERVER_BUILDLINK3_MK

BUILDLINK_TREE+=	-modular-xorg-server
