# $NetBSD: buildlink3.mk,v 1.2 2009/03/20 19:25:40 joerg Exp $

BUILDLINK_DEPMETHOD.fontcacheproto?=	build

BUILDLINK_TREE+=	fontcacheproto

.if !defined(FONTCACHEPROTO_BUILDLINK3_MK)
FONTCACHEPROTO_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.fontcacheproto+=	fontcacheproto>=0.1
BUILDLINK_PKGSRCDIR.fontcacheproto?=	../../x11/fontcacheproto
.endif # FONTCACHEPROTO_BUILDLINK3_MK

BUILDLINK_TREE+=	-fontcacheproto
