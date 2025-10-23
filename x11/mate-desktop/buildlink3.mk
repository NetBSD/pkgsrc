# $NetBSD: buildlink3.mk,v 1.9 2025/10/23 20:40:08 wiz Exp $
#

BUILDLINK_TREE+=	mate-desktop

.if !defined(MATE_DESKTOP_BUILDLINK3_MK)
MATE_DESKTOP_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.mate-desktop+=	mate-desktop>=1.24
BUILDLINK_ABI_DEPENDS.mate-desktop+=	mate-desktop>=1.26.2nb11
BUILDLINK_PKGSRCDIR.mate-desktop?=	../../x11/mate-desktop

.include "../../devel/dconf/buildlink3.mk"
.include "../../x11/startup-notification/buildlink3.mk"
.endif	# MATE_DESKTOP_BUILDLINK3_MK

BUILDLINK_TREE+=	-mate-desktop
