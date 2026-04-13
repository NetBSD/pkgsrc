# $NetBSD: buildlink3.mk,v 1.1 2026/04/13 16:52:50 kikadf Exp $

BUILDLINK_TREE+=	xwayland

.if !defined(XWAYLAND_BUILDLINK3_MK)
XWAYLAND_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.xwayland+=	xwayland>=24.1.9
BUILDLINK_PKGSRCDIR.xwayland?=		../../wayland/xwayland

.endif	# XWAYLAND_BUILDLINK3_MK

BUILDLINK_TREE+=	-xwayland
