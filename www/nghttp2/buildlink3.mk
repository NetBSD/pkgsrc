# $NetBSD: buildlink3.mk,v 1.25 2025/04/17 21:52:50 wiz Exp $

BUILDLINK_TREE+=	nghttp2

.if !defined(NGHTTP2_BUILDLINK3_MK)
NGHTTP2_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.nghttp2+=	nghttp2>=1.0.0
BUILDLINK_ABI_DEPENDS.nghttp2+=	nghttp2>=1.65.0nb1
BUILDLINK_PKGSRCDIR.nghttp2?=	../../www/nghttp2

.include "../../textproc/libxml2/buildlink3.mk"

.endif # NGHTTP2_BUILDLINK3_MK

BUILDLINK_TREE+=	-nghttp2
