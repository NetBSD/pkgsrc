# $NetBSD: buildlink3.mk,v 1.2 2014/07/08 14:57:06 jperkin Exp $

BUILDLINK_TREE+=	tinyxml

.if !defined(TINYXML_BUILDLINK3_MK)
TINYXML_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.tinyxml+=	tinyxml>=2.6.2
BUILDLINK_ABI_DEPENDS.tinyxml?=	tinyxml>=2.6.2nb2
BUILDLINK_PKGSRCDIR.tinyxml?=	../../textproc/tinyxml
.endif	# TINYXML_BUILDLINK3_MK

BUILDLINK_TREE+=	-tinyxml
