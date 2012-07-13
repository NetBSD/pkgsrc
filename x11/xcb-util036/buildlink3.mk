# $NetBSD: buildlink3.mk,v 1.1 2012/07/13 14:19:47 wiz Exp $

BUILDLINK_TREE+=	xcb-util036

.if !defined(XCB_UTIL036_BUILDLINK3_MK)
XCB_UTIL036_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.xcb-util036+=	xcb-util036>=0.3.6
BUILDLINK_PKGSRCDIR.xcb-util036?=	../../x11/xcb-util036

BUILDLINK_PASSTHRU_DIRS+=		${BUILDLINK_PREFIX.xcb-util036}/lib
BUILDLINK_PASSTHRU_RPATHDIRS+=		${PREFIX}/xcb-util036/lib
_PKG_CONFIG_LIBDIR=			${BUILDLINK_DIR}/xcb-util036/lib/pkgconfig:${BUILDLINK_DIR}/lib/pkgconfig:${BUILDLINK_DIR}/share/pkgconfig

.include "../../x11/libxcb/buildlink3.mk"
.endif	# XCB_UTIL036_BUILDLINK3_MK

BUILDLINK_TREE+=	-xcb-util036
