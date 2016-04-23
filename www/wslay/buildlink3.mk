# $NetBSD: buildlink3.mk,v 1.1 2016/04/23 18:32:09 adam Exp $

BUILDLINK_TREE+=	wslay

.if !defined(WSLAY_BUILDLINK3_MK)
WSLAY_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.wslay+=	wslay>=1.0.0
BUILDLINK_PKGSRCDIR.wslay?=	../../www/wslay

.endif	# WSLAY_BUILDLINK3_MK

BUILDLINK_TREE+=	-wslay
