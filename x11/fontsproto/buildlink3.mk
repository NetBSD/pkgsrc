# $NetBSD: buildlink3.mk,v 1.4 2013/04/06 13:46:34 rodent Exp $

BUILDLINK_TREE+=	fontsproto

.if !defined(FONTSPROTO_BUILDLINK3_MK)
FONTSPROTO_BUILDLINK3_MK:=

BUILDLINK_DEPMETHOD.fontsproto?=	build

BUILDLINK_API_DEPENDS.fontsproto+=	fontsproto>=2.0
BUILDLINK_PKGSRCDIR.fontsproto?=	../../x11/fontsproto
.endif # FONTSPROTO_BUILDLINK3_MK

BUILDLINK_TREE+=	-fontsproto
