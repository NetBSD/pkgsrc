# $NetBSD: buildlink3.mk,v 1.7 2011/04/22 13:42:36 obache Exp $

BUILDLINK_TREE+=	qt4-qscintilla

.if !defined(QT4_QSCINTILLA_BUILDLINK3_MK)
QT4_QSCINTILLA_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.qt4-qscintilla+=	qt4-qscintilla>=2.4.3
BUILDLINK_ABI_DEPENDS.qt4-qscintilla?=	qt4-qscintilla>=2.5nb1
BUILDLINK_PKGSRCDIR.qt4-qscintilla?=	../../x11/qt4-qscintilla

.include "../../x11/qt4-libs/buildlink3.mk"
.endif	# QT4_QSCINTILLA_BUILDLINK3_MK

BUILDLINK_TREE+=	-qt4-qscintilla
