# $NetBSD: buildlink3.mk,v 1.11 2012/05/07 02:45:48 dholland Exp $
#
# This Makefile fragment is included by packages that use xproto.
#

.include "../../mk/bsd.fast.prefs.mk"

BUILDLINK_TREE+=	xproto

.if !defined(XPROTO_BUILDLINK3_MK)
XPROTO_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.xproto+=		xproto>=7.0.9
BUILDLINK_PKGSRCDIR.xproto?=		../../x11/xproto
BUILDLINK_DEPMETHOD.xproto?=		build
.endif # XPROTO_BUILDLINK3_MK

BUILDLINK_TREE+=	-xproto
