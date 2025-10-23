# $NetBSD: buildlink3.mk,v 1.40 2025/10/23 20:39:52 wiz Exp $
#

BUILDLINK_TREE+=	deforaos-libdesktop

.if !defined(DEFORAOS_LIBDESKTOP_BUILDLINK3_MK)
DEFORAOS_LIBDESKTOP_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.deforaos-libdesktop+=	deforaos-libdesktop>=0.4.0
BUILDLINK_ABI_DEPENDS.deforaos-libdesktop?=	deforaos-libdesktop>=0.4.1nb15
BUILDLINK_PKGSRCDIR.deforaos-libdesktop?=	../../x11/deforaos-libdesktop

.include "../../devel/deforaos-libsystem/buildlink3.mk"
.include "../../x11/gtk3/buildlink3.mk"
.endif	# DEFORAOS_LIBDESKTOP_BUILDLINK3_MK

BUILDLINK_TREE+=	-deforaos-libdesktop
