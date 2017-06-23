# $NetBSD: buildlink3.mk,v 1.5 2017/06/23 17:17:44 youri Exp $
#

BUILDLINK_TREE+=	mate-desktop

.if !defined(MATE_DESKTOP_BUILDLINK3_MK)
MATE_DESKTOP_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.mate-desktop+=	mate-desktop>=1.18.0
BUILDLINK_ABI_DEPENDS.mate-desktop+=	mate-desktop>=1.18.0
BUILDLINK_PKGSRCDIR.mate-desktop?=	../../x11/mate-desktop

.include "../../devel/dconf/buildlink3.mk"
.include "../../x11/startup-notification/buildlink3.mk"
.endif	# MATE_DESKTOP_BUILDLINK3_MK

BUILDLINK_TREE+=	-mate-desktop
