# $NetBSD: buildlink3.mk,v 1.11 2009/03/20 19:25:32 joerg Exp $

BUILDLINK_TREE+=	${RUBY_PKGPREFIX}-rdtool

.if !defined(RUBY_RDTOOL_BUILDLINK3_MK)
RUBY_RDTOOL_BUILDLINK3_MK:=

RUBY_RD=		rd2
RUBY_RD_VERSION =	0.6.18
RUBY_RD_REQD=		0.6.14

# create string for dependency list
RUBY_RD_LIST=	${RUBY_VERSION_LIST:C/([1-9][0-9]*)/ruby&-rdtool/g}

BUILDLINK_FILES.ruby18-rdtool+=		bin/rd2
BUILDLINK_DEPMETHOD.ruby18-rdtool?=	build
BUILDLINK_API_DEPENDS.ruby18-rdtool+=	{${RUBY_RD_LIST}}>=0.6.14
BUILDLINK_PKGSRCDIR.ruby18-rdtool?=	../../textproc/ruby-rdtool
.endif # RUBY_RDTOOL_BUILDLINK3_MK

BUILDLINK_TREE+=	-${RUBY_PKGPREFIX}-rdtool
