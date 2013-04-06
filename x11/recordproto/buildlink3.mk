# $NetBSD: buildlink3.mk,v 1.6 2013/04/06 13:46:35 rodent Exp $

BUILDLINK_TREE+=	recordproto

.if !defined(RECORDPROTO_BUILDLINK3_MK)
RECORDPROTO_BUILDLINK3_MK:=

BUILDLINK_DEPMETHOD.recordproto?=	build

BUILDLINK_API_DEPENDS.recordproto+=	recordproto>=1.13.1
BUILDLINK_PKGSRCDIR.recordproto?=	../../x11/recordproto
.endif # RECORDPROTO_BUILDLINK3_MK

BUILDLINK_TREE+=	-recordproto
