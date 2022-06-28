# $NetBSD: buildlink3.mk,v 1.6 2022/06/28 11:37:57 wiz Exp $

BUILDLINK_TREE+=	pixman

.if !defined(PIXMAN_BUILDLINK3_MK)
PIXMAN_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.pixman+=	pixman>=0.25.2
BUILDLINK_ABI_DEPENDS.pixman+=	pixman>=0.40.0nb3
BUILDLINK_PKGSRCDIR.pixman?=	../../x11/pixman
.endif # PIXMAN_BUILDLINK3_MK

BUILDLINK_TREE+=	-pixman
