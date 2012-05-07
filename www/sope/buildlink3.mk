# $NetBSD: buildlink3.mk,v 1.9 2012/05/07 01:54:05 dholland Exp $

BUILDLINK_TREE+=	sope

.if !defined(SOPE_BUILDLINK3_MK)
SOPE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.sope+=	sope>=4.5.4nb2
BUILDLINK_ABI_DEPENDS.sope+=	sope>=4.5.4nb3
BUILDLINK_PKGSRCDIR.sope?=	../../www/sope
.endif # SOPE_BUILDLINK3_MK

BUILDLINK_TREE+=	-sope
