# $NetBSD: buildlink3.mk,v 1.5 2024/04/06 08:04:45 wiz Exp $

BUILDLINK_TREE+=	libxkbcommon

.if !defined(LIBXKBCOMMON_BUILDLINK3_MK)
LIBXKBCOMMON_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libxkbcommon+=	libxkbcommon>=0.4.0
BUILDLINK_ABI_DEPENDS.libxkbcommon?=	libxkbcommon>=1.7.0
BUILDLINK_PKGSRCDIR.libxkbcommon?=	../../x11/libxkbcommon
.endif	# LIBXKBCOMMON_BUILDLINK3_MK

BUILDLINK_TREE+=	-libxkbcommon
