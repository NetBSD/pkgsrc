# $NetBSD: buildlink3.mk,v 1.12 2012/05/07 01:54:13 dholland Exp $

BUILDLINK_TREE+=	qt4-qscintilla

.if !defined(QT4_QSCINTILLA_BUILDLINK3_MK)
QT4_QSCINTILLA_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.qt4-qscintilla+=	qt4-qscintilla>=2.4.3
BUILDLINK_ABI_DEPENDS.qt4-qscintilla+=	qt4-qscintilla>=2.6.1nb1
BUILDLINK_PKGSRCDIR.qt4-qscintilla?=	../../x11/qt4-qscintilla

.include "../../x11/qt4-libs/buildlink3.mk"
.endif	# QT4_QSCINTILLA_BUILDLINK3_MK

BUILDLINK_TREE+=	-qt4-qscintilla
