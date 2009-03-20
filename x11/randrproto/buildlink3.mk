# $NetBSD: buildlink3.mk,v 1.9 2009/03/20 19:25:50 joerg Exp $

.include "../../mk/bsd.fast.prefs.mk"

BUILDLINK_DEPMETHOD.randrproto?=	build

BUILDLINK_TREE+=	randrproto

.if !defined(RANDRPROTO_BUILDLINK3_MK)
RANDRPROTO_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.randrproto+=	randrproto>=1.2.0
BUILDLINK_PKGSRCDIR.randrproto?=	../../x11/randrproto
.endif # RANDRPROTO_BUILDLINK3_MK

BUILDLINK_TREE+=	-randrproto
