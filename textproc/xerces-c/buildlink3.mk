# $NetBSD: buildlink3.mk,v 1.11 2009/05/10 11:24:26 hasso Exp $

BUILDLINK_TREE+=	xerces-c

.if !defined(XERCES_C_BUILDLINK3_MK)
XERCES_C_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.xerces-c+=	xerces-c>=2.8.0
BUILDLINK_ABI_DEPENDS.xerces-c?=	xerces-c>=2.8.0
BUILDLINK_PKGSRCDIR.xerces-c?=	../../textproc/xerces-c

.include "../../converters/libiconv/buildlink3.mk"
.endif # XERCES_C_BUILDLINK3_MK

BUILDLINK_TREE+=	-xerces-c
