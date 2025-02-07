# $NetBSD: buildlink3.mk,v 1.1 2025/02/07 16:02:59 pho Exp $

BUILDLINK_TREE+=	libhubbub

.if !defined(LIBHUBBUB_BUILDLINK3_MK)
LIBHUBBUB_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libhubbub+=	libhubbub>=0.3.8
BUILDLINK_PKGSRCDIR.libhubbub?=		../../www/libhubbub

.include "../../textproc/libparserutils/buildlink3.mk"
.endif	# LIBHUBBUB_BUILDLINK3_MK

BUILDLINK_TREE+=	-libhubbub
