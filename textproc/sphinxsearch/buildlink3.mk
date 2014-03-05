# $NetBSD: buildlink3.mk,v 1.1 2014/03/05 13:44:23 fhajny Exp $

BUILDLINK_TREE+=			sphinxsearch

.if !defined(SPHINXSEARCH_BUILDLINK3_MK)
SPHINXSEARCH_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.sphinxsearch+=	sphinxsearch>=2.1.0
BUILDLINK_PKGSRCDIR.sphinxsearch?=	../../textproc/sphinxsearch

.endif	# SPHINXSEARCH_BUILDLINK3_MK

BUILDLINK_TREE+=			-sphinxsearch
