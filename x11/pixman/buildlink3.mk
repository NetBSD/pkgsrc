# $NetBSD: buildlink3.mk,v 1.2 2009/03/20 19:25:48 joerg Exp $

BUILDLINK_TREE+=	pixman

.if !defined(PIXMAN_BUILDLINK3_MK)
PIXMAN_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.pixman+=	pixman>=0.9.6
BUILDLINK_PKGSRCDIR.pixman?=	../../x11/pixman
.endif # PIXMAN_BUILDLINK3_MK

BUILDLINK_TREE+=	-pixman
