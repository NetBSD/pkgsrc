# $NetBSD: buildlink3.mk,v 1.8 2006/07/08 23:11:15 jlam Exp $

BUILDLINK_DEPTH:=			${BUILDLINK_DEPTH}+
PYQT3_BASE_BUILDLINK3_MK:=	${PYQT3_BASE_BUILDLINK3_MK}+

.include "../../lang/python/pyversion.mk"

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	pyqt3-base
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Npyqt3-base}
BUILDLINK_PACKAGES+=	pyqt3-base
BUILDLINK_ORDER:=	${BUILDLINK_ORDER} ${BUILDLINK_DEPTH}pyqt3-base

.if !empty(PYQT3_BASE_BUILDLINK3_MK:M+)
BUILDLINK_API_DEPENDS.pyqt3-base+=	${PYPKGPREFIX}-qt3-base>=3.11
BUILDLINK_ABI_DEPENDS.pyqt3-base?=	py24-qt3-base>=3.15.1nb3
BUILDLINK_PKGSRCDIR.pyqt3-base?=	../../x11/py-qt3-base

BUILDLINK_LIBDIRS.pyqt3-base+=	${PYSITELIB}
.endif	# PYQT3_BASE_BUILDLINK3_MK

.include "../../x11/py-qt3-sip/buildlink3.mk"
.include "../../x11/qt3-libs/buildlink3.mk"
.include "../../x11/qt3-tools/buildlink3.mk"

BUILDLINK_DEPTH:=			${BUILDLINK_DEPTH:S/+$//}
