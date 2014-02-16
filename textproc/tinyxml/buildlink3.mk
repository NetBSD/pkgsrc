# $NetBSD: buildlink3.mk,v 1.1 2014/02/16 23:05:33 wiz Exp $

BUILDLINK_TREE+=	tinyxml

.if !defined(TINYXML_BUILDLINK3_MK)
TINYXML_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.tinyxml+=	tinyxml>=2.6.2
BUILDLINK_PKGSRCDIR.tinyxml?=	../../textproc/tinyxml
.endif	# TINYXML_BUILDLINK3_MK

BUILDLINK_TREE+=	-tinyxml
