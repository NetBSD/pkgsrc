# $NetBSD: buildlink3.mk,v 1.8 2020/11/05 09:07:19 ryoon Exp $

BUILDLINK_TREE+=	qt5-qscintilla

.if !defined(QT5_QSCINTILLA_BUILDLINK3_MK)
QT5_QSCINTILLA_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.qt5-qscintilla+=	qt5-qscintilla>=2.11.2
BUILDLINK_ABI_DEPENDS.qt5-qscintilla+=	qt5-qscintilla>=2.11.5nb2
BUILDLINK_PKGSRCDIR.qt5-qscintilla?=	../../x11/qt5-qscintilla

.include "../../mk/bsd.fast.prefs.mk"

.if ${OPSYS} == "Darwin"
.include "../../x11/qt5-qtmacextras/buildlink3.mk"
.endif
.include "../../x11/qt5-qtbase/buildlink3.mk"
.endif	# QT5_QSCINTILLA_BUILDLINK3_MK

BUILDLINK_TREE+=	-qt5-qscintilla
