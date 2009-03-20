# $NetBSD: buildlink3.mk,v 1.3 2009/03/20 19:25:40 joerg Exp $

BUILDLINK_DEPMETHOD.fontsproto?=	build

BUILDLINK_TREE+=	fontsproto

.if !defined(FONTSPROTO_BUILDLINK3_MK)
FONTSPROTO_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.fontsproto+=	fontsproto>=2.0
BUILDLINK_PKGSRCDIR.fontsproto?=	../../x11/fontsproto
.endif # FONTSPROTO_BUILDLINK3_MK

BUILDLINK_TREE+=	-fontsproto
