# $NetBSD: buildlink3.mk,v 1.1 2015/03/09 21:33:28 tnn Exp $

BUILDLINK_TREE+=	presentproto

.if !defined(PRESENTPROTO_BUILDLINK3_MK)
PRESENTPROTO_BUILDLINK3_MK:=

BUILDLINK_DEPMETHOD.presentproto?=	build

BUILDLINK_API_DEPENDS.presentproto+=	presentproto>=1.0
BUILDLINK_PKGSRCDIR.presentproto?=	../../x11/presentproto
.endif	# PRESENTPROTO_BUILDLINK3_MK

BUILDLINK_TREE+=	-presentproto
