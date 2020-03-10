# $NetBSD: buildlink3.mk,v 1.3 2020/03/10 22:09:16 wiz Exp $

BUILDLINK_TREE+=	ruby-gtk3

.if !defined(RUBY_GTK3_BUILDLINK3_MK)
RUBY_GTK3_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.ruby-gtk3+=	${RUBY_PKGPREFIX}-gtk3>=3.3.8
BUILDLINK_ABI_DEPENDS.ruby-gtk3+=	${RUBY_PKGPREFIX}-gtk3>=3.4.1nb2
BUILDLINK_PKGSRCDIR.ruby-gtk3?=		../../x11/ruby-gtk3

.include "../../devel/ruby-pango/buildlink3.mk"
.include "../../x11/gtk3/buildlink3.mk"
.endif # RUBY_GTK3_BUILDLINK3_MK

BUILDLINK_TREE+=	-ruby-gtk3
