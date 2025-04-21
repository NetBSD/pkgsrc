# $NetBSD: buildlink3.mk,v 1.3 2025/04/21 21:10:48 perseant Exp $

BUILDLINK_TREE+=	xmltooling

.if !defined(XMLTOOLING_BUILDLINK3_MK)
XMLTOOLING_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.xmltooling+=	xmltooling>=3.1.0
BUILDLINK_PKGSRCDIR.xmltooling?=	../../textproc/xmltooling

.endif	# XMLTOOLING_BUILDLINK3_MK

BUILDLINK_TREE+=	-xmltooling
