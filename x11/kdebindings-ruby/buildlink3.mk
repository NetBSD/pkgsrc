# $NetBSD: buildlink3.mk,v 1.29 2013/10/09 17:39:03 wiz Exp $

BUILDLINK_TREE+=	kdebindings-ruby

.if !defined(KDEBINDINGS_RUBY_BUILDLINK3_MK)
KDEBINDINGS_RUBY_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.kdebindings-ruby+=	kdebindings-ruby>=3.5.5
BUILDLINK_ABI_DEPENDS.kdebindings-ruby+=	kdebindings-ruby>=3.5.10nb30
BUILDLINK_PKGSRCDIR.kdebindings-ruby?=	../../x11/kdebindings-ruby

.include "../../lang/ruby/buildlink3.mk"
.include "../../x11/kdebase3/buildlink3.mk"
.include "../../x11/kdelibs3/buildlink3.mk"
.endif # KDEBINDINGS_RUBY_BUILDLINK3_MK

BUILDLINK_TREE+=	-kdebindings-ruby
