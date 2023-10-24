# $NetBSD: buildlink3.mk,v 1.3 2023/10/24 22:11:29 wiz Exp $

BUILDLINK_TREE+=	libwebsockets

.if !defined(LIBWEBSOCKETS_BUILDLINK3_MK)
LIBWEBSOCKETS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libwebsockets+=	libwebsockets>=1.7.2
BUILDLINK_ABI_DEPENDS.libwebsockets?=	libwebsockets>=4.3.0nb1
BUILDLINK_PKGSRCDIR.libwebsockets?=	../../www/libwebsockets

.include "../../security/openssl/buildlink3.mk"
.endif	# LIBWEBSOCKETS_BUILDLINK3_MK

BUILDLINK_TREE+=	-libwebsockets
