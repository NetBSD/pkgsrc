# $NetBSD: buildlink3.mk,v 1.5 2020/04/12 08:28:14 adam Exp $

BUILDLINK_TREE+=	qt5-qscintilla

.if !defined(QT5_QSCINTILLA_BUILDLINK3_MK)
QT5_QSCINTILLA_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.qt5-qscintilla+=	qt5-qscintilla>=2.11.2
BUILDLINK_ABI_DEPENDS.qt5-qscintilla+=	qt5-qscintilla>=2.11.2nb5
BUILDLINK_PKGSRCDIR.qt5-qscintilla?=	../../x11/qt5-qscintilla

.include "../../x11/qt5-qtbase/buildlink3.mk"
.endif	# QT5_QSCINTILLA_BUILDLINK3_MK

BUILDLINK_TREE+=	-qt5-qscintilla
