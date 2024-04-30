# $NetBSD: buildlink3.mk,v 1.2 2024/04/30 18:30:52 wiz Exp $

BUILDLINK_TREE+=	tree-sitter

.if !defined(TREE_SITTER_BUILDLINK3_MK)
TREE_SITTER_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.tree-sitter+=	tree-sitter>=0.20.0
BUILDLINK_ABI_DEPENDS.tree-sitter+=	tree-sitter>=0.22.5
BUILDLINK_PKGSRCDIR.tree-sitter?=	../../textproc/tree-sitter
.endif	# TREE_SITTER_BUILDLINK3_MK

BUILDLINK_TREE+=	-tree-sitter
