# $NetBSD: buildlink3.mk,v 1.19 2020/03/08 16:48:20 wiz Exp $

BUILDLINK_TREE+=	deforaos-locker

.if !defined(DEFORAOS_LOCKER_BUILDLINK3_MK)
DEFORAOS_LOCKER_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.deforaos-locker+=	deforaos-locker>=0.1.2
BUILDLINK_ABI_DEPENDS.deforaos-locker?=	deforaos-locker>=0.4.1nb1
BUILDLINK_PKGSRCDIR.deforaos-locker?=	../../x11/deforaos-locker

.include "../../x11/deforaos-libdesktop/buildlink3.mk"
.endif	# DEFORAOS_LOCKER_BUILDLINK3_MK

BUILDLINK_TREE+=	-deforaos-locker
