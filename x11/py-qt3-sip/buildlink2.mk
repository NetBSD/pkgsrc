# $NetBSD: buildlink2.mk,v 1.2 2003/07/22 17:19:59 drochner Exp $

.if !defined(PY_QT3_SIP_BUILDLINK2_MK)
PY_QT3_SIP_BUILDLINK2_MK=	# defined

.include "../../lang/python/pyversion.mk"

BUILDLINK_PACKAGES+=		pyqt3sip
BUILDLINK_DEPENDS.pyqt3sip?=	${PYPKGPREFIX}-qt3-sip-[0-9]*
BUILDLINK_PKGSRCDIR.pyqt3sip?=	../../x11/py-qt3-sip

EVAL_PREFIX+=	BUILDLINK_PREFIX.pyqt3sip=pyqt3sip
BUILDLINK_PREFIX.pyqt3sip_DEFAULT=	${LOCALBASE}

BUILDLINK_FILES.pyqt3sip=	${PYINC}/sip.h
BUILDLINK_FILES.pyqt3sip+=	${PYINC}/sipQt.h
BUILDLINK_FILES.pyqt3sip+=	${PYSITELIB}/libsip.*

SIPBIN=	${BUILDLINK_PREFIX.pyqt3sip}/bin/sip${PYVERSSUFFIX}

BUILDLINK_LDFLAGS.pyqt3sip=	-L${PREFIX}/${PYSITELIB} -Wl,-R${PREFIX}/${PYSITELIB}
LDFLAGS+=	-Wl,-R${PREFIX}/${PYSITELIB}

BUILDLINK_TARGETS+=	pyqt3sip-buildlink

pyqt3sip-buildlink: _BUILDLINK_USE

.endif	# PY_QT3_SIP_BUILDLINK2_MK
