# $NetBSD: buildlink3.mk,v 1.7 2026/09/29 06:08:28 wiz Exp $
#

BUILDLINK_TREE+=	mate-menus

.if !defined(MATE_MENUS_BUILDLINK3_MK)
MATE_MENUS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.mate-menus+=	mate-menus>=1.8.0
BUILDLINK_ABI_DEPENDS.mate-menus?=	mate-menus>=1.26.1nb17
BUILDLINK_PKGSRCDIR.mate-menus?=	../../x11/mate-menus

.include "../../devel/glib2/buildlink3.mk"
.endif	# MATE_MENUS_BUILDLINK3_MK

BUILDLINK_TREE+=	-mate-menus
