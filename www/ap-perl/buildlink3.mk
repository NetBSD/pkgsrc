# $NetBSD: buildlink3.mk,v 1.15 2012/05/07 01:54:04 dholland Exp $

BUILDLINK_TREE+=	ap13-perl

.if !defined(AP_PERL_BUILDLINK3_MK)
AP_PERL_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.ap13-perl+=	ap13-perl>=1.29
BUILDLINK_ABI_DEPENDS.ap13-perl+=	ap13-perl>=1.29
BUILDLINK_PKGSRCDIR.ap13-perl?=	../../www/ap-perl

BUILDLINK_FILES.ap13-perl+=	lib/httpd/mod_perl.*
BUILDLINK_FILES.ap13-perl+=	\
	${PERL5_SUB_INSTALLVENDORARCH}/auto/Apache/include/*
BUILDLINK_FILES.ap13-perl+=	\
	${PERL5_SUB_INSTALLVENDORARCH}/auto/Apache/include/modules/perl/*

.include "../../www/apache/buildlink3.mk"
.endif # AP_PERL_BUILDLINK3_MK

BUILDLINK_TREE+=	-ap13-perl
