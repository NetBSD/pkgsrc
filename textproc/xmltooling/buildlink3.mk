# $NetBSD: buildlink3.mk,v 1.1.1.1 2010/03/15 18:45:36 pettai Exp $
#

BUILDLINK_TREE+=	xmltooling

.if !defined(XMLTOOLING_C_BUILDLINK3_MK)
XMLTOOLING_C_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.xmltooling+=	xmltooling>=1.3.3
BUILDLINK_PKGSRCDIR.xmltooling?=	../../textproc/xmltooling

.endif	# XMLTOOLING_C_BUILDLINK3_MK

BUILDLINK_TREE+=	-xmltooling
