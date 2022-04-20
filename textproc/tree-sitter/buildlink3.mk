# $NetBSD: buildlink3.mk,v 1.1 2022/04/20 17:21:28 nia Exp $

BUILDLINK_TREE+=	tree-sitter

.if !defined(TREE_SITTER_BUILDLINK3_MK)
TREE_SITTER_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.tree-sitter+=	tree-sitter>=0.20.0
BUILDLINK_PKGSRCDIR.tree-sitter?=	../../textproc/tree-sitter
.endif	# TREE_SITTER_BUILDLINK3_MK

BUILDLINK_TREE+=	-tree-sitter
