# $NetBSD: buildlink3.mk,v 1.3 2005/03/07 12:59:54 adam Exp $

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH}+
QT3_TOOLS_BUILDLINK3_MK:=	${QT3_TOOLS_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	qt3-tools
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nqt3-tools}
BUILDLINK_PACKAGES+=	qt3-tools

.if !empty(QT3_TOOLS_BUILDLINK3_MK:M+)
BUILDLINK_DEPENDS.qt3-tools+=	qt3-tools>=3.1.2nb3
BUILDLINK_RECOMMENDED.qt3-tools+=	qt3-tools>=3.3.3nb1
BUILDLINK_PKGSRCDIR.qt3-tools?=	../../x11/qt3-tools
.endif	# QT3_TOOLS_BUILDLINK3_MK

.include "../../x11/qt3-libs/buildlink3.mk"

CONFIGURE_ENV+=		UIC="${QTDIR}/bin/uic"
MAKE_ENV+=		UIC="${QTDIR}/bin/uic"
CONFIGURE_ENV+=		QMAKE="${QTDIR}/bin/qmake"
MAKE_ENV+=		QMAKE="${QTDIR}/bin/qmake"

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
