# $NetBSD: buildlink2.mk,v 1.1 2002/10/25 12:53:41 wiz Exp $
#

.if !defined(RUBY_ERUBY_BUILDLINK2_MK)
RUBY_ERUBY_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=			ruby-eruby
BUILDLINK_DEPENDS.ruby-eruby?=		ruby-eruby>=0.9.7
BUILDLINK_PKGSRCDIR.ruby-eruby?=	../../textproc/ruby-eruby

EVAL_PREFIX+=	BUILDLINK_PREFIX.ruby-eruby=ruby-eruby
BUILDLINK_PREFIX.ruby-eruby_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.ruby-eruby+=	include/eruby.h
BUILDLINK_FILES.ruby-eruby+=	lib/liberuby.*

BUILDLINK_TARGETS+=	ruby-eruby-buildlink

ruby-eruby-buildlink: _BUILDLINK_USE

.endif	# RUBY_ERUBY_BUILDLINK2_MK
