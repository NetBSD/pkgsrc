# $NetBSD: buildlink3.mk,v 1.1 2013/12/13 14:47:33 ryoon Exp $

BUILDLINK_TREE+=	libxkbcommon

.if !defined(LIBXKBCOMMON_BUILDLINK3_MK)
LIBXKBCOMMON_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libxkbcommon+=	libxkbcommon>=0.3.2
BUILDLINK_PKGSRCDIR.libxkbcommon?=	../../x11/libxkbcommon
.endif	# LIBXKBCOMMON_BUILDLINK3_MK

BUILDLINK_TREE+=	-libxkbcommon
