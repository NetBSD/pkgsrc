# $NetBSD: buildlink3.mk,v 1.3 2009/03/20 19:25:32 joerg Exp $

BUILDLINK_TREE+=	py-elementtree

.if !defined(PY_ELEMENTTREE_BUILDLINK3_MK)
PY_ELEMENTTREE_BUILDLINK3_MK:=

.include "../../lang/python/pyversion.mk"

BUILDLINK_API_DEPENDS.py-elementtree+=	${PYPKGPREFIX}-elementtree>=1.2.6nb3
BUILDLINK_PKGSRCDIR.py-elementtree=	../../textproc/py-elementtree
.endif # PY_ELEMENTTREE_BUILDLINK3_MK

BUILDLINK_TREE+=	-py-elementtree
