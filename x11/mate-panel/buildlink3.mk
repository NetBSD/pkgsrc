# $NetBSD: buildlink3.mk,v 1.5 2017/06/23 17:24:57 youri Exp $
#

BUILDLINK_TREE+=	mate-panel

.if !defined(MATE_PANEL_BUILDLINK3_MK)
MATE_PANEL_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.mate-panel+=	mate-panel>=1.8.1
BUILDLINK_ABI_DEPENDS.mate-panel+=	mate-panel>=1.14.1nb5
BUILDLINK_PKGSRCDIR.mate-panel?=	../../x11/mate-panel

.endif	# MATE_PANEL_BUILDLINK3_MK

BUILDLINK_TREE+=	-mate-panel
