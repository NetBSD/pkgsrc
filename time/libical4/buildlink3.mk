# $NetBSD: buildlink3.mk,v 1.1 2026/05/03 14:16:56 wiz Exp $

BUILDLINK_TREE+=	libical

.if !defined(LIBICAL_BUILDLINK3_MK)
LIBICAL_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libical+=	libical>=4.0
BUILDLINK_PKGSRCDIR.libical?=	../../time/libical4

.include "../../textproc/icu/buildlink3.mk"
.endif # LIBICAL_BUILDLINK3_MK

BUILDLINK_TREE+=	-libical
