# $NetBSD: buildlink3.mk,v 1.1 2020/10/08 22:36:20 leot Exp $

BUILDLINK_TREE+=	gumbo-parser

.if !defined(GUMBO_PARSER_BUILDLINK3_MK)
GUMBO_PARSER_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.gumbo-parser+=	gumbo-parser>=0.10.1
BUILDLINK_PKGSRCDIR.gumbo-parser?=	../../www/gumbo-parser
.endif	# GUMBO_PARSER_BUILDLINK3_MK

BUILDLINK_TREE+=	-gumbo-parser
