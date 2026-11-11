# $NetBSD: buildlink3.mk,v 1.3 2026/11/11 11:56:05 wiz Exp $

BUILDLINK_TREE+=	libical4

.if !defined(LIBICAL4_BUILDLINK3_MK)
LIBICAL4_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libical4+=	libical4>=4.0.0
BUILDLINK_ABI_DEPENDS.libical4?=		libical4>=4.0.5nb4
BUILDLINK_PKGSRCDIR.libical4?=		../../time/libical4

.include "../../textproc/icu/buildlink3.mk"
.endif	# LIBICAL4_BUILDLINK3_MK

BUILDLINK_TREE+=	-libical4
