# $NetBSD: buildlink2.mk,v 1.1.1.1 2003/07/22 17:24:50 drochner Exp $

.if !defined(PY_QT3_MODULES_BUILDLINK2_MK)
PY_QT3_MODULES_BUILDLINK2_MK=	# defined

.include "../../lang/python/pyversion.mk"

BUILDLINK_PACKAGES+=		pyqt3modules
BUILDLINK_DEPENDS.pyqt3modules?=	${PYPKGPREFIX}-qt3-modules-[0-9]*
BUILDLINK_PKGSRCDIR.pyqt3modules?=	../../x11/py-qt3-modules

.include "../../x11/py-qt3-base/buildlink2.mk"

.endif	# PY_QT3_MODULES_BUILDLINK2_MK
