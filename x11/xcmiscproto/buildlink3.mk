# $NetBSD: buildlink3.mk,v 1.3 2013/04/06 13:46:35 rodent Exp $

BUILDLINK_TREE+=	xcmiscproto

.if !defined(XCMISCPROTO_BUILDLINK3_MK)
XCMISCPROTO_BUILDLINK3_MK:=

BUILDLINK_DEPMETHOD.xcmiscproto?=	build

BUILDLINK_API_DEPENDS.xcmiscproto+=	xcmiscproto>=1.1
BUILDLINK_PKGSRCDIR.xcmiscproto?=	../../x11/xcmiscproto
.endif # XCMISCPROTO_BUILDLINK3_MK

BUILDLINK_TREE+=	-xcmiscproto
