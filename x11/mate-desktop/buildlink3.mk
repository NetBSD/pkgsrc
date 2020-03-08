# $NetBSD: buildlink3.mk,v 1.6 2020/03/08 16:48:27 wiz Exp $
#

BUILDLINK_TREE+=	mate-desktop

.if !defined(MATE_DESKTOP_BUILDLINK3_MK)
MATE_DESKTOP_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.mate-desktop+=	mate-desktop>=1.18.0
BUILDLINK_ABI_DEPENDS.mate-desktop+=	mate-desktop>=1.22.2nb1
BUILDLINK_PKGSRCDIR.mate-desktop?=	../../x11/mate-desktop

.include "../../devel/dconf/buildlink3.mk"
.include "../../x11/startup-notification/buildlink3.mk"
.endif	# MATE_DESKTOP_BUILDLINK3_MK

BUILDLINK_TREE+=	-mate-desktop
