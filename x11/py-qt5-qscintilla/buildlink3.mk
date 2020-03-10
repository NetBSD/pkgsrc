# $NetBSD: buildlink3.mk,v 1.4 2020/03/10 22:09:12 wiz Exp $

BUILDLINK_TREE+=	py-qt5-qscintilla

.if !defined(PY_QT5_QSCINTILLA_BUILDLINK3_MK)
PY_QT5_QSCINTILLA_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.py-qt5-qscintilla+=	${PYPKGPREFIX}-qt5-qscintilla>=2.11.2
BUILDLINK_ABI_DEPENDS.py-qt5-qscintilla+=	${PYPKGPREFIX}-qt5-qscintilla>=2.11.2nb5
BUILDLINK_PKGSRCDIR.py-qt5-qscintilla?=		../../x11/py-qt5-qscintilla

.include "../../x11/py-sip/buildlink3.mk"
.include "../../x11/py-qt5/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../x11/qt5-qscintilla/buildlink3.mk"
.endif	# PY_QT5_QSCINTILLA_BUILDLINK3_MK

BUILDLINK_TREE+=	-py-qt5-qscintilla
