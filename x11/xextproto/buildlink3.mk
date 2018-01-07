# $NetBSD: buildlink3.mk,v 1.12 2018/01/07 13:04:43 rillig Exp $

.include "../../mk/bsd.fast.prefs.mk"

BUILDLINK_DEPMETHOD.xextproto?=	build

BUILDLINK_TREE+=	xextproto

.if !defined(XEXTPROTO_BUILDLINK3_MK)
XEXTPROTO_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.xextproto+=	xextproto>=7.0
BUILDLINK_PKGSRCDIR.xextproto?=		../../x11/xextproto

.include "../../x11/inputproto/buildlink3.mk"
.endif # XEXTPROTO_BUILDLINK3_MK

BUILDLINK_TREE+=	-xextproto
