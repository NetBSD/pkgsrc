# $NetBSD: buildlink3.mk,v 1.9 2006/06/02 18:27:59 joerg Exp $

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
AP_PERL_BUILDLINK3_MK:=	${AP_PERL_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	ap13-perl
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nap-perl}
BUILDLINK_PACKAGES+=	ap13-perl

.if !empty(AP_PERL_BUILDLINK3_MK:M+)
BUILDLINK_API_DEPENDS.ap-perl+=	ap13-perl>=1.29nb3
BUILDLINK_ABI_DEPENDS.ap-perl?=	ap13-perl>=1.29nb5
BUILDLINK_PKGSRCDIR.ap-perl?=	../../www/ap-perl

BUILDLINK_FILES.ap-perl+=	lib/httpd/mod_perl.*
BUILDLINK_FILES.ap-perl+=	\
	${PERL5_SUB_INSTALLVENDORARCH}/auto/Apache/include/*
BUILDLINK_FILES.ap-perl+=	\
	${PERL5_SUB_INSTALLVENDORARCH}/auto/Apache/include/modules/perl/*
.endif	# AP_PERL_BUILDLINK3_MK

.include "../../www/apache/buildlink3.mk"

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH:S/+$//}
