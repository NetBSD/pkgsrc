# $NetBSD: buildlink3.mk,v 1.39 2025/10/23 20:39:52 wiz Exp $

BUILDLINK_TREE+=	deforaos-panel

.if !defined(DEFORAOS_PANEL_BUILDLINK3_MK)
DEFORAOS_PANEL_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.deforaos-panel+=	deforaos-panel>=0.3.6
BUILDLINK_ABI_DEPENDS.deforaos-panel?=	deforaos-panel>=0.4.3nb15
BUILDLINK_PKGSRCDIR.deforaos-panel?=	../../x11/deforaos-panel

.include "../../x11/deforaos-libdesktop/buildlink3.mk"
.endif	# DEFORAOS_PANEL_BUILDLINK3_MK

BUILDLINK_TREE+=	-deforaos-panel
