# $NetBSD: buildlink3.mk,v 1.2 2004/12/01 15:33:47 taca Exp $

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH}+

.include "rdversion.mk"

RUBY_RDTOOL_BUILDLINK3_MK:=	${RUBY_RDTOOL_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	ruby-rdtool
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nruby-rdtool}
BUILDLINK_PACKAGES+=	ruby-rdtool

.if !empty(RUBY_RDTOOL_BUILDLINK3_MK:M+)
BUILDLINK_FILES.ruby-rdtool+=		bin/rd2
BUILDLINK_DEPMETHOD.ruby-rdtool?=	build
BUILDLINK_DEPENDS.ruby-rdtool+=		{${RUBY_RD_LIST}}>=0.6.14
BUILDLINK_PKGSRCDIR.ruby-rdtool?=	../../textproc/ruby-rdtool
.endif

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
