# $NetBSD: buildlink3.mk,v 1.4 2009/03/20 19:25:42 joerg Exp $

BUILDLINK_TREE+=	inputproto

.if !defined(INPUTPROTO_BUILDLINK3_MK)
INPUTPROTO_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.inputproto+=	inputproto>=1.4
BUILDLINK_PKGSRCDIR.inputproto?=	../../x11/inputproto
BUILDLINK_DEPMETHOD.inputproto?=	build
.endif # INPUTPROTO_BUILDLINK3_MK

BUILDLINK_TREE+=	-inputproto
