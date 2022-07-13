# $NetBSD: buildlink3.mk,v 1.1 2022/07/13 20:37:53 wiz Exp $

BUILDLINK_TREE+=	libxcvt

.if !defined(LIBXCVT_BUILDLINK3_MK)
LIBXCVT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libxcvt+=	libxcvt>=0.1.1
BUILDLINK_PKGSRCDIR.libxcvt?=	../../x11/libxcvt
.endif	# LIBXCVT_BUILDLINK3_MK

BUILDLINK_TREE+=	-libxcvt
