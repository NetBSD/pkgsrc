# $NetBSD: buildlink2.mk,v 1.4 2004/03/29 05:05:50 jlam Exp $

.if !defined(PY_QT2_SIP_BUILDLINK2_MK)
PY_QT2_SIP_BUILDLINK2_MK=	# defined

.include "../../lang/python/pyversion.mk"

BUILDLINK_PACKAGES+=		pyqt2sip
BUILDLINK_PKGBASE.pyqt2sip?=	${PYPKGPREFIX}-qt2-sip
BUILDLINK_DEPENDS.pyqt2sip?=	${PYPKGPREFIX}-qt2-sip-[0-9]*
BUILDLINK_PKGSRCDIR.pyqt2sip?=	../../x11/py-qt2-sip

EVAL_PREFIX+=	BUILDLINK_PREFIX.pyqt2sip=pyqt2sip
BUILDLINK_PREFIX.pyqt2sip_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.pyqt2sip=	${PYINC}/sip.h
BUILDLINK_FILES.pyqt2sip+=	${PYINC}/sipQt.h
BUILDLINK_FILES.pyqt2sip+=	${PYSITELIB}/libsip.*

BUILDLINK_TARGETS+=	pyqt2sip-buildlink

pyqt2sip-buildlink: _BUILDLINK_USE

.endif	# PY_QT2_SIP_BUILDLINK2_MK
