# $NetBSD: buildlink3.mk,v 1.5 2018/12/09 18:52:09 adam Exp $

BUILDLINK_TREE+=	libical

.if !defined(LIBICAL_BUILDLINK3_MK)
LIBICAL_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libical+=	libical>=0.42
BUILDLINK_ABI_DEPENDS.libical+=	libical>=3.0.3nb3
BUILDLINK_PKGSRCDIR.libical?=	../../time/libical

.include "../../textproc/icu/buildlink3.mk"
.endif # LIBICAL_BUILDLINK3_MK

BUILDLINK_TREE+=	-libical
