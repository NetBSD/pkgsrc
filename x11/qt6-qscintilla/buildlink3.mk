# $NetBSD: buildlink3.mk,v 1.8 2025/10/23 20:40:17 wiz Exp $

BUILDLINK_TREE+=	qt6-qscintilla

.if !defined(QT6_QSCINTILLA_BUILDLINK3_MK)
QT6_QSCINTILLA_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.qt6-qscintilla+=	qt6-qscintilla>=2.14.1
BUILDLINK_ABI_DEPENDS.qt6-qscintilla+=	qt6-qscintilla>=2.14.1nb8
BUILDLINK_PKGSRCDIR.qt6-qscintilla?=	../../x11/qt6-qscintilla

.include "../../x11/qt6-qtbase/buildlink3.mk"
.endif	# QT6_QSCINTILLA_BUILDLINK3_MK

BUILDLINK_TREE+=	-qt6-qscintilla
