# $NetBSD: buildlink3.mk,v 1.2 2006/01/24 07:32:59 wiz Exp $

BUILDLINK_DEPTH:=			${BUILDLINK_DEPTH}+
PYQT3_BASE_BUILDLINK3_MK:=	${PYQT3_BASE_BUILDLINK3_MK}+

.include "../../lang/python/pyversion.mk"

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	pyqt3-base
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Npyqt3-base}
BUILDLINK_PACKAGES+=	pyqt3-base

.if !empty(PYQT3_BASE_BUILDLINK3_MK:M+)
BUILDLINK_DEPENDS.pyqt3-base+=	${PYPKGPREFIX}-qt3-base>=3.11
BUILDLINK_RECOMMENDED.pyqt3-base?=	${PYPKGPREFIX}-qt3-base>=3.15.1
BUILDLINK_PKGSRCDIR.pyqt3-base?=	../../x11/py-qt3-base

BUILDLINK_LIBDIRS.pyqt3-base+=	${PYSITELIB}
.endif	# PYQT3_BASE_BUILDLINK3_MK

.include "../../x11/py-qt3-sip/buildlink3.mk"
.include "../../x11/qt3-libs/buildlink3.mk"
.include "../../x11/qt3-tools/buildlink3.mk"

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
