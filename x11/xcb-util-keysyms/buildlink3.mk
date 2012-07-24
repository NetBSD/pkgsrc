# $NetBSD: buildlink3.mk,v 1.1 2012/07/24 18:02:07 drochner Exp $

BUILDLINK_TREE+=	xcb-util-keysyms

.if !defined(XCB_UTIL_KEYSYMS_BUILDLINK3_MK)
XCB_UTIL_KEYSYMS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.xcb-util-keysyms+=	xcb-util-keysyms>=0.3.9
BUILDLINK_PKGSRCDIR.xcb-util-keysyms?=	../../x11/xcb-util-keysyms

.include "../../x11/libxcb/buildlink3.mk"
.endif	# XCB_UTIL_KEYSYMS_BUILDLINK3_MK

BUILDLINK_TREE+=	-xcb-util-keysyms
