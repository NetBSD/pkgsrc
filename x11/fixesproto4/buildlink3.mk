# $NetBSD: buildlink3.mk,v 1.4 2018/03/07 11:57:34 wiz Exp $

.include "../../mk/bsd.fast.prefs.mk"

BUILDLINK_DEPMETHOD.fixesproto?=	build

BUILDLINK_TREE+=	fixesproto

.if !defined(FIXESPROTO_BUILDLINK3_MK)
FIXESPROTO_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.fixesproto+=	fixesproto>=3.0.0<5
BUILDLINK_PKGSRCDIR.fixesproto?=	../../x11/fixesproto4

.include "../../x11/xorgproto/buildlink3.mk"
.endif # FIXESPROTO_BUILDLINK3_MK

BUILDLINK_TREE+=	-fixesproto
