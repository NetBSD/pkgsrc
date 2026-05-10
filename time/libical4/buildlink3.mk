# $NetBSD: buildlink3.mk,v 1.2 2026/05/10 17:55:23 wiz Exp $

BUILDLINK_TREE+=	libical4

.if !defined(LIBICAL4_BUILDLINK3_MK)
LIBICAL4_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libical4+=	libical4>=4.0.0
BUILDLINK_PKGSRCDIR.libical4?=		../../time/libical4

.include "../../textproc/icu/buildlink3.mk"
.endif	# LIBICAL4_BUILDLINK3_MK

BUILDLINK_TREE+=	-libical4
