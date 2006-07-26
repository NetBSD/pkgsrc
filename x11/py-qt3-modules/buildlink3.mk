# $NetBSD: buildlink3.mk,v 1.9 2006/07/26 17:56:25 wiz Exp $

BUILDLINK_DEPTH:=			${BUILDLINK_DEPTH}+
PYQT3_MOD_BUILDLINK3_MK:=	${PYQT3_MOD_BUILDLINK3_MK}+

.include "../../lang/python/pyversion.mk"

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	pyqt3-mod
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Npyqt3-mod}
BUILDLINK_PACKAGES+=	pyqt3-mod
BUILDLINK_ORDER:=	${BUILDLINK_ORDER} ${BUILDLINK_DEPTH}pyqt3-mod

.if !empty(PYQT3_MOD_BUILDLINK3_MK:M+)
BUILDLINK_API_DEPENDS.pyqt3-mod+=	${PYPKGPREFIX}-qt3-modules>=3.11
BUILDLINK_ABI_DEPENDS.pyqt3-mod?=	${PYPKGPREFIX}-qt3-modules>=3.15.1nb3
BUILDLINK_PKGSRCDIR.pyqt3-mod?=	../../x11/py-qt3-modules

BUILDLINK_LIBDIRS.pyqt3-mod+=	${PYSITELIB}
.endif	# PYQT3_MOD_BUILDLINK3_MK

.include "../../x11/py-qt3-base/buildlink3.mk"

BUILDLINK_DEPTH:=			${BUILDLINK_DEPTH:S/+$//}
