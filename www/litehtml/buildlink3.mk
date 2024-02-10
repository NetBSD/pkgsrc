# $NetBSD: buildlink3.mk,v 1.2 2024/02/10 11:03:14 wiz Exp $

BUILDLINK_TREE+=	litehtml

.if !defined(LITEHTML_BUILDLINK3_MK)
LITEHTML_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.litehtml+=	litehtml>=0.9
BUILDLINK_PKGSRCDIR.litehtml?=		../../www/litehtml
.endif	# LITEHTML_BUILDLINK3_MK

BUILDLINK_TREE+=	-litehtml
