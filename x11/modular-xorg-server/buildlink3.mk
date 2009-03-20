# $NetBSD: buildlink3.mk,v 1.6 2009/03/20 19:25:47 joerg Exp $

BUILDLINK_TREE+=	modular-xorg-server

.if !defined(MODULAR_XORG_SERVER_BUILDLINK3_MK)
MODULAR_XORG_SERVER_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.modular-xorg-server+=	modular-xorg-server>=1.4.2
BUILDLINK_PKGSRCDIR.modular-xorg-server?=	../../x11/modular-xorg-server

.include "../../x11/pixman/buildlink3.mk"

.include "../../x11/compositeproto/buildlink3.mk"
.include "../../x11/fontsproto/buildlink3.mk"
.include "../../x11/inputproto/buildlink3.mk"
.include "../../x11/randrproto/buildlink3.mk"
.include "../../x11/renderproto/buildlink3.mk"
.include "../../x11/videoproto/buildlink3.mk"
.include "../../x11/xextproto/buildlink3.mk"
.include "../../x11/xf86driproto/buildlink3.mk"
.include "../../x11/xproto/buildlink3.mk"
.endif # MODULAR_XORG_SERVER_BUILDLINK3_MK

BUILDLINK_TREE+=	-modular-xorg-server
