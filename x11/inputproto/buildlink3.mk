# $NetBSD: buildlink3.mk,v 1.6 2010/04/10 21:09:20 tnn Exp $

BUILDLINK_TREE+=	inputproto

.if !defined(INPUTPROTO_BUILDLINK3_MK)
INPUTPROTO_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.inputproto+=	inputproto>=1.4
BUILDLINK_PKGSRCDIR.inputproto?=	../../x11/inputproto
BUILDLINK_DEPMETHOD.inputproto?=	build
.endif # INPUTPROTO_BUILDLINK3_MK

BUILDLINK_TREE+=	-inputproto
