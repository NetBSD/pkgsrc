# $NetBSD: buildlink3.mk,v 1.26 2013/10/09 17:39:01 wiz Exp $

BUILDLINK_TREE+=	qt3-tools

.if !defined(QT3_TOOLS_BUILDLINK3_MK)
QT3_TOOLS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.qt3-tools+=	qt3-tools>=3.1.2nb3
BUILDLINK_ABI_DEPENDS.qt3-tools+=	qt3-tools>=3.3.8nb15
BUILDLINK_PKGSRCDIR.qt3-tools?=	../../x11/qt3-tools
BUILDLINK_DEPMETHOD.qt3-tools?=	build

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
.endif # QT3_TOOLS_BUILDLINK3_MK

BUILDLINK_TREE+=	-qt3-tools
