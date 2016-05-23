# $NetBSD: buildlink3.mk,v 1.1 2016/05/23 08:08:09 youri Exp $

BUILDLINK_TREE+=	lxappearance

.if !defined(LXAPPEARANCE_BUILDLINK3_MK)
LXAPPEARANCE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.lxappearance+=	lxappearance>=0.6.2
BUILDLINK_PKGSRCDIR.lxappearance?=	../../x11/lxappearance

.endif	# LXAPPEARANCE_BUILDLINK3_MK

BUILDLINK_TREE+=	-lxappearance
