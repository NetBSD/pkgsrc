# $NetBSD: buildlink3.mk,v 1.1 2020/11/02 12:32:20 nia Exp $

BUILDLINK_TREE+=	libwebsockets

.if !defined(LIBWEBSOCKETS_BUILDLINK3_MK)
LIBWEBSOCKETS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libwebsockets+=	libwebsockets>=1.7.2
BUILDLINK_PKGSRCDIR.libwebsockets?=	../../www/libwebsockets

.include "../../security/openssl/buildlink3.mk"
.endif	# LIBWEBSOCKETS_BUILDLINK3_MK

BUILDLINK_TREE+=	-libwebsockets
