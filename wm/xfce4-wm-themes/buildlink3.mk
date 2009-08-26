# $NetBSD: buildlink3.mk,v 1.23 2009/08/26 19:57:03 sno Exp $

BUILDLINK_TREE+=	xfce4-wm-themes

.if !defined(XFCE4_WM_THEMES_BUILDLINK3_MK)
XFCE4_WM_THEMES_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.xfce4-wm-themes+=	xfce4-wm-themes>=4.4.3nb1
BUILDLINK_ABI_DEPENDS.xfce4-wm-themes?=	xfce4-wm-themes>=4.4.3nb2
BUILDLINK_PKGSRCDIR.xfce4-wm-themes?=	../../wm/xfce4-wm-themes

.include "../../wm/xfce4-wm/buildlink3.mk"
.include "../../devel/xfce4-dev-tools/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.endif # XFCE4_WM_THEMES_BUILDLINK3_MK

BUILDLINK_TREE+=	-xfce4-wm-themes
