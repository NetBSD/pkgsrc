# $NetBSD: buildlink3.mk,v 1.44 2024/11/14 22:22:14 wiz Exp $

BUILDLINK_TREE+=	gnustep-gui

.if !defined(GNUSTEP_GUI_BUILDLINK3_MK)
GNUSTEP_GUI_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.gnustep-gui+=	gnustep-gui>=0.28
BUILDLINK_ABI_DEPENDS.gnustep-gui+=	gnustep-gui>=0.30.0nb9
BUILDLINK_PKGSRCDIR.gnustep-gui?=	../../x11/gnustep-gui

.include "../../devel/gnustep-base/buildlink3.mk"
.endif # GNUSTEP_GUI_BUILDLINK3_MK

BUILDLINK_TREE+=	-gnustep-gui
