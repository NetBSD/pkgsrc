# $NetBSD: buildlink3.mk,v 1.1 2016/04/29 11:54:54 wiz Exp $

BUILDLINK_TREE+=	pugixml

.if !defined(PUGIXML_BUILDLINK3_MK)
PUGIXML_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.pugixml+=	pugixml>=1.7
BUILDLINK_PKGSRCDIR.pugixml?=	../../textproc/pugixml

BUILDLINK_DEPMETHOD.pugixml?=	build
.endif	# PUGIXML_BUILDLINK3_MK

BUILDLINK_TREE+=	-pugixml
