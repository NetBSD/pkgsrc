# $NetBSD: buildlink2.mk,v 1.3 2004/03/29 05:05:50 jlam Exp $

.if !defined(PY_QT3_BASE_BUILDLINK2_MK)
PY_QT3_BASE_BUILDLINK2_MK=	# defined

.include "../../lang/python/pyversion.mk"

BUILDLINK_PACKAGES+=		pyqt3base
BUILDLINK_PKGBASE.pyqt3base?=	${PYPKGPREFIX}-qt3-base
BUILDLINK_DEPENDS.pyqt3base?=	${PYPKGPREFIX}-qt3-base>=3.7nb1
BUILDLINK_PKGSRCDIR.pyqt3base?=	../../x11/py-qt3-base

EVAL_PREFIX+=	BUILDLINK_PREFIX.pyqt3base=pyqt3base
BUILDLINK_PREFIX.pyqt3base_DEFAULT=	${LOCALBASE}

# LDFLAGS for this are inherited from py-qt3-sip
BUILDLINK_FILES.pyqt3base+=	${PYSITELIB}/libqtcmodule.*

BUILDLINK_TARGETS+=	pyqt3base-buildlink

pyqt3base-buildlink: _BUILDLINK_USE

.include "../../x11/py-qt3-sip/buildlink2.mk"
.include "../../x11/qt3-libs/buildlink2.mk"
BUILDLINK_DEPENDS.qt3-tools=	qt3-tools>=3.1.2nb2
.include "../../x11/qt3-tools/buildlink2.mk"

.endif	# PY_QT3_BASE_BUILDLINK2_MK
