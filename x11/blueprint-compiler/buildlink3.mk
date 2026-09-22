# $NetBSD: buildlink3.mk,v 1.1 2026/09/22 09:04:53 ryoon Exp $

BUILDLINK_TREE+=	blueprint-compiler

.if !defined(BLUEPRINT_COMPILER_BUILDLINK3_MK)
BLUEPRINT_COMPILER_BUILDLINK3_MK:=

BUILDLINK_DEPMETHOD.blueprint-compiler?=	build

BUILDLINK_API_DEPENDS.blueprint-compiler+=	blueprint-compiler>=0.22.2
BUILDLINK_PKGSRCDIR.blueprint-compiler?=	../../x11/blueprint-compiler
.endif	# BLUEPRINT_COMPILER_BUILDLINK3_MK

BUILDLINK_TREE+=	-blueprint-compiler
