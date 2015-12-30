# $NetBSD: buildlink3.mk,v 1.1 2015/12/30 17:40:29 adam Exp $

BUILDLINK_TREE+=	libsass

.if !defined(LIBSASS_BUILDLINK3_MK)
LIBSASS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libsass+=	libsass>=3.3.2
BUILDLINK_PKGSRCDIR.libsass?=	../../www/libsass
.endif	# LIBSASS_BUILDLINK3_MK

BUILDLINK_TREE+=	-libsass
