# $NetBSD: buildlink3.mk,v 1.4 2025/03/21 16:43:53 wiz Exp $

BUILDLINK_TREE+=	tinyxml2

.if !defined(TINYXML2_BUILDLINK3_MK)
TINYXML2_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.tinyxml2+=	tinyxml2>=2.1.0
BUILDLINK_ABI_DEPENDS.tinyxml2+=	tinyxml2>=9.0.0
BUILDLINK_PKGSRCDIR.tinyxml2?=		../../textproc/tinyxml2

.endif	# TINYXML2_BUILDLINK3_MK

BUILDLINK_TREE+=	-tinyxml2
