# $NetBSD: buildlink3.mk,v 1.22 2013/06/06 12:53:42 wiz Exp $

BUILDLINK_TREE+=	qt4-qscintilla

.if !defined(QT4_QSCINTILLA_BUILDLINK3_MK)
QT4_QSCINTILLA_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.qt4-qscintilla+=	qt4-qscintilla>=2.4.3
BUILDLINK_ABI_DEPENDS.qt4-qscintilla+=	qt4-qscintilla>=2.7.1nb3
BUILDLINK_PKGSRCDIR.qt4-qscintilla?=	../../x11/qt4-qscintilla

.include "../../x11/qt4-libs/buildlink3.mk"
.endif	# QT4_QSCINTILLA_BUILDLINK3_MK

BUILDLINK_TREE+=	-qt4-qscintilla
