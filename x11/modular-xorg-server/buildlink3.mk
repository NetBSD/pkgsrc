# $NetBSD: buildlink3.mk,v 1.21 2018/03/07 11:57:38 wiz Exp $

BUILDLINK_TREE+=	modular-xorg-server

.if !defined(MODULAR_XORG_SERVER_BUILDLINK3_MK)
MODULAR_XORG_SERVER_BUILDLINK3_MK:=

.include "../../mk/bsd.fast.prefs.mk"

USE_OLD_MODULAR_XORG_SERVER?=	no

.if !empty(USE_OLD_MODULAR_XORG_SERVER:M[yY][eE][sS])
BUILDLINK_API_DEPENDS.modular-xorg-server+=	modular-xorg-server>=1.12.4nb12<1.17
BUILDLINK_PKGSRCDIR.modular-xorg-server?=	../../x11/modular-xorg-server112
.else
BUILDLINK_API_DEPENDS.modular-xorg-server+=	modular-xorg-server>=1.18
BUILDLINK_PKGSRCDIR.modular-xorg-server?=	../../x11/modular-xorg-server
.endif

BUILDLINK_DEPMETHOD.libpciaccess=	full
.include "../../sysutils/libpciaccess/buildlink3.mk"
.include "../../x11/pixman/buildlink3.mk"

.if !empty(USE_OLD_MODULAR_XORG_SERVER:M[yY][eE][sS])
.include "../../graphics/MesaLib7/buildlink3.mk" # XXX should not be needed for non-dri build
.include "../../x11/libXfont/buildlink3.mk"
.else
.include "../../x11/libXfont2/buildlink3.mk"
.include "../../graphics/MesaLib/buildlink3.mk" # XXX should not be needed for non-dri build
.endif
.include "../../x11/xorgproto/buildlink3.mk"
.endif # MODULAR_XORG_SERVER_BUILDLINK3_MK

BUILDLINK_TREE+=	-modular-xorg-server
