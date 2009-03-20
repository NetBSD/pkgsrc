# $NetBSD: buildlink3.mk,v 1.2 2009/03/20 19:25:52 joerg Exp $

BUILDLINK_DEPMETHOD.xcmiscproto?=	build

BUILDLINK_TREE+=	xcmiscproto

.if !defined(XCMISCPROTO_BUILDLINK3_MK)
XCMISCPROTO_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.xcmiscproto+=	xcmiscproto>=1.1
BUILDLINK_PKGSRCDIR.xcmiscproto?=	../../x11/xcmiscproto
.endif # XCMISCPROTO_BUILDLINK3_MK

BUILDLINK_TREE+=	-xcmiscproto
