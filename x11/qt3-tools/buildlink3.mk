# $NetBSD: buildlink3.mk,v 1.14 2006/07/08 23:11:16 jlam Exp $

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH}+
QT3_TOOLS_BUILDLINK3_MK:=	${QT3_TOOLS_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	qt3-tools
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nqt3-tools}
BUILDLINK_PACKAGES+=	qt3-tools
BUILDLINK_ORDER:=	${BUILDLINK_ORDER} ${BUILDLINK_DEPTH}qt3-tools

.if !empty(QT3_TOOLS_BUILDLINK3_MK:M+)
BUILDLINK_API_DEPENDS.qt3-tools+=	qt3-tools>=3.1.2nb3
BUILDLINK_ABI_DEPENDS.qt3-tools+=	qt3-tools>=3.3.6nb1
BUILDLINK_PKGSRCDIR.qt3-tools?=	../../x11/qt3-tools
BUILDLINK_DEPMETHOD.qt3-tools?=	build
.endif	# QT3_TOOLS_BUILDLINK3_MK

.include "../../x11/qt3-libs/buildlink3.mk"

CONFIGURE_ENV+=		UIC="${QTDIR}/bin/uic"
MAKE_ENV+=		UIC="${QTDIR}/bin/uic"
CONFIGURE_ENV+=		QMAKE="${QTDIR}/bin/qmake"
MAKE_ENV+=		QMAKE="${QTDIR}/bin/qmake"

# the way the spec files are currently instealled via pkgsrc, they
# are all identical anyway, so just pick one and point to it.
# Without specifying QMAKESPEC, qmake can't figure it out on some
# platforms (solaris for example)
CONFIGURE_ENV+=		QMAKESPEC=${QTDIR}/mkspecs/netbsd-g++
MAKE_ENV+=		QMAKESPEC=${QTDIR}/mkspecs/netbsd-g++

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH:S/+$//}
