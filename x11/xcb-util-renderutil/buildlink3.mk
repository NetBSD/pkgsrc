# $NetBSD: buildlink3.mk,v 1.1 2013/04/03 07:44:45 markd Exp $

BUILDLINK_TREE+=	xcb-util-renderutil

.if !defined(XCB_UTIL_RENDERUTIL_BUILDLINK3_MK)
XCB_UTIL_RENDERUTIL_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.xcb-util-renderutil+=	xcb-util-renderutil>=0.3.8nb1
BUILDLINK_PKGSRCDIR.xcb-util-renderutil?=	../../x11/xcb-util-renderutil

#.include "../../x11/libxcb/buildlink3.mk"
.endif	# XCB_UTIL_RENDERUTIL_BUILDLINK3_MK

BUILDLINK_TREE+=	-xcb-util-renderutil
