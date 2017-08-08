# $NetBSD: buildlink3.mk,v 1.1 2017/08/08 14:03:19 nros Exp $

BUILDLINK_TREE+=	xcb-util-xrm

.if !defined(XCB_UTIL_XRM_BUILDLINK3_MK)
XCB_UTIL_XRM_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.xcb-util-xrm+=	xcb-util-xrm>=1.0
BUILDLINK_PKGSRCDIR.xcb-util-xrm?=	../../x11/xcb-util-xrm

.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/xcb-util/buildlink3.mk"
.endif	# XCB_UTIL_XRM_BUILDLINK3_MK

BUILDLINK_TREE+=	-xcb-util-xrm
