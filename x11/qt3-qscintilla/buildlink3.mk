# $NetBSD: buildlink3.mk,v 1.22 2015/04/25 14:25:16 tnn Exp $

BUILDLINK_TREE+=	qt3-qscintilla

.if !defined(QT3_QSCINTILLA_BUILDLINK3_MK)
QT3_QSCINTILLA_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.qt3-qscintilla+=	qt3-qscintilla>=1.2
BUILDLINK_ABI_DEPENDS.qt3-qscintilla+=	qt3-qscintilla>=1.6nb15
BUILDLINK_PKGSRCDIR.qt3-qscintilla?=	../../x11/qt3-qscintilla

.include "../../x11/qt3-libs/buildlink3.mk"
.endif # QT3_QSCINTILLA_BUILDLINK3_MK

BUILDLINK_TREE+=	-qt3-qscintilla
