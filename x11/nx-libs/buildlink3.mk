# $NetBSD: buildlink3.mk,v 1.1 2021/02/24 18:38:42 hauke Exp $

BUILDLINK_TREE+=	nx-libs

.if !defined(NX_LIBS_BUILDLINK3_MK)
NX_LIBS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.nx-libs+=		nx-libs>=3.5.99
BUILDLINK_PKGSRCDIR.nx-libs?=		../../hauke/nx-libs
.endif	# NX_LIBS_BUILDLINK3_MK

BUILDLINK_TREE+=	-nx-libs
