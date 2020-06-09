# $NetBSD: buildlink3.mk,v 1.1 2020/06/09 13:53:00 nia Exp $

BUILDLINK_TREE+=	uchardet

.if !defined(UCHARDET_BUILDLINK3_MK)
UCHARDET_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.uchardet+=	uchardet>=0.0.7
BUILDLINK_PKGSRCDIR.uchardet?=		../../textproc/uchardet
.endif	# UCHARDET_BUILDLINK3_MK

BUILDLINK_TREE+=	-uchardet
