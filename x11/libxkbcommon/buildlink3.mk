# $NetBSD: buildlink3.mk,v 1.7 2026/11/11 11:56:37 wiz Exp $

BUILDLINK_TREE+=	libxkbcommon

.if !defined(LIBXKBCOMMON_BUILDLINK3_MK)
LIBXKBCOMMON_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libxkbcommon+=	libxkbcommon>=0.4.0
BUILDLINK_ABI_DEPENDS.libxkbcommon?=	libxkbcommon>=1.13.2nb1
BUILDLINK_PKGSRCDIR.libxkbcommon?=	../../x11/libxkbcommon
.include "../../textproc/libxml2/buildlink3.mk"
.endif	# LIBXKBCOMMON_BUILDLINK3_MK

BUILDLINK_TREE+=	-libxkbcommon
