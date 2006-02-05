# $NetBSD: buildlink3.mk,v 1.4 2006/02/05 23:11:42 joerg Exp $

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH}+
QT3_QSCINTILLA_BUILDLINK3_MK:=	${QT3_QSCINTILLA_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	qt3-qscintilla
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nqt3-qscintilla}
BUILDLINK_PACKAGES+=	qt3-qscintilla

.if !empty(QT3_QSCINTILLA_BUILDLINK3_MK:M+)
BUILDLINK_DEPENDS.qt3-qscintilla+=	qt3-qscintilla>=1.2
BUILDLINK_RECOMMENDED.qt3-qscintilla+=	qt3-qscintilla>=1.6nb2
BUILDLINK_PKGSRCDIR.qt3-qscintilla?=	../../x11/qt3-qscintilla
.endif	# QT3_QSCINTILLA_BUILDLINK3_MK

.include "../../x11/qt3-libs/buildlink3.mk"

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
