# $NetBSD: buildlink3.mk,v 1.2 2009/03/20 19:25:34 joerg Exp $

BUILDLINK_TREE+=	libical

.if !defined(LIBICAL_BUILDLINK3_MK)
LIBICAL_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libical+=	libical>=0.42
BUILDLINK_PKGSRCDIR.libical?=	../../time/libical
.endif # LIBICAL_BUILDLINK3_MK

BUILDLINK_TREE+=	-libical
