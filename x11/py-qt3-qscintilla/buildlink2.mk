# $NetBSD: buildlink2.mk,v 1.1.1.1 2003/07/22 17:27:05 drochner Exp $

.if !defined(PY_QT3_SCINTILLA_BUILDLINK2_MK)
PY_QT3_SCINTILLA_BUILDLINK2_MK=	# defined

.include "../../lang/python/pyversion.mk"

BUILDLINK_PACKAGES+=		pyqt3scintilla
BUILDLINK_DEPENDS.pyqt3scintilla?=	${PYPKGPREFIX}-qt3-qscintilla-[0-9]*
BUILDLINK_PKGSRCDIR.pyqt3scintilla?=	../../x11/py-qt3-qscintilla

.include "../../x11/py-qt3-base/buildlink2.mk"

.endif	# PY_QT3_SCINTILLA_BUILDLINK2_MK
