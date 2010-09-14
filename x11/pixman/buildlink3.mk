# $NetBSD: buildlink3.mk,v 1.3 2010/09/14 11:03:10 wiz Exp $

BUILDLINK_TREE+=	pixman

.if !defined(PIXMAN_BUILDLINK3_MK)
PIXMAN_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.pixman+=	pixman>=0.9.6
BUILDLINK_ABI_DEPENDS.pixman+=	pixman>=0.18.4
BUILDLINK_PKGSRCDIR.pixman?=	../../x11/pixman
.endif # PIXMAN_BUILDLINK3_MK

BUILDLINK_TREE+=	-pixman
