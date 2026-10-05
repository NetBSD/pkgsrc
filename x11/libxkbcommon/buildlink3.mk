# $NetBSD: buildlink3.mk,v 1.6 2026/10/05 18:44:39 tnn Exp $

BUILDLINK_TREE+=	libxkbcommon

.if !defined(LIBXKBCOMMON_BUILDLINK3_MK)
LIBXKBCOMMON_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libxkbcommon+=	libxkbcommon>=0.4.0
BUILDLINK_ABI_DEPENDS.libxkbcommon?=	libxkbcommon>=1.7.0
BUILDLINK_PKGSRCDIR.libxkbcommon?=	../../x11/libxkbcommon
.include "../../textproc/libxml2/buildlink3.mk"
.endif	# LIBXKBCOMMON_BUILDLINK3_MK

BUILDLINK_TREE+=	-libxkbcommon
