# $NetBSD: buildlink3.mk,v 1.1 2022/11/30 10:24:35 nros Exp $

BUILDLINK_TREE+=	litehtml

.if !defined(LITEHTML_BUILDLINK3_MK)
LITEHTML_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.litehtml+=	litehtml>=0.6
BUILDLINK_PKGSRCDIR.litehtml?=		../../www/litehtml
.endif	# LITEHTML_BUILDLINK3_MK

BUILDLINK_TREE+=	-litehtml
