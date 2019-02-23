# $NetBSD: buildlink3.mk,v 1.1 2019/02/23 08:40:45 wiz Exp $

BUILDLINK_TREE+=	xkbcomp

.if !defined(XKBCOMP_BUILDLINK3_MK)
XKBCOMP_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.xkbcomp+=	xkbcomp>=1.4.2
BUILDLINK_PKGSRCDIR.xkbcomp?=	../../x11/xkbcomp

.endif	# XKBCOMP_BUILDLINK3_MK

BUILDLINK_TREE+=	-xkbcomp
