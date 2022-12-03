# $NetBSD: buildlink3.mk,v 1.1 2022/12/03 16:01:02 adam Exp $

BUILDLINK_TREE+=	nghttp3

.if !defined(NGHTTP3_BUILDLINK3_MK)
NGHTTP3_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.nghttp3+=	nghttp3>=0.7.1
BUILDLINK_PKGSRCDIR.nghttp3?=	../../www/nghttp3
.endif	# NGHTTP3_BUILDLINK3_MK

BUILDLINK_TREE+=	-nghttp3
