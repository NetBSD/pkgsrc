# $NetBSD: buildlink3.mk,v 1.9 2021/04/21 11:40:50 adam Exp $

BUILDLINK_TREE+=	py-qt5-qscintilla

.if !defined(PY_QT5_QSCINTILLA_BUILDLINK3_MK)
PY_QT5_QSCINTILLA_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.py-qt5-qscintilla+=	${PYPKGPREFIX}-qt5-qscintilla>=2.11.2
BUILDLINK_ABI_DEPENDS.py-qt5-qscintilla+=	${PYPKGPREFIX}-qt5-qscintilla>=2.11.5nb3
BUILDLINK_PKGSRCDIR.py-qt5-qscintilla?=		../../x11/py-qt5-qscintilla

.include "../../x11/py-sip/buildlink3.mk"
.include "../../x11/py-qt5/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../x11/qt5-qscintilla/buildlink3.mk"
.endif	# PY_QT5_QSCINTILLA_BUILDLINK3_MK

BUILDLINK_TREE+=	-py-qt5-qscintilla
