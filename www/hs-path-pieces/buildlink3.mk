# $NetBSD: buildlink3.mk,v 1.5 2025/03/05 03:40:11 pho Exp $

BUILDLINK_TREE+=	hs-path-pieces

.if !defined(HS_PATH_PIECES_BUILDLINK3_MK)
HS_PATH_PIECES_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-path-pieces+=	hs-path-pieces>=0.2.1
BUILDLINK_ABI_DEPENDS.hs-path-pieces+=	hs-path-pieces>=0.2.1nb4
BUILDLINK_PKGSRCDIR.hs-path-pieces?=	../../www/hs-path-pieces
.endif	# HS_PATH_PIECES_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-path-pieces
