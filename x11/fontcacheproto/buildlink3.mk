# $NetBSD: buildlink3.mk,v 1.3 2013/04/06 13:46:34 rodent Exp $

BUILDLINK_TREE+=	fontcacheproto

.if !defined(FONTCACHEPROTO_BUILDLINK3_MK)
FONTCACHEPROTO_BUILDLINK3_MK:=

BUILDLINK_DEPMETHOD.fontcacheproto?=	build

BUILDLINK_API_DEPENDS.fontcacheproto+=	fontcacheproto>=0.1
BUILDLINK_PKGSRCDIR.fontcacheproto?=	../../x11/fontcacheproto
.endif # FONTCACHEPROTO_BUILDLINK3_MK

BUILDLINK_TREE+=	-fontcacheproto
