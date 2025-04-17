# $NetBSD: buildlink3.mk,v 1.6 2025/04/17 21:53:09 wiz Exp $

BUILDLINK_TREE+=	qt6-qscintilla

.if !defined(QT6_QSCINTILLA_BUILDLINK3_MK)
QT6_QSCINTILLA_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.qt6-qscintilla+=	qt6-qscintilla>=2.14.1
BUILDLINK_ABI_DEPENDS.qt6-qscintilla+=	qt6-qscintilla>=2.14.1nb6
BUILDLINK_PKGSRCDIR.qt6-qscintilla?=	../../x11/qt6-qscintilla

.include "../../x11/qt6-qtbase/buildlink3.mk"
.endif	# QT6_QSCINTILLA_BUILDLINK3_MK

BUILDLINK_TREE+=	-qt6-qscintilla
