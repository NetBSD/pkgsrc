# $NetBSD: buildlink3.mk,v 1.1.1.1 2007/12/06 11:28:09 markd Exp $

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH}+
QT4_QDBUS_BUILDLINK3_MK:=	${QT4_QDBUS_BUILDLINK3_MK}+

.if ${BUILDLINK_DEPTH} == "+"
BUILDLINK_DEPENDS+=	qt4-qdbus
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nqt4-qdbus}
BUILDLINK_PACKAGES+=	qt4-qdbus
BUILDLINK_ORDER:=	${BUILDLINK_ORDER} ${BUILDLINK_DEPTH}qt4-qdbus

.if ${QT4_QDBUS_BUILDLINK3_MK} == "+"
BUILDLINK_API_DEPENDS.qt4-qdbus+=	qt4-qdbus>=4.3.2
BUILDLINK_PKGSRCDIR.qt4-qdbus?=	../../x11/qt4-qdbus
.endif	# QT4_QDBUS_BUILDLINK3_MK

.include "../../x11/qt4-libs/buildlink3.mk"
.include "../../sysutils/dbus/buildlink3.mk"

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH:S/+$//}
