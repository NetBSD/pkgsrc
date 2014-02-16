# $NetBSD: buildlink3.mk,v 1.1 2014/02/16 22:58:51 wiz Exp $

BUILDLINK_TREE+=	htmlcxx

.if !defined(HTMLCXX_BUILDLINK3_MK)
HTMLCXX_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.htmlcxx+=	htmlcxx>=0.85
BUILDLINK_PKGSRCDIR.htmlcxx?=	../../www/htmlcxx
.endif	# HTMLCXX_BUILDLINK3_MK

BUILDLINK_TREE+=	-htmlcxx
