# $NetBSD: buildlink3.mk,v 1.11 2009/08/26 19:56:48 sno Exp $

BUILDLINK_TREE+=	qt3-qscintilla

.if !defined(QT3_QSCINTILLA_BUILDLINK3_MK)
QT3_QSCINTILLA_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.qt3-qscintilla+=	qt3-qscintilla>=1.2
BUILDLINK_ABI_DEPENDS.qt3-qscintilla+=	qt3-qscintilla>=1.6nb4
BUILDLINK_PKGSRCDIR.qt3-qscintilla?=	../../x11/qt3-qscintilla

.include "../../x11/qt3-libs/buildlink3.mk"
.endif # QT3_QSCINTILLA_BUILDLINK3_MK

BUILDLINK_TREE+=	-qt3-qscintilla
