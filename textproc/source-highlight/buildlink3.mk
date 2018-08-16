# $NetBSD: buildlink3.mk,v 1.9 2018/08/16 18:54:32 adam Exp $

BUILDLINK_TREE+=	source-highlight

.if !defined(SOURCE_HIGHLIGHT_BUILDLINK3_MK)
SOURCE_HIGHLIGHT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.source-highlight+=	source-highlight>=3.1.7nb2
BUILDLINK_ABI_DEPENDS.source-highlight?=	source-highlight>=3.1.8nb7
BUILDLINK_PKGSRCDIR.source-highlight?=		../../textproc/source-highlight

.include "../../devel/boost-libs/buildlink3.mk"
.endif	# SOURCE_HIGHLIGHT_BUILDLINK3_MK

BUILDLINK_TREE+=	-source-highlight
