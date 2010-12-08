# $NetBSD: buildlink3.mk,v 1.2 2010/12/08 08:10:47 abs Exp $

.include "../../mk/bsd.fast.prefs.mk"

BUILDLINK_DEPMETHOD.fixesproto?=	build

BUILDLINK_TREE+=	fixesproto

.if !defined(FIXESPROTO_BUILDLINK3_MK)
FIXESPROTO_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.fixesproto+=	fixesproto>=3.0.0
BUILDLINK_PKGSRCDIR.fixesproto?=	../../x11/fixesproto4

.include "../../x11/xextproto/buildlink3.mk"
.include "../../x11/xproto/buildlink3.mk"
.endif # FIXESPROTO_BUILDLINK3_MK

BUILDLINK_TREE+=	-fixesproto
