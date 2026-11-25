# $NetBSD: buildlink3.mk,v 1.18 2026/11/25 17:16:34 wiz Exp $

BUILDLINK_TREE+=	ap2-perl

.if !defined(AP2_PERL_BUILDLINK3_MK)
AP2_PERL_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.ap2-perl+=	ap24-perl>=2.0.1
BUILDLINK_ABI_DEPENDS.ap2-perl+=	ap24-perl>=2.0.12nb1
BUILDLINK_PKGSRCDIR.ap2-perl?=		../../www/ap2-perl

.include "../../www/apache24/buildlink3.mk"
.endif # AP2_PERL_BUILDLINK3_MK

BUILDLINK_TREE+=	-ap2-perl
