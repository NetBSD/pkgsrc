# $NetBSD: buildlink3.mk,v 1.62 2018/04/16 14:33:59 wiz Exp $

BUILDLINK_TREE+=	gnome-sharp

.if !defined(GNOME_SHARP_BUILDLINK3_MK)
GNOME_SHARP_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.gnome-sharp+=	gnome-sharp>=2.24.0
BUILDLINK_ABI_DEPENDS.gnome-sharp+=	gnome-sharp>=2.24.2nb51
BUILDLINK_PKGSRCDIR.gnome-sharp?=	../../x11/gnome-sharp

.include "../../devel/libgnomeui/buildlink3.mk"
.include "../../graphics/libart/buildlink3.mk"
.include "../../graphics/libgnomecanvas/buildlink3.mk"
.include "../../lang/mono/buildlink3.mk"
.include "../../sysutils/gnome-vfs/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../x11/gtk-sharp/buildlink3.mk"
.endif # GNOME_SHARP_BUILDLINK3_MK

BUILDLINK_TREE+=	-gnome-sharp
