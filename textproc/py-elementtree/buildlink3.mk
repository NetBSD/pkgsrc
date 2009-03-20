# $NetBSD: buildlink3.mk,v 1.2 2009/03/20 17:30:12 joerg Exp $

BUILDLINK_DEPTH:=			${BUILDLINK_DEPTH}+
PY_ELEMENTTREE_BUILDLINK3_MK:=	${PY_ELEMENTTREE_BUILDLINK3_MK}+

.if ${BUILDLINK_DEPTH} == "+"
BUILDLINK_DEPENDS+=	py-elementtree
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Npy-elementtree}
BUILDLINK_PACKAGES+=	py-elementtree
BUILDLINK_ORDER:=	${BUILDLINK_ORDER} ${BUILDLINK_DEPTH}py-elementtree

.if ${PY_ELEMENTTREE_BUILDLINK3_MK} == "+"
.include "../../lang/python/pyversion.mk"

BUILDLINK_API_DEPENDS.py-elementtree+=	${PYPKGPREFIX}-elementtree>=1.2.6nb3
BUILDLINK_PKGSRCDIR.py-elementtree=	../../textproc/py-elementtree
.endif	# PY_ELEMENTTREE_BUILDLINK3_MK

BUILDLINK_DEPTH:=			${BUILDLINK_DEPTH:S/+$//}
