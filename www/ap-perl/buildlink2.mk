# $NetBSD: buildlink2.mk,v 1.1 2002/10/27 12:38:43 seb Exp $
#
# This Makefile fragment is included by packages that use ap-perl.
#
# This file was created automatically using createbuildlink 2.2.
#

.if !defined(AP_PERL_BUILDLINK2_MK)
AP_PERL_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=			ap-perl
BUILDLINK_DEPENDS.ap-perl?=		ap-perl>=1.25nb1
BUILDLINK_PKGSRCDIR.ap-perl?=		../../www/ap-perl

EVAL_PREFIX+=	BUILDLINK_PREFIX.ap-perl=ap-perl
BUILDLINK_PREFIX.ap-perl_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.ap-perl+=	lib/httpd/mod_perl.*
BUILDLINK_FILES.ap-perl+=	\
	${PERL5_SITEARCH:S/^${BUILDLINK_PREFIX.perl}\///}/auto/Apache/include/*
BUILDLINK_FILES.ap-perl+=	\
	${PERL5_SITEARCH:S/^${BUILDLINK_PREFIX.perl}\///}/auto/Apache/include/modules/perl/*

.include "../../lang/perl5/buildlink2.mk"
.include "../../www/apache/buildlink2.mk"

BUILDLINK_TARGETS+=	ap-perl-buildlink

ap-perl-buildlink: _BUILDLINK_USE

.endif	# AP_PERL_BUILDLINK2_MK
