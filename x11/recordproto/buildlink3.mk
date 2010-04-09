# $NetBSD: buildlink3.mk,v 1.4 2010/04/09 08:27:31 tnn Exp $

BUILDLINK_DEPMETHOD.recordproto?=	build

BUILDLINK_TREE+=	recordproto

.if !defined(RECORDPROTO_BUILDLINK3_MK)
RECORDPROTO_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.recordproto+=	recordproto>=1.14
BUILDLINK_PKGSRCDIR.recordproto?=	../../x11/recordproto
.endif # RECORDPROTO_BUILDLINK3_MK

BUILDLINK_TREE+=	-recordproto
