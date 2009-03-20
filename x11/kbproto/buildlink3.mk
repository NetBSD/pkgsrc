# $NetBSD: buildlink3.mk,v 1.2 2009/03/20 19:25:42 joerg Exp $

BUILDLINK_DEPMETHOD.kbproto?=	build

BUILDLINK_TREE+=	kbproto

.if !defined(KBPROTO_BUILDLINK3_MK)
KBPROTO_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.kbproto+=	kbproto>=1.0.2
BUILDLINK_PKGSRCDIR.kbproto?=	../../x11/kbproto
.endif # KBPROTO_BUILDLINK3_MK

BUILDLINK_TREE+=	-kbproto
