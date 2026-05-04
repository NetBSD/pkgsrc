# $NetBSD: buildlink3.mk,v 1.22 2026/05/04 13:30:49 wiz Exp $

BUILDLINK_TREE+=	libical

.if !defined(LIBICAL_BUILDLINK3_MK)
LIBICAL_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libical+=	libical>=0.42
BUILDLINK_API_DEPENDS.libical+=	libical<4
BUILDLINK_ABI_DEPENDS.libical+=	libical>=3.0.20nb4
BUILDLINK_PKGSRCDIR.libical?=	../../time/libical

.include "../../textproc/icu/buildlink3.mk"
.endif # LIBICAL_BUILDLINK3_MK

BUILDLINK_TREE+=	-libical
