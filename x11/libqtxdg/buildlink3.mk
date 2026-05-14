# $NetBSD: buildlink3.mk,v 1.39 2026/05/14 16:42:28 ryoon Exp $

BUILDLINK_TREE+=	libqtxdg

.if !defined(LIBQTXDG_BUILDLINK3_MK)
LIBQTXDG_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libqtxdg+=	libqtxdg>=4.1.0
BUILDLINK_ABI_DEPENDS.libqtxdg?=	libqtxdg>=4.4.0nb1
BUILDLINK_PKGSRCDIR.libqtxdg?=		../../x11/libqtxdg

.include "../../devel/glib2/buildlink3.mk"
.include "../../x11/qt6-qtbase/buildlink3.mk"
.include "../../graphics/qt6-qtsvg/buildlink3.mk"
.endif	# LIBQTXDG_BUILDLINK3_MK

BUILDLINK_TREE+=	-libqtxdg
