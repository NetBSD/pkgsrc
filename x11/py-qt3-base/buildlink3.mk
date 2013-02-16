# $NetBSD: buildlink3.mk,v 1.22 2013/02/16 11:19:29 wiz Exp $

BUILDLINK_TREE+=	pyqt3-base

.if !defined(PYQT3_BASE_BUILDLINK3_MK)
PYQT3_BASE_BUILDLINK3_MK:=

.include "../../lang/python/pyversion.mk"

BUILDLINK_API_DEPENDS.pyqt3-base+=	${PYPKGPREFIX}-qt3-base>=3.11
BUILDLINK_ABI_DEPENDS.pyqt3-base+=	${PYPKGPREFIX}-qt3-base>=3.18.1nb10
BUILDLINK_PKGSRCDIR.pyqt3-base?=	../../x11/py-qt3-base

BUILDLINK_LIBDIRS.pyqt3-base+=	${PYSITELIB}

.include "../../x11/py-sip/buildlink3.mk"
.include "../../x11/qt3-libs/buildlink3.mk"
.include "../../x11/qt3-tools/buildlink3.mk"
.endif # PYQT3_BASE_BUILDLINK3_MK

BUILDLINK_TREE+=	-pyqt3-base
