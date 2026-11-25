# $NetBSD: buildlink3.mk,v 1.17 2026/11/25 16:14:12 wiz Exp $

BUILDLINK_TREE+=	ap2-perl

.if !defined(AP2_PERL_BUILDLINK3_MK)
AP2_PERL_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.ap2-perl+=	ap24-perl>=2.0.1
BUILDLINK_ABI_DEPENDS.ap2-perl+=	ap24-perl>=2.0.12nb1
BUILDLINK_PKGSRCDIR.ap2-perl?=		../../www/ap2-perl

.include "../../mk/apache.mk"
.endif # AP2_PERL_BUILDLINK3_MK

BUILDLINK_TREE+=	-ap2-perl
