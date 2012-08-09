# $NetBSD: buildlink3.mk,v 1.5 2012/08/09 10:15:05 sbd Exp $

BUILDLINK_TREE+=	py-qt4

.if !defined(PY_QT4_BUILDLINK3_MK)
PY_QT4_BUILDLINK3_MK:=

.include "../../lang/python/pyversion.mk"

BUILDLINK_API_DEPENDS.py-qt4+=	${PYPKGPREFIX}-qt4>=4.4.4
BUILDLINK_PKGSRCDIR.py-qt4?=	../../x11/py-qt4
.endif # PY_QT4_BUILDLINK3_MK

BUILDLINK_TREE+=	-py-qt4
