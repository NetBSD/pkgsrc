# $NetBSD: buildlink3.mk,v 1.2 2024/01/17 23:49:50 gdt Exp $

BUILDLINK_TREE+=	gumbo-parser

.if !defined(GUMBO_PARSER_BUILDLINK3_MK)
GUMBO_PARSER_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.gumbo-parser+=	gumbo-parser>=0.11.0
BUILDLINK_PKGSRCDIR.gumbo-parser?=	../../www/gumbo-parser
.endif	# GUMBO_PARSER_BUILDLINK3_MK

BUILDLINK_TREE+=	-gumbo-parser
