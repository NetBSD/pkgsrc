# $NetBSD: buildlink3.mk,v 1.1 2016/06/17 16:39:55 prlw1 Exp $

BUILDLINK_TREE+=	libecap

.if !defined(LIBECAP_BUILDLINK3_MK)
LIBECAP_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libecap+=	libecap>=1.0.1
BUILDLINK_PKGSRCDIR.libecap?=	../../www/libecap
.endif	# LIBECAP_BUILDLINK3_MK

BUILDLINK_TREE+=	-libecap
