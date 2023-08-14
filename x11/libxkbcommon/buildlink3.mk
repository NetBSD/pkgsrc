# $NetBSD: buildlink3.mk,v 1.4 2023/08/14 05:25:34 wiz Exp $

BUILDLINK_TREE+=	libxkbcommon

.if !defined(LIBXKBCOMMON_BUILDLINK3_MK)
LIBXKBCOMMON_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libxkbcommon+=	libxkbcommon>=0.4.0
BUILDLINK_ABI_DEPENDS.libxkbcommon?=	libxkbcommon>=1.5.0nb2
BUILDLINK_PKGSRCDIR.libxkbcommon?=	../../x11/libxkbcommon
.endif	# LIBXKBCOMMON_BUILDLINK3_MK

BUILDLINK_TREE+=	-libxkbcommon
