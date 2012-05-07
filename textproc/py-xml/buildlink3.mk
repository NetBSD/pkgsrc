# $NetBSD: buildlink3.mk,v 1.14 2012/05/07 01:54:03 dholland Exp $

BUILDLINK_TREE+=	pyxml

.if !defined(PYXML_BUILDLINK3_MK)
PYXML_BUILDLINK3_MK:=

.include "../../lang/python/pyversion.mk"

BUILDLINK_API_DEPENDS.pyxml+=	${PYPKGPREFIX}-xml>=0.8.3nb1
BUILDLINK_ABI_DEPENDS.pyxml+=	${PYPKGPREFIX}-xml>=0.8.4nb2
BUILDLINK_PKGSRCDIR.pyxml?=	../../textproc/py-xml

.include "../../textproc/expat/buildlink3.mk"
.endif # PYXML_BUILDLINK3_MK

BUILDLINK_TREE+=	-pyxml
