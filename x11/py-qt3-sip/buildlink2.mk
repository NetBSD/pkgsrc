# $NetBSD: buildlink2.mk,v 1.1.1.1 2003/07/15 16:40:45 drochner Exp $

.if !defined(PY_QT3_SIP_BUILDLINK2_MK)
PY_QT3_SIP_BUILDLINK2_MK=	# defined

.include "../../lang/python/pyversion.mk"

BUILDLINK_PACKAGES+=		pyqt3sip
BUILDLINK_DEPENDS.pyqt3sip?=	${PYPKGPREFIX}-qt3-sip-[0-9]*
BUILDLINK_PKGSRCDIR.pyqt3sip?=	../../x11/py-qt3-sip

EVAL_PREFIX+=	BUILDLINK_PREFIX.pyqt3sip=pyqt3sip
BUILDLINK_PREFIX.pyqt3sip_DEFAULT=	${LOCALBASE}

#BUILDLINK_FILES.pyqt3sip=	${PYINC}/sip.h
#BUILDLINK_FILES.pyqt3sip+=	${PYINC}/sipQt.h
#BUILDLINK_FILES.pyqt3sip+=	${PYSITELIB}/libsip.*

BUILDLINK_TARGETS+=	pyqt3sip-buildlink

pyqt3sip-buildlink: _BUILDLINK_USE

SIPBIN=	${BUILDLINK_PREFIX.pyqt3sip}/bin/sip${PYVERSSUFFIX}

.endif	# PY_QT3_SIP_BUILDLINK2_MK
