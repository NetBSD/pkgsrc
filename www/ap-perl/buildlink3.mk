# $NetBSD: buildlink3.mk,v 1.1 2004/02/11 05:59:54 xtraeme Exp $
#
# This Makefile fragment is included by packages that use ap-perl.
#
# This file was created automatically using createbuildlink-3.1.
#

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
AP_PERL_BUILDLINK3_MK:=	${AP_PERL_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	ap-perl
.endif

.if !empty(AP_PERL_BUILDLINK3_MK:M+)
BUILDLINK_PACKAGES+=			ap-perl
BUILDLINK_DEPENDS.ap-perl+=		ap-perl>=1.25nb1
BUILDLINK_PKGSRCDIR.ap-perl?=		../../www/ap-perl

BUILDLINK_FILES.ap-perl+=	lib/httpd/mod_perl.*
BUILDLINK_FILES.ap-perl+=	\
	${PERL5_SITEARCH:S/^${BUILDLINK_PREFIX.perl}\///}/auto/Apache/include/*
BUILDLINK_FILES.ap-perl+=	\
	${PERL5_SITEARCH:S/^${BUILDLINK_PREFIX.perl}\///}/auto/Apache/include/modules/perl/*

.include "../../www/apache/buildlink3.mk"

.endif # AP_PERL_BUILDLINK3_MK

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
