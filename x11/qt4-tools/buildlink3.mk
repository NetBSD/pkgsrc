# $NetBSD: buildlink3.mk,v 1.38 2020/01/18 21:48:35 jperkin Exp $

BUILDLINK_TREE+=	qt4-tools

.if !defined(QT4_TOOLS_BUILDLINK3_MK)
QT4_TOOLS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.qt4-tools+=	qt4-tools>=4.1.0
BUILDLINK_ABI_DEPENDS.qt4-tools+=	qt4-tools>=4.8.7nb4
BUILDLINK_PKGSRCDIR.qt4-tools?=		../../x11/qt4-tools
BUILDLINK_DEPMETHOD.qt4-tools?=		build

.include "../../x11/qt4-libs/buildlink3.mk"

CONFIGURE_ENV+=		UIC="${QTDIR}/bin/uic"
MAKE_ENV+=		UIC="${QTDIR}/bin/uic"
CONFIGURE_ENV+=		QMAKE="${QTDIR}/bin/qmake"
MAKE_ENV+=		QMAKE="${QTDIR}/bin/qmake"
CMAKE_ARGS+=		-DQT_UIC_EXECUTABLE=${QTDIR}/bin/uic
CMAKE_ARGS+=		-DQT_QMAKE_EXECUTABLE=${QTDIR}/bin/qmake

# the way the spec files are currently instealled via pkgsrc, they
# are all identical anyway, so just pick one and point to it.
# Without specifying QMAKESPEC, qmake can't figure it out on some
# platforms (solaris for example)
CONFIGURE_ENV+=		QMAKESPEC=${QTDIR}/mkspecs/netbsd-g++
MAKE_ENV+=		QMAKESPEC=${QTDIR}/mkspecs/netbsd-g++
.endif # QT4_TOOLS_BUILDLINK3_MK

BUILDLINK_TREE+=	-qt4-tools
