# $NetBSD: buildlink3.mk,v 1.12 2011/04/04 09:24:14 adam Exp $

BUILDLINK_TREE+=	ap2-perl

.if !defined(AP2_PERL_BUILDLINK3_MK)
AP2_PERL_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.ap2-perl+=	${APACHE_PKG_PREFIX}-perl>=2.0.1
BUILDLINK_ABI_DEPENDS.ap2-perl+=	${APACHE_PKG_PREFIX}-perl>=2.0.3
BUILDLINK_PKGSRCDIR.ap2-perl?=		../../www/ap2-perl

.include "../../mk/apache.mk"
.endif # AP2_PERL_BUILDLINK3_MK

BUILDLINK_TREE+=	-ap2-perl
