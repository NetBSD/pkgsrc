# $NetBSD: buildlink2.mk,v 1.3 2004/03/29 05:05:50 jlam Exp $

.if !defined(PY_QT3_MODULES_BUILDLINK2_MK)
PY_QT3_MODULES_BUILDLINK2_MK=	# defined

.include "../../lang/python/pyversion.mk"

BUILDLINK_PACKAGES+=		pyqt3modules
BUILDLINK_PKGBASE.pyqt3modules?=	${PYPKGPREFIX}-qt3-modules
BUILDLINK_DEPENDS.pyqt3modules?=	${PYPKGPREFIX}-qt3-modules>=3.7nb1
BUILDLINK_PKGSRCDIR.pyqt3modules?=	../../x11/py-qt3-modules

.include "../../x11/py-qt3-base/buildlink2.mk"

.endif	# PY_QT3_MODULES_BUILDLINK2_MK
