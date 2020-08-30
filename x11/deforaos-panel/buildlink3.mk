# $NetBSD: buildlink3.mk,v 1.24 2020/08/30 22:06:22 khorben Exp $

BUILDLINK_TREE+=	deforaos-panel

.if !defined(DEFORAOS_PANEL_BUILDLINK3_MK)
DEFORAOS_PANEL_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.deforaos-panel+=	deforaos-panel>=0.3.6
BUILDLINK_ABI_DEPENDS.deforaos-panel?=	deforaos-panel>=0.4.0nb3
BUILDLINK_PKGSRCDIR.deforaos-panel?=	../../x11/deforaos-panel

.include "../../x11/deforaos-libdesktop/buildlink3.mk"
.endif	# DEFORAOS_PANEL_BUILDLINK3_MK

BUILDLINK_TREE+=	-deforaos-panel
