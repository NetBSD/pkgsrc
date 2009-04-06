# $NetBSD: buildlink3.mk,v 1.1.1.1 2009/04/06 10:22:12 drochner Exp $

BUILDLINK_TREE+=	xcb-proto

.if !defined(XCB_PROTO_BUILDLINK3_MK)
XCB_PROTO_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.xcb-proto?=	xcb-proto>=1.4
BUILDLINK_PKGSRCDIR.xcb-proto?=	../../x11/xcb-proto
BUILDLINK_DEPMETHOD.xcb-proto?=	build
.endif # XCB_PROTO_BUILDLINK3_MK

BUILDLINK_TREE+=	-xcb-proto
