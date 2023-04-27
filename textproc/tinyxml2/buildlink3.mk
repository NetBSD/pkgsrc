# $NetBSD: buildlink3.mk,v 1.2 2023/04/27 08:19:09 wiz Exp $

BUILDLINK_TREE+=	tinyxml2

.if !defined(TINYXML2_BUILDLINK3_MK)
TINYXML2_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.tinyxml2+=	tinyxml2>=2.1.0
BUILDLINK_PKGSRCDIR.tinyxml2?=		../../textproc/tinyxml2

BUILDLINK_DEPMETHOD.tinyxml2?=		build
.endif	# TINYXML2_BUILDLINK3_MK

BUILDLINK_TREE+=	-tinyxml2
