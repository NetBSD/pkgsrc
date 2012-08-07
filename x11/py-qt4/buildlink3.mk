# $NetBSD: buildlink3.mk,v 1.4 2012/08/07 09:44:02 sbd Exp $

BUILDLINK_TREE+=	py-qt4

.if !defined(PY_QT4_BUILDLINK3_MK)
PY_QT4_BUILDLINK3_MK:=

PYTHON_VERSIONS_INCOMPATIBLE+=	25

.include "../../lang/python/pyversion.mk"

BUILDLINK_API_DEPENDS.py-qt4+=	${PYPKGPREFIX}-qt4>=4.4.4
BUILDLINK_PKGSRCDIR.py-qt4?=	../../x11/py-qt4
.endif # PY_QT4_BUILDLINK3_MK

BUILDLINK_TREE+=	-py-qt4
