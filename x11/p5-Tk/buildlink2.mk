# $NetBSD: buildlink2.mk,v 1.1 2003/09/16 15:45:14 jmmv Exp $

.if !defined(P5_TK_BUILDLINK2_MK)
P5_TK_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=		p5-Tk
BUILDLINK_DEPENDS.p5-Tk?=	p5-Tk>=800.024
BUILDLINK_PKGSRCDIR.p5-Tk?=	../../x11/p5-Tk

.include "../../lang/perl5/buildlink2.mk"

BUILDLINK_PREFIX.p5-Tk=	${BUILDLINK_PREFIX.perl}
BUILDLINK_FILES.p5-Tk=	\
	${PERL5_SITEARCH:S/^${BUILDLINK_PREFIX.perl}\///}/Tie/* \
	${PERL5_SITEARCH:S/^${BUILDLINK_PREFIX.perl}\///}/Tk/* \
	${PERL5_SITEARCH:S/^${BUILDLINK_PREFIX.perl}\///}/Tk/*/* \
	${PERL5_SITEARCH:S/^${BUILDLINK_PREFIX.perl}\///}/Tk/*/*/* \
	${PERL5_SITEARCH:S/^${BUILDLINK_PREFIX.perl}\///}/Tk/*/*/* \
	${PERL5_SITEARCH:S/^${BUILDLINK_PREFIX.perl}\///}/auto/Tk/* \
	${PERL5_SITEARCH:S/^${BUILDLINK_PREFIX.perl}\///}/auto/Tk/*/*

BUILDLINK_CPPFLAGS.p5-Tk=	-I${PERL5_SITEARCH}/Tk/pTk

BUILDLINK_TARGETS+=	p5-Tk-buildlink

p5-Tk-buildlink: _BUILDLINK_USE

.endif	# P5_TK_BUILDLINK2_MK
