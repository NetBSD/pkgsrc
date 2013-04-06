# $NetBSD: buildlink3.mk,v 1.3 2013/04/06 13:46:35 rodent Exp $

BUILDLINK_TREE+=	kbproto

.if !defined(KBPROTO_BUILDLINK3_MK)
KBPROTO_BUILDLINK3_MK:=

BUILDLINK_DEPMETHOD.kbproto?=	build

BUILDLINK_API_DEPENDS.kbproto+=	kbproto>=1.0.2
BUILDLINK_PKGSRCDIR.kbproto?=	../../x11/kbproto
.endif # KBPROTO_BUILDLINK3_MK

BUILDLINK_TREE+=	-kbproto
