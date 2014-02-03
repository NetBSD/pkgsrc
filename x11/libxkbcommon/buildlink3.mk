# $NetBSD: buildlink3.mk,v 1.3 2014/02/03 16:17:12 ryoon Exp $

BUILDLINK_TREE+=	libxkbcommon

.if !defined(LIBXKBCOMMON_BUILDLINK3_MK)
LIBXKBCOMMON_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libxkbcommon+=	libxkbcommon>=0.4.0
BUILDLINK_ABI_DEPENDS.libxkbcommon?=	libxkbcommon>=0.4.0nb1
BUILDLINK_PKGSRCDIR.libxkbcommon?=	../../x11/libxkbcommon
.endif	# LIBXKBCOMMON_BUILDLINK3_MK

BUILDLINK_TREE+=	-libxkbcommon
