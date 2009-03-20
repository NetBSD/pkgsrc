# $NetBSD: buildlink3.mk,v 1.12 2009/03/20 19:25:32 joerg Exp $

BUILDLINK_TREE+=	raptor

.if !defined(RAPTOR_BUILDLINK3_MK)
RAPTOR_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.raptor?=	raptor>=1.0.0
BUILDLINK_ABI_DEPENDS.raptor+=	raptor>=1.4.15nb1
BUILDLINK_PKGSRCDIR.raptor?=	../../textproc/raptor

.include "../../textproc/libxml2/buildlink3.mk"
.include "../../textproc/libxslt/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"
.endif # RAPTOR_BUILDLINK3_MK

BUILDLINK_TREE+=	-raptor
