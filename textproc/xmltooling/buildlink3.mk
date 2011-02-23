# $NetBSD: buildlink3.mk,v 1.2 2011/02/23 09:09:31 adam Exp $

BUILDLINK_TREE+=	xmltooling

.if !defined(XMLTOOLING_BUILDLINK3_MK)
XMLTOOLING_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.xmltooling+=	xmltooling>=1.3.3
BUILDLINK_PKGSRCDIR.xmltooling?=	../../textproc/xmltooling

.endif	# XMLTOOLING_BUILDLINK3_MK

BUILDLINK_TREE+=	-xmltooling
