# $NetBSD: buildlink3.mk,v 1.3 2011/08/06 22:21:58 ryoon Exp $

BUILDLINK_TREE+=	libunique

.if !defined(LIBUNIQUE_BUILDLINK3_MK)
LIBUNIQUE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libunique+=	libunique3>=3.0.2
BUILDLINK_PKGSRCDIR.libunique?=	../../x11/libunique3

.endif	# LIBUNIQUE_BUILDLINK3_MK

BUILDLINK_TREE+=	-libunique
