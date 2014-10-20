# $NetBSD: buildlink3.mk,v 1.25 2014/10/20 20:08:09 joerg Exp $

BUILDLINK_TREE+=	qwt

.if !defined(QWT_BUILDLINK3_MK)
QWT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.qwt+=	qwt>=5.2.0<6
BUILDLINK_ABI_DEPENDS.qwt+=	qwt>=5.2.2nb14<6
BUILDLINK_PKGSRCDIR.qwt?=	../../x11/qwt-qt4

.include "../../x11/qt4-libs/buildlink3.mk"
.endif	# QWT_BUILDLINK3_MK

BUILDLINK_TREE+=	-qwt
