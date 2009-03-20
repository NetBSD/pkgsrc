# $NetBSD: buildlink3.mk,v 1.10 2009/03/20 19:25:33 joerg Exp $

BUILDLINK_TREE+=	xerces-c

.if !defined(XERCES_C_BUILDLINK3_MK)
XERCES_C_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.xerces-c+=	xerces-c>=2.7.0
BUILDLINK_ABI_DEPENDS.xerces-c?=	xerces-c>=2.7.0
BUILDLINK_PKGSRCDIR.xerces-c?=	../../textproc/xerces-c

.include "../../converters/libiconv/buildlink3.mk"
.endif # XERCES_C_BUILDLINK3_MK

BUILDLINK_TREE+=	-xerces-c
