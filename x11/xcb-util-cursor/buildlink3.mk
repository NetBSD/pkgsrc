# $NetBSD: buildlink3.mk,v 1.2 2014/04/06 07:57:57 obache Exp $
#

BUILDLINK_TREE+=	xcb-util-cursor

.if !defined(XCB_UTIL_CURSOR_BUILDLINK3_MK)
XCB_UTIL_CURSOR_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.xcb-util-cursor+=	xcb-util-cursor>=0.1.0
BUILDLINK_ABI_DEPENDS.xcb-util-cursor+=	xcb-util-cursor>=0.1.1nb1
BUILDLINK_PKGSRCDIR.xcb-util-cursor?=	../../x11/xcb-util-cursor

.include "../../x11/libxcb/buildlink3.mk"
.include "../../x11/xcb-util-image/buildlink3.mk"
.include "../../x11/xcb-util-renderutil/buildlink3.mk"
.endif	# XCB_UTIL_CURSOR_BUILDLINK3_MK

BUILDLINK_TREE+=	-xcb-util-cursor
