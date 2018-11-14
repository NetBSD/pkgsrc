# $NetBSD: buildlink3.mk,v 1.17 2018/11/14 22:22:39 kleink Exp $

BUILDLINK_TREE+=	deforaos-locker

.if !defined(DEFORAOS_LOCKER_BUILDLINK3_MK)
DEFORAOS_LOCKER_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.deforaos-locker+=	deforaos-locker>=0.1.2
BUILDLINK_ABI_DEPENDS.deforaos-locker?=	deforaos-locker>=0.4.0nb8
BUILDLINK_PKGSRCDIR.deforaos-locker?=	../../x11/deforaos-locker

.include "../../x11/deforaos-libdesktop/buildlink3.mk"
.endif	# DEFORAOS_LOCKER_BUILDLINK3_MK

BUILDLINK_TREE+=	-deforaos-locker
