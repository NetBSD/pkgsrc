# $NetBSD: buildlink2.mk,v 1.1 2002/10/04 04:15:01 rh Exp $
#

.if !defined(TEXI2HTML_BUILDLINK2_MK)
TEXI2HTML_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=		texi2html
BUILDLINK_DEPENDS.texi2html?=	texi2html>=1.64
BUILDLINK_PKGSRCDIR.texi2html?=	../../textproc/texi2html
BUILDLINK_DEPMETHOD.texi2html?=	build

EVAL_PREFIX+=	BUILDLINK_PREFIX.texi2html=texi2html
BUILDLINK_PREFIX.texi2html_DEFAULT=	${LOCALBASE}

.include "../../lang/perl5/buildlink2.mk"

BUILDLINK_TARGETS+=	texi2html-buildlink

texi2html-buildlink: _BUILDLINK_USE

.endif	# TEXI2HTML_BUILDLINK2_MK
