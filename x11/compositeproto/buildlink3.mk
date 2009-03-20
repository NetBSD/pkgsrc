# $NetBSD: buildlink3.mk,v 1.9 2009/03/20 19:25:39 joerg Exp $

.include "../../mk/bsd.fast.prefs.mk"

BUILDLINK_DEPMETHOD.compositeproto?=	build

BUILDLINK_TREE+=	compositeproto

.if !defined(COMPOSITEPROTO_BUILDLINK3_MK)
COMPOSITEPROTO_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.compositeproto+=	compositeproto>=0.3.1
BUILDLINK_PKGSRCDIR.compositeproto?=	../../x11/compositeproto

.include "../../x11/fixesproto/buildlink3.mk"
.include "../../x11/xproto/buildlink3.mk"
.endif # COMPOSITEPROTO_BUILDLINK3_MK

BUILDLINK_TREE+=	-compositeproto
