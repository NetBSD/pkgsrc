# $NetBSD: buildlink3.mk,v 1.4 2010/09/14 19:07:00 tron Exp $

BUILDLINK_TREE+=	pixman

.if !defined(PIXMAN_BUILDLINK3_MK)
PIXMAN_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.pixman+=	pixman>=0.18.4
BUILDLINK_ABI_DEPENDS.pixman+=	pixman>=0.18.4
BUILDLINK_PKGSRCDIR.pixman?=	../../x11/pixman
.endif # PIXMAN_BUILDLINK3_MK

BUILDLINK_TREE+=	-pixman
