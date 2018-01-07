# $NetBSD: buildlink3.mk,v 1.3 2018/01/07 13:04:35 rillig Exp $

BUILDLINK_TREE+=	uriparser

.if !defined(URIPARSER_BUILDLINK3_MK)
URIPARSER_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.uriparser+=	uriparser>=0.6.0
BUILDLINK_PKGSRCDIR.uriparser?=		../../textproc/uriparser
.endif # URIPARSER_BUILDLINK3_MK

BUILDLINK_TREE+=	-uriparser
