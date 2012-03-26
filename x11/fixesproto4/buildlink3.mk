# $NetBSD: buildlink3.mk,v 1.3 2012/03/26 13:07:34 joerg Exp $

.include "../../mk/bsd.fast.prefs.mk"

BUILDLINK_DEPMETHOD.fixesproto?=	build

BUILDLINK_TREE+=	fixesproto

.if !defined(FIXESPROTO_BUILDLINK3_MK)
FIXESPROTO_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.fixesproto+=	fixesproto>=3.0.0<5
BUILDLINK_PKGSRCDIR.fixesproto?=	../../x11/fixesproto4

.include "../../x11/xextproto/buildlink3.mk"
.include "../../x11/xproto/buildlink3.mk"
.endif # FIXESPROTO_BUILDLINK3_MK

BUILDLINK_TREE+=	-fixesproto
