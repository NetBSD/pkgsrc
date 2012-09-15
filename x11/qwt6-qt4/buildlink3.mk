# $NetBSD: buildlink3.mk,v 1.3 2012/09/15 10:07:14 obache Exp $

BUILDLINK_TREE+=	qwt

.if !defined(QWT_BUILDLINK3_MK)
QWT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.qwt+=	qwt>=6.0.1
BUILDLINK_ABI_DEPENDS.qwt+=	qwt>=6.0.1nb3
BUILDLINK_PKGSRCDIR.qwt?=	../../x11/qwt6-qt4

.include "../../x11/qt4-libs/buildlink3.mk"
.endif	# QWT_BUILDLINK3_MK

BUILDLINK_TREE+=	-qwt
