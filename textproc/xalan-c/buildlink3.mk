# $NetBSD: buildlink3.mk,v 1.11 2009/03/25 22:37:15 he Exp $

BUILDLINK_TREE+=	xalan-c

.if !defined(XALAN_C_BUILDLINK3_MK)
XALAN_C_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.xalan-c+=	xalan-c>=1.6nb3
BUILDLINK_ABI_DEPENDS.xalan-c?=	xalan-c>=1.10nb1
BUILDLINK_PKGSRCDIR.xalan-c?=	../../textproc/xalan-c

.include "../../textproc/icu/buildlink3.mk"
.include "../../textproc/xerces-c/buildlink3.mk"
.endif # XALAN_C_BUILDLINK3_MK

BUILDLINK_TREE+=	-xalan-c
