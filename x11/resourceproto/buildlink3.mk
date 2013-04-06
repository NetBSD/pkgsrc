# $NetBSD: buildlink3.mk,v 1.3 2013/04/06 13:46:35 rodent Exp $

BUILDLINK_TREE+=	resourceproto

.if !defined(RESOURCEPROTO_BUILDLINK3_MK)
RESOURCEPROTO_BUILDLINK3_MK:=

BUILDLINK_DEPMETHOD.resourceproto?=	build

BUILDLINK_API_DEPENDS.resourceproto+=	resourceproto>=1.0.1
BUILDLINK_PKGSRCDIR.resourceproto?=	../../x11/resourceproto
.endif # RESOURCEPROTO_BUILDLINK3_MK

BUILDLINK_TREE+=	-resourceproto
