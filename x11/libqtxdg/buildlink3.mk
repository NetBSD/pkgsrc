# $NetBSD: buildlink3.mk,v 1.29 2024/11/01 00:54:20 wiz Exp $

BUILDLINK_TREE+=	libqtxdg

.if !defined(LIBQTXDG_BUILDLINK3_MK)
LIBQTXDG_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libqtxdg+=	libqtxdg>=4.0.0
BUILDLINK_ABI_DEPENDS.libqtxdg?=		libqtxdg>=4.0.1nb1
BUILDLINK_PKGSRCDIR.libqtxdg?=		../../x11/libqtxdg

.include "../../devel/glib2/buildlink3.mk"
.include "../../x11/qt6-qtbase/buildlink3.mk"
.include "../../graphics/qt6-qtsvg/buildlink3.mk"
.endif	# LIBQTXDG_BUILDLINK3_MK

BUILDLINK_TREE+=	-libqtxdg
