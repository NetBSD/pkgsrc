# $NetBSD: buildlink3.mk,v 1.3 2004/12/16 13:20:37 taca Exp $

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH}+

.include "rdversion.mk"

RUBY_RDTOOL_BUILDLINK3_MK:=	${RUBY_RDTOOL_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	${RUBY_PKGPREFIX}-rdtool
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:N${RUBY_PKGPREFIX}-rdtool}
BUILDLINK_PACKAGES+=	${RUBY_PKGPREFIX}-rdtool

.if !empty(RUBY_RDTOOL_BUILDLINK3_MK:M+)
.if ${RUBY_VER} == "16"
BUILDLINK_FILES.ruby16-rdtool+=		bin/rd2
BUILDLINK_DEPMETHOD.ruby16-rdtool?=	build
BUILDLINK_DEPENDS.ruby16-rdtool+=	{${RUBY_RD_LIST}}>=0.6.14
BUILDLINK_PKGSRCDIR.ruby16-rdtool?=	../../textproc/ruby-rdtool
.elif ${RUBY_VER} == "18"
BUILDLINK_FILES.ruby18-rdtool+=		bin/rd2
BUILDLINK_DEPMETHOD.ruby18-rdtool?=	build
BUILDLINK_DEPENDS.ruby18-rdtool+=	{${RUBY_RD_LIST}}>=0.6.14
BUILDLINK_PKGSRCDIR.ruby18-rdtool?=	../../textproc/ruby-rdtool
.endif
.endif

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
