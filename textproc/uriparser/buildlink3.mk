# $NetBSD: buildlink3.mk,v 1.2 2009/03/20 19:25:33 joerg Exp $

BUILDLINK_TREE+=	uriparser

.if !defined(URIPARSER_BUILDLINK3_MK)
URIPARSER_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.uriparser+=	uriparser>=0.6.0
BUILDLINK_PKGSRCDIR.uriparser?=	../../textproc/uriparser
.endif # URIPARSER_BUILDLINK3_MK

BUILDLINK_TREE+=	-uriparser
