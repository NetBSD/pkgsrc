# $NetBSD: buildlink2.mk,v 1.2 2004/03/29 05:05:55 jlam Exp $

.if !defined(QT3_SCINTILLA_BUILDLINK2_MK)
QT3_SCINTILLA_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=		qt3-scintilla
BUILDLINK_PKGBASE.qt3-scintilla?=	qt3-qscintilla
BUILDLINK_DEPENDS.qt3-scintilla?=	qt3-qscintilla-[0-9]*
BUILDLINK_PKGSRCDIR.qt3-scintilla?=	../../x11/qt3-qscintilla

EVAL_PREFIX+=	BUILDLINK_PREFIX.qt3-scintilla=qt3-qscintilla
BUILDLINK_PREFIX.qt3-scintilla_DEFAULT=	${X11PREFIX}
BUILDLINK_FILES.qt3-scintilla+=	qt3/include/qextscintilla*.h
BUILDLINK_FILES.qt3-scintilla+=	qt3/lib/libqscintilla.*

.include "../../x11/qt3-libs/buildlink2.mk"

BUILDLINK_TARGETS+=	qt3-scintilla-buildlink

qt3-scintilla-buildlink: _BUILDLINK_USE

.endif	# QT3_SCINTILLA_BUILDLINK2_MK
