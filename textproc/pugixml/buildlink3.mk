# $NetBSD: buildlink3.mk,v 1.2 2016/12/23 03:34:41 ryoon Exp $

BUILDLINK_TREE+=	pugixml

.if !defined(PUGIXML_BUILDLINK3_MK)
PUGIXML_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.pugixml+=	pugixml>=1.7
BUILDLINK_PKGSRCDIR.pugixml?=	../../textproc/pugixml
.endif	# PUGIXML_BUILDLINK3_MK

BUILDLINK_TREE+=	-pugixml
