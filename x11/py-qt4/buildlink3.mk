# $NetBSD: buildlink3.mk,v 1.3 2009/03/20 19:25:49 joerg Exp $

BUILDLINK_TREE+=	py-qt4

.if !defined(PY_QT4_BUILDLINK3_MK)
PY_QT4_BUILDLINK3_MK:=

.include "../../lang/python/pyversion.mk"

BUILDLINK_API_DEPENDS.py-qt4+=	${PYPKGPREFIX}-qt4>=4.4.4
BUILDLINK_PKGSRCDIR.py-qt4?=	../../x11/py-qt4
.endif # PY_QT4_BUILDLINK3_MK

BUILDLINK_TREE+=	-py-qt4
