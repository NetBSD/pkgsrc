# $NetBSD: buildlink3.mk,v 1.1 2016/05/28 23:09:30 schnoebe Exp $

BUILDLINK_TREE+=	http-parser

.if !defined(HTTP_PARSER_BUILDLINK3_MK)
HTTP_PARSER_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.http-parser+=	http-parser>=2.7.0
BUILDLINK_PKGSRCDIR.http-parser?=	../../www/http-parser
.endif	# HTTP_PARSER_BUILDLINK3_MK

BUILDLINK_TREE+=	-http-parser
