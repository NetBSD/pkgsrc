# $NetBSD: buildlink3.mk,v 1.28 2023/01/29 21:15:05 ryoon Exp $

BUILDLINK_TREE+=	deforaos-panel

.if !defined(DEFORAOS_PANEL_BUILDLINK3_MK)
DEFORAOS_PANEL_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.deforaos-panel+=	deforaos-panel>=0.3.6
BUILDLINK_ABI_DEPENDS.deforaos-panel?=	deforaos-panel>=0.4.3nb4
BUILDLINK_PKGSRCDIR.deforaos-panel?=	../../x11/deforaos-panel

.include "../../x11/deforaos-libdesktop/buildlink3.mk"
.endif	# DEFORAOS_PANEL_BUILDLINK3_MK

BUILDLINK_TREE+=	-deforaos-panel
