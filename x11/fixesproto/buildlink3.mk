# $NetBSD: buildlink3.mk,v 1.8 2009/03/20 19:25:40 joerg Exp $

.include "../../mk/bsd.fast.prefs.mk"

BUILDLINK_DEPMETHOD.fixesproto?=	build

BUILDLINK_TREE+=	fixesproto

.if !defined(FIXESPROTO_BUILDLINK3_MK)
FIXESPROTO_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.fixesproto+=	fixesproto>=3.0.0
BUILDLINK_PKGSRCDIR.fixesproto?=	../../x11/fixesproto

.include "../../x11/xextproto/buildlink3.mk"
.include "../../x11/xproto/buildlink3.mk"
.endif # FIXESPROTO_BUILDLINK3_MK

BUILDLINK_TREE+=	-fixesproto
