# $NetBSD: buildlink3.mk,v 1.4 2025/04/23 18:54:19 perseant Exp $

BUILDLINK_TREE+=	xmltooling

.if !defined(XMLTOOLING_BUILDLINK3_MK)
XMLTOOLING_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.xmltooling+=	xmltooling>=3.3.0
BUILDLINK_PKGSRCDIR.xmltooling?=	../../textproc/xmltooling

.endif	# XMLTOOLING_BUILDLINK3_MK

BUILDLINK_TREE+=	-xmltooling
