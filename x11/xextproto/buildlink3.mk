# $NetBSD: buildlink3.mk,v 1.10 2010/04/09 08:33:38 tnn Exp $

.include "../../mk/bsd.fast.prefs.mk"

BUILDLINK_DEPMETHOD.xextproto?=	build

BUILDLINK_TREE+=	xextproto

.if !defined(XEXTPROTO_BUILDLINK3_MK)
XEXTPROTO_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.xextproto+=	xextproto>=7.1.1
BUILDLINK_PKGSRCDIR.xextproto?=	../../x11/xextproto

.include "../../x11/inputproto/buildlink3.mk"
.endif # XEXTPROTO_BUILDLINK3_MK

BUILDLINK_TREE+=	-xextproto
