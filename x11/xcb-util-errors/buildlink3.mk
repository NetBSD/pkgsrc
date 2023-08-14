# $NetBSD: buildlink3.mk,v 1.2 2023/08/14 05:25:36 wiz Exp $

BUILDLINK_TREE+=	xcb-util-errors

.if !defined(XCB_UTIL_ERRORS_BUILDLINK3_MK)
XCB_UTIL_ERRORS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.xcb-util-errors+=	xcb-util-errors>=1.0.1
BUILDLINK_ABI_DEPENDS.xcb-util-errors?=	xcb-util-errors>=1.0.1nb1
BUILDLINK_PKGSRCDIR.xcb-util-errors?=	../../x11/xcb-util-errors

.include "../../x11/libxcb/buildlink3.mk"
.endif	# XCB_UTIL_ERRORS_BUILDLINK3_MK

BUILDLINK_TREE+=	-xcb-util-errors
