# $NetBSD: buildlink3.mk,v 1.2 2022/07/03 10:46:54 wiz Exp $

BUILDLINK_TREE+=	libwebsockets

.if !defined(LIBWEBSOCKETS_BUILDLINK3_MK)
LIBWEBSOCKETS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libwebsockets+=	libwebsockets>=1.7.2
BUILDLINK_ABI_DEPENDS.libwebsockets?=	libwebsockets>=4.3.0
BUILDLINK_PKGSRCDIR.libwebsockets?=	../../www/libwebsockets

.include "../../security/openssl/buildlink3.mk"
.endif	# LIBWEBSOCKETS_BUILDLINK3_MK

BUILDLINK_TREE+=	-libwebsockets
