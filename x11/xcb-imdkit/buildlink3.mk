# $NetBSD: buildlink3.mk,v 1.1 2021/02/15 15:05:55 ryoon Exp $

BUILDLINK_TREE+=	xcb-imdkit

.if !defined(XCB_IMDKIT_BUILDLINK3_MK)
XCB_IMDKIT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.xcb-imdkit+=	xcb-imdkit>=1.0.2
BUILDLINK_PKGSRCDIR.xcb-imdkit?=	../../x11/xcb-imdkit

.include "../../x11/libxcb/buildlink3.mk"
.include "../../x11/xcb-util/buildlink3.mk"
.endif	# XCB_IMDKIT_BUILDLINK3_MK

BUILDLINK_TREE+=	-xcb-imdkit
