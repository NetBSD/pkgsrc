# $NetBSD: buildlink3.mk,v 1.31 2014/04/10 06:21:19 obache Exp $

BUILDLINK_TREE+=	kdebindings-ruby

.if !defined(KDEBINDINGS_RUBY_BUILDLINK3_MK)
KDEBINDINGS_RUBY_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.kdebindings-ruby+=	kdebindings-ruby>=3.5.5
BUILDLINK_ABI_DEPENDS.kdebindings-ruby+=	kdebindings-ruby>=3.5.10nb33
BUILDLINK_PKGSRCDIR.kdebindings-ruby?=	../../x11/kdebindings-ruby

.include "../../lang/ruby/buildlink3.mk"
.include "../../x11/kdebase3/buildlink3.mk"
.include "../../x11/kdelibs3/buildlink3.mk"
.endif # KDEBINDINGS_RUBY_BUILDLINK3_MK

BUILDLINK_TREE+=	-kdebindings-ruby
