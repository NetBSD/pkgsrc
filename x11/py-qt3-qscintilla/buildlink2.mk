# $NetBSD: buildlink2.mk,v 1.2 2003/08/19 04:35:05 jmc Exp $

.if !defined(PY_QT3_SCINTILLA_BUILDLINK2_MK)
PY_QT3_SCINTILLA_BUILDLINK2_MK=	# defined

.include "../../lang/python/pyversion.mk"

BUILDLINK_PACKAGES+=		pyqt3scintilla
BUILDLINK_DEPENDS.pyqt3scintilla?=	${PYPKGPREFIX}-qt3-qscintilla>=3.7nb1
BUILDLINK_PKGSRCDIR.pyqt3scintilla?=	../../x11/py-qt3-qscintilla

.include "../../x11/py-qt3-base/buildlink2.mk"

.endif	# PY_QT3_SCINTILLA_BUILDLINK2_MK
