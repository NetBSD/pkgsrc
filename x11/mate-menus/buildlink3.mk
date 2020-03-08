# $NetBSD: buildlink3.mk,v 1.2 2020/03/08 16:48:27 wiz Exp $
#

BUILDLINK_TREE+=	mate-menus

.if !defined(MATE_MENUS_BUILDLINK3_MK)
MATE_MENUS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.mate-menus+=	mate-menus>=1.8.0
BUILDLINK_ABI_DEPENDS.mate-menus?=	mate-menus>=1.22.1nb1
BUILDLINK_PKGSRCDIR.mate-menus?=	../../x11/mate-menus

.include "../../devel/glib2/buildlink3.mk"
.endif	# MATE_MENUS_BUILDLINK3_MK

BUILDLINK_TREE+=	-mate-menus
