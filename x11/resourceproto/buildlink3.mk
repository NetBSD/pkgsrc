# $NetBSD: buildlink3.mk,v 1.2 2009/03/20 19:25:50 joerg Exp $

BUILDLINK_DEPMETHOD.resourceproto?=	build

BUILDLINK_TREE+=	resourceproto

.if !defined(RESOURCEPROTO_BUILDLINK3_MK)
RESOURCEPROTO_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.resourceproto+=	resourceproto>=1.0.1
BUILDLINK_PKGSRCDIR.resourceproto?=	../../x11/resourceproto
.endif # RESOURCEPROTO_BUILDLINK3_MK

BUILDLINK_TREE+=	-resourceproto
