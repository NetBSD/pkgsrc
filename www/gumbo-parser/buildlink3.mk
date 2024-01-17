# $NetBSD: buildlink3.mk,v 1.3 2024/01/17 23:57:50 gdt Exp $

BUILDLINK_TREE+=	gumbo-parser

.if !defined(GUMBO_PARSER_BUILDLINK3_MK)
GUMBO_PARSER_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.gumbo-parser+=	gumbo-parser>=0.11.0
BUILDLINK_ABI_DEPENDS.gumbo-parser?=	gumbo-parser>=0.12.1
BUILDLINK_PKGSRCDIR.gumbo-parser?=	../../www/gumbo-parser
.endif	# GUMBO_PARSER_BUILDLINK3_MK

BUILDLINK_TREE+=	-gumbo-parser
