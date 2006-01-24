# $NetBSD: buildlink3.mk,v 1.5 2006/01/24 07:32:42 wiz Exp $

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
AP_PERL_BUILDLINK3_MK:=	${AP_PERL_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	ap-perl
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nap-perl}
BUILDLINK_PACKAGES+=	ap-perl

.if !empty(AP_PERL_BUILDLINK3_MK:M+)
BUILDLINK_DEPENDS.ap-perl+=	ap-perl>=1.29nb3
BUILDLINK_RECOMMENDED.ap-perl?=	ap-perl>=1.29nb4
BUILDLINK_PKGSRCDIR.ap-perl?=	../../www/ap-perl

BUILDLINK_FILES.ap-perl+=	lib/httpd/mod_perl.*
BUILDLINK_FILES.ap-perl+=	\
	${PERL5_SUB_INSTALLVENDORARCH}/auto/Apache/include/*
BUILDLINK_FILES.ap-perl+=	\
	${PERL5_SUB_INSTALLVENDORARCH}/auto/Apache/include/modules/perl/*
.endif	# AP_PERL_BUILDLINK3_MK

.include "../../www/apache/buildlink3.mk"

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
