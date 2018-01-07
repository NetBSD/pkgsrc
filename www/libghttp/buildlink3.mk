# $NetBSD: buildlink3.mk,v 1.9 2018/01/07 13:04:37 rillig Exp $

BUILDLINK_TREE+=	libghttp

.if !defined(LIBGHTTP_BUILDLINK3_MK)
LIBGHTTP_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libghttp+=	libghttp>=1.0.9
BUILDLINK_ABI_DEPENDS.libghttp+=	libghttp>=1.0.9nb1
BUILDLINK_PKGSRCDIR.libghttp?=		../../www/libghttp
.endif # LIBGHTTP_BUILDLINK3_MK

BUILDLINK_TREE+=	-libghttp
