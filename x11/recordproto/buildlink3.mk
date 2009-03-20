# $NetBSD: buildlink3.mk,v 1.3 2009/03/20 19:25:50 joerg Exp $

BUILDLINK_DEPMETHOD.recordproto?=	build

BUILDLINK_TREE+=	recordproto

.if !defined(RECORDPROTO_BUILDLINK3_MK)
RECORDPROTO_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.recordproto+=	recordproto>=1.13.1
BUILDLINK_PKGSRCDIR.recordproto?=	../../x11/recordproto
.endif # RECORDPROTO_BUILDLINK3_MK

BUILDLINK_TREE+=	-recordproto
