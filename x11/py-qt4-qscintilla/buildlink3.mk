# $NetBSD: buildlink3.mk,v 1.1.1.1 2010/05/08 15:34:02 drochner Exp $

BUILDLINK_TREE+=	py26-qt4-qscintilla

.if !defined(PY26_QT4_QSCINTILLA_BUILDLINK3_MK)
PY26_QT4_QSCINTILLA_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.py26-qt4-qscintilla+=	${PYPKGPREFIX}-qt4-qscintilla>=2.4.3
BUILDLINK_PKGSRCDIR.py26-qt4-qscintilla?=	../../x11/py-qt4-qscintilla

.include "../../x11/py-sip/buildlink3.mk"
.include "../../x11/py-qt4/buildlink3.mk"
.include "../../x11/qt4-qscintilla/buildlink3.mk"
.include "../../x11/qt4-libs/buildlink3.mk"
.endif	# PY26_QT4_QSCINTILLA_BUILDLINK3_MK

BUILDLINK_TREE+=	-py26-qt4-qscintilla
